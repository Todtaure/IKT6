#include "stdafx.h"
#include "COMerrorUtility.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////
// Function......: ShowErrorMessage
// Responsibility: Display detailed status information on std console output
// Returns.......: void
// Parameters....:
//		HRESULT hr	: IN - COM status code
//
// Remarks.......: must include <comdef.h> for _com_error
//////////////////////////////////////////////////////////////////////////////
void ShowErrorMessage(HRESULT hr)
{
	if (SUCCEEDED(hr))
	{
		cout << "OK" << endl;
	}
	else
	{
		// construct a _com_error using the HRESULT
		_com_error e(hr);
		char temp[32];

		// convert to hexidecimal string and display
		sprintf_s( temp, "0x%x", hr );
		cout << "Error   : " << temp << endl;

		// The hr as a decimal number
		cout << "Decimal : " << hr << endl;

		// show the 1st 16 bits (SCODE)
		cout << "SCODE   : " << HRESULT_CODE( hr ) << endl;
		// Show facility code as a decimal number and as text
		unsigned long facility;
		facility = HRESULT_FACILITY( hr );
		cout << "Facility: " << facility; // << endl;
		switch (facility)
		{
		case 0: 
			cout << " = NULL\n";
			break;
		case 1: 
			cout << " = RPC\n";
			break;
		case 2: 
			cout << " = Dispatch\n";
			break;
		case 3: 
			cout << " = Structured Storage\n";
			break;
		case 4: 
			cout << " = Interface\n";
			break;
		case 7: 
			cout << " = Win32\n";
			break;
		case 8: 
			cout << " = Windows\n";
			break;
		case 9: 
			cout << " = SSPI\n";
			break;
		default:
			;
		}

		// Show the severity bit
		cout << "Severity: " << HRESULT_SEVERITY( hr ) << endl;
		// Use the _com_error object to format a message string. This is 
		// Much easier then using ::FormatMessage
		cout << "Message : " << e.ErrorMessage() << endl;	
	}
}

