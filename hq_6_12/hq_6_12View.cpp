// hq_6_12View.cpp : implementation of the CHq_6_12View class
//

#include "stdafx.h"
#include "hq_6_12.h"

#include "hq_6_12Set.h"
#include "hq_6_12Doc.h"
#include "hq_6_12View.h"
#include"HQDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHq_6_12View

IMPLEMENT_DYNCREATE(CHq_6_12View, CRecordView)

BEGIN_MESSAGE_MAP(CHq_6_12View, CRecordView)
	//{{AFX_MSG_MAP(CHq_6_12View)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	ON_BN_CLICKED(IDC_SEARCH, OnSearch)
	ON_COMMAND(ID_SORT_ID, OnSortId)
	ON_COMMAND(ID_SORT_PRICE, OnSortPrice)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHq_6_12View construction/destruction

CHq_6_12View::CHq_6_12View()
	: CRecordView(CHq_6_12View::IDD)
{
	//{{AFX_DATA_INIT(CHq_6_12View)
	m_pSet = NULL;
	m_condition = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CHq_6_12View::~CHq_6_12View()
{
}

void CHq_6_12View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHq_6_12View)
	DDX_Control(pDX, IDC_COMBO1, m_find);
	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->m_BookID, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->m_BookName, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->m_Price, m_pSet);
	DDX_Text(pDX, IDC_EDIT4, m_condition);
	//}}AFX_DATA_MAP
}

BOOL CHq_6_12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CHq_6_12View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_hq_6_12Set;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	strcpy(MING,"图书名字");
	strcpy(ID,"图书编码");
	m_find.AddString((LPCTSTR)MING);
	m_find.AddString((LPCTSTR)ID);
	m_find.SetCurSel(0);

}

/////////////////////////////////////////////////////////////////////////////
// CHq_6_12View printing

BOOL CHq_6_12View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHq_6_12View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHq_6_12View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHq_6_12View diagnostics

#ifdef _DEBUG
void CHq_6_12View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CHq_6_12View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CHq_6_12Doc* CHq_6_12View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHq_6_12Doc)));
	return (CHq_6_12Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHq_6_12View database support
CRecordset* CHq_6_12View::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CHq_6_12View message handlers

void CHq_6_12View::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CHQDlg dlg;
	dlg.DoModal();
	try
	{	
		if(record.IsOpen())
		    record.Close();
		record.Open();
		record.AddNew();
		UpdateData(true);
		record.m_BookID=dlg.m_bookid1;
		record.m_BookName=dlg.m_bookname1;
		record.m_Price=dlg.m_bookprice1;
		record.Update();
		record.Requery();	
	}
	catch(CException* e)
	{	
		MessageBox("Add data failure!"); 
	}
	//UpdateData(FALSE);
}

void CHq_6_12View::OnDelete() 
{
	if(MessageBox("真的要删除该记录吗？","删除记录",MB_YESNO|
                    MB_ICONQUESTION)==IDYES)
	{	m_pSet->Delete();
		m_pSet->MovePrev();
	}
	
	 UpdateData(FALSE);
}

void CHq_6_12View::OnEdit() 
{
	CHQDlg dialog;
    dialog.m_bookid1=m_pSet->m_BookID;
	dialog.m_bookname1=m_pSet->m_BookName;
	dialog.m_bookprice1=m_pSet->m_Price;
	UpdateData(false);


	if(dialog.DoModal()==IDOK)
	UpdateData(true);
	 m_pSet->m_BookID=dialog.m_bookid1;
	 m_pSet->m_BookName=dialog.m_bookname1;
	 m_pSet->m_Price=dialog.m_bookprice1;
	 	UpdateData(false);
		m_pSet->Requery();

}

void CHq_6_12View::OnSearch() 
{
	// TODO: Add your control notification handler code here
	CString m_getstring;
	m_find.GetLBText(m_find.GetCurSel(),m_getstring);
	if(m_getstring==(CString)MING)
	{
		UpdateData(true);
		CString str="BookName";
		str=str+="='"+m_condition+"'";
		m_pSet->m_strFilter=str;
		m_pSet->Requery();
		int rectCount=m_pSet->GetRecordCount();
		if(rectCount==0)
		{
			MessageBox("没有匹配的记录","查询",MB_ICONWARNING);
			m_pSet->m_BookName="";
			m_pSet->Requery();
		}
		UpdateData(FALSE);
	}
	if(m_getstring==(CString)ID)
	{
		UpdateData(true);
		CString str="BookID";
		str=str+"='"+m_condition+"'";
		m_pSet->m_strFilter=str;
		m_pSet->Requery();
		int rectCount=m_pSet->GetRecordCount();
		if(rectCount==0)
		{
			MessageBox("没有匹配的记录","查找",MB_ICONWARNING);
			m_pSet->m_BookID="";
			m_pSet->Requery();
		}
		UpdateData(FALSE);
	}

}

void CHq_6_12View::OnSortId() 
{
	// TODO: Add your command handler code here
	m_pSet->Close();
	m_pSet->m_strSort="BookID";
	m_pSet->Open();
	UpdateData(FALSE);
}

void CHq_6_12View::OnSortPrice() 
{
	// TODO: Add your command handler code here
	m_pSet->Close();
	m_pSet->m_strSort="Price";
	m_pSet->Open();
	UpdateData(FALSE);
}
