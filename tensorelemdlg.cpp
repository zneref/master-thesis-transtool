// tensorelemdlg.cpp : implementation file
//
/**
*	\author Marian Ferenz
*/
#include "stdafx.h"
#include "TransTool.h"
#include "tensorelemdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
*	zmienne globalne z pliku transmatdlg.cpp
*	przechowuj¹ nazwê uk³adu krystalograficznego oraz macierz przejscia
*/
extern CString sysName;
extern Matrix MGlobal;
/////////////////////////////////////////////////////////////////////////////
// TensorElemDlg property page

IMPLEMENT_DYNCREATE(TensorElemDlg, CPropertyPage)

TensorElemDlg::TensorElemDlg() : CPropertyPage(TensorElemDlg::IDD)
{
	//{{AFX_DATA_INIT(TensorElemDlg)
	m_cc11 = 0.0; m_cc12 = 0.0; m_cc13 = 0.0; m_cc14 = 0.0; m_cc15 = 0.0; m_cc16 = 0.0;
	m_cc21 = 0.0; m_cc22 = 0.0; m_cc23 = 0.0; m_cc24 = 0.0; m_cc25 = 0.0; m_cc26 = 0.0;
	m_cc31 = 0.0; m_cc32 = 0.0; m_cc33 = 0.0; m_cc34 = 0.0; m_cc35 = 0.0; m_cc36 = 0.0;
	m_cc41 = 0.0; m_cc42 = 0.0; m_cc43 = 0.0; m_cc44 = 0.0; m_cc45 = 0.0; m_cc46 = 0.0;
	m_cc51 = 0.0; m_cc52 = 0.0; m_cc53 = 0.0; m_cc54 = 0.0; m_cc55 = 0.0; m_cc56 = 0.0;
	m_cc61 = 0.0; m_cc62 = 0.0; m_cc63 = 0.0; m_cc64 = 0.0; m_cc65 = 0.0; m_cc66 = 0.0;
	m_cl11 = 0.0; m_cl12 = 0.0; m_cl13 = 0.0; m_cl14 = 0.0; m_cl15 = 0.0; m_cl16 = 0.0;
	m_cl21 = 0.0; m_cl22 = 0.0; m_cl23 = 0.0; m_cl24 = 0.0; m_cl25 = 0.0; m_cl26 = 0.0;
	m_cl31 = 0.0; m_cl32 = 0.0; m_cl33 = 0.0; m_cl34 = 0.0; m_cl35 = 0.0; m_cl36 = 0.0;
	m_cl41 = 0.0; m_cl42 = 0.0; m_cl43 = 0.0; m_cl44 = 0.0; m_cl45 = 0.0; m_cl46 = 0.0;
	m_cl51 = 0.0; m_cl52 = 0.0; m_cl53 = 0.0; m_cl54 = 0.0; m_cl55 = 0.0; m_cl56 = 0.0; 
	m_cl61 = 0.0; m_cl62 = 0.0; m_cl63 = 0.0; m_cl64 = 0.0; m_cl65 = 0.0; m_cl66 = 0.0;
	m_m11 = 0.0; m_m12 = 0.0; m_m13 = 0.0;
	m_m21 = 0.0; m_m22 = 0.0; m_m23 = 0.0;
	m_m31 = 0.0; m_m32 = 0.0; m_m33 = 0.0;
	//}}AFX_DATA_INIT
}

TensorElemDlg::~TensorElemDlg()
{
}

