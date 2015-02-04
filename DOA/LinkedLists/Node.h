#pragma once

template <typename T>
class Node
{
public:
	Node(T i = T(), Node* n = nullptr)
		:info(i), next(n){}
	~Node(){}

	T info;
	Node* next;
};

