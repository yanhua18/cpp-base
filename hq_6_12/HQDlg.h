#if !defined(AFX_HQDLG_H__0B16970F_A92C_484B_9857_E7A57E9894C3__INCLUDED_)
#define AFX_HQDLG_H__0B16970F_A92C_484B_9857_E7A57E9894C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HQDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHQDlg dialog

class CHQDlg : public CDialog
{
// Construction
public:
	CHQDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHQDlg)
	enum { IDD = IDD_DIALOG1 };
	CString	m_bookid1;
	CString	m_bookname1;
	int		m_bookprice1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHQDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHQDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HQDLG_H__0B16970F_A92C_484B_9857_E7A57E9894C3__INCLUDED_)
