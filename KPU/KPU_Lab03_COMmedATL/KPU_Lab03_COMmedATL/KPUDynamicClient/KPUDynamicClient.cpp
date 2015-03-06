// KPUDynamicClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "COMerrorUtility.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "From Dynamic Client\n";
	DISPID addDispid;
	DISPID offsetDispid;
	DISPID subDispid;
	IDispatch* pDisp = NULL;
	HRESULT hr = S_OK;
	CLSID clsid;
	int res = 0;
	LPOLESTR str;
	DISPPARAMS offsetArgParams;  

	// Build VARIANT for arguments
	VARIANT argVars[2];
	VariantInit(&argVars[0]);
	argVars[0].vt = VT_INT;
	argVars[0].intVal = 0;

	VariantInit(&argVars[1]);
	argVars[1].vt = VT_INT;
	argVars[1].intVal = 0;

	DISPPARAMS argParams = {argVars, 0, 2, 0};

	// Build VARIANT for result
	VARIANT result;
	VariantInit(&result);
	result.vt = VT_INT;
	result.intVal = 0;

	// Initialize COM
	CoInitialize(NULL);  

	// Go look up the CLSID from the ProgID.
	hr = CLSIDFromProgID(OLESTR("AU.ASE.KPU.Calculator"), &clsid);

	if (SUCCEEDED(hr))
	{
		// Create object and get an IDispatch interface
		hr = CoCreateInstance(clsid, NULL, CLSCTX_SERVER, IID_IDispatch, (void**)&pDisp);
	}
	else
	{
		ShowErrorMessage(hr);
	}

	if (SUCCEEDED(hr))
	{
		// Get Add DISPID from object 
		str = OLESTR("Add");
		pDisp->GetIDsOfNames(IID_NULL, &str, 1, LOCALE_SYSTEM_DEFAULT, &addDispid);
	}
	else
	{
		ShowErrorMessage(hr);  // CoCreateInstance failed
		if (pDisp == NULL)
			cout << "Unable to create COM object!";
	}

	// Use the COM-server - same test as in lab 6.2
	// ---------------------------------------------------------------------------
	if (SUCCEEDED(hr))
	{
		// Dynamic version of: hr = pICalculator->Add(2, 3, &ReturnValue);
		// setup argVars with the values
		argVars[0].intVal = 2;
		argVars[1].intVal = 3;

		// Call add() using Invoke().
		hr = pDisp->Invoke(addDispid, IID_NULL, LOCALE_SYSTEM_DEFAULT,    
			DISPATCH_METHOD, &argParams, &result, NULL, NULL);

		res = result.intVal;
		cout << "The answer for 2 + 3 is: " << res << endl;

		// Prepare for offset
		// Get DISPID from object 
		str = OLESTR("Offset");
		hr = pDisp->GetIDsOfNames(IID_NULL, &str, 1, LOCALE_SYSTEM_DEFAULT, &offsetDispid);
	}
	else
	{
		ShowErrorMessage(hr);  // Invoke add failed
	}
	// If succeeded then call the Add method again, this time with an offset on, if it fails
	// then display an appropriate message to the user.
	if (SUCCEEDED(hr))
	{
		// Dynamic version of: hr = pICalculator->put_Offset(4);
		// When you use IDispatch::Invoke() with DISPATCH_PROPERTYPUT or DISPATCH_PROPERTYPUTREF, 
		// you have to specially initialize the cNamedArgs and rgdispidNamedArgs elements of your 
		// DISPPARAMS structure with the following: 
		DISPID dispidNamed = DISPID_PROPERTYPUT;
		offsetArgParams.cNamedArgs = 1;
		offsetArgParams.rgdispidNamedArgs = &dispidNamed;
		offsetArgParams.cArgs = 1;	// Only 1 arg this time
		offsetArgParams.rgvarg = argVars;

		// setup argVars with the values
		argVars[0].intVal = 4;

		// Call put_Offset() using Invoke().
		hr = pDisp->Invoke(offsetDispid, IID_NULL, LOCALE_SYSTEM_DEFAULT,    
			DISPATCH_PROPERTYPUT, &offsetArgParams, NULL, NULL, NULL);
		if (SUCCEEDED(hr))
		{
			// setup argVars with the values
			argVars[0].intVal = 2;
			argVars[1].intVal = 3;
			// Call add() using Invoke().
			hr = pDisp->Invoke(addDispid, IID_NULL, LOCALE_SYSTEM_DEFAULT,    
				DISPATCH_METHOD, &argParams, &result, NULL, NULL);
			res = result.intVal;
			cout << "The answer for 2 + 3 with offset 4 is: " << res << endl;

			// Prepare for sub
			// Get DISPID from object 
			str = OLESTR("sub");
			hr = pDisp->GetIDsOfNames(IID_NULL, &str, 1, LOCALE_SYSTEM_DEFAULT, &subDispid);
		}
		else
		{
			ShowErrorMessage(hr);  // Invoke - offset failed
		}
	}
	else
	{
		ShowErrorMessage(hr);  // Get Invoke dispID failed
	}

	// If succeeded then call the Sub method, if it fails
	// then display an appropriate message to the user.
	if (SUCCEEDED(hr))
	{
		// Set offset to 0
		argVars[0].intVal = 0;
		hr = pDisp->Invoke(offsetDispid, IID_NULL, LOCALE_SYSTEM_DEFAULT,    
			DISPATCH_PROPERTYPUT, &offsetArgParams, NULL, NULL, NULL);

		// Dynamic version of: hr = pICalculator->Sub(3, 2, &ReturnValue);
		// setup argVars with the values
		argVars[0].intVal = 2;
		argVars[1].intVal = 3;
		// Call sub() using Invoke().
		hr = pDisp->Invoke(subDispid, IID_NULL, LOCALE_SYSTEM_DEFAULT,    
			DISPATCH_METHOD, &argParams, &result, NULL, NULL);
		res = result.intVal;
		cout << "The answer for 3 - 2 is: " << res << endl;
	}
	else
	{
		ShowErrorMessage(hr);
	}

	// If succeeded then call the Sub method again, this time with an offset on, if it fails
	// then display an appropriate message to the user.
	if (SUCCEEDED(hr))
	{
		// Set offset to 7 ~ hr = pICalculator->put_Offset(7);
		argVars[0].intVal = 7;
		hr = pDisp->Invoke(offsetDispid, IID_NULL, LOCALE_SYSTEM_DEFAULT,    
			DISPATCH_PROPERTYPUT, &offsetArgParams, NULL, NULL, NULL);

		// Dynamic version of: hr = pICalculator->Sub(3, 2, &ReturnValue);
		// setup argVars with the values
		argVars[0].intVal = 2;
		argVars[1].intVal = 3;
		hr = pDisp->Invoke(subDispid, IID_NULL, LOCALE_SYSTEM_DEFAULT,    
			DISPATCH_METHOD, &argParams, &result, NULL, NULL);
		res = result.intVal;
		cout << "The answer for 3 - 2 with offset 7 is: " << res << endl;
	}
	else
	{
		ShowErrorMessage(hr);
	}

	// Clean up.
	if (pDisp!=NULL)
		pDisp->Release();
	CoUninitialize();

	// Wait for user
	string dummy;
	getline(cin, dummy);

	return 0;
}
