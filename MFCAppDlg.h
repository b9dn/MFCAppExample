
// MFCAppDlg.h : header file
//

#pragma once
#include <vector>
#include "MFCAppDlgProgressBar.h"


// CMFCAppDlg dialog
class CMFCAppDlg : public CDialogEx
{
// Construction
public:
	CMFCAppDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPP_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	void InitializeTexts();
	std::vector<CString> m_texts;
	int m_currentTextIndex;
	void InitializeListControl();
	CEdit m_editBoxTextChangeControl;
	CString m_editBoxTextChangeValue;
	double m_editBoxFirstNumber;
	double m_editBoxSecondNumber;
	int m_radioButtonMultiplyDivide;
	CString m_staticTextResult;
	CListCtrl m_listControl;

	CMFCAppDlgProgressBar* m_progressBarDialog;
public:
	afx_msg void OnBnClickedButtonChangeText();
	afx_msg void OnBnClickedButtonMessageBoxShow();
	afx_msg void OnBnClickedButtonCalculate();
	afx_msg void OnBnClickedRadioMultiply();
	afx_msg void OnBnClickedRadioDivide();
	afx_msg void OnBnClickedButtonGoToProgressBarWnd();
};
