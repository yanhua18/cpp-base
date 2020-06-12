// hq13_1Doc.h : interface of the CHq13_1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HQ13_1DOC_H__C1AF21A3_4935_40C4_AB09_C3B4D77E653F__INCLUDED_)
#define AFX_HQ13_1DOC_H__C1AF21A3_4935_40C4_AB09_C3B4D77E653F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "hq13_1Set.h"


class CHq13_1Doc : public CDocument
{
protected: // create from serialization only
	CHq13_1Doc();
	DECLARE_DYNCREATE(CHq13_1Doc)

// Attributes
public:
	CHq13_1Set m_hq13_1Set;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHq13_1Doc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHq13_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHq13_1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HQ13_1DOC_H__C1AF21A3_4935_40C4_AB09_C3B4D77E653F__INCLUDED_)
