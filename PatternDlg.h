#pragma once
#include "ClientConnectionModule.h"

class CPatternDlg : public CDialogEx
{
public:
	CPatternDlg(CWnd* pParent = nullptr);

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PATTERN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);


protected:
	HICON m_hIcon;
	ClientConnectionModule* m_pConnectionModule;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
