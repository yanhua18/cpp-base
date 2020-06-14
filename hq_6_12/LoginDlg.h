#if !defined(AFX_LOGINDLG_H__84F27C18_7329_4D49_AA03_224F6DAE81F2__INCLUDED_)
#define AFX_LOGINDLG_H__84F27C18_7329_4D49_AA03_224F6DAE81F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog

class CLoginDlg : public CDialog
{
// Construction
public:
	CLoginDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLoginDlg)
	enum { IDD = IDD_DIALOG2 };
	CEdit	m_ctrPass;
	CString	m_loginname;
	CString	m_loginpassword;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoginDlg)
	afx_msg void OnLogin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDLG_H__84F27C18_7329_4D49_AA03_224F6DAE81F2__INCLUDED_)
