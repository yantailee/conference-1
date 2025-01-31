// ZqpsrcReader.h : CZqpsrcReader 的声明

#pragma once
#include "resource.h"       // 主符号

#include "zkmcu_mod_i.h"

#include "PackageForAudio.h"
#include "PackageForVideo.h"
#include <zonekey/zqpsource.h>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CZqpsrcReader

class ATL_NO_VTABLE CZqpsrcReader :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CZqpsrcReader, &CLSID_ZqpsrcReader>,
	public IDispatchImpl<IZqpsrcReader, &IID_IZqpsrcReader, &LIBID_zkmcu_modLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
	void *src_;

public:
	CZqpsrcReader()
	{
		src_ = 0;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ZQPSRCREADER)


BEGIN_COM_MAP(CZqpsrcReader)
	COM_INTERFACE_ENTRY(IZqpsrcReader)
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

	STDMETHOD(Open)(BSTR url);
	STDMETHOD(Close)(void);
	STDMETHOD(GetNextPacket)(IDispatch** package);
};

OBJECT_ENTRY_AUTO(__uuidof(ZqpsrcReader), CZqpsrcReader)
