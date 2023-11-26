// dllmain.h : Declaração da classe módulo.

class CAtlComServerModule : public ATL::CAtlDllModuleT< CAtlComServerModule >
{
public :
	DECLARE_LIBID(LIBID_AtlComServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLCOMSERVER, "{d698ac75-3b16-4b5f-8783-547e77b9eb0f}")
};

extern class CAtlComServerModule _AtlModule;
