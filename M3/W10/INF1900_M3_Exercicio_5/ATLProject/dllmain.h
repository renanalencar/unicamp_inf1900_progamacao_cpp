// dllmain.h : Declaration of module class.

class CATLProjectModule : public ATL::CAtlDllModuleT< CATLProjectModule >
{
public :
	DECLARE_LIBID(LIBID_ATLProjectLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLPROJECT, "{d384e5fd-0515-409e-959b-b0fe3c747d0d}")
};

extern class CATLProjectModule _AtlModule;
