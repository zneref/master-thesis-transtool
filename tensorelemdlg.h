#if !defined(AFX_TENSORELEMDLG_H__D56FF460_DC65_11D6_AADA_977D71F04642__INCLUDED_)
#define AFX_TENSORELEMDLG_H__D56FF460_DC65_11D6_AADA_977D71F04642__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// tensorelemdlg.h : header file
//
#include "./translib/matrix.h"
#include "./translib/tensor.h"
/////////////////////////////////////////////////////////////////////////////
// tensorelemdlg dialog

class TensorElemDlg : public CPropertyPage
{
	DECLARE_DYNCREATE(TensorElemDlg)

// Construction
public:
	TensorElemDlg();
	~TensorElemDlg();

// Dialog Data
	//{{AFX_DATA(TensorElemDlg)
	enum { IDD = IDD_TENSOR_DLG };
	CEdit	m_ecc11;
	CEdit	m_ecc12;
	CEdit	m_ecc13;
	CEdit	m_ecc14;
	CEdit	m_ecc15;
	CEdit	m_ecc16;
	CEdit	m_ecc21;
	CEdit	m_ecc22;
	CEdit	m_ecc23;
	CEdit	m_ecc24;
	CEdit	m_ecc25;
	CEdit	m_ecc26;
	CEdit	m_ecc31;
	CEdit	m_ecc32;
	CEdit	m_ecc33;
	CEdit	m_ecc34;
	CEdit	m_ecc35;
	CEdit	m_ecc36;
	CEdit	m_ecc41;
	CEdit	m_ecc42;
	CEdit	m_ecc43;
	CEdit	m_ecc44;
	CEdit	m_ecc45;
	CEdit	m_ecc46;
	CEdit	m_ecc51;
	CEdit	m_ecc52;
	CEdit	m_ecc53;
	CEdit	m_ecc54;
	CEdit	m_ecc55;
	CEdit	m_ecc56;
	CEdit	m_ecc61;
	CEdit	m_ecc62;
	CEdit	m_ecc63;
	CEdit	m_ecc64;
	CEdit	m_ecc65;
	CEdit	m_ecc66;
	double	m_cc11;
	double	m_cc12;
	double	m_cc13;
	double	m_cc14;
	double	m_cc15;
	double	m_cc16;
	double	m_cc21;
	double	m_cc22;
	double	m_cc23;
	double	m_cc24;
	double	m_cc25;
	double	m_cc26;
	double	m_cc31;
	double	m_cc32;
	double	m_cc33;
	double	m_cc34;
	double	m_cc35;
	double	m_cc36;
	double	m_cc41;
	double	m_cc42;
	double	m_cc43;
	double	m_cc44;
	double	m_cc45;
	double	m_cc46;
	double	m_cc51;
	double	m_cc52;
	double	m_cc53;
	double	m_cc54;
	double	m_cc55;
	double	m_cc56;
	double	m_cc61;
	double	m_cc62;
	double	m_cc63;
	double	m_cc64;
	double	m_cc65;
	double	m_cc66;
	double	m_cl11;
	double	m_cl12;
	double	m_cl13;
	double	m_cl14;
	double	m_cl15;
	double	m_cl16;
	double	m_cl21;
	double	m_cl22;
	double	m_cl23;
	double	m_cl24;
	double	m_cl25;
	double	m_cl26;
	double	m_cl31;
	double	m_cl32;
	double	m_cl33;
	double	m_cl34;
	double	m_cl35;
	double	m_cl36;
	double	m_cl41;
	double	m_cl42;
	double	m_cl43;
	double	m_cl44;
	double	m_cl45;
	double	m_cl46;
	double	m_cl51;
	double	m_cl52;
	double	m_cl53;
	double	m_cl54;
	double	m_cl55;
	double	m_cl56;
	double	m_cl61;
	double	m_cl62;
	double	m_cl63;
	double	m_cl64;
	double	m_cl65;
	double	m_cl66;
	double	m_m11;
	double	m_m12;
	double	m_m13;
	double	m_m21;
	double	m_m22;
	double	m_m23;
	double	m_m31;
	double	m_m32;
	double	m_m33;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(TensorElemDlg)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void EnableAllCC();
	void ClearAllCC();
	void DisableCC();
	// Generated message map functions
	//{{AFX_MSG(TensorElemDlg)
	afx_msg void OnFromFile();
	afx_msg void OnSave();
	afx_msg void OnTransTensor();
	afx_msg void OnMatFromFile();
	afx_msg void OnMatSave();
	afx_msg void OnKillfocusCc12();
	afx_msg void OnKillfocusCc13();
	afx_msg void OnKillfocusCc14();
	afx_msg void OnKillfocusCc15();
	afx_msg void OnKillfocusCc16();
	afx_msg void OnKillfocusCc21();
	afx_msg void OnKillfocusCc23();
	afx_msg void OnKillfocusCc24();
	afx_msg void OnKillfocusCc25();
	afx_msg void OnKillfocusCc26();
	afx_msg void OnKillfocusCc31();
	afx_msg void OnKillfocusCc32();
	afx_msg void OnKillfocusCc34();
	afx_msg void OnKillfocusCc35();
	afx_msg void OnKillfocusCc36();
	afx_msg void OnKillfocusCc41();
	afx_msg void OnKillfocusCc42();
	afx_msg void OnKillfocusCc43();
	afx_msg void OnKillfocusCc45();
	afx_msg void OnKillfocusCc46();
	afx_msg void OnKillfocusCc51();
	afx_msg void OnKillfocusCc52();
	afx_msg void OnKillfocusCc53();
	afx_msg void OnKillfocusCc54();
	afx_msg void OnKillfocusCc56();
	afx_msg void OnKillfocusCc61();
	afx_msg void OnKillfocusCc62();
	afx_msg void OnKillfocusCc63();
	afx_msg void OnKillfocusCc64();
	afx_msg void OnKillfocusCc65();
	afx_msg void OnKillfocusCc11();
	afx_msg void OnKillfocusCc22();
	afx_msg void OnKillfocusCc33();
	afx_msg void OnKillfocusCc44();
	afx_msg void OnKillfocusCc55();
	afx_msg void OnKillfocusCc66();
	afx_msg void OnRadioCub();
	afx_msg void OnRadioMono();
	afx_msg void OnRadioOrtho();
	afx_msg void OnRadioTetra();
	afx_msg void OnRadioTri();
	afx_msg void OnRadioTrig();
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioHeksa();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TENSORELEMDLG_H__D56FF460_DC65_11D6_AADA_977D71F04642__INCLUDED_)
