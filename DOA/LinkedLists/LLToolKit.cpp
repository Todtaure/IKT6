#include "stdafx.h"
#include "LLToolKit.h"


//LLToolKit::LLToolKit()
//{
//}
//
//LLToolKit::~LLToolKit()
//{
//}

void LLToolKit::headinsert(Node*& headRef, int info)
{
	headRef = new Node(info, headRef);
}

void LLToolKit::headRemove(Node*& headRef)
{
	headRef = headRef->next; //missing delete statement?
}

void LLToolKit::insert(Node* prevNodePtr, int info)
{
	Node* tmpPtr = prevNodePtr->next;
	
	prevNodePtr->next = new Node(info, tmpPtr);
}

void LLToolKit::remove(Node* prevNodePtr)
{
	Node* tmpPtr = prevNodePtr->next;

	prevNodePtr->next = tmpPtr->next;

	delete tmpPtr;
}

Node* LLToolKit::copy(Node* sourcePtr)
{
	Node* newHead = new Node(sourcePtr->info, NULL);
	Node* current = newHead;

	for (Node* cursor = sourcePtr->next; cursor != NULL; cursor = cursor->next)
	{
		current->next = new Node(cursor->info, NULL);
		current = current->next;
	}

	return newHead;
}