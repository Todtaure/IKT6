// SimpelCalcClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "COMerrorUtility.h"						// Help filen for COM errors
#include "..\KPUCalcServer\KPUCalcServer_i.h"  		// Define the interface
#include "..\KPUCalcServer\KPUCalcServer_i.c"		// Define the GUIDs

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
// Declare HRESULT and a pointer to the ATLCalculator interface
	HRESULT		hr;
	ICalculator	*pICalculator;
	long		ReturnValue;

	// Intilize COM
	hr = CoInitialize(0);

	// Use the SUCCEEDED macro and see if we can get a pointer 
	// to the interface
	if(SUCCEEDED(hr))
	{
		hr = CoCreateInstance( CLSID_Calculator, NULL, CLSCTX_INPROC_SERVER,
			IID_ICalculator, (void**) &pICalculator);
//		LIBID_KPUCalcServerLib, (void**) &pICalculator);  // To provoke an error uncomment this line 

		// If succeeded then call the Add method, if it fails
		// then display an appropriate message to the user.
		if (SUCCEEDED(hr))
		{
			hr = pICalculator->Add(2, 3, &ReturnValue);
			cout << "The answer for 2 + 3 is: " << ReturnValue << endl;
		}
		else
		{
			ShowErrorMessage(hr);
		}

		// If succeeded then call the Add method again, this time with an offset on, if it fails
		// then display an appropriate message to the user.
		if (SUCCEEDED(hr))
		{
			hr = pICalculator->put_Offset(4);
			hr = pICalculator->Add(2, 3, &ReturnValue);
			cout << "The answer for 2 + 3 with offset 4 is: " << ReturnValue << endl;
		}
		else
		{
			ShowErrorMessage(hr);
		}

		// If succeeded then call the Sub method, if it fails
		// then display an appropriate message to the user.
		if (SUCCEEDED(hr))
		{
			hr = pICalculator->put_Offset(0);
			hr = pICalculator->Sub(3, 2, &ReturnValue);
			cout << "The answer for 3 - 2 is: " << ReturnValue << endl;
		}
		else
		{
			ShowErrorMessage(hr);
		}

		// If succeeded then call the Sub method again, this time with an offset on, if it fails
		// then display an appropriate message to the user.
		if (SUCCEEDED(hr))
		{
			hr = pICalculator->put_Offset(7);
			hr = pICalculator->Sub(3, 2, &ReturnValue);
			cout << "The answer for 3 - 2 with offset 7 is: " << ReturnValue << endl;
			string dummy;
			getline(cin, dummy);
		}
		else
		{
			ShowErrorMessage(hr);
		}

		// Release the interface
		if (pICalculator != NULL)
			hr = pICalculator->Release();  
	}
	else
	{
		ShowErrorMessage(hr);
	}
	// Uninitialize COM
	CoUninitialize();

	return 0;}

