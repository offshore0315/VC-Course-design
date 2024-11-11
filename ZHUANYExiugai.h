#pragma once
#include "afxdialogex.h"



// ZHUANYExiugai 对话框

class ZHUANYExiugai : public CDialogEx
{
	DECLARE_DYNAMIC(ZHUANYExiugai)

public:
	ZHUANYExiugai(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ZHUANYExiugai();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit m_Edit;
	CString m_zhuanyexiugai;
};
