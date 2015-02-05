#pragma once
#include "stdafx.h"
#include "Node.h"

template <typename T>
class LLToolKit
{
public:
	/*LLToolKit();
	~LLToolKit();*/

	static void headinsert(Node<T>*& headRef, T info)	// O(1)
	{
		headRef = new Node<T>(info, headRef);
	}

	static void headRemove(Node<T>*& headRef)			// O(1)
	{
		if (headRef == NULL)
		{
			return;
		}
		Node<T>* tmp = headRef;
		headRef = headRef->next;
		delete tmp;
	}

	static void insert(Node<T>* prevNodePtr, T info)	// O(1)
	{
		Node<T>* tmpPtr = prevNodePtr->next;
		prevNodePtr->next = new Node<T>(info, tmpPtr);
	}

	static void remove(Node<T>* prevNodePtr)			// O(1)
	{
		Node<T>* tmpPtr = prevNodePtr->next;

		prevNodePtr->next = tmpPtr->next;

		delete tmpPtr;
	}
	
	static Node<T>* copy(Node<T>* sourcePtr)			// O(n)
	{
		if (sourcePtr == NULL)
		{
			return NULL;
		}
		
		Node<T>* newHead = new Node<T>(sourcePtr->info, NULL);
		Node<T>* current = newHead;

		for (Node<T>* cursor = sourcePtr->next; cursor != NULL; cursor = cursor->next)
		{			
			current->next = new Node<T>(cursor->info, NULL);
			current = current->next;
		}

		return newHead;
	}

	//Exercise 6

	static void clear(Node<T>*& headRef)
	{
		while (headRef != NULL)
		{
			headRemove(headRef);
		}
	}

	static void print(Node<T>* headPtr)
	{
		std::string tmp = "";

		for (Node<T>* cursor = headPtr; cursor != NULL; cursor = cursor->next)
		{
			tmp += std::to_string(cursor->info) + " | ";
		}

		std::cout << "Data in list: " << std::endl << tmp << std::endl;
	}

	static void reverse(Node<T>*& headRef)
	{
		if (headRef == NULL || headRef->next NULL) //Works? TODO
		{
			return;
		}
		Node<T>* previous = NULL;

		for (Node<T>* nextElement = headRef->next; nextElement != NULL; nextElement = nextElement->next)
		{
			headRef->next = previous;
			previous = headRef;
			headRef = nextElement;
		}
	}

	static Node<T>* split(Node<T>* splitPtr)
	{
		Node<T>* splitHead = splitPtr->next;
		splitPtr->next = NULL;
		return splitHead;
	}

	static Node<int>* build(int* values, std::size_t n)
	{
		if (n == 0)
		{
			return NULL;
		}

		return new Node<int>(*(values + (n - 1)), build(values, n - 1));
	}

	static void join(Node<T>*& headOneRef, Node<T>* headTwoPtr)
	{
		Node<T>* cursor = headOneRef;
		while (cursor->next != NULL)
		{
			cursor = cursor->next;
		}
		cursor->next = headTwoPtr;
	}

	static void rotateLeft(Node<T>*& headRef)
	{
		if (headRef == NULL)
		{
			return;
		}

		Node<T>* tail = headRef;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
				
		tail->next = headRef;		
		headRef = headRef->next;
		tail->next->next = NULL;
	}

	static void rotateRight(Node<T>*& headRef)
	{
		if (headRef == NULL )
		{			
			return;
		}
		if (headRef->next == NULL)
		{
			return;
		}

		Node<T>* cursor = headRef;
		Node<T>* tail = NULL;
		while (cursor->next->next != NULL)
		{
			cursor = cursor->next;
		}

		tail = cursor->next;
		tail->next = headRef;
		cursor->next = NULL;
		headRef = tail;
	}
	
};

