// XUEYUANxiugai.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "XUEYUANxiugai.h"


// XUEYUANxiugai 对话框

IMPLEMENT_DYNAMIC(XUEYUANxiugai, CDialogEx)

XUEYUANxiugai::XUEYUANxiugai(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, m_XUEYUANxiugai(_T(""))
{

}

XUEYUANxiugai::~XUEYUANxiugai()
{
}

void XUEYUANxiugai::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_XUEYUANxiugai);
	DDX_Control(pDX, IDC_EDIT1, m_Enit);
}


BEGIN_MESSAGE_MAP(XUEYUANxiugai, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &XUEYUANxiugai::OnBnClickedButton1)
END_MESSAGE_MAP()


// XUEYUANxiugai 消息处理程序


void XUEYUANxiugai::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString str;
	//m_Enit.GetWindowText(str);//添加控件进行判断
	//if (str.IsEmpty())  //判断是否为空
	//{
	//	AfxMessageBox(_T("修改院系为空"));
	//	return;
	//}
	CDialogEx::OnOK();
}
