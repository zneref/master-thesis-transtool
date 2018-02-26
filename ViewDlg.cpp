// ViewDlg.cpp : implementation file
//
/**
*	\author Marian Ferenz
*/
#include "stdafx.h"
#include "TransTool.h"
#include "translib/matrix.h"
#include "translib/vector.h"
#include "ViewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ViewDlg dialog
int comp(const void* i,const void* j);
	static char label[3];

ViewDlg::ViewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ViewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ViewDlg)
	m_pPal=NULL;
	isCreated=-1;
	btnDown=false;
	ox=0; oy=1; oz=0,oo=0; angle=0;

	//}}AFX_DATA_INIT
}


void ViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ViewDlg)

	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ViewDlg, CDialog)
	//{{AFX_MSG_MAP(ViewDlg)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_WM_CLOSE()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ViewDlg message handlers
/**
*	Obs³uga rysowania w oknie
*/
void ViewDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
   // Select the palette.
    CPalette* ppalOld = NULL;
	if (m_pPal)
	{
    	ppalOld = dc.SelectPalette(m_pPal, 0);
    	dc.RealizePalette();
	}
	
	// Make the HGLRC current
    wglMakeCurrent(dc.m_hDC, m_hrc);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f) ;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	if(oo==1)
		glRotated(angle,1.0,1.0,1.0);
	else
		glRotated(angle,(double)ox,(double)oy,(double)oz);
	
	// drawing
	for(int i=0;i<3;i++)
		DrawHKL(M.GetElem(i,0),M.GetElem(i,1),M.GetElem(i,2));
	
	DrawElemCell();
	DrawCrysAxis();
	DrawLabAxis();
	SwapBuffers(dc.m_hDC);

    // select old palette if we altered it
    if (ppalOld) dc.SelectPalette(ppalOld, 0); 

	wglMakeCurrent(NULL, NULL) ;
}

int ViewDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
  CPaintDC dc(this) ;
   //
   // Fill in the pixel format descriptor.
   //
   PIXELFORMATDESCRIPTOR pfd ;
   memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR)) ;
   pfd.nSize      = sizeof(PIXELFORMATDESCRIPTOR); 
   pfd.nVersion   = 1 ; 
   pfd.dwFlags    = PFD_DOUBLEBUFFER |
                    PFD_SUPPORT_OPENGL |
                    PFD_DRAW_TO_WINDOW ;
   pfd.iPixelType = PFD_TYPE_RGBA ;
   pfd.cColorBits = 24 ;
   pfd.cDepthBits = 32 ;
   pfd.iLayerType = PFD_MAIN_PLANE ;

    int nPixelFormat = ChoosePixelFormat(dc.m_hDC, &pfd);
	if (nPixelFormat == 0)
		return -1 ;
    BOOL bResult = SetPixelFormat(dc.m_hDC, nPixelFormat, &pfd);
	if (!bResult)
		return -1 ;	
    // Create a rendering context.
    m_hrc = wglCreateContext(dc.m_hDC);
	if (!m_hrc)
		return -1;	
	return 0;
}

void ViewDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
    CPaintDC dc(this) ;
    BOOL bResult = wglMakeCurrent(dc.m_hDC, m_hrc);
	if (!bResult)
		return ;

   	glLoadIdentity();
 	glViewport(0, 0, cx, cy);	//size of glWorld
	// No rendering context will be current.
    wglMakeCurrent(NULL, NULL);	
	RefreshView();
}
/**
*	Rysowanie œcian hkl
*	\param h wskaŸnik h Millera
*	\param k wskaŸnik k Millera
*	\param l wskaŸnik l Millera
*/
void ViewDlg::DrawHKL(double h,double k, double l)
{
	Vector va=C*Vector(1,0,0); 
	Vector vb=C*Vector(0,1,0); 
	Vector vc=C*Vector(0,0,1);
	Vector vd=C*Vector(1,1,0); 
	Vector ve=C*Vector(1,0,1); 
	Vector vf=C*Vector(0,1,1); 
	Vector vg=C*Vector(1,1,1);
	
	double a=sqrt(va*va); double b=sqrt(vb*vb); double c=sqrt(vc*vc);
	double scale=TheBiggest(a,b,c);
	scale*=2;
	// draw hkl
	h*=scale;
	k*=scale;
	l*=scale;
	// draw hkl
	glLineWidth(1);
	glColor3d(0.4,0.4,0.4);
	if(h==0 && k==0)				//(00l)
	{
		Vector vcl=C*Vector(0,0,1/l);
		Vector vel=C*Vector(1/scale,0,1/l);
		Vector vgl=C*Vector(1/scale,1/scale,1/l);
		Vector vfl=C*Vector(0,1/scale,1/l);
		glBegin(GL_POLYGON);
			glVertex3d(vcl[0],vcl[1],vcl[2]);
			glVertex3d(vel[0],vel[1],vel[2]);
			glVertex3d(vgl[0],vgl[1],vgl[2]);
			glVertex3d(vfl[0],vfl[1],vfl[2]);
		glEnd();
	}
	else if(h==0 && l==0)			// (0k0) 
	{
		Vector vbk=C*Vector(0,1/k,0);
		Vector vdk=C*Vector(1/scale,1/k,0);
		Vector vgk=C*Vector(1/scale,1/k,1/scale);
		Vector vfk=C*Vector(0,1/k,1/scale);
		glBegin(GL_POLYGON);
			glVertex3d(vbk[0],vbk[1],vbk[2]);
			glVertex3d(vdk[0],vdk[1],vdk[2]);
			glVertex3d(vgk[0],vgk[1],vgk[2]);
			glVertex3d(vfk[0],vfk[1],vfk[2]);
		glEnd();
	}
	else if(k==0 && l==0)			// (h00)
	{
		Vector vah=C*Vector(1/h,0,0);
		Vector vdh=C*Vector(1/h,1/scale,0);
		Vector vgh=C*Vector(1/h,1/scale,1/scale);
		Vector veh=C*Vector(1/h,0,1/scale);
		glBegin(GL_POLYGON);
			glVertex3d(vah[0],vah[1],vah[2]);
			glVertex3d(vdh[0],vdh[1],vdh[2]);
			glVertex3d(vgh[0],vgh[1],vgh[2]);
			glVertex3d(veh[0],veh[1],veh[2]);
		glEnd();
	}
	else if(h==0 && k!=0 && l!=0)	// (0kl)
	{
		Vector vckl=C*Vector(0,0,1/l);
		Vector vekl=C*Vector(1/scale,0,1/l);
		Vector vdkl=C*Vector(1/scale,1/k,0);
		Vector vbkl=C*Vector(0,1/k,0);
		glBegin(GL_POLYGON);
			glVertex3d(vckl[0],vckl[1],vckl[2]);
			glVertex3d(vekl[0],vekl[1],vekl[2]);
			glVertex3d(vdkl[0],vdkl[1],vdkl[2]);
			glVertex3d(vbkl[0],vbkl[1],vbkl[2]);
		glEnd();
	}
	else if(h!=0 && k==0 && l!=0)	// (h0l)
	{
		Vector vchl=C*Vector(0,0,1/l);
		Vector vfhl=C*Vector(0,1/scale,1/l);	//
		Vector vdhl=C*Vector(1/h,1/scale,0);	//
		Vector vahl=C*Vector(1/h,0,0);
		glBegin(GL_POLYGON);
			glVertex3d(vchl[0],vchl[1],vchl[2]);
			glVertex3d(vfhl[0],vfhl[1],vfhl[2]);
			glVertex3d(vdhl[0],vdhl[1],vdhl[2]);
			glVertex3d(vahl[0],vahl[1],vahl[2]);
		glEnd();
	}
	else if(h!=0 && k!=0 && l==0)	// (hk0)
	{
		Vector vahk=C*Vector(1/h,0,0);
		Vector vehk=C*Vector(1/h,0,1/scale);	//
		Vector vfhk=C*Vector(0,1/k,1/scale);	//
		Vector vbhk=C*Vector(0,1/k,0);
		glBegin(GL_POLYGON);
			glVertex3d(vahk[0],vahk[1],vahk[2]);
			glVertex3d(vehk[0],vehk[1],vehk[2]);
			glVertex3d(vfhk[0],vfhk[1],vfhk[2]);
			glVertex3d(vbhk[0],vbhk[1],vbhk[2]);
		glEnd();
	}
	else							// (hkl)
	{
		glBegin(GL_POLYGON);
			glVertex3d(va[0]/h,va[1]/h,va[2]/h);
			glVertex3d(vb[0]/k,vb[1]/k,vb[2]/k);
			glVertex3d(vc[0]/l,vc[1]/l,vc[2]/l);
		glEnd();
	}
}
/**
*	Rysowanie komórki elementarnej
*/
void ViewDlg::DrawElemCell()
{
	Vector va=C*Vector(1,0,0); 
	Vector vb=C*Vector(0,1,0); 
	Vector vc=C*Vector(0,0,1);
	Vector vd=C*Vector(1,1,0); 
	Vector ve=C*Vector(1,0,1); 
	Vector vf=C*Vector(0,1,1); 
	Vector vg=C*Vector(1,1,1);
	
	double a=sqrt(va*va); double b=sqrt(vb*vb); double c=sqrt(vc*vc);
	double scale=TheBiggest(a,b,c);
	scale*=2;
	
	// draw elementary cell
	glLineWidth(1);
	glColor3d(1.0,1.0,0.0);
	glBegin(GL_LINES);
		glVertex3d(va[0]/scale,va[1]/scale,va[2]/scale);
		glVertex3d(vd[0]/scale,vd[1]/scale,vd[2]/scale);

		glVertex3d(va[0]/scale,va[1]/scale,va[2]/scale);
		glVertex3d(ve[0]/scale,ve[1]/scale,ve[2]/scale);

		glVertex3d(vc[0]/scale,vc[1]/scale,vc[2]/scale);
		glVertex3d(ve[0]/scale,ve[1]/scale,ve[2]/scale);

		glVertex3d(vb[0]/scale,vb[1]/scale,vb[2]/scale);
		glVertex3d(vd[0]/scale,vd[1]/scale,vd[2]/scale);

		glVertex3d(vd[0]/scale,vd[1]/scale,vd[2]/scale);
		glVertex3d(vg[0]/scale,vg[1]/scale,vg[2]/scale);

		glVertex3d(vc[0]/scale,vc[1]/scale,vc[2]/scale);
		glVertex3d(vf[0]/scale,vf[1]/scale,vf[2]/scale);

		glVertex3d(vb[0]/scale,vb[1]/scale,vb[2]/scale);
		glVertex3d(vf[0]/scale,vf[1]/scale,vf[2]/scale);

		glVertex3d(vg[0]/scale,vg[1]/scale,vg[2]/scale);
		glVertex3d(vf[0]/scale,vf[1]/scale,vf[2]/scale);

		glVertex3d(vg[0]/scale,vg[1]/scale,vg[2]/scale);
		glVertex3d(ve[0]/scale,ve[1]/scale,ve[2]/scale);
	glEnd();
}
/**
*	Rysowanie osi uk³adu krystalograficznego
*/
void ViewDlg::DrawCrysAxis()
{
	Vector va=C*Vector(1,0,0); Vector vb=C*Vector(0,1,0); Vector vc=C*Vector(0,0,1);
	double a=sqrt(va*va); double b=sqrt(vb*vb); double c=sqrt(vc*vc);
	double sc=TheBiggest(a,b,c);
	glLineWidth(2);
	glColor3d(1.0,0.0,0.0);
	glBegin(GL_LINES); //os X
		glVertex3d(-va[0]/a,-va[1]/a,-va[2]/a);
		glVertex3d(va[0]/a,va[1]/a,va[2]/a);
	glEnd();
	glColor3d(0.0,1.0,0.0);
	glBegin(GL_LINES); //os Y
		glVertex3d(-vb[0]/b,-vb[1]/b,-vb[2]/b);
		glVertex3d(vb[0]/b,vb[1]/b,vb[2]/b);
	glEnd();
	glColor3d(0.5,0.5,1.0);
	glBegin(GL_LINES); //os Z
		glVertex3d(-vc[0]/c,-vc[1]/c,-vc[2]/c);
		glVertex3d(vc[0]/c,vc[1]/c,vc[2]/c);
	glEnd();

}
/**
*	Rysowanie osi uk³adu labolatoryjnego
*/
void ViewDlg::DrawLabAxis()
{
	Vector vx=E*Vector(1,0,0); Vector vy=E*Vector(0,1,0); Vector vz=E*Vector(0,0,1);
	double x=sqrt(vx*vx); double y=sqrt(vy*vy); double z=sqrt(vz*vz);
	glLineWidth(1);
	glColor3d(1.0,1.0,1.0);
	glBegin(GL_LINES);
		glVertex3d(-vx[0]/x,-vx[1]/x,-vx[2]/x); glVertex3d(vx[0]/x,vx[1]/x,vx[2]/x); //x
		glVertex3d(-vy[0]/y,-vy[1]/y,-vy[2]/y); glVertex3d(vy[0]/y,vy[1]/y,vy[2]/y); //y
		glVertex3d(-vz[0]/z,-vz[1]/z,-vz[2]/z); glVertex3d(vz[0]/z,vz[1]/z,vz[2]/z); //z
	glEnd();
}
/**
*	Wyznaczenie najwiêkszej jednostki osiowej
*	potrzebne do przeskalowania komórki elementarnej przy rysowaniu
*	\param a jednostka osiowa a
*	\param b jednostka osiowa b
*	\param c jednostka osiowa c
*/
double ViewDlg::TheBiggest(double a,double b,double c)
{
	double tmp[]={a,b,c};
	qsort(tmp,3,sizeof(double),comp); 
	return tmp[2];
}
/**
*	funkcja porównuje dwa elementy 
*	\param i wskaŸnik na pierwszy element
*	\param j wskaŸnik na drugi element
*	Zwraca 1 jeœli i> j, w przeciwnym wypadku -1 
*/
int comp(const void* i,const void* j)
{
	double val1=(*(double*)i);
	double val2=(*(double*)j);
	if(val1<val2)
		return -1;
	else if(val1>val2)
		return 1;
	return 0;
}

void ViewDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	wglMakeCurrent(NULL,NULL) ; 
	if (m_hrc) 
	{
		wglDeleteContext(m_hrc) ;
		m_hrc = NULL ;
	}
	isCreated=-1;
	KillTimer(1);
	angle=0;
}
/**
*	Odœwierzenie rysunku
*
*/
void ViewDlg::RefreshView()
{
	Invalidate(FALSE);
}

void ViewDlg::OnClose() 
{
	CDialog::OnClose();
	wglMakeCurrent(NULL,NULL) ; 
	if (m_hrc) 
	{
		wglDeleteContext(m_hrc) ;
		m_hrc = NULL ;
	}

	isCreated=-1;
	KillTimer(1);
	angle=0;
}

void ViewDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if(btnDown)
	{
		SetTimer(1,100,NULL);
		btnDown=false;
	}
	else
	{
		KillTimer(1);
		btnDown=true;
	}
	CDialog::OnLButtonDown(nFlags, point);
}

BOOL ViewDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	angle=0;
	SetTimer(1,100,NULL);
	return TRUE;
}

void ViewDlg::OnTimer(UINT nIDEvent) 
{
	angle+=1;
	if(angle>=360)
		angle=0;
	RefreshView();
	CDialog::OnTimer(nIDEvent);
}

/**
*	Pobiera macierz krystalograficzn¹
*/
void ViewDlg::GetCMatrix(const Matrix& M)
{
	C=M;
	//Przekazana macierz jest macierz odwrotna i transponowana
	//powrot do macierzy wyjsciowej:
	C.Transp();
	C.TurnOver();
}
/**
*	Pobiera bazê uk³adu labolatoryjnego
*/
void ViewDlg::GetEMatrix(const Matrix& M)
{
	E=M;
}
/**
*	Pobiera bazê uk³adu krystalograficznego
*/
void ViewDlg::GetMMatrix(const Matrix& A)
{
	M=A;
}