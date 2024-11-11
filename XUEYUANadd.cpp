// XUEYUANadd.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "XUEYUANadd.h"


// XUEYUANadd 对话框

IMPLEMENT_DYNAMIC(XUEYUANadd, CDialogEx)

XUEYUANadd::XUEYUANadd(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, m_xueyuanadd(_T(""))
{

}

XUEYUANadd::~XUEYUANadd()
{
}

void XUEYUANadd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_xueyuanadd);
	DDX_Control(pDX, IDC_EDIT1, m_enit);
}


BEGIN_MESSAGE_MAP(XUEYUANadd, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &XUEYUANadd::OnBnClickedButton1)
END_MESSAGE_MAP()


// XUEYUANadd 消息处理程序


void XUEYUANadd::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString str;
	//m_enit.GetWindowText(str);//添加控件进行判断
	//if (str.IsEmpty())  //判断是否为空
	//{
	//	AfxMessageBox(_T("输入院系为空"));
	//	return;
	//}
	CDialogEx::OnOK();
}