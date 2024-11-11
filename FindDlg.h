#pragma once
#include "afxdialogex.h"


// FindDlg 对话框

class FindDlg : public CDialogEx
{
	DECLARE_DYNAMIC(FindDlg)

public:
	FindDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~FindDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG9 };
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
