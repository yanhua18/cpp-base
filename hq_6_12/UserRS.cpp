// UserRS.cpp : implementation file
//

#include "stdafx.h"
#include "hq_6_12.h"
#include "UserRS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserRS

IMPLEMENT_DYNAMIC(CUserRS, CRecordset)

CUserRS::CUserRS(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CUserRS)
	m_UserName = _T("");
	m_Password = _T("");
	m_authority = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CUserRS::GetDefaultConnect()
{
	return _T("ODBC;DSN=hq_6_12");
}

CString CUserRS::GetDefaultSQL()
{
	return _T("[user]");
}

void CUserRS::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CUserRS)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[UserName]"), m_UserName);
	RFX_Text(pFX, _T("[Password]"), m_Password);
	RFX_Text(pFX, _T("[authority]"), m_authority);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CUserRS diagnostics

#ifdef _DEBUG
void CUserRS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CUserRS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
