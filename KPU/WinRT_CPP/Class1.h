﻿#include <collection.h>
#include <amp.h>
#include <amp_math.h>

#pragma once

namespace WinRT_CPP
{
	public delegate void PrimeFoundHandler(int result);

    public ref class Class1 sealed
    {
    public:
        Class1();
		//sync
		Windows::Foundation::Collections::IVector<double>^ ComputeResult(double input);
		
		//async
		Windows::Foundation::IAsyncOperationWithProgress<Windows::Foundation::Collections::IVector<int>^, double>^ GetPrimesOrdered(int first, int last);
		Windows::Foundation::IAsyncActionWithProgress<double>^ GetPrimesUnordered(int first, int last);

		//delegate
		event PrimeFoundHandler^ primeFoundEvent;

	private:
		bool is_prime(int n);
		Windows::UI::Core::CoreDispatcher^ m_dispatcher;
    };
}