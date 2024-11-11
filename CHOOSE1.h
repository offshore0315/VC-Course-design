#pragma once
#include "afxdialogex.h"


// CHOOSE1 对话框

class CHOOSE1 : public CDialogEx
{
	DECLARE_DYNAMIC(CHOOSE1)

public:
	CHOOSE1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CHOOSE1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG16 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CString m_strxueyuan;
};
