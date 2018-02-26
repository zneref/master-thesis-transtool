#if !defined(AFX_TransMatDlg_H__D7FC2D8F_DBB5_11D6_AADA_D64466184840__INCLUDED_)
#define AFX_TransMatDlg_H__D7FC2D8F_DBB5_11D6_AADA_D64466184840__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TransMatDlg.h : header file
//
#include "millptrox.h"
#include "millptroy.h"
#include "millptroz.h"
#include "./translib/matrix.h"
#include "./translib/vector.h"
#include "viewdlg.h"
#include "listelem.h"

/////////////////////////////////////////////////////////////////////////////
// TransMatDlg dialog

class TransMatDlg : public CPropertyPage
{
	DECLARE_DYNCREATE(TransMatDlg)

// Construction
public:
	TransMatDlg();
	~TransMatDlg();
	CrystMatrix K;
	Matrix M;
	void OnVisualWnd();
	void OnTurnOo();
	void OnTurnOx();
	void OnTurnOy();
	void OnTurnOz();
// Dialog Data
	//{{AFX_DATA(TransMatDlg)
	enum { IDD = IDD_CROSSMAT_DLG };
	CComboBox	m_sysList;
	CComboBox	m_classList;
	//}}AFX_DATA
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(TransMatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	POINT* ox_rect;
	POINT* oy_rect;
	POINT* oz_rect;
	ViewDlg* pvDlg;
	millptrox ox_dlg;
	millptroy oy_dlg;
	millptroz oz_dlg;
	int isClicked;
	BOOL oxClicked;
	BOOL oyClicked;
	BOOL ozClicked;
	BOOL cellBtn;
	COLORREF* fillCol;
	SysListElem* psysElem;
	CBitmap m_bm;
	RotateMatrix SetRMatrix(int nId);
	void LoadBmImage();
	void DisplayBitmap(CDC* pDC, CBitmap* pBitmap, int x,int y);
	// Generated message map functions
	//{{AFX_MSG(TransMatDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnResetData();
	afx_msg void OnFindMatrix();
	afx_msg void OnCellParam();
	afx_msg void OnSelchangeClassList();
	afx_msg void OnSelchangeSystemList();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TransMatDlg_H__D7FC2D8F_DBB5_11D6_AADA_D64466184840__INCLUDED_)
