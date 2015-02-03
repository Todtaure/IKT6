// dllmain.h : Declaration of module class.

class CATLMathServerModule : public ATL::CAtlDllModuleT< CATLMathServerModule >
{
public :
	DECLARE_LIBID(LIBID_ATLMathServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLMATHSERVER, "{D9E2772A-34AA-4F90-9DB5-E981D0BF5999}")
};

extern class CATLMathServerModule _AtlModule;
