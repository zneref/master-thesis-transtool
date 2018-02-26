// TransTool.h : main header file for the TRANSTOOL application
//

#if !defined(AFX_TRANSTOOL_H__D7FC2D84_DBB5_11D6_AADA_D64466184840__INCLUDED_)
#define AFX_TRANSTOOL_H__D7FC2D84_DBB5_11D6_AADA_D64466184840__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTransToolApp:
// See TransTool.cpp for the implementation of this class
//

class CTransToolApp : public CWinApp
{
public:
	CTransToolApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransToolApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTransToolApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSTOOL_H__D7FC2D84_DBB5_11D6_AADA_D64466184840__INCLUDED_)
