// hq4.h : main header file for the HQ4 application
//

#if !defined(AFX_HQ4_H__D0604C3F_7030_4EB0_9BD2_C61E57D45A32__INCLUDED_)
#define AFX_HQ4_H__D0604C3F_7030_4EB0_9BD2_C61E57D45A32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHq4App:
// See hq4.cpp for the implementation of this class
//

class CHq4App : public CWinApp
{
public:
	CHq4App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHq4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHq4App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HQ4_H__D0604C3F_7030_4EB0_9BD2_C61E57D45A32__INCLUDED_)
