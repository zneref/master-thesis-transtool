// millptroz.cpp : implementation file
//

#include "stdafx.h"
#include "TransTool.h"
#include "millptroz.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// millptroz dialog


millptroz::millptroz(CWnd* pParent /*=NULL*/)
	: CDialog(millptroz::IDD, pParent)
{
	//{{AFX_DATA_INIT(millptroz)
	m_hoz = 0;
	m_koz = 0;
	m_loz = 1;
	//}}AFX_DATA_INIT
}


void millptroz::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(millptroz)
	DDX_Text(pDX, IDC_HOZ, m_hoz);
	DDX_Text(pDX, IDC_KOZ, m_koz);
	DDX_Text(pDX, IDC_LOZ, m_loz);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(millptroz, CDialog)
	//{{AFX_MSG_MAP(millptroz)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// millptroz message handlers
