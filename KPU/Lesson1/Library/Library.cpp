// Library.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Library.h"


// This is an example of an exported variable
LIBRARY_API int nLibrary=0;

// This is an example of an exported function.
LIBRARY_API int fnLibrary(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see Library.h for the class definition
CLibrary::CLibrary()
{
	return;
}

int sumInt32(int first, int second)
{
	return first += second;
}

std::string concatString(std::string first, std::string second)
{
	return first += second;
}

char* concatChar(char first, char second)
{
	char tmp[3];

	tmp[0] = first;
	tmp[1] = second;
	tmp[2] = '\0';

	return tmp;
}