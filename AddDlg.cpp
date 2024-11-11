// AddDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "AddDlg.h"


// AddDlg 对话框

IMPLEMENT_DYNAMIC(AddDlg, CDialogEx)

AddDlg::AddDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG8, pParent)
	, sName(_T(""))
	, sID(_T(""))
	, sSex(_T(""))
	, sAge(_T(""))
	, sMajor(_T(""))
	, sPhone(_T(""))
{

}

AddDlg::~AddDlg()
{
}

void AddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, sName);
	DDX_Text(pDX, IDC_EDIT2, sID);
	//  DDX_Control(pDX, IDC_EDIT3, sSex);
	DDX_Text(pDX, IDC_EDIT3, sSex);
	DDX_Text(pDX, IDC_EDIT4, sAge);
	DDX_Text(pDX, IDC_EDIT5, sMajor);
	DDX_Text(pDX, IDC_EDIT6, sPhone);
}


BEGIN_MESSAGE_MAP(AddDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &AddDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// AddDlg 消息处理程序


void AddDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
