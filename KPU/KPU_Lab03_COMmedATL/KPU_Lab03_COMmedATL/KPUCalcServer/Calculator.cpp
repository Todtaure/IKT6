// Calculator.cpp : Implementation of CCalculator

#include "stdafx.h"
#include "Calculator.h"


// CCalculator



STDMETHODIMP CCalculator::Add(LONG arg1, LONG arg2, LONG* result)
{
	// TODO: Add your implementation code here
	*result = arg1 + arg2 + offset; 

	return S_OK;
}


STDMETHODIMP CCalculator::Sub(LONG arg1, LONG arg2, LONG* result)
{
	// TODO: Add your implementation code here
	*result = arg1 - arg2 + offset;
	return S_OK;
}


STDMETHODIMP CCalculator::get_Offset(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = offset;
	return S_OK;
}


STDMETHODIMP CCalculator::put_Offset(LONG newVal)
{
	// TODO: Add your implementation code here
	offset = newVal;
	return S_OK;
}

STDMETHODIMP CCalculator::Mul(LONG arg1, LONG arg2, LONG * result)
{
	// Add your function implementation here.
	*result = arg1 * arg2 + offset;   
	return S_OK;
}

STDMETHODIMP CCalculator::Div(LONG arg1, LONG arg2, LONG * result)
{
	if (arg2 != 0)
	{
		*result = (arg1 / arg2) + offset;
		return S_OK;
	}
	else
		return E_INVALIDARG;
}