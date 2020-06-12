// hq13_1View.cpp : implementation of the CHq13_1View class
//

#include "stdafx.h"
#include "hq13_1.h"

#include "hq13_1Set.h"
#include "hq13_1Doc.h"
#include "hq13_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHq13_1View

IMPLEMENT_DYNCREATE(CHq13_1View, CRecordView)

BEGIN_MESSAGE_MAP(CHq13_1View, CRecordView)
	//{{AFX_MSG_MAP(CHq13_1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHq13_1View construction/destruction

CHq13_1View::CHq13_1View()
	: CRecordView(CHq13_1View::IDD)
{
	//{{AFX_DATA_INIT(CHq13_1View)
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CHq13_1View::~CHq13_1View()
{
}

void CHq13_1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHq13_1View)
	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->m_StudentID, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->m_Name, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->m_age, m_pSet);
	//}}AFX_DATA_MAP
}

BOOL CHq13_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CHq13_1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_hq13_1Set;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CHq13_1View printing

BOOL CHq13_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHq13_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHq13_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHq13_1View diagnostics

#ifdef _DEBUG
void CHq13_1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CHq13_1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CHq13_1Doc* CHq13_1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHq13_1Doc)));
	return (CHq13_1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHq13_1View database support
CRecordset* CHq13_1View::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CHq13_1View message handlers
