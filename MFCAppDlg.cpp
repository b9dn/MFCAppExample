
// MFCAppDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApp.h"
#include "MFCAppDlg.h"
#include "MFCAppDlgProgressBar.h"
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


// CMFCAppDlg dialog



CMFCAppDlg::CMFCAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPP_DIALOG, pParent)
	, m_editBoxTextChangeValue(_T(""))
	, m_currentTextIndex(0)
	, m_editBoxFirstNumber(1.0)
	, m_editBoxSecondNumber(1.0)
	, m_radioButtonMultiplyDivide(0)
	, m_staticTextResult(_T("Wynik: "))
	, m_progressBarDialog(nullptr)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_editBoxTextChangeControl);
	DDX_Text(pDX, IDC_EDIT1, m_editBoxTextChangeValue);
	DDX_Text(pDX, IDC_EDIT2, m_editBoxFirstNumber);
	DDV_MinMaxDouble(pDX, m_editBoxFirstNumber, 0.0, 100.0);
	DDX_Text(pDX, IDC_EDIT3, m_editBoxSecondNumber);
	DDV_MinMaxDouble(pDX, m_editBoxSecondNumber, 0.0, 100.0);
	DDX_Radio(pDX, IDC_RADIO1, m_radioButtonMultiplyDivide);
	DDX_Text(pDX, IDC_STATIC_RESULT, m_staticTextResult);
	DDX_Control(pDX, IDC_LISTCTRL, m_listControl);
}

BEGIN_MESSAGE_MAP(CMFCAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCAppDlg::OnBnClickedButtonChangeText)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCAppDlg::OnBnClickedButtonMessageBoxShow)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCAppDlg::OnBnClickedButtonCalculate)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCAppDlg::OnBnClickedRadioMultiply)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCAppDlg::OnBnClickedRadioDivide)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCAppDlg::OnBnClickedButtonGoToProgressBarWnd)
END_MESSAGE_MAP()

void CMFCAppDlg::InitializeTexts() {
    m_texts.push_back(_T("Pierwszy tekst"));
    m_texts.push_back(_T("Drugi tekst"));
    m_texts.push_back(_T("Trzeci tekst"));
    m_texts.push_back(_T("Czwarty tekst"));
    m_texts.push_back(_T("Piaty tekst"));
}


void CMFCAppDlg::InitializeListControl() {
    m_listControl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    m_listControl.InsertColumn(0, _T("Kolumna 1"), LVCFMT_LEFT, 100);
    m_listControl.InsertColumn(1, _T("Kolumna 2"), LVCFMT_LEFT, 100);
    m_listControl.InsertColumn(2, _T("Kolumna 3"), LVCFMT_LEFT, 100);
    m_listControl.InsertColumn(3, _T("Kolumna 4"), LVCFMT_LEFT, 100);
    m_listControl.InsertColumn(4, _T("Kolumna 5"), LVCFMT_LEFT, 100);

    for (int i = 0; i < 4; i++) {
        CString itemText;
        itemText.Format(_T("Element %d-1"), i + 1);
        int nItem = m_listControl.InsertItem(i, itemText);
        for (int j = 1; j < 5; j++) {
            CString subItemText;
            subItemText.Format(_T("Element %d-%d"), i + 1, j + 1);
            m_listControl.SetItemText(nItem, j, subItemText);
        }
    }
}

// CMFCAppDlg message handlers

BOOL CMFCAppDlg::OnInitDialog()
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
	InitializeTexts();
	InitializeListControl();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCAppDlg::OnPaint()
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
HCURSOR CMFCAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCAppDlg::OnBnClickedButtonChangeText() {
	m_editBoxTextChangeValue = m_texts[m_currentTextIndex];
    m_currentTextIndex = (m_currentTextIndex + 1) % m_texts.size();
    UpdateData(FALSE);
}


void CMFCAppDlg::OnBnClickedButtonMessageBoxShow()
{
	MessageBoxW(_T("Wcisnieto przycisk MessageBox"), _T("MessageBox"), MB_ICONINFORMATION | MB_OK);
}

void CMFCAppDlg::OnBnClickedButtonCalculate()
{
	UpdateData(TRUE);

	double first_number = m_editBoxFirstNumber;
	double second_number = m_editBoxSecondNumber;
	double result;
	if (m_radioButtonMultiplyDivide == 0) {
		result = first_number * second_number;
	}
	else {
		if (second_number == 0.0) {
			MessageBox(_T("Nie mozna dzielic przez 0. Wpisz inna liczbe."), NULL, MB_ICONWARNING | MB_OK);
			return;
		}
		result = first_number / second_number;
	}

	CString result_message;
	result_message.Format(_T("Wynik: %.2lf"), result);
	m_staticTextResult = result_message;

	UpdateData(FALSE);
}


void CMFCAppDlg::OnBnClickedRadioMultiply()
{
	m_radioButtonMultiplyDivide = 0;
	UpdateData(FALSE);
}


void CMFCAppDlg::OnBnClickedRadioDivide()
{
	m_radioButtonMultiplyDivide = 1;
	UpdateData(FALSE);
}


void CMFCAppDlg::OnBnClickedButtonGoToProgressBarWnd()
{
	if (m_progressBarDialog == nullptr) {
		m_progressBarDialog = new CMFCAppDlgProgressBar(this);
		if (m_progressBarDialog->Create(IDD_PROGRESS_BAR_DIALOG, this)) {
			m_progressBarDialog->ShowWindow(SW_SHOW);
		}
		else {
			delete m_progressBarDialog;
			m_progressBarDialog = nullptr;
		}
	}
	else {
		m_progressBarDialog->ShowWindow(SW_SHOW);
		m_progressBarDialog->SetForegroundWindow();
	}
}
