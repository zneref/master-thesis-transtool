// TransMatDlg.cpp : implementation file
//
/**
*	\author Marian Ferenz
*/
#include "stdafx.h"
#include "TransTool.h"
#include "transmatdlg.h"
#include "cellparamdlg.h"
#include "resultdlg.h"
#include "assert.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString sysName=_T("");
Matrix MGlobal;
/////////////////////////////////////////////////////////////////////////////
// transmatdlg property page

IMPLEMENT_DYNCREATE(TransMatDlg, CPropertyPage)

TransMatDlg::TransMatDlg() : CPropertyPage(TransMatDlg::IDD)
{
	//{{AFX_DATA_INIT(TransMatDlg)
	ox_rect=new POINT[4];
	oy_rect=new POINT[4];
	oz_rect=new POINT[4];
	fillCol=new COLORREF[3];
	//}}AFX_DATA_INIT
	fillCol[0]=RGB(190,190,255);
	fillCol[1]=RGB(150,150,255);
	fillCol[2]=RGB(170,170,255);
	isClicked=0;
	oxClicked=FALSE;
	oyClicked=FALSE;
	ozClicked=FALSE;
	cellBtn=FALSE;
	pvDlg=new ViewDlg;
}

TransMatDlg::~TransMatDlg()
{

}

void TransMatDlg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TransMatDlg)
	DDX_Control(pDX, IDC_SYSTEM_LIST, m_sysList);
	DDX_Control(pDX, IDC_CLASS_LIST, m_classList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TransMatDlg, CPropertyPage)
	//{{AFX_MSG_MAP(TransMatDlg)
	ON_WM_PAINT()
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_RESETDATA, OnResetData)
	ON_BN_CLICKED(IDC_FIND_MATRIX, OnFindMatrix)
	ON_BN_CLICKED(IDC_CELL_PARAM, OnCellParam)
	ON_CBN_SELCHANGE(IDC_CLASS_LIST, OnSelchangeClassList)
	ON_CBN_SELCHANGE(IDC_SYSTEM_LIST, OnSelchangeSystemList)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// TransMatDlg message handlers
