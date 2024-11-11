#pragma once
#include "afxdialogex.h"


// KAOQINFING 对话框

class KAOQINFING : public CDialogEx
{
	DECLARE_DYNAMIC(KAOQINFING)

public:
	KAOQINFING(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~KAOQINFING();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG13 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CString fName;
	CString fID;
};
