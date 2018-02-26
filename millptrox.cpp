// millptrox.cpp : implementation file
//

#include "stdafx.h"
#include "TransTool.h"
#include "millptrox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// millptrox dialog


millptrox::millptrox(CWnd* pParent /*=NULL*/)
	: CDialog(millptrox::IDD, pParent)
{
	//{{AFX_DATA_INIT(millptrox)
	m_hox = 1;
	m_kox = 0;
	m_lox = 0;
	//}}AFX_DATA_INIT
}


void millptrox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(millptrox)
	DDX_Text(pDX, IDC_HOX, m_hox);
	DDX_Text(pDX, IDC_KOX, m_kox);
	DDX_Text(pDX, IDC_LOX, m_lox);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(millptrox, CDialog)
	//{{AFX_MSG_MAP(millptrox)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// millptrox message handlers
