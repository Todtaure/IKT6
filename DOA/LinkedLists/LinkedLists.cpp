// LinkedLists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LLToolKit.h"
#include <iostream>

void printAllNodes(Node* head);

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "Initilizing Linked Lists console application..." << std::endl;

	Node* head = new Node(1, new Node(2, new Node(3, NULL)));

	std::cout << "What is head?" << std::endl << "head : " << head << std::endl << "&head : " << &head << std::endl;

	printAllNodes(head);

	std::cout << std::endl << "Delete first node..." << std::endl;
	LLToolKit::headRemove(head);
	printAllNodes(head);

	std::cout << std::endl << "Insert before first node..." << std::endl;
	LLToolKit::headinsert(head, 1);	
	printAllNodes(head);

	std::cout << std::endl << "Insert between 2 and 3..." << std::endl;
	LLToolKit::insert(head->next, 5);
	printAllNodes(head);

	std::cout << std::endl << "Remove node between 2 and 3..." << std::endl;
	LLToolKit::remove(head->next);
	printAllNodes(head);

	std::cout << std::endl << "Copy first head, to ensure a copy was made, add node to copy..." << std::endl;
	Node* copy = LLToolKit::copy(head);
	LLToolKit::insert(copy->next->next, 4);
	
	std::cout << "Original list:" << std::endl;
	printAllNodes(head);
	std::cout << "New copy list:" << std::endl;
	printAllNodes(copy);

	getchar();

	return 0;
}

void printAllNodes(Node* head)
{
	std::cout << "Nodes in linked list:" << std::endl;
	for (Node* current = head; current != NULL; current = current->next)
	{
		std::cout << current->info << std::endl;
	}
}

