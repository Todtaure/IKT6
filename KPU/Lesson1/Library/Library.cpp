// Library.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Library.h"


int sumInt32(int first, int second)
{
	return first += second;
}

std::string concatString(std::string first, std::string second)
{
	return first += second;
}

char* concatChar(char* first, char* second)
{
	size_t len = strlen(first) + strlen(second) + 1;
	char* retVal = new char[len];
	retVal[0] = 0;  // Empty string
	strcat_s(retVal, len, first);
	strcat_s(retVal, len, second);
	return retVal;
}