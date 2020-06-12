// hq13_1Set.cpp : implementation of the CHq13_1Set class
//

#include "stdafx.h"
#include "hq13_1.h"
#include "hq13_1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHq13_1Set implementation

IMPLEMENT_DYNAMIC(CHq13_1Set, CRecordset)

CHq13_1Set::CHq13_1Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CHq13_1Set)
	m_StudentID = _T("");
	m_Name = _T("");
	m_age = 0;
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}

CString CHq13_1Set::GetDefaultConnect()
{
	return _T("ODBC;DSN=second");
}

CString CHq13_1Set::GetDefaultSQL()
{
	return _T("[student]");
}

void CHq13_1Set::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CHq13_1Set)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[StudentID]"), m_StudentID);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	RFX_Int(pFX, _T("[age]"), m_age);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CHq13_1Set diagnostics

#ifdef _DEBUG
void CHq13_1Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CHq13_1Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
