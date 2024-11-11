#pragma once
#include "afxdialogex.h"
#include"XUEYUAN.h"
#include"ZHUANYE.h"
#include"AddDlg.h"
#include"FindDlg.h"
#include"MFCApplication1Dlg.h"
#include"CSaveHelper.h"
#include"sPicture.h"
#include"KAOQIN.h"


// LOGINDlg 对话框

class LOGINDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LOGINDlg)

public:
	LOGINDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LOGINDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl Student_list;
	void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	//	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	//	virtual void Serialize(CArchive& ar);
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton7();
	//afx_msg void OnBnClickedButton8();
};