void TensorElemDlg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TensorElemDlg)
	DDX_Control(pDX, IDC_CC11, m_ecc11);
	DDX_Control(pDX, IDC_CC12, m_ecc12);
	DDX_Control(pDX, IDC_CC13, m_ecc13);
	DDX_Control(pDX, IDC_CC14, m_ecc14);
	DDX_Control(pDX, IDC_CC15, m_ecc15);
	DDX_Control(pDX, IDC_CC16, m_ecc16);
	DDX_Control(pDX, IDC_CC21, m_ecc21);
	DDX_Control(pDX, IDC_CC22, m_ecc22);
	DDX_Control(pDX, IDC_CC23, m_ecc23);
	DDX_Control(pDX, IDC_CC24, m_ecc24);
	DDX_Control(pDX, IDC_CC25, m_ecc25);
	DDX_Control(pDX, IDC_CC26, m_ecc26);
	DDX_Control(pDX, IDC_CC31, m_ecc31);
	DDX_Control(pDX, IDC_CC32, m_ecc32);
	DDX_Control(pDX, IDC_CC33, m_ecc33);
	DDX_Control(pDX, IDC_CC34, m_ecc34);
	DDX_Control(pDX, IDC_CC35, m_ecc35);
	DDX_Control(pDX, IDC_CC36, m_ecc36);
	DDX_Control(pDX, IDC_CC41, m_ecc41);
	DDX_Control(pDX, IDC_CC42, m_ecc42);
	DDX_Control(pDX, IDC_CC43, m_ecc43);
	DDX_Control(pDX, IDC_CC44, m_ecc44);
	DDX_Control(pDX, IDC_CC45, m_ecc45);
	DDX_Control(pDX, IDC_CC46, m_ecc46);
	DDX_Control(pDX, IDC_CC51, m_ecc51);
	DDX_Control(pDX, IDC_CC52, m_ecc52);
	DDX_Control(pDX, IDC_CC53, m_ecc53);
	DDX_Control(pDX, IDC_CC54, m_ecc54);
	DDX_Control(pDX, IDC_CC55, m_ecc55);
	DDX_Control(pDX, IDC_CC56, m_ecc56);
	DDX_Control(pDX, IDC_CC61, m_ecc61);
	DDX_Control(pDX, IDC_CC62, m_ecc62);
	DDX_Control(pDX, IDC_CC63, m_ecc63);
	DDX_Control(pDX, IDC_CC64, m_ecc64);
	DDX_Control(pDX, IDC_CC65, m_ecc65);
	DDX_Control(pDX, IDC_CC66, m_ecc66);
	DDX_Text(pDX, IDC_CC11, m_cc11);
	DDX_Text(pDX, IDC_CC12, m_cc12);
	DDX_Text(pDX, IDC_CC13, m_cc13);
	DDX_Text(pDX, IDC_CC14, m_cc14);
	DDX_Text(pDX, IDC_CC15, m_cc15);
	DDX_Text(pDX, IDC_CC16, m_cc16);
	DDX_Text(pDX, IDC_CC21, m_cc21);
	DDX_Text(pDX, IDC_CC22, m_cc22);
	DDX_Text(pDX, IDC_CC23, m_cc23);
	DDX_Text(pDX, IDC_CC24, m_cc24);
	DDX_Text(pDX, IDC_CC25, m_cc25);
	DDX_Text(pDX, IDC_CC26, m_cc26);
	DDX_Text(pDX, IDC_CC31, m_cc31);
	DDX_Text(pDX, IDC_CC32, m_cc32);
	DDX_Text(pDX, IDC_CC33, m_cc33);
	DDX_Text(pDX, IDC_CC34, m_cc34);
	DDX_Text(pDX, IDC_CC35, m_cc35);
	DDX_Text(pDX, IDC_CC36, m_cc36);
	DDX_Text(pDX, IDC_CC41, m_cc41);
	DDX_Text(pDX, IDC_CC42, m_cc42);
	DDX_Text(pDX, IDC_CC43, m_cc43);
	DDX_Text(pDX, IDC_CC44, m_cc44);
	DDX_Text(pDX, IDC_CC45, m_cc45);
	DDX_Text(pDX, IDC_CC46, m_cc46);
	DDX_Text(pDX, IDC_CC51, m_cc51);
	DDX_Text(pDX, IDC_CC52, m_cc52);
	DDX_Text(pDX, IDC_CC53, m_cc53);
	DDX_Text(pDX, IDC_CC54, m_cc54);
	DDX_Text(pDX, IDC_CC55, m_cc55);
	DDX_Text(pDX, IDC_CC56, m_cc56);
	DDX_Text(pDX, IDC_CC61, m_cc61);
	DDX_Text(pDX, IDC_CC62, m_cc62);
	DDX_Text(pDX, IDC_CC63, m_cc63);
	DDX_Text(pDX, IDC_CC64, m_cc64);
	DDX_Text(pDX, IDC_CC65, m_cc65);
	DDX_Text(pDX, IDC_CC66, m_cc66);
	DDX_Text(pDX, IDC_CL11, m_cl11);
	DDX_Text(pDX, IDC_CL12, m_cl12);
	DDX_Text(pDX, IDC_CL13, m_cl13);
	DDX_Text(pDX, IDC_CL14, m_cl14);
	DDX_Text(pDX, IDC_CL15, m_cl15);
	DDX_Text(pDX, IDC_CL16, m_cl16);
	DDX_Text(pDX, IDC_CL21, m_cl21);
	DDX_Text(pDX, IDC_CL22, m_cl22);
	DDX_Text(pDX, IDC_CL23, m_cl23);
	DDX_Text(pDX, IDC_CL24, m_cl24);
	DDX_Text(pDX, IDC_CL25, m_cl25);
	DDX_Text(pDX, IDC_CL26, m_cl26);
	DDX_Text(pDX, IDC_CL31, m_cl31);
	DDX_Text(pDX, IDC_CL32, m_cl32);
	DDX_Text(pDX, IDC_CL33, m_cl33);
	DDX_Text(pDX, IDC_CL34, m_cl34);
	DDX_Text(pDX, IDC_CL35, m_cl35);
	DDX_Text(pDX, IDC_CL36, m_cl36);
	DDX_Text(pDX, IDC_CL41, m_cl41);
	DDX_Text(pDX, IDC_CL42, m_cl42);
	DDX_Text(pDX, IDC_CL43, m_cl43);
	DDX_Text(pDX, IDC_CL44, m_cl44);
	DDX_Text(pDX, IDC_CL45, m_cl45);
	DDX_Text(pDX, IDC_CL46, m_cl46);
	DDX_Text(pDX, IDC_CL51, m_cl51);
	DDX_Text(pDX, IDC_CL52, m_cl52);
	DDX_Text(pDX, IDC_CL53, m_cl53);
	DDX_Text(pDX, IDC_CL54, m_cl54);
	DDX_Text(pDX, IDC_CL55, m_cl55);
	DDX_Text(pDX, IDC_CL56, m_cl56);
	DDX_Text(pDX, IDC_CL61, m_cl61);
	DDX_Text(pDX, IDC_CL62, m_cl62);
	DDX_Text(pDX, IDC_CL63, m_cl63);
	DDX_Text(pDX, IDC_CL64, m_cl64);
	DDX_Text(pDX, IDC_CL65, m_cl65);
	DDX_Text(pDX, IDC_CL66, m_cl66);
	DDX_Text(pDX, IDC_M11, m_m11);
	DDX_Text(pDX, IDC_M12, m_m12);
	DDX_Text(pDX, IDC_M13, m_m13);
	DDX_Text(pDX, IDC_M21, m_m21);
	DDX_Text(pDX, IDC_M22, m_m22);
	DDX_Text(pDX, IDC_M23, m_m23);
	DDX_Text(pDX, IDC_M31, m_m31);
	DDX_Text(pDX, IDC_M32, m_m32);
	DDX_Text(pDX, IDC_M33, m_m33);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TensorElemDlg, CPropertyPage)
	//{{AFX_MSG_MAP(TensorElemDlg)
	ON_BN_CLICKED(IDC_FROM_FILE, OnFromFile)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_BN_CLICKED(IDC_TRANSF, OnTransTensor)
	ON_BN_CLICKED(IDC_MAT_FROM_FILE, OnMatFromFile)
	ON_BN_CLICKED(IDC_MAT_SAVE, OnMatSave)
	ON_EN_KILLFOCUS(IDC_CC12, OnKillfocusCc12)
	ON_EN_KILLFOCUS(IDC_CC13, OnKillfocusCc13)
	ON_EN_KILLFOCUS(IDC_CC14, OnKillfocusCc14)
	ON_EN_KILLFOCUS(IDC_CC15, OnKillfocusCc15)
	ON_EN_KILLFOCUS(IDC_CC16, OnKillfocusCc16)
	ON_EN_KILLFOCUS(IDC_CC21, OnKillfocusCc21)
	ON_EN_KILLFOCUS(IDC_CC23, OnKillfocusCc23)
	ON_EN_KILLFOCUS(IDC_CC24, OnKillfocusCc24)
	ON_EN_KILLFOCUS(IDC_CC25, OnKillfocusCc25)
	ON_EN_KILLFOCUS(IDC_CC26, OnKillfocusCc26)
	ON_EN_KILLFOCUS(IDC_CC31, OnKillfocusCc31)
	ON_EN_KILLFOCUS(IDC_CC32, OnKillfocusCc32)
	ON_EN_KILLFOCUS(IDC_CC34, OnKillfocusCc34)
	ON_EN_KILLFOCUS(IDC_CC35, OnKillfocusCc35)
	ON_EN_KILLFOCUS(IDC_CC36, OnKillfocusCc36)
	ON_EN_KILLFOCUS(IDC_CC41, OnKillfocusCc41)
	ON_EN_KILLFOCUS(IDC_CC42, OnKillfocusCc42)
	ON_EN_KILLFOCUS(IDC_CC43, OnKillfocusCc43)
	ON_EN_KILLFOCUS(IDC_CC45, OnKillfocusCc45)
	ON_EN_KILLFOCUS(IDC_CC46, OnKillfocusCc46)
	ON_EN_KILLFOCUS(IDC_CC51, OnKillfocusCc51)
	ON_EN_KILLFOCUS(IDC_CC52, OnKillfocusCc52)
	ON_EN_KILLFOCUS(IDC_CC53, OnKillfocusCc53)
	ON_EN_KILLFOCUS(IDC_CC54, OnKillfocusCc54)
	ON_EN_KILLFOCUS(IDC_CC56, OnKillfocusCc56)
	ON_EN_KILLFOCUS(IDC_CC61, OnKillfocusCc61)
	ON_EN_KILLFOCUS(IDC_CC62, OnKillfocusCc62)
	ON_EN_KILLFOCUS(IDC_CC63, OnKillfocusCc63)
	ON_EN_KILLFOCUS(IDC_CC64, OnKillfocusCc64)
	ON_EN_KILLFOCUS(IDC_CC65, OnKillfocusCc65)
	ON_EN_KILLFOCUS(IDC_CC11, OnKillfocusCc11)
	ON_EN_KILLFOCUS(IDC_CC22, OnKillfocusCc22)
	ON_EN_KILLFOCUS(IDC_CC33, OnKillfocusCc33)
	ON_EN_KILLFOCUS(IDC_CC44, OnKillfocusCc44)
	ON_EN_KILLFOCUS(IDC_CC55, OnKillfocusCc55)
	ON_EN_KILLFOCUS(IDC_CC66, OnKillfocusCc66)
	ON_BN_CLICKED(IDC_RADIO_CUB, OnRadioCub)
	ON_BN_CLICKED(IDC_RADIO_MONO, OnRadioMono)
	ON_BN_CLICKED(IDC_RADIO_ORTHO, OnRadioOrtho)
	ON_BN_CLICKED(IDC_RADIO_TETRA, OnRadioTetra)
	ON_BN_CLICKED(IDC_RADIO_TRI, OnRadioTri)
	ON_BN_CLICKED(IDC_RADIO_TRIG, OnRadioTrig)
	ON_BN_CLICKED(IDC_RADIO_HEKSA, OnRadioHeksa)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TensorElemDlg message handlers
