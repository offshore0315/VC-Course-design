#pragma once
#include "afxdialogex.h"
#include"LOGINDlg.h"
#include"CHOOSE1.h"
#include"CHOOSE2.h"


// CHOOSE 对话框

class CHOOSE : public CDialogEx
{
	DECLARE_DYNAMIC(CHOOSE)

public:
	CHOOSE(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CHOOSE();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG15 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CTreeCtrl m_treechoose;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton3();
	//afx_msg void OnBnClickedButton4();
	//afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnTvnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult);
	void RefreshList(HTREEITEM parent);
	void ExpandAllltem(HTREEITEM parent);

};
