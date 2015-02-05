// PriorityQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FIFOQueue.h"
#include <iostream>
#include "PriorityQueue.h"

void RunExercise3();
void RunExercise4();

int _tmain(int argc, _TCHAR* argv[])
{
	//RunExercise3();

	RunExercise4();

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

void RunExercise4() 
{
	PriorityQueue<int>* priorityQueue = new PriorityQueue<int>();

	std::cout << "Checking if queue is empty (1=true, 0=false): " << priorityQueue->isEmpty() << std::endl;

	std::cout << "Pushing elements..." << std::endl;
	priorityQueue->push(21, priorityQueue->LOW);
	priorityQueue->push(22, priorityQueue->MED_LOW);
	priorityQueue->push(23, priorityQueue->MED);
	priorityQueue->push(24, priorityQueue->MED_LOW);
	priorityQueue->push(25, priorityQueue->MED_HIGH);
	priorityQueue->push(26, priorityQueue->HIGH);

	std::cout << "Checking if queue is empty after elements pushed(1=true, 0=false): " << priorityQueue->isEmpty() << std::endl;

	std::cout << "Checking the first element and then popping:" << priorityQueue->front() << std::endl;
	priorityQueue->pop();

	std::cout << "Checking the first element and then popping:" << priorityQueue->front() << std::endl;
	priorityQueue->pop();

	std::cout << "Checking the first element and then popping:" << priorityQueue->front() << std::endl;
	priorityQueue->pop();

	std::cout << "Checking the first element and then popping:" << priorityQueue->front() << std::endl;
	priorityQueue->pop();

	std::cout << "Checking the first element and then popping:" << priorityQueue->front() << std::endl;
	priorityQueue->pop();

	std::cout << "Checking the first element and then popping:" << priorityQueue->front() << std::endl;
	priorityQueue->pop();

	std::cout << "Checking if queue is empty (1=true, 0=false): " << priorityQueue->isEmpty() << std::endl;
}
