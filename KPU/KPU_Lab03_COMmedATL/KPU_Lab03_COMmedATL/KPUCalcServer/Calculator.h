// Calculator.h : Declaration of the CCalculator

#pragma once
#include "resource.h"       // main symbols



#include "KPUCalcServer_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CCalculator

class ATL_NO_VTABLE CCalculator :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCalculator, &CLSID_Calculator>,
	public IDispatchImpl<ICalculator, &IID_ICalculator, &LIBID_KPUCalcServerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IDispatchImpl<IAdvCal, &__uuidof(IAdvCal), &LIBID_KPUCalcServerLib, /* wMajor = */ 1, /* wMinor = */ 0>
{

public:
	CCalculator()
	{
		offset = 0;
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_CALCULATOR)


	BEGIN_COM_MAP(CCalculator)
		COM_INTERFACE_ENTRY(ICalculator)
		COM_INTERFACE_ENTRY2(IDispatch, IAdvCal)
		COM_INTERFACE_ENTRY(IAdvCal)
	END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

private:
	LONG offset;

public:



	STDMETHOD(Add)(LONG arg1, LONG arg2, LONG* result);
	STDMETHOD(Sub)(LONG arg1, LONG arg2, LONG* result);
	STDMETHOD(get_Offset)(LONG* pVal);
	STDMETHOD(put_Offset)(LONG newVal);

	// IAdvCal Methods
public:
	STDMETHOD(Mul)(LONG arg1, LONG arg2, LONG * result);
	STDMETHOD(Div)(LONG arg1, LONG arg2, LONG * result);
};

OBJECT_ENTRY_AUTO(__uuidof(Calculator), CCalculator)
