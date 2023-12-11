// Calculator.h : Declaration of the CCalculator

#pragma once
#include "resource.h"       // main symbols 
#include "ATLProject_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CCalculator

class ATL_NO_VTABLE CCalculator :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCalculator, &CLSID_Calculator>,
	public IDispatchImpl<ICalculator, &IID_ICalculator, &LIBID_ATLProjectLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
    DECLARE_REGISTRY_RESOURCEID(IDR_CALCULATOR)

    DECLARE_CLASSFACTORY()
    DECLARE_NOT_AGGREGATABLE(CCalculator)

    BEGIN_COM_MAP(CCalculator)
        COM_INTERFACE_ENTRY(ICalculator)
    END_COM_MAP()

    // ICalculator methods
    STDMETHOD(ApproximatePi)(double* result);
    
}; 
OBJECT_ENTRY_AUTO(__uuidof(Calculator), CCalculator)