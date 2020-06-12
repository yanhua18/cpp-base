#if !defined(AFX_USERRS_H__33F9A20E_8008_40F9_8E2B_703AC4A36B31__INCLUDED_)
#define AFX_USERRS_H__33F9A20E_8008_40F9_8E2B_703AC4A36B31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserRS recordset

class CUserRS : public CRecordset
{
public:
	CUserRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CUserRS)

// Field/Param Data
	//{{AFX_FIELD(CUserRS, CRecordset)
	CString	m_UserName;
	CString	m_Password;
	CString	m_authority;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserRS)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERRS_H__33F9A20E_8008_40F9_8E2B_703AC4A36B31__INCLUDED_)
