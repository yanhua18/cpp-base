// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__4926BCAE_FAD5_4CCA_A146_0FA4CDD0FBEA__INCLUDED_)
#define AFX_MAINFRM_H__4926BCAE_FAD5_4CCA_A146_0FA4CDD0FBEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
    CString m_name;
	CString m_password;
	CString m_which; //��¼��Ȩ��
	BOOL m_log; //��¼״̬


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLoginIn();
	afx_msg void OnLoginOut();
	afx_msg void OnUpdateRecordAdd(CCmdUI* pCmdUI);
	afx_msg void OnRecordAdd();
	afx_msg void OnRecoedSearch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__4926BCAE_FAD5_4CCA_A146_0FA4CDD0FBEA__INCLUDED_)
