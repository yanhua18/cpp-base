// hq_6_12Set.h : interface of the CHq_6_12Set class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HQ_6_12SET_H__F7B09CDE_1DEE_4B04_A592_5CB2D6D1DEB5__INCLUDED_)
#define AFX_HQ_6_12SET_H__F7B09CDE_1DEE_4B04_A592_5CB2D6D1DEB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CHq_6_12Set : public CRecordset
{
public:
	CHq_6_12Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CHq_6_12Set)

// Field/Param Data
	//{{AFX_FIELD(CHq_6_12Set, CRecordset)
	CString	m_BookID;
	CString	m_BookName;
	int	m_Price;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHq_6_12Set)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HQ_6_12SET_H__F7B09CDE_1DEE_4B04_A592_5CB2D6D1DEB5__INCLUDED_)

