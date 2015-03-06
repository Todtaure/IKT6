#pragma once
//////////////////////////////////////////////////////////////////////////////
// Function......: ShowErrorMessage
// Responsibility: Display detailed status information on std console output
// Returns.......: void
// Parameters....:
//		HRESULT hr	: IN - COM status code
//
// Remarks.......: must include <comdef.h> for _com_error
//////////////////////////////////////////////////////////////////////////////

void ShowErrorMessage(HRESULT hr);

