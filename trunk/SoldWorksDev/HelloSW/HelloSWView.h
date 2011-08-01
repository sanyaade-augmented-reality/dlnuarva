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

// HelloSWView.h : CHelloSWView ��Ľӿ�
//

#pragma once

#include "CSldWorks.h"

class CHelloSWView : public CView
{
protected: // �������л�����
	CHelloSWView();
	DECLARE_DYNCREATE(CHelloSWView)

// ����
public:
	CHelloSWDoc* GetDocument() const;

// ����
public:

//����
private:
	int TraverseChildren(long RecurseLevel, CString* MyString, IComponent2* pComponent, ISldWorks* m_pSldWorks) ;
	void GetModelAssembly(ISldWorks* m_pSldWorks);
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CHelloSWView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnButtonStrartsw();
	afx_msg void OnButtonOpenASM();
	DECLARE_MESSAGE_MAP()
public:
	//Use ATL smart pointers 
	CComPtr<ISldWorks> swApp; 
	CComPtr<IModelDoc2> swModel;
	CComPtr<IModelDocExtension> swDocExt;
	CComPtr<IAssemblyDoc> swAssy;
	CComPtr<IComponent2> swComponent;
	CComPtr<IFeature> mateFeature;
	CComPtr<IModelDoc2> tmpObj;
	CComPtr<IMate2> swMate;
};

#ifndef _DEBUG  // HelloSWView.cpp �еĵ��԰汾
inline CHelloSWDoc* CHelloSWView::GetDocument() const
   { return reinterpret_cast<CHelloSWDoc*>(m_pDocument); }
#endif
