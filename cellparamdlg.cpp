// cellparamdlg.cpp : implementation file
//
/**
*	\author Marian Ferenz
*
*/
#include "stdafx.h"
#include "TransTool.h"
#include "cellparamdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// cellparamdlg dialog

cellparamdlg::cellparamdlg(CWnd* pParent /*=NULL*/)
	: CDialog(cellparamdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(cellparamdlg)
	m_a = 3.0;
	m_b = 3.0;
	m_c = 3.0;
	m_alpha = 90.0;
	m_beta = 90.0;
	m_gamma = 90.0;
	m_hox=1;
	m_kox=0;
	m_lox=0;
	m_hoy=0;
	m_koy=1;
	m_loy=0;
	m_hoz=0;
	m_koz=0;
	m_loz=1;
	//}}AFX_DATA_INIT
}


void cellparamdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(cellparamdlg)
	DDX_Text(pDX, IDC_A, m_a);
	DDX_Text(pDX, IDC_BETA, m_beta);
	DDX_Text(pDX, IDC_ALPHA, m_alpha);
	DDX_Text(pDX, IDC_B, m_b);
	DDX_Text(pDX, IDC_C, m_c);
	DDX_Text(pDX, IDC_GAMMA, m_gamma);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(cellparamdlg, CDialog)
	//{{AFX_MSG_MAP(cellparamdlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// cellparamdlg message handlers
/**
*	Przypisanie parametrom komórki elementarnej odpowiednich wartoœci.
*	w zale¿noœci od rodzaju uk³adu wspó³rzêdnych
*	\param sysName nazwa uk³adu krystalograficznego
*
*/
void cellparamdlg::SetCelInitParam(const char* sysName)
{
	if(!strcmp(sysName,"tetragonalny"))
	{
		m_a=1;
		m_b=1;
		m_c=3;
		m_alpha=90;
		m_beta=90;
		m_gamma=90;
	}
	else if(!strcmp(sysName,"regularny"))
	{
		m_a=3;
		m_b=3;
		m_c=3;
		m_alpha=90;
		m_beta=90;
		m_gamma=90;
	}
	else if(!strcmp(sysName,"rombowy"))
	{
		m_a=1;
		m_b=2;
		m_c=3;
		m_alpha=90;
		m_beta=90;
		m_gamma=90;
	}
	else if(!strcmp(sysName,"trygonalny") || !strcmp(sysName,"heksagonalny"))
	{
		m_a=1;
		m_b=1;
		m_c=3;
		m_alpha=90;
		m_beta=90;
		m_gamma=120;
	}
	else if(!strcmp(sysName,"jednoskoœny"))
	{
		m_a=1;
		m_b=2;
		m_c=3;
		m_alpha=90;
		m_beta=70;
		m_gamma=90;
	}
	else if(!strcmp(sysName,"trójskoœny"))
	{
		m_a=1;
		m_b=2;
		m_c=3;
		m_alpha=60;
		m_beta=120;
		m_gamma=70;
	}
};
/**
*	Sprawdzenie poprawnoœci wpisanych wartoœci parametrów kom. elem
*	\param sysName nazwa uk³adu krystalograficznego
*/
int cellparamdlg::CheckCelParam(const char* sysName)
{
	if(!strcmp(sysName,"tetragonalny"))
	{
		if(m_a==m_b && m_a!=m_c && m_alpha==90 && m_beta==90 && m_gamma==90)
			return 1;
		return 0;
	}
	else if(!strcmp(sysName,"regularny"))
	{
		if(m_a==m_b && m_a==m_c && m_alpha==90 && m_beta==90 && m_gamma==90)
			return 1;
		return 0;
	}
	else if(!strcmp(sysName,"rombowy"))
	{
		if(m_a!=m_b && m_a!=m_c && m_b!=m_c && m_alpha==90 && m_beta==90 && m_gamma==90)
			return 1;
		return 0;
	}
	else if(!strcmp(sysName,"trygonalny") || !strcmp(sysName,"heksagonalny"))
	{
		if(m_a==m_b && m_a!=m_c && m_alpha==90 && m_beta==90 && m_gamma==120)
			return 1;
		return 0;
	}
	else if(!strcmp(sysName,"jednoskoœny"))
	{
		if(m_a!=m_b && m_a!=m_c && m_b!=m_c && m_alpha==90 && m_beta!=90 && m_gamma==90)
			return 1;
		return 0;
	}
	else if(!strcmp(sysName,"trójskoœny"))
	{
		if(m_a!=m_b && m_a!=m_c && m_b!=m_c && m_alpha!=90 && m_beta!=90 && m_gamma!=90 && m_beta!=m_alpha && m_gamma!=m_beta && m_gamma!=m_alpha)
			return 1;
		return 0;
	}
	return 0;		
};
