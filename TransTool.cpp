// TransTool.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "TransTool.h"
#include "TransToolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTransToolApp

BEGIN_MESSAGE_MAP(CTransToolApp, CWinApp)
	//{{AFX_MSG_MAP(CTransToolApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransToolApp construction

CTransToolApp::CTransToolApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTransToolApp object

CTransToolApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTransToolApp initialization

BOOL CTransToolApp::InitInstance()
{
	// Standard initialization

	CTransToolDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
