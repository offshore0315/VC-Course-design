#pragma once
#include "afxdialogex.h"
#include"LOGINDlg.h"
#include"KANQINAdd.h"
#include"KAOQINFING.h"
#include"HUITU.h"



// KAOQIN 对话框

class KAOQIN : public CDialogEx
{
	DECLARE_DYNAMIC(KAOQIN)

public:
	KAOQIN(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~KAOQIN();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG11 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	CListCtrl KAOQIN_list;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton9();
	//afx_msg void OnBnClickedButton12();
};
