#pragma once
#include "afxdialogex.h"


// Picture 对话框

class Picture : public CDialogEx
{
	DECLARE_DYNAMIC(Picture)

public:
	Picture(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Picture();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG10 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
