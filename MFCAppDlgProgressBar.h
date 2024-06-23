#pragma once
#include "afxdialogex.h"


// CMFCAppDlgProgressBar dialog

class CMFCAppDlgProgressBar : public CDialogEx
{
	DECLARE_DYNAMIC(CMFCAppDlgProgressBar)

public:
	CMFCAppDlgProgressBar(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMFCAppDlgProgressBar();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROGRESS_BAR_WINDOW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	void OnTimer(UINT_PTR nIDEvent);

	DECLARE_MESSAGE_MAP()
public:
private:
	CProgressCtrl m_progressCtrl;
	int m_progressPos;
};
