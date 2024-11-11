#pragma once
#include "afxdialogex.h"


// KANQINAdd 对话框

class KANQINAdd : public CDialogEx
{
	DECLARE_DYNAMIC(KANQINAdd)

public:
	KANQINAdd(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~KANQINAdd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG12 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString str1;
	CString str2;
	CString str3;
	CString str4;
	CString str5;
	CString str6;
	CString str7;
	CString str8;
	CString str9;
	CString str10;
	CString str11;
	CString str12;
	CString str13;
	CString str14;
};
