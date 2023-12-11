#pragma once
#include "resource.h"       // recursos principais
#include <atlbase.h>
#include <atlcom.h>
#include "AtlComServer_i.h"

using namespace ATL;

class CCalculator :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CCalculator, &CLSID_Calculator>,
    public IDispatchImpl<ICalculator, &IID_ICalculator, &LIBID_AtlComServerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
    CCalculator() = default;

DECLARE_REGISTRY_RESOURCEID(IDR_CALCULATOR)

DECLARE_NOT_AGGREGATABLE(CCalculator)

BEGIN_COM_MAP(CCalculator)
    COM_INTERFACE_ENTRY(ICalculator)
    COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

DECLARE_PROTECT_FINAL_CONSTRUCT()

public:
    // ICalculator
    STDMETHOD(ApproximatePi)(DOUBLE* result);
};

OBJECT_ENTRY_AUTO(__uuidof(Calculator), CCalculator)


