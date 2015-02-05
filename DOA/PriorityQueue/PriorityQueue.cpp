// PriorityQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FIFOQueue.h"
#include <iostream>
#include "PriorityQueue.h"

void RunExercise3();

int _tmain(int argc, _TCHAR* argv[])
{
	PriorityQueue<int>* priorityQueue = new PriorityQueue<int>();

	priorityQueue->push(25, priorityQueue->LOW);
	priorityQueue->push(25, priorityQueue->MED_LOW);
	priorityQueue->push(25, priorityQueue->MED);
	priorityQueue->push(25, priorityQueue->MED_LOW);
	priorityQueue->push(25, priorityQueue->MED_HIGH);
	priorityQueue->push(25, priorityQueue->HIGH);



	getchar();


	return 0;
}

void RunExercise3() 
{
	Queue<int>* queue = new Queue<int>();

	std::cout << "Check if queue is empty: " << queue->isEmpty() << std::endl;
	std::cout << "push some values, 2 and 4: " << std::endl;
	queue->push(2);
	queue->push(4);
	std::cout << "print: " << std::endl;
	queue->dump();
	std::cout << "Check the first element: " << queue->front() << std::endl;
	std::cout << "Check if queue is empty: " << queue->isEmpty() << std::endl;
	queue->pop();
	queue->dump();
	queue->pop();
	std::cout << queue->isEmpty() << std::endl;
}