/**
*	Transforamcja s³adowych tensora do labolatoryjnego uk³adu wspó³rzêdnych
*/
void TensorElemDlg::OnTransTensor() 
{
	Matrix M;
	VoigtTensor TK,TL;
	UpdateData(TRUE);
	M.SetElem(0,0,m_m11); M.SetElem(0,1,m_m12); M.SetElem(0,2,m_m13);
	M.SetElem(1,0,m_m21); M.SetElem(1,1,m_m22); M.SetElem(1,2,m_m23);
	M.SetElem(2,0,m_m31); M.SetElem(2,1,m_m32); M.SetElem(2,2,m_m33);

	TK.SetVal(0,0,m_cc11); TK.SetVal(0,1,m_cc12); TK.SetVal(0,2,m_cc13); TK.SetVal(0,3,m_cc14); TK.SetVal(0,4,m_cc15); TK.SetVal(0,5,m_cc16);
	TK.SetVal(1,0,m_cc21); TK.SetVal(1,1,m_cc22); TK.SetVal(1,2,m_cc23); TK.SetVal(1,3,m_cc24); TK.SetVal(1,4,m_cc25); TK.SetVal(1,5,m_cc26);
	TK.SetVal(2,0,m_cc31); TK.SetVal(2,1,m_cc32); TK.SetVal(2,2,m_cc33); TK.SetVal(2,3,m_cc34); TK.SetVal(2,4,m_cc35); TK.SetVal(2,5,m_cc36);
	TK.SetVal(3,0,m_cc41); TK.SetVal(3,1,m_cc42); TK.SetVal(3,2,m_cc43); TK.SetVal(3,3,m_cc44); TK.SetVal(3,4,m_cc45); TK.SetVal(3,5,m_cc46);
	TK.SetVal(4,0,m_cc51); TK.SetVal(4,1,m_cc52); TK.SetVal(4,2,m_cc53); TK.SetVal(4,3,m_cc54); TK.SetVal(4,4,m_cc55); TK.SetVal(4,5,m_cc56);
	TK.SetVal(5,0,m_cc61); TK.SetVal(5,1,m_cc62); TK.SetVal(5,2,m_cc63); TK.SetVal(5,3,m_cc64); TK.SetVal(5,4,m_cc65); TK.SetVal(5,5,m_cc66);
	
	Tensor t;
	t.SpreadTensor(TK);
	t.Convert(M);
	TL=t.CurlTensor();
	m_cl11 = TL.GetVal(0,0); m_cl12 = TL.GetVal(0,1); m_cl13 = TL.GetVal(0,2); m_cl14 = TL.GetVal(0,3); m_cl15 = TL.GetVal(0,4); m_cl16 = TL.GetVal(0,5);
	m_cl21 = TL.GetVal(1,0); m_cl22 = TL.GetVal(1,1); m_cl23 = TL.GetVal(1,2); m_cl24 = TL.GetVal(1,3); m_cl25 = TL.GetVal(1,4); m_cl26 = TL.GetVal(1,5);
	m_cl31 = TL.GetVal(2,0); m_cl32 = TL.GetVal(2,1); m_cl33 = TL.GetVal(2,2); m_cl34 = TL.GetVal(2,3); m_cl35 = TL.GetVal(2,4); m_cl36 = TL.GetVal(2,5);
	m_cl41 = TL.GetVal(3,0); m_cl42 = TL.GetVal(3,1); m_cl43 = TL.GetVal(3,2); m_cl44 = TL.GetVal(3,3); m_cl45 = TL.GetVal(3,4); m_cl46 = TL.GetVal(3,5);
	m_cl51 = TL.GetVal(4,0); m_cl52 = TL.GetVal(4,1); m_cl53 = TL.GetVal(4,2); m_cl54 = TL.GetVal(4,3); m_cl55 = TL.GetVal(4,4); m_cl56 = TL.GetVal(4,5); 
	m_cl61 = TL.GetVal(5,0); m_cl62 = TL.GetVal(5,1); m_cl63 = TL.GetVal(5,2); m_cl64 = TL.GetVal(5,3); m_cl65 = TL.GetVal(5,4); m_cl66 = TL.GetVal(5,5);
	UpdateData(FALSE);
}
/**
*	Odczytanie tensora z pliku
*	powinien byæ zapisany w macierzy trókatnej (tensor symetryczny)
*/
void TensorElemDlg::OnFromFile() 
{
	VoigtTensor TK;
	CFileDialog	 fDlg(TRUE,NULL,NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"Pliki tekstowe (*.txt)|*.txt|Wszystkie pliki (*.*)|*.*||",NULL );
	if(fDlg.DoModal()==IDOK)
	{
		TK.ReadTensor(fDlg.GetPathName());
		m_cc11 = TK.GetVal(0,0); m_cc12 = TK.GetVal(0,1); m_cc13 = TK.GetVal(0,2); m_cc14 = TK.GetVal(0,3); m_cc15 = TK.GetVal(0,4); m_cc16 = TK.GetVal(0,5);
		m_cc21 = TK.GetVal(1,0); m_cc22 = TK.GetVal(1,1); m_cc23 = TK.GetVal(1,2); m_cc24 = TK.GetVal(1,3); m_cc25 = TK.GetVal(1,4); m_cc26 = TK.GetVal(1,5);
		m_cc31 = TK.GetVal(2,0); m_cc32 = TK.GetVal(2,1); m_cc33 = TK.GetVal(2,2); m_cc34 = TK.GetVal(2,3); m_cc35 = TK.GetVal(2,4); m_cc36 = TK.GetVal(2,5);
		m_cc41 = TK.GetVal(3,0); m_cc42 = TK.GetVal(3,1); m_cc43 = TK.GetVal(3,2); m_cc44 = TK.GetVal(3,3); m_cc45 = TK.GetVal(3,4); m_cc46 = TK.GetVal(3,5);
		m_cc51 = TK.GetVal(4,0); m_cc52 = TK.GetVal(4,1); m_cc53 = TK.GetVal(4,2); m_cc54 = TK.GetVal(4,3); m_cc55 = TK.GetVal(4,4); m_cc56 = TK.GetVal(4,5); 
		m_cc61 = TK.GetVal(5,0); m_cc62 = TK.GetVal(5,1); m_cc63 = TK.GetVal(5,2); m_cc64 = TK.GetVal(5,3); m_cc65 = TK.GetVal(5,4); m_cc66 = TK.GetVal(5,5);
		UpdateData(FALSE);
	}
}

