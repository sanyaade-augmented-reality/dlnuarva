// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://msdn.microsoft.com/officeui。
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// HelloSWView.cpp : CHelloSWView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "HelloSW.h"
#endif

#include "HelloSWDoc.h"
#include "HelloSWView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHelloSWView

IMPLEMENT_DYNCREATE(CHelloSWView, CView)

BEGIN_MESSAGE_MAP(CHelloSWView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHelloSWView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_BUTTON_OPENASM, &CHelloSWView::OnButtonOpenASM)
	ON_COMMAND(ID_BUTTON_StrartSW, &CHelloSWView::OnButtonStrartsw)
END_MESSAGE_MAP()

// CHelloSWView 构造/析构

CHelloSWView::CHelloSWView()
{
	// TODO: 在此处添加构造代码

}

CHelloSWView::~CHelloSWView()
{
}

BOOL CHelloSWView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CHelloSWView 绘制

void CHelloSWView::OnDraw(CDC* pDC)
{
	CHelloSWDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->TextOutW(50, 50, _T("Hello SolidWorks"));
}


// CHelloSWView 打印


void CHelloSWView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CHelloSWView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CHelloSWView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CHelloSWView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CHelloSWView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CHelloSWView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CHelloSWView 诊断

#ifdef _DEBUG
void CHelloSWView::AssertValid() const
{
	CView::AssertValid();
}

void CHelloSWView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHelloSWDoc* CHelloSWView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHelloSWDoc)));
	return (CHelloSWDoc*)m_pDocument;
}
#endif //_DEBUG


// CHelloSWView 消息处理程序

//To open the assembly file.
void CHelloSWView::OnButtonOpenASM()
{
	//Check
	if (!swApp) {
		MessageBox(_T("请先启动SolidWorks"), _T("错误"));
		return;
	}

	CString fileStr;
	long lErrors;
	long lWarnings;
	long lMateError;

	//Trace
	((CMainFrame*)GetParent())->SetMessageText(_T("正在打开装配体文件。"));

	CFileDialog fileDlg(TRUE);
	//To set file filter.
	fileDlg.m_ofn.lpstrFilter = LPCTSTR(_T("SolidWorks Assembly File(*.SLDASM)\0*.SLDASM"));
	fileDlg.m_ofn.lpstrTitle = _T("打开装配体文件");
	if (fileDlg.DoModal() == IDOK) {
		fileStr = fileDlg.GetPathName();
		//Trace
		((CMainFrame*)GetParent())->SetMessageText(fileStr);
	} else {
		return;
	}

	//Open the assembly document
	CComBSTR sAssemblyName(fileStr);
	CComBSTR sDefaultConfiguration(_T("Default"));
	swModel = swApp->OpenDoc6(
		BSTR(sAssemblyName), 
		2, //swDocASSEMBLY,
		0,//swOpenDocOptions_Silent, 
		BSTR(sDefaultConfiguration), 
		&lErrors, 
		&lWarnings
	);
}

// To Start SolidWorks
void CHelloSWView::OnButtonStrartsw()
{ 
	//Trace
	((CMainFrame*)GetParent())->SetMessageText(_T("正在打开SolidWorks"));

	//Initialize COM
	HRESULT hres = CoInitialize(NULL);
	//Create an instance of SolidWorks
	hres = swApp.CoCreateInstance(__uuidof(SldWorks), NULL, CLSCTX_LOCAL_SERVER);

	if (SUCCEEDED(hres)) {
		((CMainFrame*)GetParent())->SetMessageText(_T("打开SolidWorks成功！"));
		VARIANT_BOOL visibility;
		swApp->get_Visible(&visibility);
		swApp->put_Visible(TRUE);
	} else {
		((CMainFrame*)GetParent())->SetMessageText(_T("打开SolidWorks失败！"));
		//Uninitialize COM
		CoUninitialize();
	}
}
