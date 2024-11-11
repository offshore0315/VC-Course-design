// ZHUANYEadd.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "ZHUANYEadd.h"


// ZHUANYEadd 对话框

IMPLEMENT_DYNAMIC(ZHUANYEadd, CDialogEx)

ZHUANYEadd::ZHUANYEadd(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
	, m_zhuanyeadd(_T(""))
{

}

ZHUANYEadd::~ZHUANYEadd()
{
}

void ZHUANYEadd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Text(pDX, IDC_EDIT1, m_zhuanyeadd);
}


BEGIN_MESSAGE_MAP(ZHUANYEadd, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ZHUANYEadd::OnBnClickedButton1)
END_MESSAGE_MAP()


// ZHUANYEadd 消息处理程序


void ZHUANYEadd::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
