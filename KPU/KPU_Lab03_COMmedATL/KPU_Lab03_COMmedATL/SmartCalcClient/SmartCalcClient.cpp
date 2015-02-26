// SmartCalcClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#import "..\\Debug\\KPUCalcServer.dll" no_namespace named_guids

using namespace std;

void CallCalcServer()
{
	ICalculatorPtr calcPtr(__uuidof(Calculator));

	int result = calcPtr->Add(1, 2);
	cout << "The answer for 1 + 2 is: " << result << endl;
	result = calcPtr->Sub(4, 2);
	cout << "The answer for 4 - 2 is: " << result << endl;

	IAdvCalPtr advCalcPtr(__uuidof(Calculator));
	result = advCalcPtr->Mul(3, 3);
	cout << "The answer for 3 x 3 is: " << result << endl;

}   // Com server is automaticaly relaesed here 


int _tmain(int argc, _TCHAR* argv[])
{
	// Bootstrap COM.
	CoInitialize(NULL);

	CallCalcServer();
	string dummy;
	getline(cin, dummy);

	// Clean up COM
	CoUninitialize();
	
	return 0;;
}

