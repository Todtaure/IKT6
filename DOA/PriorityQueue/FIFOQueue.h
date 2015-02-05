#include "stdafx.h"
#include "Node.h"
#include "LLToolKit.h"

template <typename T> 
class Queue 
{
public: 
	Queue<T>()
		: _head(nullptr), _tail(nullptr){}
	
	void push(T value) 
	{	
		if (_head != nullptr)
		{
			LLToolKit<T>::insert(_tail, value);
			return;
		}	
		_head = new Node<T>(value, nullptr);
		_tail = _head;
	}
	
	void pop() 
	{
		LLToolKit<T>::headRemove(_head);
		
		if (_head == nullptr)
		{
			_tail = nullptr;
		}
	}

	T front() 
	{
		return _head->info;
	}

	bool isEmpty() 
	{
		return _head == nullptr;
	}

	void dump() 
	{
		LLToolKit<T>::print(_head);
	}

private:
	Node<T>* _head;
	Node<T>* _tail;
};
