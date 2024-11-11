// FindDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "FindDlg.h"


// FindDlg 对话框

IMPLEMENT_DYNAMIC(FindDlg, CDialogEx)

FindDlg::FindDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG9, pParent)
	, fName(_T(""))
	, fID(_T(""))
{

}

FindDlg::~FindDlg()
{
}

void FindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, fName);
	DDX_Text(pDX, IDC_EDIT2, fID);
}


BEGIN_MESSAGE_MAP(FindDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &FindDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &FindDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// FindDlg 消息处理程序


void FindDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void FindDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