/**
*	Inicjalizacja zak³adki: Za³adowanie bitmap, utworzenie list uk³adów krystalograficznych,
*	klas kryszta³ow, narysowanie szeœcianu
*/
BOOL TransMatDlg::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	static char* sysNames[]={
		"tetragonalny","rombowy","trygonalny","jednoskoœny","trójskoœny","regularny","heksagonalny"
	};
	static char* classNames[]={
		/*----------------tetragonalny-----------------------*/
		"4/m B","4/m A","4 A","4 B","4i2m A","4i2m B","4i A",
		"4i B","4i C","4i D","4/mmm","422","4mm A","4mm B",
		/*----------------rombowy-----------------------*/
		"222","mm2 A","mm2 B","mmm",
		/*----------------trygonalny--------------------------*/
		"32 A","32 B","3im A","3im B","3m A","3m B","3m C","3m D",
		"3 A","3 B","3 C","3 D","3i A","3i B","3i C","3i D",
		/*----------------jednoskosny--------------------------*/
		"2","m A","m B","2/m",
		/*----------------trojskosny--------------------------*/
		"1","1i",
		/*----------------regularny--------------------------*/
		"23 A","23 B","m3 A","m3 B","4i3m A","4i3m B","432","m3m",
		/*----------------heksagonalny--------------------------*/
		"6 A","6 B","6/m A","6/m B","622","6mm A","6mm B","6im2 A",
		"6/mmm","6i A"
	};
	static int nBmp[]={
		/*----------------tetragonalny--------------------------------------*/
		IDB_4PERMB,IDB_4PERMA,IDB_4A,IDB_4B,IDB_4INV2MA,IDB_4INV2MB,IDB_4INVA,
		IDB_4INVB,IDB_4INVC,IDB_4INVD,IDB_4PERMMMA,IDB_422A,IDB_4MMA,IDB_4MMB,
		/*----------------rombowy-----------------------*/
		IDB_222,IDB_MM2A,IDB_MM2B,IDB_MMM,
		/*----------------trygonalny--------------------------*/
		IDB_32A,IDB_32B,IDB_3INVMA,IDB_3INVMB,IDB_3MA,IDB_3MB,IDB_3MC,IDB_3MD,
		IDB_3A,IDB_3B,IDB_3C,IDB_3D,IDB_3INVA,IDB_3INVB,IDB_3INVC,IDB_3INVD,
		/*----------------jednoskosny--------------------------*/
		IDB_2,IDB_MA,IDB_MB,IDB_2PERM,
		/*----------------trojskosny--------------------------*/
		IDB_1,IDB_1INV,
		/*----------------regularny--------------------------*/
		IDB_23A,IDB_23B,IDB_M3A,IDB_M3B,IDB_4INV3MA,IDB_4INV3MB,IDB_432,IDB_M3M,
		/*----------------heksagonalny--------------------------*/
		IDB_6A,IDB_6B,IDB_6PERMA,IDB_6PERMB,IDB_622,IDB_6MMA,IDB_6MMB,IDB_6INVM2A,
		IDB_6PERMMM,IDB_6INVA
	};

	int nSize[]={0,14,18,34,38,40,48,58};
	int sysPos;
	for(int i=0;i<7;i++)
	{
		ClassVec* pclassVec=new ClassVec;
		for(int j=nSize[i];j<nSize[i+1];j++)
		{
			ClassListElem* pclass=new ClassListElem(classNames[j],nBmp[j]);
			pclassVec->push_back(pclass);
		}
		psysElem=new SysListElem(sysNames[i],pclassVec);
		if(CB_ERR != (sysPos=m_sysList.AddString(psysElem->GetSysName())))
			m_sysList.SetItemDataPtr(sysPos,(void*) psysElem);
	}
	//wyswietlenie ukladu w kontrolce 
	m_sysList.SetCurSel(m_sysList.GetTopIndex());
	sysPos=m_sysList.GetCurSel();
	if(CB_ERR!=sysPos)
	{
		int classPos;
		psysElem=(SysListElem*)m_sysList.GetItemDataPtr(sysPos);
		sysName=psysElem->GetSysName();
		ClassVec* pclassVec=psysElem->GetPtrClassVec();
		if(pclassVec)
		{
			for(int i=0;i<pclassVec->size();i++)
			{
				ClassListElem* pclass=pclassVec->at(i);
				if(CB_ERR != (classPos=m_classList.AddString(pclass->GetClassName())))
					m_classList.SetItemDataPtr(classPos,(void*) pclass);			
			}
			// wyswietlenie pierwszej klasy i odpowiedniego dla niej rysunka
			m_classList.SetCurSel(m_sysList.GetTopIndex());
			classPos=m_classList.GetCurSel();
			if(CB_ERR!=sysPos)
			{
				ClassListElem* pclass=(ClassListElem*)m_classList.GetItemDataPtr(classPos);
				if(pclass)
					m_bm.LoadBitmap(pclass->GetNumBmp());
			}
		}
	}
	// ustawienie œcian szeœcianu
	ox_rect[0].x=300;
	ox_rect[0].y=160;
	ox_rect[1].x=300;
	ox_rect[1].y=260;
	ox_rect[2].x=400;
	ox_rect[2].y=260;
	ox_rect[3].x=400;
	ox_rect[3].y=160;

	oy_rect[0].x=400;
	oy_rect[0].y=260;
	oy_rect[1].x=400;
	oy_rect[1].y=160;
	oy_rect[2].x=450;
	oy_rect[2].y=110;
	oy_rect[3].x=450;
	oy_rect[3].y=210;

	oz_rect[0].x=300;
	oz_rect[0].y=160;
	oz_rect[1].x=350;
	oz_rect[1].y=110;
	oz_rect[2].x=450;
	oz_rect[2].y=110;
	oz_rect[3].x=400;
	oz_rect[3].y=160;

	// konstrukcja i otworzenie okla wizualizacji
	pvDlg->isCreated=pvDlg->Create(ViewDlg::IDD,NULL);
	pvDlg->RefreshView();
	return TRUE;  // return TRUE unless you set the focus to a control
}
/**
*	Obs³uga rysowania w dialogu
*/
void TransMatDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	dc.SetBkMode(TRANSPARENT);
	CPen rect_pen(PS_SOLID,1,RGB(0,0,0)), axis_pen(PS_SOLID,2,RGB(255,255,255));
	CBrush ox_brush(fillCol[0]),oy_brush(fillCol[1]),oz_brush(fillCol[2]);
	CBrush *poldBrush;
	CPen *poldPen;
	// rysowanie szescianu
	poldPen=dc.SelectObject(&rect_pen);
	poldBrush=dc.SelectObject(&ox_brush);
	dc.Polygon((LPPOINT)ox_rect,4);
	dc.SelectObject(&oy_brush);
	dc.Polygon((LPPOINT)oy_rect,4);
	dc.SelectObject(&oz_brush);
	dc.Polygon((LPPOINT)oz_rect,4);
	// rysowanie osi i etykiet
	dc.SelectObject(axis_pen);
	//os X
	dc.MoveTo(ox_rect[1]);
	dc.LineTo(ox_rect[1].x-40,ox_rect[1].y+40);
	dc.TextOut(ox_rect[1].x-25,ox_rect[1].y+30,"X");
	// os Y
	dc.MoveTo(oy_rect[3]);
	dc.LineTo(oy_rect[3].x+70,oy_rect[3].y);
	dc.TextOut(oy_rect[3].x+60,oy_rect[3].y+5,"Y");
	//os Z
	dc.MoveTo(oz_rect[1]);
	dc.LineTo(oz_rect[1].x,oz_rect[1].y-60);
	dc.TextOut(oz_rect[1].x+5,oz_rect[1].y-60,"Z");

	dc.SelectObject(poldBrush);
	dc.SelectObject(poldPen);
	//wyswietlenie bitmap
	DisplayBitmap(&dc,&m_bm,15,80);
}
/**
*	Pobranie wskaŸników Millera
*	funkcja rozpoznaje, która œciana zosta³a wskazana
*	i wywo³uje odpowiedni dla niej dialog do wprowadzenia wskaŸników Millera 
*/
void TransMatDlg::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	int h,k,l;
	if(PtInRegion(CreatePolygonRgn(ox_rect,4,WINDING),point.x,point.y))
	{
		if(!oyClicked || !ozClicked)
		{
			fillCol[0]=RGB(180,255,180);
			CRect rect(160,110,450,260);
			InvalidateRect(&rect,TRUE);
			if(IDOK==ox_dlg.DoModal())
			{
				h=ox_dlg.m_hox; k=ox_dlg.m_kox; l=ox_dlg.m_lox;
				M.SetElem(0,0,h);
				M.SetElem(0,1,k);
				M.SetElem(0,2,l);
				if(!oxClicked)
					isClicked++;
				oxClicked=TRUE;
			}
		}
	}
	else if(PtInRegion(CreatePolygonRgn(oy_rect,4,WINDING),point.x,point.y))
	{
		if(!oxClicked || !ozClicked)
		{
			fillCol[1]=RGB(120,255,120);
			CRect rect(160,110,450,260);
			InvalidateRect(&rect,TRUE);
			if(IDOK==oy_dlg.DoModal())
			{
				h=oy_dlg.m_hoy; k=oy_dlg.m_koy; l=oy_dlg.m_loy;
				M.SetElem(1,0,h);
				M.SetElem(1,1,k);
				M.SetElem(1,2,l);
				if(!oyClicked)
					isClicked++;
				oyClicked=TRUE;
			}
		}
	}
	else if(PtInRegion(CreatePolygonRgn(oz_rect,4,WINDING),point.x,point.y))
	{
		if(!oyClicked || !oxClicked)
		{
			fillCol[2]=RGB(150,255,150);
			CRect rect(160,110,450,260);
			InvalidateRect(&rect,TRUE);
			if(IDOK==oz_dlg.DoModal())
			{
				h=oz_dlg.m_hoz; k=oz_dlg.m_koz; l=oz_dlg.m_loz;
				M.SetElem(2,0,h);
				M.SetElem(2,1,k);
				M.SetElem(2,2,l);
				if(!ozClicked)
					isClicked++;
				ozClicked=TRUE;
			}
		}
	}
	CPropertyPage::OnLButtonDblClk(nFlags, point);
}
/**
*	Wyznaczenie macierzy przejœcia
*/
void TransMatDlg::OnFindMatrix() 
{
	if(isClicked<2)
	{
		AfxMessageBox("Podaj wskaŸniki Millera dwóch wybranych œcian\noraz parametry komórki elementarnej.");
		return;
	}
	if(!cellBtn)
		OnCellParam();
	///////////////////////////////////////////////////////////////////////////
	// 1. Wybór krystalograficznego uk³adu wspó³rzêdnych
	//	  w oparciu o klasê krysztalu		
	int classPos=m_classList.GetCurSel();
	ClassListElem* pclass=(ClassListElem*)m_classList.GetItemDataPtr(classPos);
	RotateMatrix RM=SetRMatrix(pclass->GetNumBmp());
	//obrót do wybranego wariantu uk³adu krystalograficznego 
	Matrix KR=K*RM; // krystal
	///////////////////////////////////////////////////////////////////////////
	// 2. Konstrukcja bazy uk³adu fizyczno-krystalograficznego
	Vector x,y,z;
	KR.MatToVec(x,y,z);
	x.Normalize(); y.Normalize(); z.Normalize();
	if((x*z)!=0 && (x*y)!=0) //trojskosny
	{
		Matrix OY=RotateMatrix(90,1);
		x=OY*z;
		// ortogonalizacja wektora x
		double a=(x*z)/(z*z);
		x.Scale(a);
		x=z-x;
		//wyznaczenie wektora y
		y=Vector::VectProduct(z,x);
	}
	else if((x*z)!=0) // jednoskoœny
		x=Vector::VectProduct(y,z);
	else if((x*y)!=0 && (x*z)==0) //trygonalny, heksagonalny, 
		y=Vector::VectProduct(z,x);
	// zapisujemy wersory uk³adu fizyczno-krystalicznego w macierzy
	Matrix T;
	T.VecToMat(x,y,z);
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	//4. Konstrukcja bazy uk³adu labolatoryjnego (wektory prostopadle do scian (hkl))
	//4a. Konstrukcja bazy sieci odwrotnej
	KR.TurnOver();
	KR.Transp();		// transpozycja potrzebna do dalszych operacji
	Matrix R=M*KR;		//macierz wektorów sieci odwrotnej=macierz wskaznikow Millera*macierz krystal.
	Vector rox,roy,roz;
	R.MatToVec(rox,roy,roz);
	//4b. Wyznaczenie 3 wektora bazy z iloczynu wektorowego
	//	  Dwa wektory wyznaczone s¹ z wskaŸników Millera, trzeci nie istnieje 
	if(!(rox*rox)/*nie istnieje*/ && !(roy*roz)/*wektory MUSZ¥ byc prostopad³e*/) 
	{
		// rox=roy x roz
		rox=Vector::VectProduct(roy,roz);
	}
	else if(!(roy*roy) && !(rox*roz))
	{
		// roy=roz x rox
		roy=Vector::VectProduct(roz,rox);
	}
	else if(!(roz*roz) && !(rox*roy))
	{
		// roz=rox x roy
		roz=Vector::VectProduct(rox,roy);
	}
	else
	{
		AfxMessageBox("Nieprawid³owe wskaŸniki Millera!\nŒciany MUSZ¥ byæ wzajemnie prostopad³e!");
		return;
	}
	// normalizacja wektorów
	rox.Normalize(); roy.Normalize(); roz.Normalize();
	// wersory (prostopad³e do œcian (hkl)) uk³adu labolatoryjnego zosta³y wyznaczone
	// zapisujemy je w macierzy
	Matrix E;
	E.VecToMat(rox,roy,roz);
	/////////////////////////////////////////////////////////////////////////////
	//5. Wyznaczenie macierzy przejscia z uk³adu fizyczno-krystal. do uk³adu lab.
	//   macierz przejscia = iloczyn odwróconej macierzy uk³adu fizyczno-kryst.
	//		                 i macierzy uk³adu labolatoryjnego.
	Matrix TO=T;	// macierz bazy uk³adu fizyczno-krystalograf
	TO.TurnOver();
	Matrix A=TO*E;
	MGlobal=A;	// 
	/////////////////////////////////////////////////////////////////////////////
	//6. Przekazanie danych do dialogów
	//okno wyników
	ResultDlg resDlg;
	resDlg.GetTMatrix(T);
	resDlg.GetEMatrix(E);
	resDlg.GetAMatrix(A);
	//okno wizualizacji
	pvDlg->GetCMatrix(KR);
	pvDlg->GetEMatrix(E);
	pvDlg->GetMMatrix(M);
	resDlg.DoModal();	
}

