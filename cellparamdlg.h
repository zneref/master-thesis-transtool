#if !defined(AFX_CELLPARAMDLG_H__17F8ADE1_E841_11D6_AADA_B1EA92382347__INCLUDED_)
#define AFX_CELLPARAMDLG_H__17F8ADE1_E841_11D6_AADA_B1EA92382347__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// cellparamdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// cellparamdlg dialog

class cellparamdlg : public CDialog
{
// Construction
public:
	cellparamdlg(CWnd* pParent = NULL);   // standard constructor
	int CheckCelParam(const char* sysName);
	void SetCelInitParam(const char* sysName);

// Dialog Data
	//{{AFX_DATA(cellparamdlg)
	enum { IDD = IDD_CELL_PARAM_DLG };
	double m_a;
	double m_beta;
	double m_alpha;
	double m_b;
	double m_c;
	double m_gamma;
	double m_hox;
	double m_kox;
	double m_lox;
	double m_hoy;
	double m_koy;
	double m_loy;
	double m_hoz;
	double m_koz;
	double m_loz;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(cellparamdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(cellparamdlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CELLPARAMDLG_H__17F8ADE1_E841_11D6_AADA_B1EA92382347__INCLUDED_)
