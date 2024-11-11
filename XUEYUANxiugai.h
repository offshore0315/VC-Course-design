#pragma once
#include "afxdialogex.h"


// XUEYUANxiugai 对话框

class XUEYUANxiugai : public CDialogEx
{
	DECLARE_DYNAMIC(XUEYUANxiugai)

public:
	XUEYUANxiugai(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~XUEYUANxiugai();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_XUEYUANxiugai;
	CEdit m_Enit;
	afx_msg void OnBnClickedButton1();
};
