// Lab0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "TestFunctions.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char key = '.';

	do{
		CalcPi(500000);
		key = getchar();
	} while (key != 'q');
	
	return 0;
}
