#if !defined(AFX_ResultDlg_H__D56FF462_DC65_11D6_AADA_977D71F04642__INCLUDED_)
#define AFX_ResultDlg_H__D56FF462_DC65_11D6_AADA_977D71F04642__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ResultDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ResultDlg dialog

class ResultDlg : public CDialog
{
// Construction
public:
	ResultDlg(CWnd* pParent = NULL);   // standard constructor
	void GetAMatrix(const Matrix&);
	void GetTMatrix(const Matrix&);
	void GetEMatrix(const Matrix&);
// Dialog Data
	//{{AFX_DATA(ResultDlg)
	enum { IDD = IDD_END_MAT_DLG };
	double	m_a11;
	double	m_a12;
	double	m_a13;
	double	m_a21;
	double	m_a22;
	double	m_a23;
	double	m_a31;
	double	m_a32;
	double	m_a33;
	double	m_t11;
	double	m_t12;
	double	m_t13;
	double	m_t21;
	double	m_t22;
	double	m_t23;
	double	m_t31;
	double	m_t32;
	double	m_t33;
	double	m_e11;
	double	m_e12;
	double	m_e13;
	double	m_e21;
	double	m_e22;
	double	m_e23;
	double	m_e31;
	double	m_e32;
	double	m_e33;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ResultDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(ResultDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ResultDlg_H__D56FF462_DC65_11D6_AADA_977D71F04642__INCLUDED_)
