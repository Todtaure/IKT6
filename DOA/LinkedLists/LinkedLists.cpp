// LinkedLists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LLToolKit.h"
#include <iostream>

template <typename T> void printAllNodes(Node<T>* head);

template <typename T> void runExerciseThree();

void runExerciseSix();

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "Initilizing Linked Lists console application..." << std::endl;

	Node<int>* head = new Node<int>(1, new Node<int>(2, new Node<int>(3, NULL)));

	runExerciseSix();

	return 0;
}

void runExerciseSix()
{
	int* values = new int[ 1, 2, 3, 4 ];
	
	Node<int>* result = LLToolKit<int>::build(values, sizeof(values));

	printAllNodes(result);
}

template <typename T> void runExerciseThree(Node<T> head)
{
	std::cout << "What is head?" << std::endl << "head : " << head << std::endl << "&head : " << &head << std::endl;

	printAllNodes(head);

	std::cout << std::endl << "Delete first node..." << std::endl;
	LLToolKit<int>::headRemove(head);
	printAllNodes(head);

	std::cout << std::endl << "Insert before first node..." << std::endl;
	LLToolKit<int>::headinsert(head, 1);
	printAllNodes(head);

	std::cout << std::endl << "Insert between 2 and 3..." << std::endl;
	LLToolKit<int>::insert(head->next, 5);
	printAllNodes(head);

	std::cout << std::endl << "Remove node between 2 and 3..." << std::endl;
	LLToolKit<int>::remove(head->next);
	printAllNodes(head);

	std::cout << std::endl << "Copy first head, to ensure a copy was made, add node to copy..." << std::endl;
	Node<int>* copy = LLToolKit<int>::copy(head);
	LLToolKit<int>::insert(copy->next->next, 4);

	std::cout << "Original list:" << std::endl;
	printAllNodes(head);
	std::cout << "New copy list:" << std::endl;
	printAllNodes(copy);

	getchar();
}

template <typename T> void printAllNodes(Node<T>* head)
{
	std::cout << "Nodes in linked list:" << std::endl;
	for (Node<T>* current = head; current != NULL; current = current->next)
	{
		std::cout << current->info << std::endl;
	}
}
