// TransToolDlg.h : header file
//

#if !defined(AFX_TRANSTOOLDLG_H__D7FC2D86_DBB5_11D6_AADA_D64466184840__INCLUDED_)
#define AFX_TRANSTOOLDLG_H__D7FC2D86_DBB5_11D6_AADA_D64466184840__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTransToolDlg dialog
#include "transmatdlg.h"
#include "tensorelemdlg.h"
class CTransToolDlg : public CDialog
{
// Construction
public:
	CTransToolDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTransToolDlg)
	enum { IDD = IDD_TRANSTOOL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransToolDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CPropertySheet	m_sheet;
	TransMatDlg		matpage;
	TensorElemDlg	tenpage;
	bool matfinded;
	// Generated message map functions
	//{{AFX_MSG(CTransToolDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnVisualWnd();
	afx_msg void OnTurnOo();
	afx_msg void OnTurnOx();
	afx_msg void OnTurnOy();
	afx_msg void OnTurnOz();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSTOOLDLG_H__D7FC2D86_DBB5_11D6_AADA_D64466184840__INCLUDED_)
