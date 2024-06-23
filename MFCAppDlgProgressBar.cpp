// CMFCAppDlgProgressBar.cpp : implementation file
//

#include "pch.h"
#include "MFCApp.h"
#include "MFCAppDlgProgressBar.h"
#include "afxdialogex.h"


// CMFCAppDlgProgressBar dialog

IMPLEMENT_DYNAMIC(CMFCAppDlgProgressBar, CDialogEx)

CMFCAppDlgProgressBar::CMFCAppDlgProgressBar(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROGRESS_BAR_DIALOG, pParent)
	, m_progressPos(0)
{

}

CMFCAppDlgProgressBar::~CMFCAppDlgProgressBar()
{
}

void CMFCAppDlgProgressBar::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS_BAR, m_progressCtrl);
}

BOOL CMFCAppDlgProgressBar::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_progressCtrl.SetRange(0, 100);
	m_progressCtrl.SetPos(0);

	SetTimer(1, 200, nullptr);

	return TRUE;
}


BEGIN_MESSAGE_MAP(CMFCAppDlgProgressBar, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMFCAppDlgProgressBar message handlers

void CMFCAppDlgProgressBar::OnTimer(UINT_PTR nIDEvent) {
	if (nIDEvent == 1) {
		m_progressPos += 2;
		if (m_progressPos > 100) {
			m_progressPos = 0;
		}
		m_progressCtrl.SetPos(m_progressPos);
	}
}
