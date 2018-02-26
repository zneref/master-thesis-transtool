#if !defined(AFX_MILLPTROX_H__D7FC2D90_DBB5_11D6_AADA_D64466184840__INCLUDED_)
#define AFX_MILLPTROX_H__D7FC2D90_DBB5_11D6_AADA_D64466184840__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// millptrox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// millptrox dialog

class millptrox : public CDialog
{
// Construction
public:
	millptrox(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(millptrox)
	enum { IDD = IDD_MILLPTR_OX };
	int		m_hox;
	int		m_kox;
	int		m_lox;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(millptrox)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(millptrox)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MILLPTROX_H__D7FC2D90_DBB5_11D6_AADA_D64466184840__INCLUDED_)
