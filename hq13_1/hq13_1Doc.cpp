// hq13_1Doc.cpp : implementation of the CHq13_1Doc class
//

#include "stdafx.h"
#include "hq13_1.h"

#include "hq13_1Set.h"
#include "hq13_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHq13_1Doc

IMPLEMENT_DYNCREATE(CHq13_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CHq13_1Doc, CDocument)
	//{{AFX_MSG_MAP(CHq13_1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHq13_1Doc construction/destruction

CHq13_1Doc::CHq13_1Doc()
{
	// TODO: add one-time construction code here

}

CHq13_1Doc::~CHq13_1Doc()
{
}

BOOL CHq13_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHq13_1Doc diagnostics

#ifdef _DEBUG
void CHq13_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHq13_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHq13_1Doc commands
