// hq13_1.h : main header file for the HQ13_1 application
//

#if !defined(AFX_HQ13_1_H__02F6405A_4D02_4959_9FE6_B4212547AFD8__INCLUDED_)
#define AFX_HQ13_1_H__02F6405A_4D02_4959_9FE6_B4212547AFD8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHq13_1App:
// See hq13_1.cpp for the implementation of this class
//

class CHq13_1App : public CWinApp
{
public:
	CHq13_1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHq13_1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CHq13_1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HQ13_1_H__02F6405A_4D02_4959_9FE6_B4212547AFD8__INCLUDED_)
