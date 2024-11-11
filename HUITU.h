#pragma once
#include "afxdialogex.h"


// HUITU 对话框

class HUITU : public CDialogEx
{
	DECLARE_DYNAMIC(HUITU)

public:
	HUITU(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~HUITU();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HUITU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void OnPaint();
	CWnd* pWnd;
	afx_msg void OnStnClickedMystatic();
	afx_msg void OnBnClickedButton1();
};
