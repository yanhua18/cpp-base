// HQDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hq_6_12.h"
#include "HQDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHQDlg dialog


CHQDlg::CHQDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHQDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHQDlg)
	m_bookid1 = _T("");
	m_bookname1 = _T("");
	m_bookprice1 = 0;
	//}}AFX_DATA_INIT
}


void CHQDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHQDlg)
	DDX_Text(pDX, IDC_EDIT1, m_bookid1);
	DDX_Text(pDX, IDC_EDIT2, m_bookname1);
	DDX_Text(pDX, IDC_EDIT3, m_bookprice1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHQDlg, CDialog)
	//{{AFX_MSG_MAP(CHQDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHQDlg message handlers
