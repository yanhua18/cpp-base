// LoginDlg1.cpp : implementation file
//

#include "stdafx.h"
#include "hq_6_12.h"
#include "LoginDlg1.h"
#include"UserRS.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg1 dialog


CLoginDlg1::CLoginDlg1(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg1)
	m_loginname = _T("");
	m_loginpassword = _T("");
	//}}AFX_DATA_INIT
}


void CLoginDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg1)
	DDX_Control(pDX, IDC_EDIT2, m_ctrPass);
	DDX_Text(pDX, IDC_EDIT1, m_loginname);
	DDX_Text(pDX, IDC_EDIT2, m_loginpassword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg1, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg1)
	ON_BN_CLICKED(ID_LOGIN, OnLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg1 message handlers

void CLoginDlg1::OnLogin() 
{
	// TODO: Add your control notification handler code here
	CUserRS recordset;
	CString strSQL;
	UpdateData(true);
	strSQL.Format("select * from user where UserName='%s' AND Password='%s'",m_loginname,m_loginpassword);
    recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL);
	if(recordset.GetRecordCount()==0)
	{	recordset.Close();
		MessageBox("用户名/密码错误，请重新输入！");
		m_loginpassword="";
		m_ctrPass.SetFocus();
		UpdateData(FALSE);	}
	else
	{	recordset.Close();
		AfxMessageBox("登录成功");	//弹出登录成功消息框
		CDialog::OnOK();
	}

}
