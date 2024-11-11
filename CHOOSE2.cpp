// CHOOSE2.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CHOOSE2.h"


// CHOOSE2 对话框

IMPLEMENT_DYNAMIC(CHOOSE2, CDialogEx)

CHOOSE2::CHOOSE2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG17, pParent)
	, m_strzhuanye(_T(""))
{

}

CHOOSE2::~CHOOSE2()
{
}

void CHOOSE2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strzhuanye);
}


BEGIN_MESSAGE_MAP(CHOOSE2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CHOOSE2::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CHOOSE2::OnBnClickedButton2)
END_MESSAGE_MAP()


// CHOOSE2 消息处理程序


void CHOOSE2::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_strzhuanye == "")
	{
		AfxMessageBox(_T("信息不完整，请重新输入"));
		return;
	}
	CDialogEx::OnOK();
}


void CHOOSE2::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT i;
	i = MessageBox(TEXT("确认要取消添加吗？"), TEXT("温馨提示"), MB_YESNO | MB_ICONQUESTION);
	if (i == IDNO)
	{
		return;
	}
	EndDialog(0);
}
