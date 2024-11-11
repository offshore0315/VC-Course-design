#pragma once
#include "afxdialogex.h"
#include"XUEYUANadd.h"
#include"XUEYUANxiugai.h"


// XUEYUAN 对话框

class XUEYUAN : public CDialogEx
{
	//DECLARE_SERIAL(XUEYUAN)
	DECLARE_DYNAMIC(XUEYUAN)


public:
	XUEYUAN(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~XUEYUAN();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl XUEYUAN_list;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	virtual void Serialize(CArchive& ar);
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
};
