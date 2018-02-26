#if !defined(AFX_VIEWDLG_H__D56FF461_DC65_11D6_AADA_977D71F04642__INCLUDED_)
#define AFX_VIEWDLG_H__D56FF461_DC65_11D6_AADA_977D71F04642__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewDlg.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// ViewDlg dialog

class ViewDlg : public CDialog
{
// Construction
public:
	ViewDlg(CWnd* pParent = NULL);   // standard constructor
	CPalette* m_pPal ;		//Palette
	HGLRC m_hrc ; 			//OpenGL Rendering Context
	void DrawLabAxis();
	void DrawCrysAxis();
	void DrawElemCell();
	void DrawHKL(double h,double k, double l);
	double TheBiggest(double,double,double);
	void RefreshView();
	void GetCMatrix(const Matrix& );
	void GetEMatrix(const Matrix& );
	void GetMMatrix(const Matrix& );
	int isCreated;
	int ox; int oy; int oz; int oo;

// Dialog Data
	//{{AFX_DATA(ViewDlg)
	enum { IDD = IDD_VIEW_DLG};
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ViewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	double angle;
	bool btnDown;
	Matrix C;
	Matrix CO;
	Matrix E;
	Matrix M;
	// Generated message map functions
	//{{AFX_MSG(ViewDlg)
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnClose();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWDLG_H__D56FF461_DC65_11D6_AADA_977D71F04642__INCLUDED_)
