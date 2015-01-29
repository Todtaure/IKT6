#pragma once
class Node
{
public:
	Node(int i = 0, Node* n = nullptr)
		:info(i), next(n){}
	~Node();

	int info;
	Node* next;
};

