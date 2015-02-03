// CDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "CDLL.h"
#include "..\Lab2_headers\CDLLclass.h"

// This is an example of an exported variable
CDLL_API int nCDLL=0;

// This is an example of an exported function.
CDLL_API int fnCDLL(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see CDLL.h for the class definition
CCDLL::CCDLL()
{
	return;
}

CDLLclass* CreateDllObject()
{

}

void DeleteDllObject(CDLLclass* cdll)
{

}
