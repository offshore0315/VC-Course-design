// ZHUANYE.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "ZHUANYE.h"
#include"ZHUANYEadd.h"
#include"ZHUANYExiugai.h"


// ZHUANYE 对话框

IMPLEMENT_DYNAMIC(ZHUANYE, CDialogEx)

ZHUANYE::ZHUANYE(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

ZHUANYE::~ZHUANYE()
{
}

void ZHUANYE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(ZHUANYE, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ZHUANYE::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ZHUANYE::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &ZHUANYE::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &ZHUANYE::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &ZHUANYE::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &ZHUANYE::OnBnClickedButton6)
END_MESSAGE_MAP()


// ZHUANYE 消息处理程序


void ZHUANYE::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ZHUANYEadd dlg;
	dlg.DoModal();
	CString m = dlg.m_zhuanyeadd;
	if (dlg.m_zhuanyeadd.IsEmpty())
	{
		AfxMessageBox(_T("添加学院信息不能为空"));
		return;
	}
	int nCount = m_list.GetItemCount();
	m_list.InsertItem(nCount, m);
}


void ZHUANYE::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int nCount = m_list.GetItemCount();

	for (int i = 0; i < m_list.GetItemCount(); i++) // 遍历每一项，判断是否被选中
	{
		BOOL state = m_list.GetCheck(i);
		if (state)
		{
			m_list.DeleteItem(i); // 删除选定的项目
			i--;  // 因为for循环的原因，会导致程序从1.3.5.7.9这样子去判断每一项的状态，因此让程序返回一项判断，实现每一个项目的一个一个判断
		}
	}
}


void ZHUANYE::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < m_list.GetItemCount(); i++) // 遍历每一项，判断是否被选中
	{
		BOOL state = m_list.GetCheck(i);
		if (state)
		{
			ZHUANYExiugai dlg;
			dlg.DoModal();
			if (dlg.m_zhuanyexiugai.IsEmpty())
			{
				AfxMessageBox(_T("修改学院信息不能为空"));
				return;
			}

			// 对已有信息进行修改（编辑），即在选定的项上，因此不用用InestItem(),直接用SetItemText() 即可
			m_list.SetItemText(i, 0, dlg.m_zhuanyexiugai);
		}
	}
}


void ZHUANYE::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


BOOL ZHUANYE::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES | LVS_EX_FLATSB); // 扩展样式，整行选中加复选框
	m_list.InsertColumn(0, _T("专业名称"), 0, 200);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ZHUANYE::OnBnClickedButton5()//保存
{
	// TODO: 在此添加控件通知处理程序代码
	// 建立一个CFileDialog文件对象（对话框），再进行文件的读取，再做出相应的操作。但应该注意的是，“.txt”会报错，因为字符分字符集和多字节储存
	// (对象状态，文件类型，文件名字，覆盖功能，文件格式过滤，文件指针（这里不需要，用（空）NULL代表）)
	CFileDialog fDlg(FALSE, ".txt", "saveData", OFN_OVERWRITEPROMPT, "文本文档(*.txt)|*.txt|保存的数据(*.dat)|*.dat|所有文件(*.*)|*.*||", NULL);

	if (fDlg.DoModal() == IDOK) // 判断文件是否打开成功
	{
		CStdioFile file(fDlg.GetPathName(), CFile::modeWrite | CFile::modeCreate); // 创建一个操作文件的对象（所获取的文件路径，文件的读取方式，写与新建并写入）

		for (int i = 0; i < m_list.GetItemCount(); i++)  // 实现每一行数据的保持，写入文件，并且以逗号隔开
		{
			CString cs = ""; // 创建一个接受字符的空变量
			for (int j = 0; j < 6; j++)
			{
				cs += m_list.GetItemText(i, j) + "#";
				if (j == 4)
				{
					cs += m_list.GetItemText(i, 5) + "\n";
					j = 6;
				}
			}
			file.WriteString(cs); // 每一行写入一次
		}
		file.Close(); // 关闭文件流
		AfxMessageBox(_T("保存学校专业信息成功"));
	}
}


void ZHUANYE::OnBnClickedButton6()//打开
{
	// TODO: 在此添加控件通知处理程序代码
	// （对象状态，文件格式，文件名，因为打开操作没有覆盖操作，即用0代替，文件格式过滤，文件指针（无））
	CFileDialog fDlg(TRUE, ".txt", "saveData", 0, "文本文档(*.txt)|*.txt|保存的数据(*.dat)|*.dat|所有文件(*.*)|*.*||", NULL);

	if (fDlg.DoModal() == IDOK) // 判断文件是否打开成功
	{
		CStdioFile file(fDlg.GetPathName(), CFile::modeRead); // 创建文件对象，进行读取的操作
		CString cs; // 创建一个从文件取字符串的变量

		int i = 0;
		while (file.ReadString(cs)) // 利用C++中的Find() Left() Right() Mid()函数进行截取
		{
			int x = cs.Find("#");
			int x1 = x;
			m_list.InsertItem(i, cs.Left(x));
			for (int j = 1; j < 5; j++)
			{
				int x2 = cs.Find("#", x1 + 1);
				m_list.SetItemText(i, j, cs.Mid(x1 + 1, x2 - x1 - 1));
				x1 = x2;
				if (j == 4)
				{
					m_list.SetItemText(i, j + 1, cs.Right(cs.GetLength() - x1 - 1));
					j++;
				}
			}
			i++;
		}
	}
}
