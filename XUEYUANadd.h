#pragma once
#include "afxdialogex.h"


// XUEYUANadd 对话框

class XUEYUANadd : public CDialogEx
{
	DECLARE_DYNAMIC(XUEYUANadd)

public:
	XUEYUANadd(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~XUEYUANadd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_xueyuanadd;
	CEdit m_enit;
};
