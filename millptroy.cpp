// millptroy.cpp : implementation file
//

#include "stdafx.h"
#include "TransTool.h"
#include "millptroy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// millptroy dialog


millptroy::millptroy(CWnd* pParent /*=NULL*/)
	: CDialog(millptroy::IDD, pParent)
{
	//{{AFX_DATA_INIT(millptroy)
	m_hoy = 0;
	m_koy = 1;
	m_loy = 0;
	//}}AFX_DATA_INIT
}


void millptroy::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(millptroy)
	DDX_Text(pDX, IDC_HOY, m_hoy);
	DDX_Text(pDX, IDC_KOY, m_koy);
	DDX_Text(pDX, IDC_LOY, m_loy);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(millptroy, CDialog)
	//{{AFX_MSG_MAP(millptroy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// millptroy message handlers

