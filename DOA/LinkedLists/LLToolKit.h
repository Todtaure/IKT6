#pragma once
#include "Node.h"

class LLToolKit
{
public:
	/*LLToolKit();
	~LLToolKit();*/

	static void headinsert(Node*& headRef, int info);
	static void headRemove(Node*& headRef);
	static void insert(Node* prevNodePtr, int info);
	static void remove(Node* prevNodePtr);
	
	static Node* copy(Node* sourcePtr);

};