/**
*	Zapisanie tensora do pliku
*/
void TensorElemDlg::OnSave() 
{

	VoigtTensor TL;
	CFileDialog	 fDlg(FALSE,".txt","tensor", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"Pliki tekstowe (*.txt)|*.txt||",NULL );
	if(fDlg.DoModal()==IDOK)
	{
		TL.SetVal(0,0,m_cl11); TL.SetVal(0,1,m_cl12); TL.SetVal(0,2,m_cl13); TL.SetVal(0,3,m_cl14); TL.SetVal(0,4,m_cl15); TL.SetVal(0,5,m_cl16);
		TL.SetVal(1,0,m_cl21); TL.SetVal(1,1,m_cl22); TL.SetVal(1,2,m_cl23); TL.SetVal(1,3,m_cl24); TL.SetVal(1,4,m_cl25); TL.SetVal(1,5,m_cl26);
		TL.SetVal(2,0,m_cl31); TL.SetVal(2,1,m_cl32); TL.SetVal(2,2,m_cl33); TL.SetVal(2,3,m_cl34); TL.SetVal(2,4,m_cl35); TL.SetVal(2,5,m_cl36);
		TL.SetVal(3,0,m_cl41); TL.SetVal(3,1,m_cl42); TL.SetVal(3,2,m_cl43); TL.SetVal(3,3,m_cl44); TL.SetVal(3,4,m_cl45); TL.SetVal(3,5,m_cl46);
		TL.SetVal(4,0,m_cl51); TL.SetVal(4,1,m_cl52); TL.SetVal(4,2,m_cl53); TL.SetVal(4,3,m_cl54); TL.SetVal(4,4,m_cl55); TL.SetVal(4,5,m_cl56);
		TL.SetVal(5,0,m_cl61); TL.SetVal(5,1,m_cl62); TL.SetVal(5,2,m_cl63); TL.SetVal(5,3,m_cl64); TL.SetVal(5,4,m_cl65); TL.SetVal(5,5,m_cl66);
		TL.PrintTensor(fDlg.GetPathName());
	}	
}

