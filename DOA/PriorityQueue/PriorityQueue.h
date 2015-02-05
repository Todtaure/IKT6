#pragma once

#include "stdafx.h"
#include "FIFOQueue.h"

template <typename T>
class PriorityQueue
{
public:
	enum Priority
	{
		LOW,
		MED_LOW,
		MED,
		MED_HIGH,
		HIGH
	};

	PriorityQueue<T>()
	{
		_qLow = new Queue<T>();
		_qMedLow = new Queue<T>();
		_qMed = new Queue<T>();
		_qMedHigh = new Queue<T>();
		_qHigh = new Queue<T>();
	}

	void push(T value, Priority priority)
	{
		switch (priority)
		{
		case LOW:
			_qLow->push(value);
			break;
		case MED_LOW:
			_qMedLow->push(value);
			break;
		case MED:
			_qMed->push(value);
			break;
		case MED_HIGH:
			_qMedHigh->push(value);
			break;
		case HIGH:
			_qHigh->push(value);
			break;
		}
	}

	void pop()
	{
		if (!_qHigh->isEmpty())
		{
			_qHigh->pop();
		}

		else if (!_qMedHigh->isEmpty())
		{
			_qMedHigh->pop();
		}

		else if (!_qMed->isEmpty())
		{
			_qMed->pop();
		}

		else if (!_qMedLow->isEmpty())
		{
			_qMedLow->pop();
		}

		else if (!_qLow->isEmpty())
		{
			_qLow->pop();
		}
	}

	T front()
	{
		if (!_qHigh->isEmpty())
		{
			return _qHigh->front();
		}

		else if (!_qMedHigh->isEmpty())
		{
			return _qMedHigh->front();
		}

		else if (!_qMed->isEmpty())
		{
			return _qMed->front();
		}

		else if (!_qMedLow->isEmpty())
		{
			return _qMedLow->front();
		}

		else if (!_qLow->isEmpty())
		{
			return _qLow->front();
		}
	}

	bool isEmpty()
	{
		return _qLow->isEmpty() || _qMedLow->isEmpty() || _qMed->isEmpty() || _qMedHigh->isEmpty() || _qHigh->isEmpty();
	}

private:
	Queue<T>* _qLow;
	Queue<T>* _qMedLow;
	Queue<T>* _qMed;
	Queue<T>* _qMedHigh;
	Queue<T>* _qHigh;
};