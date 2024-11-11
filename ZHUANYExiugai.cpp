// ZHUANYExiugai.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "ZHUANYExiugai.h"


// ZHUANYExiugai 对话框

IMPLEMENT_DYNAMIC(ZHUANYExiugai, CDialogEx)

ZHUANYExiugai::ZHUANYExiugai(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG7, pParent)
	, m_zhuanyexiugai(_T(""))
{

}

ZHUANYExiugai::~ZHUANYExiugai()
{
}

void ZHUANYExiugai::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	DDX_Text(pDX, IDC_EDIT1, m_zhuanyexiugai);
}


BEGIN_MESSAGE_MAP(ZHUANYExiugai, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ZHUANYExiugai::OnBnClickedButton1)
END_MESSAGE_MAP()


// ZHUANYExiugai 消息处理程序


void ZHUANYExiugai::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