/**
*	Odczytanie macierzy przejœcia z pliku
*/
void TensorElemDlg::OnMatFromFile() 
{
	CFileDialog	 fDlg(TRUE,NULL,NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"Pliki tekstowe (*.txt)|*.txt|Wszystkie pliki (*.*)|*.*||",NULL );
	if(fDlg.DoModal()==IDOK)
	{
		Matrix M;
		M.ReadMatrix(fDlg.GetPathName());
		m_m11=M.GetElem(0,0); m_m12=M.GetElem(0,1); m_m13=M.GetElem(0,2);
		m_m21=M.GetElem(1,0); m_m22=M.GetElem(1,1); m_m23=M.GetElem(1,2);
		m_m31=M.GetElem(2,0); m_m32=M.GetElem(2,1); m_m33=M.GetElem(2,2);
		UpdateData(FALSE);
	}
}
/**
*	Zapisanie macierz yprzejœcia do pliku
*/
void TensorElemDlg::OnMatSave() 
{
	Matrix M;
	M.SetElem(0,0,m_m11); M.SetElem(0,1,m_m12); M.SetElem(0,2,m_m13);
	M.SetElem(1,0,m_m21); M.SetElem(1,1,m_m22); M.SetElem(1,2,m_m23);
	M.SetElem(2,0,m_m31); M.SetElem(2,1,m_m32); M.SetElem(2,2,m_m33);
	CFileDialog	 fDlg(FALSE,".txt","macierz", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"Pliki tekstowe (*.txt)|*.txt||",NULL );
	if(fDlg.DoModal()==IDOK)
		M.Print(fDlg.GetPathName());

}
/**
*	Automatyczne uzupe³nienie kontrolek odpowiadaj¹cym równowa¿nym wspó³czynnikom tensora 
*	
*/
void TensorElemDlg::OnKillfocusCc12() 
{
	UpdateData(TRUE);
	if(sysName=="regularny")
		m_cc21=m_cc31=m_cc13=m_cc32=m_cc23=m_cc12;
	else 
		m_cc21=m_cc12;
	UpdateData(FALSE);	
}

