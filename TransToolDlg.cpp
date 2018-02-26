// TransToolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TransTool.h"
#include "TransToolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransToolDlg dialog

CTransToolDlg::CTransToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTransToolDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTransToolDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	matfinded=false;
}

void CTransToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTransToolDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTransToolDlg, CDialog)
	//{{AFX_MSG_MAP(CTransToolDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_VISUAL_WND, OnVisualWnd)
	ON_BN_CLICKED(IDC_TURN_OO, OnTurnOo)
	ON_BN_CLICKED(IDC_TURN_OX, OnTurnOx)
	ON_BN_CLICKED(IDC_TURN_OY, OnTurnOy)
	ON_BN_CLICKED(IDC_TURN_OZ, OnTurnOz)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransToolDlg message handlers

BOOL CTransToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	m_sheet.AddPage(&matpage);
	m_sheet.AddPage(&tenpage);

	m_sheet.Create(this,WS_CHILD|WS_VISIBLE,0);
	m_sheet.ModifyStyleEx(0,WS_EX_CONTROLPARENT);
	m_sheet.ModifyStyle(0,WS_TABSTOP);

	CRect rect;
	GetClientRect(&rect);
	m_sheet.SetWindowPos(NULL,rect.left,rect.top,0,0,SWP_NOZORDER|SWP_NOSIZE|SWP_NOACTIVATE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTransToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTransToolDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // device context for painting
		dc.SetBkMode(TRANSPARENT);
		CPen X_pen(PS_SOLID,2,RGB(255,0,0)), Y_pen(PS_SOLID,2,RGB(0,255,0)), Z_pen(PS_SOLID,2,RGB(0,0,255)),lab_pen(PS_SOLID,2,RGB(255,255,255));
		CPen *poldPen;
		// rysowanie szescianu
		poldPen=dc.SelectObject(&X_pen);
		dc.MoveTo(300,410);
		dc.LineTo(350,410);
		dc.TextOut(355,400,"uk³. krys. - X");
		dc.SelectObject(poldPen);

		poldPen=dc.SelectObject(&Y_pen);
		dc.MoveTo(300,425);
		dc.LineTo(350,425);
		dc.TextOut(355,415,"uk³. krys. - Y");
		dc.SelectObject(poldPen);

		poldPen=dc.SelectObject(&Z_pen);
		dc.MoveTo(300,440);
		dc.LineTo(350,440);
		dc.TextOut(355,430,"uk³. krys. - Z");
		dc.SelectObject(poldPen);

		poldPen=dc.SelectObject(&lab_pen);
		dc.MoveTo(300,455);
		dc.LineTo(350,455);
		dc.TextOut(355,445,"uk³. lab.");
		dc.SelectObject(poldPen);

		//CDialog::OnPaint();
	}
}

HCURSOR CTransToolDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTransToolDlg::OnVisualWnd() 
{
	matpage.OnVisualWnd();
}

void CTransToolDlg::OnTurnOo() 
{
	matpage.OnTurnOo();
	
}

void CTransToolDlg::OnTurnOx() 
{
	matpage.OnTurnOx();
	
}

void CTransToolDlg::OnTurnOy() 
{
	matpage.OnTurnOy();
	
}

void CTransToolDlg::OnTurnOz() 
{
	matpage.OnTurnOz();
	
}