/**
*	
*/
void TransMatDlg::OnResetData() 
{
	fillCol[0]=RGB(190,190,255);
	fillCol[1]=RGB(150,150,255);
	fillCol[2]=RGB(170,170,255);
	isClicked=0;
	oxClicked=FALSE;
	oyClicked=FALSE;
	ozClicked=FALSE;
	UpdateData(FALSE);
	CRect rect(160,110,450,260);
	InvalidateRect(&rect,TRUE);
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			M.SetElem(i,j,0);
	cellBtn=FALSE;
}

/**
*	Wyœwietlenie bitmap z klasami symetrii
*/
void TransMatDlg::DisplayBitmap(CDC* pDC, CBitmap* pBitmap, int x,int y)
{
	BITMAP bm;
	CDC memDC;
	memDC.CreateCompatibleDC(NULL);
	memDC.SelectObject(pBitmap);
	pBitmap->GetObject(sizeof(bm),&bm);
	pDC->BitBlt(x,y,bm.bmWidth,bm.bmHeight,&memDC,0,0,SRCCOPY);
}
/**
*	wywo³anie dialogu do wprowadzenia parametrów komórki elementarnej
*	i konstrukcja macirzy krystalograficznej
*/
void TransMatDlg::OnCellParam() 
{
	int sysPos=m_sysList.GetCurSel();
	psysElem=(SysListElem*)m_sysList.GetItemDataPtr(sysPos);
	cellparamdlg dlg;
	dlg.SetCelInitParam(psysElem->GetSysName());
	int isCorrect=0;
	while(!isCorrect)
	{	
		dlg.DoModal();
		if(!dlg.CheckCelParam(psysElem->GetSysName()))
			AfxMessageBox("Nieprawid³owe parametry komórki elementarnej!");
		else
			isCorrect=1;
	}
	//konstrukcja macierzy krystalograficznej
	K=CrystMatrix(dlg.m_a,dlg.m_b,dlg.m_c,dlg.m_alpha,dlg.m_beta,dlg.m_gamma);
	cellBtn=TRUE;
}

