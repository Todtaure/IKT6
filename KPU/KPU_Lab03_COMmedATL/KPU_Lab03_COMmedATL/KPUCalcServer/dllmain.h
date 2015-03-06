// dllmain.h : Declaration of module class.

class CKPUCalcServerModule : public ATL::CAtlDllModuleT< CKPUCalcServerModule >
{
public :
	DECLARE_LIBID(LIBID_KPUCalcServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_KPUCALCSERVER, "{13A101E1-B9BE-4574-A1AF-654665791E9B}")
};

extern class CKPUCalcServerModule _AtlModule;
