// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hq_6_12.h"
#include "LoginDlg.h"

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
	CLoginDlg recordset;
	CString strSQL;
	UpdateData(true);
	strSQL.Format("select * from user where UserName='%s' AND Password='%s'",m_loginname,m_loginpassword);
    recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL);
	if(recordset.GetRecordCount()==0)
	{	recordset.Close();
		MessageBox("�û���/����������������룡");
		m_loginpassword="";
		m_ctrPass.SetFocus();
		UpdateData(FALSE);	}
	else
	{	recordset.Close();
		AfxMessageBox("��¼�ɹ�");	//������¼�ɹ���Ϣ��
		CDialog::OnOK();
	}

}
