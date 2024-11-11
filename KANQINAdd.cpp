// KANQINAdd.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "KANQINAdd.h"


// KANQINAdd 对话框

IMPLEMENT_DYNAMIC(KANQINAdd, CDialogEx)

KANQINAdd::KANQINAdd(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG12, pParent)
	, str1(_T(""))
	, str2(_T(""))
	, str3(_T(""))
	, str4(_T(""))
	, str5(_T(""))
	, str6(_T(""))
	, str7(_T(""))
	, str8(_T(""))
	, str9(_T(""))
	, str10(_T(""))
	, str11(_T(""))
	, str12(_T(""))
	, str13(_T(""))
	, str14(_T(""))
{

}

KANQINAdd::~KANQINAdd()
{
}

void KANQINAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, str1);
	DDX_Text(pDX, IDC_EDIT2, str2);
	DDX_Text(pDX, IDC_EDIT3, str3);
	DDX_Text(pDX, IDC_EDIT4, str4);
	DDX_Text(pDX, IDC_EDIT5, str5);
	DDX_Text(pDX, IDC_EDIT6, str6);
	DDX_Text(pDX, IDC_EDIT7, str7);
	DDX_Text(pDX, IDC_EDIT8, str8);
	DDX_Text(pDX, IDC_EDIT9, str9);
	DDX_Text(pDX, IDC_EDIT10, str10);
	DDX_Text(pDX, IDC_EDIT11, str11);
	DDX_Text(pDX, IDC_EDIT12, str12);
	DDX_Text(pDX, IDC_EDIT13, str13);
	DDX_Text(pDX, IDC_EDIT14, str14);
}


BEGIN_MESSAGE_MAP(KANQINAdd, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &KANQINAdd::OnBnClickedButton1)
END_MESSAGE_MAP()


// KANQINAdd 消息处理程序


void KANQINAdd::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
