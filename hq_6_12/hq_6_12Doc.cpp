// hq_6_12Doc.cpp : implementation of the CHq_6_12Doc class
//

#include "stdafx.h"
#include "hq_6_12.h"

#include "hq_6_12Set.h"
#include "hq_6_12Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHq_6_12Doc

IMPLEMENT_DYNCREATE(CHq_6_12Doc, CDocument)

BEGIN_MESSAGE_MAP(CHq_6_12Doc, CDocument)
	//{{AFX_MSG_MAP(CHq_6_12Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHq_6_12Doc construction/destruction

CHq_6_12Doc::CHq_6_12Doc()
{
	// TODO: add one-time construction code here

}

CHq_6_12Doc::~CHq_6_12Doc()
{
}

BOOL CHq_6_12Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHq_6_12Doc diagnostics

#ifdef _DEBUG
void CHq_6_12Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHq_6_12Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHq_6_12Doc commands
