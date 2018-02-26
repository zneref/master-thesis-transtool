// ResultDlg.cpp : implementation file
//
/**
*	\author Marian Ferenz
*/
#include "stdafx.h"
#include "TransTool.h"
#include "./translib/matrix.h"
#include "resultdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ResultDlg dialog


ResultDlg::ResultDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ResultDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ResultDlg)
	m_a11 = 0.0;
	m_a12 = 0.0;
	m_a13 = 0.0;
	m_a21 = 0.0;
	m_a22 = 0.0;
	m_a23 = 0.0;
	m_a31 = 0.0;
	m_a32 = 0.0;
	m_a33 = 0.0;
	m_t11 = 0.0;
	m_t12 = 0.0;
	m_t13 = 0.0;
	m_t21 = 0.0;
	m_t22 = 0.0;
	m_t23 = 0.0;
	m_t31 = 0.0;
	m_t32 = 0.0;
	m_t33 = 0.0;
	m_e11 = 0.0;
	m_e12 = 0.0;
	m_e13 = 0.0;
	m_e21 = 0.0;
	m_e22 = 0.0;
	m_e23 = 0.0;
	m_e31 = 0.0;
	m_e32 = 0.0;
	m_e33 = 0.0;
	//}}AFX_DATA_INIT
}


void ResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ResultDlg)
	DDX_Text(pDX, IDC_A11, m_a11);
	DDX_Text(pDX, IDC_A12, m_a12);
	DDX_Text(pDX, IDC_A13, m_a13);
	DDX_Text(pDX, IDC_A21, m_a21);
	DDX_Text(pDX, IDC_A22, m_a22);
	DDX_Text(pDX, IDC_A23, m_a23);
	DDX_Text(pDX, IDC_A31, m_a31);
	DDX_Text(pDX, IDC_A32, m_a32);
	DDX_Text(pDX, IDC_A33, m_a33);
	DDX_Text(pDX, IDC_T11, m_t11);
	DDX_Text(pDX, IDC_T12, m_t12);
	DDX_Text(pDX, IDC_T13, m_t13);
	DDX_Text(pDX, IDC_T21, m_t21);
	DDX_Text(pDX, IDC_T22, m_t22);
	DDX_Text(pDX, IDC_T23, m_t23);
	DDX_Text(pDX, IDC_T31, m_t31);
	DDX_Text(pDX, IDC_T32, m_t32);
	DDX_Text(pDX, IDC_T33, m_t33);
	DDX_Text(pDX, IDC_E11, m_e11);
	DDX_Text(pDX, IDC_E12, m_e12);
	DDX_Text(pDX, IDC_E13, m_e13);
	DDX_Text(pDX, IDC_E21, m_e21);
	DDX_Text(pDX, IDC_E22, m_e22);
	DDX_Text(pDX, IDC_E23, m_e23);
	DDX_Text(pDX, IDC_E31, m_e31);
	DDX_Text(pDX, IDC_E32, m_e32);
	DDX_Text(pDX, IDC_E33, m_e33);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ResultDlg, CDialog)
	//{{AFX_MSG_MAP(ResultDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ResultDlg message handlers
/**
*	Zapisanie macierzy przejscia do pliku
*/
void ResultDlg::OnOK() 
{
	Matrix A;
	A.SetElem(0,0,m_a11);
	A.SetElem(0,1,m_a12);
	A.SetElem(0,2,m_a13);
	A.SetElem(1,0,m_a21);
	A.SetElem(1,1,m_a22);
	A.SetElem(1,2,m_a23);
	A.SetElem(2,0,m_a31);
	A.SetElem(2,1,m_a32);
	A.SetElem(2,2,m_a33);

	CFileDialog	 fDlg(FALSE,".txt","macierz", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"Pliki tekstowe (*.txt)|*.txt||",NULL );
	if(fDlg.DoModal()==IDOK)
		A.Print(fDlg.GetPathName());	
	CDialog::OnOK();
}
/**
*	pobranie macierzy przejœcia
*	\param A macierz przejscia
*/
void ResultDlg::GetAMatrix(const Matrix& A)
{	
	m_a11 = A.GetElem(0,0);
	m_a12 = A.GetElem(0,1);
	m_a13 = A.GetElem(0,2);
	m_a21 = A.GetElem(1,0);
	m_a22 = A.GetElem(1,1);
	m_a23 = A.GetElem(1,2);
	m_a31 = A.GetElem(2,0);
	m_a32 = A.GetElem(2,1);
	m_a33 = A.GetElem(2,2);	
}
/**
*	pobranie bazy uk³adu fizyczno krystalicznego
*	\param T macierz bazy uk³adu fiz-krystal.
*/
void ResultDlg::GetTMatrix(const Matrix& T)
{	
	m_t11 = T.GetElem(0,0);
	m_t12 = T.GetElem(0,1);
	m_t13 = T.GetElem(0,2);
	m_t21 = T.GetElem(1,0);
	m_t22 = T.GetElem(1,1);
	m_t23 = T.GetElem(1,2);
	m_t31 = T.GetElem(2,0);
	m_t32 = T.GetElem(2,1);
	m_t33 = T.GetElem(2,2);	
}
/**
*	Pobranie bazy uk³adu labolatoryjnego
*	\param E macierz bazy uk³adu labolatoryjnego
*/
void ResultDlg::GetEMatrix(const Matrix& E)
{	
	m_e11 = E.GetElem(0,0);
	m_e12 = E.GetElem(0,1);
	m_e13 = E.GetElem(0,2);
	m_e21 = E.GetElem(1,0);
	m_e22 = E.GetElem(1,1);
	m_e23 = E.GetElem(1,2);
	m_e31 = E.GetElem(2,0);
	m_e32 = E.GetElem(2,1);
	m_e33 = E.GetElem(2,2);	
}
