#pragma once
#include "afxdialogex.h"


// QUXIAN 对话框

class QUXIAN : public CDialogEx
{
	DECLARE_DYNAMIC(QUXIAN)

public:
	QUXIAN(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~QUXIAN();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG14 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
