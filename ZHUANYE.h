#pragma once
#include "afxdialogex.h"
#include"ZHUANYEadd.h"
#include"ZHUANYExiugai.h"


// ZHUANYE 对话框

class ZHUANYE : public CDialogEx
{
	DECLARE_DYNAMIC(ZHUANYE)
	//DECLARE_SERIAL(XUEYUAN)

public:
	ZHUANYE(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ZHUANYE();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	virtual BOOL OnInitDialog();
//	virtual void Serialize(CArchive& ar);
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
};
