// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����

// HelloSWView.cpp : CHelloSWView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHelloSWView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_BUTTON_OPENASM, &CHelloSWView::OnButtonOpenASM)
	ON_COMMAND(ID_BUTTON_StrartSW, &CHelloSWView::OnButtonStrartsw)
END_MESSAGE_MAP()

// CHelloSWView ����/����

CHelloSWView::CHelloSWView()
{
	// TODO: �ڴ˴���ӹ������

}

CHelloSWView::~CHelloSWView()
{
}

BOOL CHelloSWView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CHelloSWView ����

void CHelloSWView::OnDraw(CDC* pDC)
{
	CHelloSWDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->TextOutW(50, 50, L"Hello SolidWorks");
}


// CHelloSWView ��ӡ


void CHelloSWView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CHelloSWView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CHelloSWView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CHelloSWView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CHelloSWView ���

#ifdef _DEBUG
void CHelloSWView::AssertValid() const
{
	CView::AssertValid();
}

void CHelloSWView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHelloSWDoc* CHelloSWView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHelloSWDoc)));
	return (CHelloSWDoc*)m_pDocument;
}
#endif //_DEBUG


// CHelloSWView ��Ϣ�������

//To open the assembly file.
void CHelloSWView::OnButtonOpenASM()
{
	//Check
	if (!swApp) {
		MessageBox(L"��������SolidWorks", L"����");
		return;
	}

	CString fileStr;
	long lErrors;
	long lWarnings;
	//long lMateError;
	HRESULT hres;

	//Trace
	((CMainFrame*)GetParent())->SetMessageText(L"���ڴ�װ�����ļ���");

	CFileDialog fileDlg(TRUE);
	//To set file filter.
	fileDlg.m_ofn.lpstrFilter = LPCTSTR(L"SolidWorks Assembly File(*.SLDASM)\0*.SLDASM");
	fileDlg.m_ofn.lpstrTitle = L"��װ�����ļ�";
	if (fileDlg.DoModal() == IDOK) {
		fileStr = fileDlg.GetPathName();
		//Trace
		((CMainFrame*)GetParent())->SetMessageText(fileStr);
	} else {
		return;
	}

	//Open the assembly document
	CComBSTR sAssemblyName(fileStr);
	CComBSTR sDefaultConfiguration(L"Default");
	hres = swApp->OpenDoc6(
		BSTR(sAssemblyName), 
		swDocASSEMBLY,
		swOpenDocOptions_Silent, 
		BSTR(sDefaultConfiguration), 
		&lErrors, 
		&lWarnings,
		&swModel
	);

	if (hres == S_OK) {
		//Trace
		((CMainFrame*)GetParent())->SetMessageText(L"�ɹ���װ�����ļ�" + fileStr);
	} else {
		//Trace
		((CMainFrame*)GetParent())->SetMessageText(L"��װ�����ļ�" + fileStr + "ʧ�ܣ�");
		MessageBox(L"��װ�����ļ�" + fileStr + "ʧ�ܣ�");
	}
	
	//Trace
	((CMainFrame*)GetParent())->SetMessageText(L"���ڱ���װ�����ļ�" + fileStr);
	GetModelAssembly(swApp);
}

// To Start SolidWorks
void CHelloSWView::OnButtonStrartsw()
{ 
	//Trace
	((CMainFrame*)GetParent())->SetMessageText(L"���ڴ�SolidWorks");

	//Initialize COM
	HRESULT hres = CoInitialize(NULL);
	//Create an instance of SolidWorks
	hres = swApp.CoCreateInstance(__uuidof(SldWorks), NULL, CLSCTX_LOCAL_SERVER);

	if (SUCCEEDED(hres)) {
		((CMainFrame*)GetParent())->SetMessageText(L"��SolidWorks�ɹ���");
		VARIANT_BOOL visibility;
		swApp->get_Visible(&visibility);
		swApp->put_Visible(TRUE);
	} else {
		((CMainFrame*)GetParent())->SetMessageText(_T("��SolidWorksʧ�ܣ�"));
		//Uninitialize COM
		CoUninitialize();
	}
}

//////////////////////////////////////////////////////////////////////////
// Function: TraverseChildren
// Arguments: RecurseLevel - Level of recursion
//    MyString - Textural record of assembly
//    pComponent - Component to traverse
// Return: Number of children
// Description: Perform any operations specific to the component, then
//    if the component has children, recursively call
//    this function for each child.
//////////////////////////////////////////////////////////////////////////
int CHelloSWView::TraverseChildren(long RecurseLevel, CString* MyString, IComponent2* pComponent, ISldWorks* m_pSldWorks) {
	IComponent2** pChildren = NULL;
	int   nChildren;
	int   i;
	BSTR  Name;
	HRESULT  hres = S_OK;
	IModelDoc2*  pModelDoc = NULL;

	// Retrieve the component name
	if(RecurseLevel==0) {
		// Special case of top-level components
		hres = m_pSldWorks->get_IActiveDoc2(&pModelDoc);
		if(S_OK == hres || pModelDoc != NULL)
			Name = pModelDoc->GetTitle();
	} else {
		// Get the component name
		Name = pComponent->Name;
	}

	if(S_OK == hres && Name != NULL) {
		CString tempstr;
		for( i=1; i<=RecurseLevel; i++) {
			tempstr += " ";
		}

		CString Tmp(Name);
		tempstr += Tmp;
		tempstr += L"\r\n";
		*MyString = *MyString + tempstr;
	}
	RecurseLevel++;
	nChildren = pComponent->IGetChildrenCount();

	// Check if this component has children
	if (S_OK == hres || nChildren > 0) {
		pChildren = new IComponent2*[nChildren];
		IComponent2* temp =  pComponent->IGetChildren();
		//pChildren = pComponent->IGetChildren();
		//_variant_t children =  pComponent->GetChildren();

		if(S_OK == hres) {
			for (i=0; i<nChildren; i++){
				TraverseChildren(RecurseLevel, MyString, pChildren[i], m_pSldWorks);
				pChildren[i]->Release();
			}
		}
		delete [] pChildren;
	}

	RecurseLevel--;
	return nChildren;
}

void CHelloSWView::GetModelAssembly(ISldWorks* m_pSldWorks) {
	CComPtr<IConfiguration> pConfiguration = NULL;
	CComPtr<IComponent2> pRootComponent = NULL;
	CComPtr<IModelDoc2> pModelDoc = NULL;
	HRESULT hres = S_OK;
	long RecurseLevel = 0;

	hres = m_pSldWorks->get_IActiveDoc2(&pModelDoc );  
 
	// Retrieve model document pointer
	if(S_OK != hres || pModelDoc == NULL)
		return;  

	// Get the active configuration and root component
	if ((pConfiguration = pModelDoc->IGetActiveConfiguration())) {
		if ((pRootComponent = pConfiguration->GetRootComponent3(TRUE))) {
			CString MyString;
			TraverseChildren(RecurseLevel, &MyString, pRootComponent, swApp);
			//pRootComponent->Release();
			// Display the structure in a message box
			MessageBox(MyString);
		}
		//pConfiguration->Release();
	}
}
