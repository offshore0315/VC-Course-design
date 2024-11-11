#pragma once
#include "afxdialogex.h"


// sPicture 对话框

class sPicture : public CDialogEx
{
	DECLARE_DYNAMIC(sPicture)

public:
	sPicture(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~sPicture();

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
