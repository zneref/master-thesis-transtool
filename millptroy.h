#if !defined(AFX_MILLPTROY_H__D7FC2D91_DBB5_11D6_AADA_D64466184840__INCLUDED_)
#define AFX_MILLPTROY_H__D7FC2D91_DBB5_11D6_AADA_D64466184840__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// millptroy.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// millptroy dialog

class millptroy : public CDialog
{
// Construction
public:
	millptroy(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(millptroy)
	enum { IDD = IDD_MILLPTR_OY };
	int		m_hoy;
	int		m_koy;
	int		m_loy;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(millptroy)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(millptroy)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MILLPTROY_H__D7FC2D91_DBB5_11D6_AADA_D64466184840__INCLUDED_)
