// UnmanagedDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

extern "C"{
	double __declspec(dllexport) Add(double a, double b)
	{
		return a + b;
	}

	double __declspec(dllexport) Subtract(double a, double b)
	{
		return a - b;
	}

	double __declspec(dllexport) Multiply(double a, double b)
	{
		return a * b;
	}
}