/**
*	Obs³uga listy klas symetrii
*/
void TransMatDlg::OnSelchangeClassList() 
{
	int classPos=m_classList.GetCurSel();
	if(CB_ERR!=classPos)
	{
		ClassListElem* pclassElem=(ClassListElem*)m_classList.GetItemDataPtr(classPos);
		if(pclassElem)
		{
			m_bm.DeleteObject();
			m_bm.LoadBitmap(pclassElem->GetNumBmp());
			CRect rect(15,70,220,290);
			InvalidateRect(&rect,TRUE);
		}
	}
}
/**
*	Obs³uga listy uk³adów krystalograficznych
*/
void TransMatDlg::OnSelchangeSystemList() 
{
	m_classList.ResetContent();
	int sysPos=m_sysList.GetCurSel();
	if(CB_ERR!=sysPos)
	{
		int classPos;
		psysElem=(SysListElem*)m_sysList.GetItemDataPtr(sysPos);
		sysName=psysElem->GetSysName();
		ClassVec* pclassVec=psysElem->GetPtrClassVec();
		if(pclassVec)
		{
			for(int i=0;i<pclassVec->size();i++)
			{
				ClassListElem* pElem=pclassVec->at(i);
				if(CB_ERR != (classPos=m_classList.AddString(pElem->GetClassName())))
					m_classList.SetItemDataPtr(classPos,(void*) pElem);
			}
			m_classList.SetCurSel(m_classList.GetTopIndex());
			OnSelchangeClassList();
		}
		cellBtn=FALSE;
	}	
}
/**
*	Wyznaczenie macierzy obrotu w zale¿noœci od wybranego
*	uk³adu wspó³rzêdnych (ID bitmapy klasy sym)
*/
RotateMatrix TransMatDlg::SetRMatrix(int nId)
{
	RotateMatrix RM,M,N;
	switch(nId)
	{
	/******************************przekszta³cenie 1z******************************/
	/*tetragonalny*/
	case IDB_4PERMMMA:case IDB_422A:case IDB_4A:case IDB_4MMA:case IDB_4PERMA:case IDB_4INV2MA: case IDB_4INVA:
	/*rombowy*/
	case IDB_222:case IDB_MMM:case IDB_MM2A:
	/*trygonalny*/
	case IDB_32A:case IDB_3INVMA:case IDB_3MA:case IDB_3A:case IDB_3INVA:
	/*jednoskoœny*/
	case IDB_2:case IDB_2PERM:case IDB_MA:
	/*trojskoœny*/
	case IDB_1:case IDB_1INV:
	/*regularny*/
	case IDB_23A:case IDB_M3A:case IDB_432:case IDB_4INV3MA:case IDB_M3M:
	/*heksagonalny*/
	case IDB_6A:case IDB_6INVA:case IDB_6PERMA:case IDB_622:case IDB_6MMA:case IDB_6INVM2A:case IDB_6PERMMM:
		RM=RotateMatrix(360);
		break;
	/*****************************przekszta³cenie 2x*******************************/
	/*tetragonalny*/
	case IDB_4B:case IDB_4MMB:case IDB_4PERMB:case IDB_4INVC:
	/*heksagonalny*/
	case IDB_6B:case IDB_6PERMB:case IDB_6MMB:case IDB_6INVM2B:
	/*trygonalny*/
	case IDB_3C:case IDB_3INVC:case IDB_3MC:
		RM=RotateMatrix(180,0/*==X*/);
		break;
	/******************************przekszta³cenie 4z******************************/
	/*tetragonalny*/
	case IDB_4INV2MB:case IDB_4INVB:
	/*regularny*/
	case IDB_23B:case IDB_M3B:case IDB_4INV3MB:
		RM=RotateMatrix(90);
		break;
	/*******************************przekszta³cenie 2y******************************/
	/*rombowy*/
	case IDB_MM2B:
	/*jednoskosny*/
	case IDB_MB:
	/*trygonalny*/
	case IDB_3D:case IDB_3INVD:case IDB_3MD:
		RM=RotateMatrix(180,1/*==Y*/);
		break;
	/*******************************przekszta³cenie 2u=4z*2y************************/
	/*tetragonalny*/
	case IDB_4INVD:
		M=RotateMatrix(90);
		N=RotateMatrix(180,1/*==Y*/);
		RM=M*N;
		break;
	/*******************************przekszta³cenie 2z******************************/
	/*trygonalny*/
	case IDB_3B:case IDB_32B:case IDB_3INVB:case IDB_3INVMB:case IDB_3MB:
		RM=RotateMatrix(180,2/*==Z*/);
		break;
	default:
		break;
	};
	return RM;
}

