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
	if(headRef == NULL)
	{
		return;
	}
	Node* tmp = headRef;
	headRef = headRef->next;
	delete tmp;
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
	if (sourcePtr == NULL)
	{
		return NULL;
	}

	Node* newHead = new Node(sourcePtr->info, NULL);
	Node* current = newHead;

	for (Node* cursor = sourcePtr->next; cursor != NULL; cursor = cursor->next)
	{
		current->next = new Node(cursor->info, NULL);
		current = current->next;
	}

	return newHead;
}
