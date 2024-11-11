// CHOOSE1.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CHOOSE1.h"


// CHOOSE1 对话框

IMPLEMENT_DYNAMIC(CHOOSE1, CDialogEx)

CHOOSE1::CHOOSE1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG16, pParent)
	, m_strxueyuan(_T(""))
{

}

CHOOSE1::~CHOOSE1()
{
}

void CHOOSE1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strxueyuan);
}


BEGIN_MESSAGE_MAP(CHOOSE1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CHOOSE1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CHOOSE1::OnBnClickedButton2)
END_MESSAGE_MAP()


// CHOOSE1 消息处理程序


void CHOOSE1::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_strxueyuan == "")
	{
		AfxMessageBox(_T("信息不完整，请重新输入"));
		return;
	}
	CDialogEx::OnOK();
}


void CHOOSE1::OnBnClickedButton2()
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