/**
*	W³¹czenie /wy³aczenie okna wizualizacji
*/
void TransMatDlg::OnVisualWnd() 
{
	//update view in the window
	if(pvDlg->isCreated==-1)
	{
		pvDlg->isCreated=pvDlg->Create(ViewDlg::IDD,NULL);
		pvDlg->RefreshView();
	}
	else
	{
		pvDlg->DestroyWindow();
		pvDlg->isCreated=-1;
	}	
}

/**
*	Obrót wokó³ pocz¹tku uk³adu wspó³rzêdnych w 
*	oknie wizualizacji
*/
void TransMatDlg::OnTurnOo()
{
	pvDlg->ox=0; pvDlg->oy=0; pvDlg->oz=0; pvDlg->oo=1;	
}
/**
*	Obrót wokó³ osi x w oknie wizualizacji
*/
void TransMatDlg::OnTurnOx()
{
	pvDlg->ox=1; pvDlg->oy=0; pvDlg->oz=0; pvDlg->oo=0;	
}
/**
*	Obrót wokó³ osi y w oknie wizualizacji
*/
void TransMatDlg::OnTurnOy()
{
	pvDlg->ox=0; pvDlg->oy=1; pvDlg->oz=0; pvDlg->oo=0;
}
/**
*	Obrót wokó³ osi z w oknie wizualizacji
*/
void TransMatDlg::OnTurnOz()
{
	pvDlg->ox=0; pvDlg->oy=0; pvDlg->oz=1; pvDlg->oo=0;	
}
/**
*	Zniszczenie okna po uprzedniej dealokacji pamiêci
*/
void TransMatDlg::OnDestroy() 
{
	CPropertyPage::OnDestroy();
	//zwolnienie pamiêci
	while(m_sysList.GetCount())
	{
		m_sysList.SetCurSel(m_sysList.GetTopIndex());
		int sysPos=m_sysList.GetCurSel();
		if(CB_ERR!=sysPos)
		{
			psysElem=(SysListElem*)m_sysList.GetItemDataPtr(sysPos);	
			psysElem->GetPtrClassVec()->clear();
			m_sysList.DeleteString(sysPos);
			m_sysList.Clear();
			delete psysElem;
		}
	}

	delete[] ox_rect;
	delete[] oy_rect;
	delete[] oz_rect;
	delete[] fillCol;
	delete pvDlg;
}
