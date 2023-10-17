
// MfcImageDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MfcImage.h"
#include "MfcImageDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMfcImageDlg dialog



CMfcImageDlg::CMfcImageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCIMAGE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfcImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMfcImageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_IMAGE, &CMfcImageDlg::OnBnClickedBtnImage)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CMfcImageDlg::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_LOAD, &CMfcImageDlg::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_BTN_ACTION, &CMfcImageDlg::OnBnClickedBtnAction)
END_MESSAGE_MAP()


// CMfcImageDlg message handlers

BOOL CMfcImageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMfcImageDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMfcImageDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMfcImageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMfcImageDlg::OnBnClickedBtnImage()
{
	// TODO: Add your control notification handler code here
	if (m_image != NULL) {
		m_image.Destroy();
	}
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8)
	{
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nWidth * nHeight);

	//for (int j = 0; j < nHeight; j++)
	//	for (int i = 0; i < nWidth; i++)
	//	{
	//		fm[j * nPitch + i] = j % 0xff;
	//	}

	//for (int j = 0; j < nHeight / 2; j++)
	//	for (int i = 0; i < nWidth / 2; i++)
	//		fm[j * nPitch + i] = 200;

	//CClientDC dc(this);
	//m_image.Draw(dc, 0, 0);
	UpdateDisplay();
}

CString g_strFileImage = _T("D://projects//mfc_app//MfcImage//Image//save.bmp");
void CMfcImageDlg::OnBnClickedBtnSave()
{
	// TODO: Add your control notification handler code here
	m_image.Save(g_strFileImage);
}


void CMfcImageDlg::OnBnClickedBtnLoad()
{
	// TODO: Add your control notification handler code here
	if (m_image != NULL)
		m_image.Destroy();
	m_image.Load(g_strFileImage);
	//CClientDC dc(this);
	//m_image.Draw(dc, 0, 0);
	UpdateDisplay();
}


void CMfcImageDlg::UpdateDisplay()
{
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);

}

void CMfcImageDlg::MoveRect()
{
	static int nSttX = 0;
	static int nSttY = 0;
	int nGray = 80;
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	memset(fm, 0xff, nWidth * nHeight);


	for (int j = nSttY; j < nSttY + 48; j++)
		for (int i = nSttX; i < nSttX + 64; i++)
			if (ValidImgPos(i, j))
				fm[j * nPitch + i] = nGray;
	nSttX++;
	nSttY++;
	UpdateDisplay();
}

void CMfcImageDlg::OnBnClickedBtnAction()
{
	// TODO: Add your control notification handler code here
	for (int i = 0; i < 480; i++)
	{
		//MoveRect();
		MoveCircle();
		Sleep(10);
	}
}


BOOL CMfcImageDlg::ValidImgPos(int x, int y)
{
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	CRect rect(0, 0, nWidth, nHeight);

	return rect.PtInRect(CPoint(x, y));
}


void CMfcImageDlg::DrawCircle(unsigned char* fm, int x, int y, int nRadius, int nColor)
{
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_image.GetPitch();
	CPoint center(nCenterX, nCenterY);

	for (int j = y; j < (y + 2 * nRadius); j++)
		for (int i = x; i < (x + 2 * nRadius); i++)
			if (Dis2Point(CPoint(i, j), center) < nRadius && ValidImgPos(i, j))
				fm[j * nPitch + i] = nColor;

}

BOOL CMfcImageDlg::Dis2Point(CPoint point1, CPoint point2)
{
	return (sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2)));
}


void CMfcImageDlg::MoveCircle()
{
	static int nSttX = 0;
	static int nSttY = 0;
	int nGray = 80;
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	int nRadius = 10;
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	//memset(fm, 0xff, nWidth * nHeight);

	DrawCircle(fm, nSttX++, nSttY++, nRadius, 0xff);
	DrawCircle(fm, nSttX, nSttY, nRadius, nGray);
	UpdateDisplay();
}
