// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "hq13_1.h"

#include "MainFrm.h"
#include"LoginDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_LOGIN_IN, OnLoginIn)
	ON_COMMAND(ID_LOGIN_OUT, OnLoginOut)
	ON_UPDATE_COMMAND_UI(ID_RECORD_ADD, OnUpdateRecordAdd)
	ON_COMMAND(ID_RECORD_ADD, OnRecordAdd)
	ON_COMMAND(ID_RECOED_SEARCH, OnRecoedSearch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnLoginIn() 
{
	// TODO: Add your command handler code here
	CLoginDlg dlg;
	dlg.DoModal();
	if(dlg.m_bLogin==true)
	{
		m_log=dlg.m_bLogin;
		m_name=dlg.m_loginname;
		m_password=dlg.m_loginpassword;
		m_which=dlg.m_which;
	}
}

void CMainFrame::OnLoginOut() 
{
	// TODO: Add your command handler code here
	m_which="";
	m_log=false;
}

void CMainFrame::OnUpdateRecordAdd(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CString str="管理员";
	int len=str.GetLength();
	if(m_which.Left(len)!="管理员")
		pCmdUI->Enable(false);//非管理员则更新状态不可用
	else
		pCmdUI->Enable(true);
}


void CMainFrame::OnRecordAdd() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnRecoedSearch() 
{
	// TODO: Add your command handler code here
	
}
