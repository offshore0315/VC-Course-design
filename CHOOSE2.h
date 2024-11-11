#pragma once
#include "afxdialogex.h"


// CHOOSE2 对话框

class CHOOSE2 : public CDialogEx
{
	DECLARE_DYNAMIC(CHOOSE2)

public:
	CHOOSE2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CHOOSE2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG17 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strzhuanye;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
