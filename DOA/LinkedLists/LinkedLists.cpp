// LinkedLists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LLToolKit.h"
#include <iostream>

template <typename T> void printAllNodes(Node<T>* head);

void runExerciseThree();

void runExerciseSix();

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "Initilizing Linked Lists console application..." << std::endl;
	
	runExerciseThree();
	runExerciseSix();

	getchar();

	return 0;
}

void runExerciseSix()
{
	std::cout << std::endl;
	//LLToolKit<int>::split
	std::cout << "TEST -- LLToolKit<int>::split..." << std::endl;
	std::cout << "Split between 2 and 3" << std::endl;
	Node<int>* head = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, NULL))));
	Node<int>* secHead = LLToolKit<int>::split(head->next);
	std::cout << "First list: " << std::endl;
	printAllNodes(head);
	std::cout << "Second list: " << std::endl;
	printAllNodes(secHead);

	std::cout << std::endl;
	// LLToolKit<int>::build
	std::cout << "TEST -- LLToolKit<int>::build..." << std::endl;
	std::cout << "Build from array[1,2,3,4]" << std::endl;
	int values [4] =  {1, 2, 3, 4 };
	int* valPtr = values;	
	Node<int>* result = LLToolKit<int>::build(valPtr, sizeof(valPtr));
	printAllNodes(result);	
}

void runExerciseThree()
{
	std::cout << std::endl;
	Node<int>* head = new Node<int>(1, new Node<int>(2, new Node<int>(3, NULL)));
	std::cout << "What is head?" << std::endl << "head : " << head << std::endl << "&head : " << &head << std::endl;
	printAllNodes(head);

	std::cout << std::endl;
	//LLToolKit<int>::headRemove
	std::cout << "TEST -- LLToolKit<int>::headRemove..." << std::endl;
	LLToolKit<int>::headRemove(head);
	printAllNodes(head);

	std::cout << std::endl;
	//LLToolKit<int>::headInsert
	std::cout << "TEST -- LLToolKit<int>::headInsert..." << std::endl;
	LLToolKit<int>::headinsert(head, 1);
	printAllNodes(head);

	std::cout << std::endl;
	//LLToolKit<int>::insert
	std::cout << "TEST -- LLToolKit<int>::insert..." << std::endl;
	std::cout << std::endl << "Insert between 2 and 3..." << std::endl;
	LLToolKit<int>::insert(head->next, 5);
	printAllNodes(head);

	std::cout << std::endl;
	//LLToolKit<int>::remove
	std::cout << "TEST -- LLToolKit<int>::remove..." << std::endl;
	std::cout << std::endl << "Remove node between 2 and 3..." << std::endl;
	LLToolKit<int>::remove(head->next);
	printAllNodes(head);

	std::cout << std::endl;
	//LLToolKit<int>::copy
	std::cout << "TEST -- LLToolKit<int>::copy..." << std::endl;
	std::cout << std::endl << "Copy first head, to ensure a copy was made, add node to copy..." << std::endl;
	Node<int>* copy = LLToolKit<int>::copy(head);
	LLToolKit<int>::insert(copy->next->next, 4);
	std::cout << "Original list:" << std::endl;
	printAllNodes(head);
	std::cout << "New copy list:" << std::endl;
	printAllNodes(copy);
}

template <typename T> void printAllNodes(Node<T>* head)
{
	std::cout << "Nodes in linked list:" << std::endl;
	for (Node<T>* current = head; current != NULL; current = current->next)
	{
		std::cout << current->info << std::endl;
	}
}
