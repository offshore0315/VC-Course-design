#pragma once
#include "afxdialogex.h"


// ZHUANYEadd 对话框

class ZHUANYEadd : public CDialogEx
{
	DECLARE_DYNAMIC(ZHUANYEadd)

public:
	ZHUANYEadd(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ZHUANYEadd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	CString m_zhuanyeadd;
	afx_msg void OnBnClickedButton1();
};
