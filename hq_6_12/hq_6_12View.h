// hq_6_12View.h : interface of the CHq_6_12View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HQ_6_12VIEW_H__8B6E54EF_4969_49CA_95B5_1DD583476992__INCLUDED_)
#define AFX_HQ_6_12VIEW_H__8B6E54EF_4969_49CA_95B5_1DD583476992__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"Hq_6_12Set.h"
class CHq_6_12Set;

class CHq_6_12View : public CRecordView
{
protected: // create from serialization only
	CHq_6_12View();
	DECLARE_DYNCREATE(CHq_6_12View)

public:
	//{{AFX_DATA(CHq_6_12View)
	enum { IDD = IDD_HQ_6_12_FORM };
	CComboBox	m_find;
	CHq_6_12Set* m_pSet;
	CString	m_condition;
	//}}AFX_DATA

	CHq_6_12Set record;
// Attributes
public:
	CHq_6_12Doc* GetDocument();

// Operations
public:
	char MING[10];
	char ID[10];
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHq_6_12View)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHq_6_12View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHq_6_12View)
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnEdit();
	afx_msg void OnSearch();
	afx_msg void OnSortId();
	afx_msg void OnSortPrice();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in hq_6_12View.cpp
inline CHq_6_12Doc* CHq_6_12View::GetDocument()
   { return (CHq_6_12Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HQ_6_12VIEW_H__8B6E54EF_4969_49CA_95B5_1DD583476992__INCLUDED_)
