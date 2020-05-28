// hq4Dlg.h : header file
//

#if !defined(AFX_HQ4DLG_H__AE15B913_823A_48DA_908D_AD146874D590__INCLUDED_)
#define AFX_HQ4DLG_H__AE15B913_823A_48DA_908D_AD146874D590__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHq4Dlg dialog

class CHq4Dlg : public CDialog
{
// Construction
public:
	CHq4Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHq4Dlg)
	enum { IDD = IDD_HQ4_DIALOG };
	int		m_NumEdit;
	BOOL	m_usible;
	BOOL	m_visible;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHq4Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHq4Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPlus();
	afx_msg void OnMinus();
	virtual void OnOK();
	afx_msg void OnUsible();
	afx_msg void OnVisible();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HQ4DLG_H__AE15B913_823A_48DA_908D_AD146874D590__INCLUDED_)
