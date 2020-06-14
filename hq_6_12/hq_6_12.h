// hq_6_12.h : main header file for the HQ_6_12 application
//

#if !defined(AFX_HQ_6_12_H__A61E591A_E5A9_4A66_9FA9_AE7289BC9FC8__INCLUDED_)
#define AFX_HQ_6_12_H__A61E591A_E5A9_4A66_9FA9_AE7289BC9FC8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHq_6_12App:
// See hq_6_12.cpp for the implementation of this class
//

class CHq_6_12App : public CWinApp
{
public:
	CHq_6_12App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHq_6_12App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CHq_6_12App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HQ_6_12_H__A61E591A_E5A9_4A66_9FA9_AE7289BC9FC8__INCLUDED_)