void TensorElemDlg::OnKillfocusCc13() 
{
	UpdateData(TRUE);
	if(sysName=="tetragonalny" || sysName=="heksagonalny" || sysName=="trygonalny")
		m_cc32=m_cc23=m_cc31=m_cc13;
	else if(sysName=="regularny")
		m_cc32=m_cc23=m_cc12=m_cc21=m_cc31=m_cc13;
	else
		m_cc31=m_cc13;
	UpdateData(FALSE);		
}

void TensorElemDlg::OnKillfocusCc14() 
{
	UpdateData(TRUE);
	m_cc41=m_cc14;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc15() 
{
	UpdateData(TRUE);
	m_cc51=m_cc15;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc16() 
{
	UpdateData(TRUE);
	m_cc61=m_cc16;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc21() 
{
	UpdateData(TRUE);
	if(sysName=="regularny")
		m_cc31=m_cc13=m_cc32=m_cc23=m_cc12=m_cc21;
	else 
		m_cc12=m_cc21;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc23() 
{
	UpdateData(TRUE);
	if(sysName=="tetragonalny" || sysName=="heksagonalny" || sysName=="trygonalny")
		m_cc31=m_cc13=m_cc32=m_cc23;
	else if(sysName=="regularny")
		m_cc12=m_cc21=m_cc31=m_cc13=m_cc32=m_cc23;
	else
		m_cc32=m_cc23;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc24() 
{
	UpdateData(TRUE);
	m_cc42=m_cc24;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc25() 
{
	UpdateData(TRUE);
	m_cc52=m_cc25;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc26() 
{
	UpdateData(TRUE);
	m_cc62=m_cc26;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc31() 
{
	UpdateData(TRUE);
	if(sysName=="tetragonalny" || sysName=="heksagonalny" || sysName=="trygonalny")
		m_cc32=m_cc13=m_cc32=m_cc31;
	else if(sysName=="regularny")
		m_cc12=m_cc21=m_cc23=m_cc13=m_cc32=m_cc31;
	else
		m_cc13=m_cc31;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc32() 
{
	UpdateData(TRUE);
	if(sysName=="tetragonalny" || sysName=="heksagonalny" || sysName=="trygonalny")
		m_cc31=m_cc13=m_cc23=m_cc32;
	else if(sysName=="regularny")
		m_cc12=m_cc21=m_cc31=m_cc13=m_cc23=m_cc32;
	else 
		m_cc23=m_cc32;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc34() 
{
	UpdateData(TRUE);
	m_cc43=m_cc34;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc35() 
{
	UpdateData(TRUE);
	m_cc53=m_cc35;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc36() 
{
	UpdateData(TRUE);
	m_cc63=m_cc36;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc41() 
{
	UpdateData(TRUE);
	m_cc14=m_cc41;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc42() 
{
	UpdateData(TRUE);
	m_cc24=m_cc42;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc43() 
{
	UpdateData(TRUE);
	m_cc34=m_cc43;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc45() 
{
	UpdateData(TRUE);
	m_cc54=m_cc45;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc46() 
{
	UpdateData(TRUE);
	m_cc64=m_cc46;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc51() 
{
	UpdateData(TRUE);
	m_cc15=m_cc51;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc52() 
{
	UpdateData(TRUE);
	m_cc25=m_cc52;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc53() 
{
	UpdateData(TRUE);
	m_cc35=m_cc53;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc54() 
{
	UpdateData(TRUE);
	m_cc45=m_cc54;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc56() 
{
	UpdateData(TRUE);
	m_cc65=m_cc56;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc61() 
{
	UpdateData(TRUE);
	m_cc16=m_cc61;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc62() 
{
	UpdateData(TRUE);
	m_cc26=m_cc62;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc63() 
{
	UpdateData(TRUE);
	m_cc36=m_cc63;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc64() 
{
	UpdateData(TRUE);
	m_cc46=m_cc64;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc65() 
{
	UpdateData(TRUE);
	m_cc56=m_cc65;
	UpdateData(FALSE);	
	
}

void TensorElemDlg::OnKillfocusCc11() 
{
	UpdateData(TRUE);
	if(sysName=="tetragonalny" || sysName=="trygonalny" || sysName=="heksagonalny")
		m_cc22=m_cc11;
	else if(sysName=="regularny")
		m_cc33=m_cc22=m_cc11;
	UpdateData(FALSE);	
}

void TensorElemDlg::OnKillfocusCc22() 
{
	UpdateData(TRUE);
	if(sysName=="tetragonalny" || sysName=="trygonalny" || sysName=="heksagonalny")
		m_cc11=m_cc22;
	else if(sysName=="regularny")
		m_cc11=m_cc33=m_cc22;
	UpdateData(FALSE);	
}

void TensorElemDlg::OnKillfocusCc33() 
{
	UpdateData(TRUE);
	if(sysName=="regularny")
		m_cc11=m_cc22=m_cc33;
	UpdateData(FALSE);	
}

void TensorElemDlg::OnKillfocusCc44() 
{
	UpdateData(TRUE);
	if(sysName=="tetragonalny" || sysName=="trygonalny" || sysName=="heksagonalny")
		m_cc55=m_cc44;
	else if(sysName=="regularny")
		m_cc55=m_cc66=m_cc44;
	UpdateData(FALSE);	
}

void TensorElemDlg::OnKillfocusCc55() 
{
	UpdateData(TRUE);
	if(sysName=="tetragonalny" || sysName=="trygonalny" || sysName=="heksagonalny")
		m_cc44=m_cc55;
	else if(sysName=="regularny")
		m_cc66=m_cc44=m_cc55;
	UpdateData(FALSE);	
}

void TensorElemDlg::OnKillfocusCc66() 
{
	UpdateData(TRUE);
	if(sysName=="regularny")
		m_cc55=m_cc44=m_cc66;
	UpdateData(FALSE);	
}

/**
*	Ustawienie klasy tensora oraz przepisanie macierzy przejscia przy aktywacji zak³adki
*/
BOOL TensorElemDlg::OnSetActive() 
{
	static CString prevSysName="default";
	m_m11=MGlobal.GetElem(0,0); m_m12=MGlobal.GetElem(0,1); m_m13=MGlobal.GetElem(0,2);
	m_m21=MGlobal.GetElem(1,0); m_m22=MGlobal.GetElem(1,1); m_m23=MGlobal.GetElem(1,2);
	m_m31=MGlobal.GetElem(2,0); m_m32=MGlobal.GetElem(2,1); m_m33=MGlobal.GetElem(2,2);
	UpdateData(FALSE);
	if(sysName=="trójskoœny")
		CWnd::CheckRadioButton(IDC_RADIO_MONO,IDC_RADIO_ORTHO,IDC_RADIO_TRI);
	else if(sysName=="jednoskoœny")
		CWnd::CheckRadioButton(IDC_RADIO_MONO,IDC_RADIO_ORTHO,IDC_RADIO_MONO);
	else if(sysName=="rombowy")
		CWnd::CheckRadioButton(IDC_RADIO_MONO,IDC_RADIO_ORTHO,IDC_RADIO_ORTHO);
	else if(sysName=="tetragonalny")
		CWnd::CheckRadioButton(IDC_RADIO_MONO,IDC_RADIO_ORTHO,IDC_RADIO_TETRA);
	else if(sysName=="regularny")
		CWnd::CheckRadioButton(IDC_RADIO_MONO,IDC_RADIO_ORTHO,IDC_RADIO_CUB);
	else if(sysName=="heksagonalny")
		CWnd::CheckRadioButton(IDC_RADIO_MONO,IDC_RADIO_ORTHO,IDC_RADIO_HEKSA);
	else if(sysName=="trygonalny")
		CWnd::CheckRadioButton(IDC_RADIO_MONO,IDC_RADIO_ORTHO,IDC_RADIO_TRIG);
	DisableCC();
	if(prevSysName!=sysName)
		ClearAllCC();
	prevSysName=sysName;
	return CPropertyPage::OnSetActive();
}
/**
*	Aktywacja wszystkich kontrolek tensora 
*/
void TensorElemDlg::EnableAllCC() 
{
	m_ecc14.EnableWindow(TRUE);m_ecc15.EnableWindow(TRUE);m_ecc16.EnableWindow(TRUE);
	m_ecc24.EnableWindow(TRUE);m_ecc25.EnableWindow(TRUE);m_ecc26.EnableWindow(TRUE);
	m_ecc34.EnableWindow(TRUE);m_ecc35.EnableWindow(TRUE);m_ecc36.EnableWindow(TRUE);
	m_ecc41.EnableWindow(TRUE);m_ecc42.EnableWindow(TRUE);m_ecc43.EnableWindow(TRUE);m_ecc45.EnableWindow(TRUE);m_ecc46.EnableWindow(TRUE);
	m_ecc51.EnableWindow(TRUE);m_ecc52.EnableWindow(TRUE);m_ecc53.EnableWindow(TRUE);m_ecc54.EnableWindow(TRUE);m_ecc56.EnableWindow(TRUE);
	m_ecc61.EnableWindow(TRUE);m_ecc62.EnableWindow(TRUE);m_ecc63.EnableWindow(TRUE);m_ecc64.EnableWindow(TRUE);m_ecc65.EnableWindow(TRUE);
}
/**
*	Deaktywacja kontrolek tensora w zale¿noœci od klasy symetrii
*/
void TensorElemDlg::DisableCC()
{
	EnableAllCC();
	if(sysName=="regularny" || sysName=="rombowy" || sysName=="heksagonalny")
	{
		m_ecc14.EnableWindow(FALSE);m_ecc15.EnableWindow(FALSE);m_ecc16.EnableWindow(FALSE);
		m_ecc24.EnableWindow(FALSE);m_ecc25.EnableWindow(FALSE);m_ecc26.EnableWindow(FALSE);
		m_ecc34.EnableWindow(FALSE);m_ecc35.EnableWindow(FALSE);m_ecc36.EnableWindow(FALSE);
		m_ecc41.EnableWindow(FALSE);m_ecc42.EnableWindow(FALSE);m_ecc43.EnableWindow(FALSE);m_ecc45.EnableWindow(FALSE);m_ecc46.EnableWindow(FALSE);
		m_ecc51.EnableWindow(FALSE);m_ecc52.EnableWindow(FALSE);m_ecc53.EnableWindow(FALSE);m_ecc54.EnableWindow(FALSE);m_ecc56.EnableWindow(FALSE);
		m_ecc61.EnableWindow(FALSE);m_ecc62.EnableWindow(FALSE);m_ecc63.EnableWindow(FALSE);m_ecc64.EnableWindow(FALSE);m_ecc65.EnableWindow(FALSE);
	}
	else if(sysName=="jednoskoœny")
	{
		m_ecc14.EnableWindow(FALSE);m_ecc16.EnableWindow(FALSE);
		m_ecc24.EnableWindow(FALSE);m_ecc26.EnableWindow(FALSE);
		m_ecc34.EnableWindow(FALSE);m_ecc36.EnableWindow(FALSE);
		m_ecc41.EnableWindow(FALSE);m_ecc42.EnableWindow(FALSE);m_ecc43.EnableWindow(FALSE);m_ecc45.EnableWindow(FALSE);
		m_ecc54.EnableWindow(FALSE);m_ecc56.EnableWindow(FALSE);
		m_ecc61.EnableWindow(FALSE);m_ecc62.EnableWindow(FALSE);m_ecc63.EnableWindow(FALSE);m_ecc65.EnableWindow(FALSE);
		
	}
	else if(sysName=="tetragonalny")
	{
		m_ecc14.EnableWindow(FALSE);m_ecc15.EnableWindow(FALSE);
		m_ecc24.EnableWindow(FALSE);m_ecc25.EnableWindow(FALSE);
		m_ecc34.EnableWindow(FALSE);m_ecc35.EnableWindow(FALSE);m_ecc36.EnableWindow(FALSE);
		m_ecc41.EnableWindow(FALSE);m_ecc42.EnableWindow(FALSE);m_ecc43.EnableWindow(FALSE);m_ecc45.EnableWindow(FALSE);m_ecc46.EnableWindow(FALSE);
		m_ecc51.EnableWindow(FALSE);m_ecc52.EnableWindow(FALSE);m_ecc53.EnableWindow(FALSE);m_ecc54.EnableWindow(FALSE);m_ecc56.EnableWindow(FALSE);
		m_ecc63.EnableWindow(FALSE);m_ecc64.EnableWindow(FALSE);m_ecc65.EnableWindow(FALSE);
	}
	else if(sysName=="trygonalny")
	{
		m_ecc16.EnableWindow(FALSE);
		m_ecc26.EnableWindow(FALSE);
		m_ecc34.EnableWindow(FALSE);m_ecc35.EnableWindow(FALSE);m_ecc36.EnableWindow(FALSE);
		m_ecc43.EnableWindow(FALSE);m_ecc45.EnableWindow(FALSE);
		m_ecc53.EnableWindow(FALSE);m_ecc54.EnableWindow(FALSE);
		m_ecc61.EnableWindow(FALSE);m_ecc62.EnableWindow(FALSE);m_ecc63.EnableWindow(FALSE);
	}

} 

/**
*	Wyzerowanie kontrolek
*/
void TensorElemDlg::ClearAllCC()
{
	m_cc11 = 0.0; m_cc12 = 0.0; m_cc13 = 0.0; m_cc14 = 0.0; m_cc15 = 0.0; m_cc16 = 0.0;
	m_cc21 = 0.0; m_cc22 = 0.0; m_cc23 = 0.0; m_cc24 = 0.0; m_cc25 = 0.0; m_cc26 = 0.0;
	m_cc31 = 0.0; m_cc32 = 0.0; m_cc33 = 0.0; m_cc34 = 0.0; m_cc35 = 0.0; m_cc36 = 0.0;
	m_cc41 = 0.0; m_cc42 = 0.0; m_cc43 = 0.0; m_cc44 = 0.0; m_cc45 = 0.0; m_cc46 = 0.0;
	m_cc51 = 0.0; m_cc52 = 0.0; m_cc53 = 0.0; m_cc54 = 0.0; m_cc55 = 0.0; m_cc56 = 0.0;
	m_cc61 = 0.0; m_cc62 = 0.0; m_cc63 = 0.0; m_cc64 = 0.0; m_cc65 = 0.0; m_cc66 = 0.0;
	UpdateData(FALSE);
}
/**
*	Obs³uga radio buttonów
*/
void TensorElemDlg::OnRadioCub() 
{
	UpdateData(TRUE);
	sysName="regularny";
	ClearAllCC();
	DisableCC();
}

void TensorElemDlg::OnRadioHeksa() 
{
	UpdateData(TRUE);
	sysName="heksagonalny";
	ClearAllCC();
	DisableCC();
}

void TensorElemDlg::OnRadioMono() 
{
	UpdateData(TRUE);
	sysName="jednoskoœny";
	ClearAllCC();
	DisableCC();
}

void TensorElemDlg::OnRadioOrtho() 
{
	UpdateData(TRUE);
	sysName="rombowy";
	ClearAllCC();
	DisableCC();
}

void TensorElemDlg::OnRadioTetra() 
{
	UpdateData(TRUE);
	sysName="tetragonalny";
	ClearAllCC();
	DisableCC();
}

void TensorElemDlg::OnRadioTri() 
{
	UpdateData(TRUE);
	sysName="trójskoœny";
	ClearAllCC();
	DisableCC();
}

void TensorElemDlg::OnRadioTrig() 
{
	UpdateData(TRUE);
	sysName="trygonalny";
	ClearAllCC();
	DisableCC();
}

BOOL TensorElemDlg::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
//	CWnd::CheckRadioButton(IDC_RADIO_MONO,IDC_RADIO_ORTHO,IDC_RADIO_DEF);	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

