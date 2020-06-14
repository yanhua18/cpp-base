// hq_6_12Set.cpp : implementation of the CHq_6_12Set class
//

#include "stdafx.h"
#include "hq_6_12.h"
#include "hq_6_12Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHq_6_12Set implementation

IMPLEMENT_DYNAMIC(CHq_6_12Set, CRecordset)

CHq_6_12Set::CHq_6_12Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CHq_6_12Set)
	m_BookID = _T("");
	m_BookName = _T("");
	m_Price = 0;
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CHq_6_12Set::GetDefaultConnect()
{
	return _T("ODBC;DSN=hq_6_12");
}

CString CHq_6_12Set::GetDefaultSQL()
{
	return _T("[book]");
}

void CHq_6_12Set::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CHq_6_12Set)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[BookID]"), m_BookID);
	RFX_Text(pFX, _T("[BookName]"), m_BookName);
	RFX_Int(pFX, _T("[Price]"), m_Price);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CHq_6_12Set diagnostics

#ifdef _DEBUG
void CHq_6_12Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CHq_6_12Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
