#if !defined(AFX_LOGINDLG1_H__4A770CE6_2CB8_4202_83D6_03BE74B624CD__INCLUDED_)
#define AFX_LOGINDLG1_H__4A770CE6_2CB8_4202_83D6_03BE74B624CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDlg1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg1 dialog

class CLoginDlg1 : public CDialog
{
// Construction
public:
	CLoginDlg1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLoginDlg1)
	enum { IDD = IDD_DIALOG2 };
	CEdit	m_ctrPass;
	CString	m_loginname;
	CString	m_loginpassword;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginDlg1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoginDlg1)
	afx_msg void OnLogin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDLG1_H__4A770CE6_2CB8_4202_83D6_03BE74B624CD__INCLUDED_)
