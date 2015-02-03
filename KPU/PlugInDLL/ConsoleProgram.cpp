// PlugInDLL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "..\Lab2_headers\CAppUtil.h"
#include "..\Lab2_headers\CDLLclass.h"

int _tmain(int argc, _TCHAR* argv[])
{
	typedef CDLLclass(*PFNCreate) (void);
	PFNCreate createPtr;

	typedef void(*PFNDelete) (CDLLclass);
	PFNDelete deletePtr;


	std::wstring libraryName;
	
	std::wcout << TEXT("Please enter the name of the plug-in you want to load: ");
	getline(std::wcin, libraryName);

	HINSTANCE dllHandle = NULL;
	dllHandle = LoadLibrary(libraryName.c_str());

	if (dllHandle == NULL)
	{
		std::wcout << "Unable to load library: " << libraryName << std::endl;
		return 1;
	}

	char* funcName = "CreateDllObject";
	createPtr = (PFNCreate)GetProcAddress(dllHandle, funcName);

	funcName = "DeleteDllObject";
	deletePtr = (PFNDelete)GetProcAddress(dllHandle, funcName);	

	if (createPtr == NULL || deletePtr == NULL)
	{
		return 1;
	}
	
	return 0;
}

