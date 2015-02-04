// ConsoleTester.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "..\Library\Library.h"

int testLoadTimeLinking();
int testRunTimeLinking();
void GiveErrMessageFuncMissing(std::wstring libraryName, char* funcName);

int _tmain(int argc, _TCHAR* argv[])
{
	testLoadTimeLinking();

	return 0;
}

int testLoadTimeLinking()
{
	int no1;
	int no2;
	int res;

	const int STRLEN = 81;
	char ach1[STRLEN];
	char ach2[STRLEN];
	char *achRes = NULL;
	std::string str1;
	std::string str2;
	std::string strRes;

	std::cout << "Please enter first number: ";
	std::cin >> no1;
	std::cout << "\nPlease enter second number: ";
	std::cin >> no2;
	res = sumInt32(no1, no2);
	std::cout << "The sum of " << no1 << " and " << no2 << " is " << res << ".\n\n";

	std::cout << "Test of char* version ----------------\n";
	std::cout << "Please enter first string: ";
	std::cin.getline(ach1, STRLEN);  // Get rid of new-line chars
	std::cin.getline(ach1, STRLEN);
	std::cout << "Please enter second string: ";
	std::cin.getline(ach2, STRLEN);
	achRes = concatChar(ach1, ach2);

	std::cout << "The concatenated string: " << achRes << "\n\n";
	delete[] achRes;	// Free the allocated memory

	// The use of getline makes it possible to enter spaces
	// If you don't need spaces just use cin >> str1;
	std::cout << "Test of string version ----------------\n";
	std::cout << "Please enter first string: ";
	getline(std::cin, str1);
	std::cout << "Please enter second string: ";
	getline(std::cin, str2);
	strRes = concatString(str1, str2);
	std::cout << "The concatenated string: " << strRes << "\n\n";

	std::cout << "Press Enter to stop program";
	getline(std::cin, str1);
}

int testRunTimeLinking()
{
	int no1;
	int no2;
	int res;

	const int STRLEN = 81;
	char ach1[STRLEN];
	char ach2[STRLEN];
	char *achRes = NULL;
	std::string str1;
	std::string str2;
	std::string strRes;
	std::wstring libraryName;

	//libraryName = TEXT("Lab1_1.dll");

	// Read filename from console by use of C++ functions
	// --------------------------------------------------------------- 
	std::wcout << TEXT("Please enter the name of the plug-in you want to load: ");
	getline(std::wcin, libraryName);


	// A typedef to hold the address of the myAdd() method.
	typedef int(*PFNsumInt) (int, int);
	PFNsumInt pfnsumInt;

	// A typedef to hold the address of the myStr() method.
	typedef char* (*PFNconcatChar) (char*, char*);
	PFNconcatChar pfnconcatChar;

	// A typedef to hold the address of the myString() method.
	typedef std::string(*PFNconcatString) (std::string, std::string);
	PFNconcatString pfnconcatString;

	HINSTANCE dllHandle = NULL;	// Handle to dll              

	// Load the dll and keep the handle to it
	// Assume this DLL is in the same folder as the 
	// client EXE (or in another folder in the search chain)
	dllHandle = LoadLibrary(libraryName.c_str());

	// If the handle is valid, try to get the function addresses. 
	if (dllHandle == NULL)
	{
		std::wcout << "Unable to load library: " << libraryName << std::endl;
		return 1;
	}

	//Get pointer to the myAdd function using GetProcAddress:
	char* funcName = "sumInt";
	pfnsumInt = (PFNsumInt)GetProcAddress(dllHandle, funcName);

	// If the function address is invalid, give error message and abort program. 
	if (pfnsumInt == NULL)
	{
		GiveErrMessageFuncMissing(libraryName, funcName);
		return 1;
	}
	std::cout << "Please enter first number: ";
	std::cin >> no1;
	std::cout << "Please enter second number: ";
	std::cin >> no2;
	res = pfnsumInt(no1, no2);
	std::cout << "The sum of " << no1 << " and " << no2 << " is " << res << ".\n\n";


	//Get pointer to the myAddStr function using GetProcAddress:
	funcName = "concatChar";
	pfnconcatChar = (PFNconcatChar)GetProcAddress(dllHandle, funcName);

	// If the function address is invalid, give error message and abort program. 
	if (pfnconcatChar == NULL)
	{
		GiveErrMessageFuncMissing(libraryName, funcName);
		return 1;
	}
	std::cout << "Test of char* version ----------------\n";
	std::cout << "Please enter first string: ";
	std::cin.getline(ach1, STRLEN);  // Get rid of new-line chars
	std::cin.getline(ach1, STRLEN);
	std::cout << "Please enter second string: ";
	std::cin.getline(ach2, STRLEN);
	achRes = pfnconcatChar(ach1, ach2);

	std::cout << "The concatenated string: " << achRes << "\n\n";
	delete[] achRes;

	// The use of getline makes it possible to enter spaces
	// If you don't need spaces just use cin >> str1;
	//Get pointer to the myAddStr function using GetProcAddress:
	funcName = "concatString";
	pfnconcatString = (PFNconcatString)GetProcAddress(dllHandle, funcName);

	// If the function address is invalid, give error message and abort program. 
	if (pfnconcatString == NULL)
	{
		GiveErrMessageFuncMissing(libraryName, funcName);
		return 1;
	}
	std::cout << "Test of string version ----------------\n";
	std::cout << "Please enter first string: ";
	getline(std::cin, str1);
	std::cout << "Please enter second string: ";
	getline(std::cin, str2);
	strRes = pfnconcatString(str1, str2);
	std::cout << "The concatenated string: " << strRes << "\n\n";

	std::cout << "Press Enter to stop program" << std::endl;
	getline(std::cin, str1);

	//Free the library:
	FreeLibrary(dllHandle);

	return 0;
}

void GiveErrMessageFuncMissing(std::wstring libraryName, char* funcName)
{
	std::wcout << "Unable to locate the function: " << funcName << " in " << libraryName << std::endl;
}