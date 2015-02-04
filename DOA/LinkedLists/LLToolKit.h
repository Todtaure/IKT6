#pragma once
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
		Node<T>* tmp = headRef; //DAFUQ?
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

	static void reverse(Node<T>*& headRef)
	{
		if (headRef == NULL || headRef->next NULL)
		{
			return;
		}
		Node<T>* previous = NULL;

		for (Node<T>* nextElement = sourcePtr->next; nextElement != NULL; nextElement = nextElement->next)
		{
			headRef->next = previous;
			previous = headRef;
			headRef = nextElement

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
		if (n < 0)
		{
			return NULL;
		}

		return new Node<int>(*(values + (n - 1)), build(values, n - 1));
	}

	
};

