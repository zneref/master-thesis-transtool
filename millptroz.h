#if !defined(AFX_MILLPTROZ_H__D7FC2D92_DBB5_11D6_AADA_D64466184840__INCLUDED_)
#define AFX_MILLPTROZ_H__D7FC2D92_DBB5_11D6_AADA_D64466184840__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// millptroz.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// millptroz dialog

class millptroz : public CDialog
{
// Construction
public:
	millptroz(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(millptroz)
	enum { IDD = IDD_MILLPTR_OZ };
	int		m_hoz;
	int		m_koz;
	int		m_loz;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(millptroz)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(millptroz)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MILLPTROZ_H__D7FC2D92_DBB5_11D6_AADA_D64466184840__INCLUDED_)
