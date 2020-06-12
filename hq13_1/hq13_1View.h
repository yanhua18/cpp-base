// hq13_1View.h : interface of the CHq13_1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HQ13_1VIEW_H__812B4C90_AC01_4BED_B4C8_BDD9E61EE95F__INCLUDED_)
#define AFX_HQ13_1VIEW_H__812B4C90_AC01_4BED_B4C8_BDD9E61EE95F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CHq13_1Set;

class CHq13_1View : public CRecordView
{
protected: // create from serialization only
	CHq13_1View();
	DECLARE_DYNCREATE(CHq13_1View)

public:
	//{{AFX_DATA(CHq13_1View)
	enum { IDD = IDD_HQ13_1_FORM };
	CHq13_1Set* m_pSet;
	//}}AFX_DATA

// Attributes
public:
	CHq13_1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHq13_1View)
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
	virtual ~CHq13_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHq13_1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in hq13_1View.cpp
inline CHq13_1Doc* CHq13_1View::GetDocument()
   { return (CHq13_1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HQ13_1VIEW_H__812B4C90_AC01_4BED_B4C8_BDD9E61EE95F__INCLUDED_)
