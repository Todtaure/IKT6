// PlugInDLL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "..\Lab2_headers\CAppUtil.h"

int _tmain(int argc, _TCHAR* argv[])
{
	typedef bool(*PFNInit) (CAppUtil);
	PFNInit initPtr;


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

	char* funcName = "Init";
	initPtr = (PFNInit)GetProcAddress(dllHandle, funcName);
	
	
	return 0;
}

