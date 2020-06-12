// hq13_1Set.h : interface of the CHq13_1Set class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HQ13_1SET_H__5F6D4A90_55D3_4034_BB81_B7E5F70F9F82__INCLUDED_)
#define AFX_HQ13_1SET_H__5F6D4A90_55D3_4034_BB81_B7E5F70F9F82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CHq13_1Set : public CRecordset
{
public:
	CHq13_1Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CHq13_1Set)

// Field/Param Data
	//{{AFX_FIELD(CHq13_1Set, CRecordset)
	CString	m_StudentID;
	CString	m_Name;
	int	m_age;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHq13_1Set)
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

#endif // !defined(AFX_HQ13_1SET_H__5F6D4A90_55D3_4034_BB81_B7E5F70F9F82__INCLUDED_)

