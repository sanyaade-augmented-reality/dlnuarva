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

// HelloSWView.h : CHelloSWView 类的接口
//

#pragma once

#include "CSldWorks.h"

class CHelloSWView : public CView
{
protected: // 仅从序列化创建
	CHelloSWView();
	DECLARE_DYNCREATE(CHelloSWView)

// 特性
public:
	CHelloSWDoc* GetDocument() const;

// 操作
public:

//方法
private:
	int TraverseChildren(long RecurseLevel, CString* MyString, IComponent2* pComponent, ISldWorks* m_pSldWorks) ;
	void GetModelAssembly(ISldWorks* m_pSldWorks);
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CHelloSWView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // HelloSWView.cpp 中的调试版本
inline CHelloSWDoc* CHelloSWView::GetDocument() const
   { return reinterpret_cast<CHelloSWDoc*>(m_pDocument); }
#endif
