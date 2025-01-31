// PackageForVideo.h : CPackageForVideo 的声明

#pragma once
#include "resource.h"       // 主符号

#include "zkmcu_mod_i.h"
#include <zonekey/zqpsource.h>
#include "Zqpkt.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CPackageForVideo

class ATL_NO_VTABLE CPackageForVideo :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPackageForVideo, &CLSID_PackageForVideo>,
	public IDispatchImpl<IPackageForVideo, &IID_IPackageForVideo, &LIBID_zkmcu_modLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public Zqpkt
{
public:
	CPackageForVideo()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PACKAGEFORVIDEO)


BEGIN_COM_MAP(CPackageForVideo)
	COM_INTERFACE_ENTRY(IPackageForVideo)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(get_Data)(VARIANT* pVal);
	STDMETHOD(get_Stamp)(DOUBLE* pVal);
	STDMETHOD(get_Key)(VARIANT_BOOL* pVal);
	STDMETHOD(DataType)(LONG* t);
};

OBJECT_ENTRY_AUTO(__uuidof(PackageForVideo), CPackageForVideo)
