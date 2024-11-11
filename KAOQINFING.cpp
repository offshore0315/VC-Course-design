// KAOQINFING.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "KAOQINFING.h"


// KAOQINFING 对话框

IMPLEMENT_DYNAMIC(KAOQINFING, CDialogEx)

KAOQINFING::KAOQINFING(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG13, pParent)
	, fName(_T(""))
	, fID(_T(""))
{

}

KAOQINFING::~KAOQINFING()
{
}

void KAOQINFING::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, fName);
	DDX_Text(pDX, IDC_EDIT2, fID);
}


BEGIN_MESSAGE_MAP(KAOQINFING, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &KAOQINFING::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &KAOQINFING::OnBnClickedButton2)
END_MESSAGE_MAP()


// KAOQINFING 消息处理程序


void KAOQINFING::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void KAOQINFING::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
