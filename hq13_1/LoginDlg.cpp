// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hq13_1.h"
#include "LoginDlg.h"
#include"UserRS.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
	m_loginname = _T("");
	m_loginpassword = _T("");
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Control(pDX, IDC_EDIT2, m_ctrPass);
	DDX_Text(pDX, IDC_EDIT1, m_loginname);
	DDX_Text(pDX, IDC_EDIT2, m_loginpassword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	ON_BN_CLICKED(ID_LOGIN, OnLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnLogin() 
{
	// TODO: Add your control notification handler code here
    CUserRS recordset;
	CString strSQL;
	UpdateData(true);
	strSQL.Format("select * from user where UserName='%s' AND Password='%s'",m_loginname,m_loginpassword);
    recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL);
	if(recordset.GetRecordCount()==0)
	{	
		recordset.Close();
		MessageBox("用户名/密码错误，请重新输入！");
		m_loginpassword="";
		m_ctrPass.SetFocus();
		UpdateData(FALSE);	
	}
	else
	{	
		m_bLogin=true;
		recordset.GetFieldValue(2,m_which);
		recordset.Close();
		AfxMessageBox(m_which+"登录成功");	//弹出登录成功消息框
		CDialog::OnOK();
    }
}
