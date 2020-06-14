// hq_6_12Doc.h : interface of the CHq_6_12Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HQ_6_12DOC_H__8A235FEC_9CA0_415B_AA25_0E8F0C473D1D__INCLUDED_)
#define AFX_HQ_6_12DOC_H__8A235FEC_9CA0_415B_AA25_0E8F0C473D1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "hq_6_12Set.h"

class CHq_6_12Doc : public CDocument
{
protected: // create from serialization only
	CHq_6_12Doc();
	DECLARE_DYNCREATE(CHq_6_12Doc)

// Attributes
public:
	CHq_6_12Set m_hq_6_12Set;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHq_6_12Doc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHq_6_12Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHq_6_12Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HQ_6_12DOC_H__8A235FEC_9CA0_415B_AA25_0E8F0C473D1D__INCLUDED_)
