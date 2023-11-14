

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 00:14:07 2038
 */
/* Compiler settings for ATLProject.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0628 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ATLProject_i_h__
#define __ATLProject_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __ICalculator_FWD_DEFINED__
#define __ICalculator_FWD_DEFINED__
typedef interface ICalculator ICalculator;

#endif 	/* __ICalculator_FWD_DEFINED__ */


#ifndef __Calculator_FWD_DEFINED__
#define __Calculator_FWD_DEFINED__

#ifdef __cplusplus
typedef class Calculator Calculator;
#else
typedef struct Calculator Calculator;
#endif /* __cplusplus */

#endif 	/* __Calculator_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ICalculator_INTERFACE_DEFINED__
#define __ICalculator_INTERFACE_DEFINED__

/* interface ICalculator */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICalculator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("599a38f6-0608-421c-80a3-d9915dd1f3c4")
    ICalculator : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ApproximatePi( 
            /* [retval][out] */ double *result) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICalculatorVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICalculator * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICalculator * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICalculator * This);
        
        DECLSPEC_XFGVIRT(ICalculator, ApproximatePi)
        HRESULT ( STDMETHODCALLTYPE *ApproximatePi )( 
            ICalculator * This,
            /* [retval][out] */ double *result);
        
        END_INTERFACE
    } ICalculatorVtbl;

    interface ICalculator
    {
        CONST_VTBL struct ICalculatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICalculator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICalculator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICalculator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICalculator_ApproximatePi(This,result)	\
    ( (This)->lpVtbl -> ApproximatePi(This,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICalculator_INTERFACE_DEFINED__ */



#ifndef __ATLProjectLib_LIBRARY_DEFINED__
#define __ATLProjectLib_LIBRARY_DEFINED__

/* library ATLProjectLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ATLProjectLib;

EXTERN_C const CLSID CLSID_Calculator;

#ifdef __cplusplus

class DECLSPEC_UUID("c69f1f08-37db-42d0-9d54-fbb1c036c78f")
Calculator;
#endif
#endif /* __ATLProjectLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


