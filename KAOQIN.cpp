// KAOQIN.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "KAOQIN.h"
#include"LOGINDlg.h"
#include"KANQINAdd.h"
#include"KAOQINFING.h"
#include"HUITU.h"

// KAOQIN 对话框

IMPLEMENT_DYNAMIC(KAOQIN, CDialogEx)

KAOQIN::KAOQIN(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG11, pParent)
{

}

KAOQIN::~KAOQIN()
{
}

void KAOQIN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, KAOQIN_list);
}


BEGIN_MESSAGE_MAP(KAOQIN, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &KAOQIN::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON5, &KAOQIN::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &KAOQIN::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &KAOQIN::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &KAOQIN::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON10, &KAOQIN::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &KAOQIN::OnBnClickedButton11)
	ON_WM_LBUTTONDBLCLK()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &KAOQIN::OnNMDblclkList1)
	ON_BN_CLICKED(IDC_BUTTON1, &KAOQIN::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &KAOQIN::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &KAOQIN::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &KAOQIN::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON9, &KAOQIN::OnBnClickedButton9)
	//ON_BN_CLICKED(IDC_BUTTON12, &KAOQIN::OnBnClickedButton12)
END_MESSAGE_MAP()


// KAOQIN 消息处理程序


void KAOQIN::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


BOOL KAOQIN::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	// TODO:  在此添加额外的初始化
	KAOQIN_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES | LVS_EX_FLATSB); // 扩展样式，整行选中加复选框
	KAOQIN_list.InsertColumn(0, _T("姓名"), 0, 75);
	KAOQIN_list.InsertColumn(1, _T("学号"), 0, 60);
	KAOQIN_list.InsertColumn(2, _T("1月出勤"), 0, 70);
	KAOQIN_list.InsertColumn(3, _T("2月出勤"), 0, 70);
	KAOQIN_list.InsertColumn(4, _T("3月出勤"), 0, 70);
	KAOQIN_list.InsertColumn(5, _T("4月出勤"), 0, 70);
	KAOQIN_list.InsertColumn(6, _T("5月出勤"), 0, 70);
	KAOQIN_list.InsertColumn(7, _T("6月出勤"), 0, 70);
	KAOQIN_list.InsertColumn(8, _T("7月出勤"), 0, 70);
	KAOQIN_list.InsertColumn(9, _T("8月出勤"), 0, 70);
	KAOQIN_list.InsertColumn(10, _T("9月出勤"), 0, 70);
	KAOQIN_list.InsertColumn(11, _T("10月出勤"), 0, 80);
	KAOQIN_list.InsertColumn(12, _T("11月出勤"), 0, 80);
	KAOQIN_list.InsertColumn(13, _T("12月出勤"), 0, 80);
	KAOQIN_list.InsertColumn(14, _T("总计"), 0, 60);

	//LOGINDlg dlg;
	//int rows = dlg.Student_list.GetItemCount();//行数
	//int cols = dlg.Student_list.GetHeaderCtrl()->GetItemCount();//列数
	//for (int i = 0; i < rows; i++) {
	//	//CString strInfor = dlg.Student_list.GetItemText(i, 0);
	//	//dlg.Student_list.InsertItem(i, );
	//}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void KAOQIN::OnBnClickedButton5()//增加
{
	// TODO: 在此添加控件通知处理程序代码
	KANQINAdd dlg;//创建对话框
	if (IDCANCEL == dlg.DoModal()) // 弹出对话框
	{
		return;
	}

	int nCount = KAOQIN_list.GetItemCount();

	if (dlg.str1.IsEmpty())
	{
		AfxMessageBox(_T("姓名不能为空!!!"));
		return;
	}

	if (dlg.str14.IsEmpty())
	{
		AfxMessageBox(_T("学号不能为空"));
		return;
	}

	if (dlg.str2.IsEmpty())
	{
		AfxMessageBox(_T("一月考勤不能为空"));
		return;
	}

	if (dlg.str3.IsEmpty())
	{
		AfxMessageBox(_T("二月考勤不能为空"));
		return;
	}

	if (dlg.str4.IsEmpty())
	{
		AfxMessageBox(_T("三月考勤不能为空"));
		return;
	}

	if (dlg.str5.IsEmpty())
	{
		AfxMessageBox(_T("四月考勤不能为空"));
		return;
	}
	if (dlg.str6.IsEmpty())
	{
		AfxMessageBox(_T("五月考勤不能为空"));
		return;
	}
	if (dlg.str7.IsEmpty())
	{
		AfxMessageBox(_T("六月考勤不能为空"));
		return;
	}
	if (dlg.str8.IsEmpty())
	{
		AfxMessageBox(_T("七月考勤不能为空"));
		return;
	}
	if (dlg.str9.IsEmpty())
	{
		AfxMessageBox(_T("八月考勤不能为空"));
		return;
	}
	if (dlg.str10.IsEmpty())
	{
		AfxMessageBox(_T("九月考勤不能为空"));
		return;
	}
	if (dlg.str11.IsEmpty())
	{
		AfxMessageBox(_T("十月考勤不能为空"));
		return;
	}
	if (dlg.str12.IsEmpty())
	{
		AfxMessageBox(_T("十一月考勤不能为空"));
		return;
	}
	if (dlg.str13.IsEmpty())
	{
		AfxMessageBox(_T("十二月考勤不能为空"));
		return;
	}

	// 判断学号是否唯一
	for (int i = 0; i < nCount; i++)
	{
		if (dlg.str14 == KAOQIN_list.GetItemText(i, 1))
		{
			AfxMessageBox(_T("学号重复，请输入正确的学号"));
			return;
		}
	}
	// 编辑信息
	KAOQIN_list.InsertItem(nCount, dlg.str1);
	KAOQIN_list.SetItemText(nCount, 1, dlg.str14);
	KAOQIN_list.SetItemText(nCount, 2, dlg.str2);
	KAOQIN_list.SetItemText(nCount, 3, dlg.str3);
	KAOQIN_list.SetItemText(nCount, 4, dlg.str4);
	KAOQIN_list.SetItemText(nCount, 5, dlg.str5);
	KAOQIN_list.SetItemText(nCount, 6, dlg.str6);
	KAOQIN_list.SetItemText(nCount, 7, dlg.str7);
	KAOQIN_list.SetItemText(nCount, 8, dlg.str8);
	KAOQIN_list.SetItemText(nCount, 9, dlg.str9);
	KAOQIN_list.SetItemText(nCount, 10, dlg.str10);
	KAOQIN_list.SetItemText(nCount, 11, dlg.str11);
	KAOQIN_list.SetItemText(nCount, 12, dlg.str12);
	KAOQIN_list.SetItemText(nCount, 13, dlg.str13);

}


void KAOQIN::OnBnClickedButton6()//删除
{
	// TODO: 在此添加控件通知处理程序代码
	int nCount = KAOQIN_list.GetItemCount();
	int flag = 1;
	for (int i = 0; i < nCount; i++) // 判断是否与单选框得选中，然后再进行删除方式的切换
	{
		if (KAOQIN_list.GetCheck(i) == 1)
		{
			flag = 0;
		}

	}
	if (flag)
	{
		KAOQIN::OnBnClickedButton8();
		for (int i = 0; i < KAOQIN_list.GetItemCount(); i++) // 遍历每一项，判断是否被选中
		{
			BOOL state = KAOQIN_list.GetCheck(i);
			if (state)
			{
				KAOQIN_list.DeleteItem(i); // 删除选定的项目
				i--;  // 因为for循环的原因，会导致程序从1.3.5.7.9这样子去判断每一项的状态，因此让程序返回一项判断，实现每一个项目的一个一个判断
			}
		}
	}
	if (!flag)
	{
		for (int i = 0; i < KAOQIN_list.GetItemCount(); i++) // 遍历每一项，判断是否被选中
		{
			BOOL state = KAOQIN_list.GetCheck(i);
			if (state)
			{
				KAOQIN_list.DeleteItem(i); // 删除选定的项目
				i--;  // 因为for循环的原因，会导致程序从1.3.5.7.9这样子去判断每一项的状态，因此让程序返回一项判断，实现每一个项目的一个一个判断
			}
		}
	}
}


void KAOQIN::OnBnClickedButton8()//查询
{
	// TODO: 在此添加控件通知处理程序代码
	int nCount = KAOQIN_list.GetItemCount();
	for (int i = 0; i < nCount; i++) // 清空上次所选项
	{
		// ((CButton*)GetDlgItem(IDC_RADIO))->SetCheck(0);
		if (KAOQIN_list.GetCheck(i) == 1)
		{
			KAOQIN_list.SetCheck(i, 0);
		}

	}

	FindDlg dlg;
	if (IDCANCEL == dlg.DoModal()) // 弹出对话框
	{
		return;
	}

	if (dlg.fID == "" && dlg.fName == "")
	{
		AfxMessageBox(_T("请输入所需要查询的学生信息"));
	}
	else
	{
		int uNum = 1;
		for (int i = 0; i < nCount; i++) // 通过和文本比较，选定寻找信息
		{
			if ((KAOQIN_list.GetItemText(i, 1) == dlg.fID || KAOQIN_list.GetItemText(i, 0) == dlg.fName))
			{
				KAOQIN_list.SetCheck(i);  // 避免了在用姓名查找时因为名字重复而导致漏选的情况
				uNum = 0;
			}
			if (i == nCount - 1)
			{
				if (uNum)
				{
					AfxMessageBox(_T("未找到相应记录"));
				}
			}

		}
	}
}


void KAOQIN::OnBnClickedButton7()//修改
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < KAOQIN_list.GetItemCount(); i++) // 遍历每一项，判断是否被选中
	{
		BOOL state = KAOQIN_list.GetCheck(i);
		if (state)
		{
			KANQINAdd dlg;
			if (IDCANCEL == dlg.DoModal()) // 弹出对话框
			{
				return;
			}

			if (dlg.str1.IsEmpty())
			{
				AfxMessageBox(_T("姓名不能为空!!!"));
				return;
			}

			if (dlg.str14.IsEmpty())
			{
				AfxMessageBox(_T("学号不能为空"));
				return;
			}

			if (dlg.str2.IsEmpty())
			{
				AfxMessageBox(_T("一月考勤不能为空"));
				return;
			}

			if (dlg.str3.IsEmpty())
			{
				AfxMessageBox(_T("二月考勤不能为空"));
				return;
			}

			if (dlg.str4.IsEmpty())
			{
				AfxMessageBox(_T("三月考勤不能为空"));
				return;
			}

			if (dlg.str5.IsEmpty())
			{
				AfxMessageBox(_T("四月考勤不能为空"));
				return;
			}
			if (dlg.str6.IsEmpty())
			{
				AfxMessageBox(_T("五月考勤不能为空"));
				return;
			}
			if (dlg.str7.IsEmpty())
			{
				AfxMessageBox(_T("六月考勤不能为空"));
				return;
			}
			if (dlg.str8.IsEmpty())
			{
				AfxMessageBox(_T("七月考勤不能为空"));
				return;
			}
			if (dlg.str9.IsEmpty())
			{
				AfxMessageBox(_T("八月考勤不能为空"));
				return;
			}
			if (dlg.str10.IsEmpty())
			{
				AfxMessageBox(_T("九月考勤不能为空"));
				return;
			}
			if (dlg.str11.IsEmpty())
			{
				AfxMessageBox(_T("十月考勤不能为空"));
				return;
			}
			if (dlg.str12.IsEmpty())
			{
				AfxMessageBox(_T("十一月考勤不能为空"));
				return;
			}
			if (dlg.str13.IsEmpty())
			{
				AfxMessageBox(_T("十二月考勤不能为空"));
				return;
			}

			//// 判断学号是否唯一
			//int nCount = KAOQIN_list.GetItemCount();
			//for (int i = 0; i < nCount; i++)
			//{
			//	if (dlg.str14 == KAOQIN_list.GetItemText(i, 1))
			//	{
			//		AfxMessageBox(_T("学号重复，请输入正确的学号"));
			//		return;
			//	}
			//}

			// 对已有信息进行修改（编辑），即在选定的项上，因此不用用InestItem(),直接用SetItemText() 即可
			KAOQIN_list.SetItemText(i, 0, dlg.str1);
			KAOQIN_list.SetItemText(i, 1, dlg.str14);
			KAOQIN_list.SetItemText(i, 2, dlg.str2);
			KAOQIN_list.SetItemText(i, 3, dlg.str3);
			KAOQIN_list.SetItemText(i, 4, dlg.str4);
			KAOQIN_list.SetItemText(i, 5, dlg.str5);
			KAOQIN_list.SetItemText(i, 6, dlg.str6);
			KAOQIN_list.SetItemText(i, 7, dlg.str7);
			KAOQIN_list.SetItemText(i, 8, dlg.str8);
			KAOQIN_list.SetItemText(i, 9, dlg.str9);
			KAOQIN_list.SetItemText(i, 10, dlg.str10);
			KAOQIN_list.SetItemText(i, 11, dlg.str11);
			KAOQIN_list.SetItemText(i, 12, dlg.str12);
			KAOQIN_list.SetItemText(i, 13, dlg.str13);
		}
	}
}


void KAOQIN::OnBnClickedButton10()//全选
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < KAOQIN_list.GetItemCount(); i++)
	{
		KAOQIN_list.SetCheck(i, TRUE);
	}
}


void KAOQIN::OnBnClickedButton11()//反选
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < KAOQIN_list.GetItemCount(); i++)
	{
		KAOQIN_list.SetCheck(i, !KAOQIN_list.GetCheck(i));
	}
}


void KAOQIN::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialogEx::OnLButtonDblClk(nFlags, point);
}

void KAOQIN::OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast <LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	int i = pNMItemActivate->iItem;

	KANQINAdd dlg;
	if (IDCANCEL == dlg.DoModal()) // 弹出对话框
	{
		return;
	}
	if (dlg.str1.IsEmpty())
	{
		AfxMessageBox(_T("姓名不能为空!!!"));
		return;
	}

	if (dlg.str14.IsEmpty())
	{
		AfxMessageBox(_T("学号不能为空"));
		return;
	}

	if (dlg.str2.IsEmpty())
	{
		AfxMessageBox(_T("一月考勤不能为空"));
		return;
	}

	if (dlg.str3.IsEmpty())
	{
		AfxMessageBox(_T("二月考勤不能为空"));
		return;
	}

	if (dlg.str4.IsEmpty())
	{
		AfxMessageBox(_T("三月考勤不能为空"));
		return;
	}

	if (dlg.str5.IsEmpty())
	{
		AfxMessageBox(_T("四月考勤不能为空"));
		return;
	}
	if (dlg.str6.IsEmpty())
	{
		AfxMessageBox(_T("五月考勤不能为空"));
		return;
	}
	if (dlg.str7.IsEmpty())
	{
		AfxMessageBox(_T("六月考勤不能为空"));
		return;
	}
	if (dlg.str8.IsEmpty())
	{
		AfxMessageBox(_T("七月考勤不能为空"));
		return;
	}
	if (dlg.str9.IsEmpty())
	{
		AfxMessageBox(_T("八月考勤不能为空"));
		return;
	}
	if (dlg.str10.IsEmpty())
	{
		AfxMessageBox(_T("九月考勤不能为空"));
		return;
	}
	if (dlg.str11.IsEmpty())
	{
		AfxMessageBox(_T("十月考勤不能为空"));
		return;
	}
	if (dlg.str12.IsEmpty())
	{
		AfxMessageBox(_T("十一月考勤不能为空"));
		return;
	}
	if (dlg.str13.IsEmpty())
	{
		AfxMessageBox(_T("十二月考勤不能为空"));
		return;
	}

	//// 判断学号是否唯一
	//int nCount = KAOQIN_list.GetItemCount();
	//for (int i = 0; i < nCount; i++)
	//{
	//	if (dlg.str14 == KAOQIN_list.GetItemText(i, 1))
	//	{
	//		AfxMessageBox(_T("学号重复，请输入正确的学号"));
	//		return;
	//	}
	//}

	KAOQIN_list.SetItemText(i, 0, dlg.str1);
	KAOQIN_list.SetItemText(i, 1, dlg.str14);
	KAOQIN_list.SetItemText(i, 2, dlg.str2);
	KAOQIN_list.SetItemText(i, 3, dlg.str3);
	KAOQIN_list.SetItemText(i, 4, dlg.str4);
	KAOQIN_list.SetItemText(i, 5, dlg.str5);
	KAOQIN_list.SetItemText(i, 6, dlg.str6);
	KAOQIN_list.SetItemText(i, 7, dlg.str7);
	KAOQIN_list.SetItemText(i, 8, dlg.str8);
	KAOQIN_list.SetItemText(i, 9, dlg.str9);
	KAOQIN_list.SetItemText(i, 10, dlg.str10);
	KAOQIN_list.SetItemText(i, 11, dlg.str11);
	KAOQIN_list.SetItemText(i, 12, dlg.str12);
	KAOQIN_list.SetItemText(i, 13, dlg.str13);
}

void KAOQIN::OnBnClickedButton1()//打开
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
			KAOQIN_list.InsertItem(i, cs.Left(x));
			for (int j = 1; j < 15; j++)
			{
				int x2 = cs.Find("#", x1 + 1);
				KAOQIN_list.SetItemText(i, j, cs.Mid(x1 + 1, x2 - x1 - 1));
				x1 = x2;
				if (j == 13)
				{
					KAOQIN_list.SetItemText(i, j + 1, cs.Right(cs.GetLength() - x1 - 1));
					j++;
				}
			}
			i++;
		}
	}
}


void KAOQIN::OnBnClickedButton2()//保存
{
	// TODO: 在此添加控件通知处理程序代码
	// 建立一个CFileDialog文件对象（对话框），再进行文件的读取，再做出相应的操作。但应该注意的是，“.txt”会报错，因为字符分字符集和多字节储存
	// (对象状态，文件类型，文件名字，覆盖功能，文件格式过滤，文件指针（这里不需要，用（空）NULL代表）)
	CFileDialog fDlg(FALSE, ".txt", "saveData", OFN_OVERWRITEPROMPT, "文本文档(*.txt)|*.txt|保存的数据(*.dat)|*.dat|所有文件(*.*)|*.*||", NULL);

	if (fDlg.DoModal() == IDOK) // 判断文件是否打开成功
	{
		CStdioFile file(fDlg.GetPathName(), CFile::modeWrite | CFile::modeCreate); // 创建一个操作文件的对象（所获取的文件路径，文件的读取方式，写与新建并写入）

		for (int i = 0; i < KAOQIN_list.GetItemCount(); i++)  // 实现每一行数据的保持，写入文件，并且以逗号隔开
		{
			CString cs = ""; // 创建一个接受字符的空变量
			for (int j = 0; j < 15; j++)
			{
				cs += KAOQIN_list.GetItemText(i, j) + "#";
				if (j == 13)
				{
					cs += KAOQIN_list.GetItemText(i, 14) + "\n";
					j = 15;
				}
			}
			file.WriteString(cs); // 每一行写入一次
		}
		file.Close(); // 关闭文件流
		AfxMessageBox(_T("保存学生信息成功"));
	}
}


void KAOQIN::OnBnClickedButton3()//曲线生成
{
	// TODO: 在此添加控件通知处理程序代码
	HUITU dlg;
	dlg.DoModal();
}


//void KAOQIN::OnBnClickedButton4()//退出
//{
//	// TODO: 在此添加控件通知处理程序代码
//	CDialog::OnCancel();
//}


void KAOQIN::OnBnClickedButton9()//学期总计
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < KAOQIN_list.GetItemCount(); i++)
	{
		CString str2 = KAOQIN_list.GetItemText(i, 2);
		CString str3 = KAOQIN_list.GetItemText(i, 3);
		CString str4 = KAOQIN_list.GetItemText(i, 4);
		CString str5 = KAOQIN_list.GetItemText(i, 5);
		CString str6 = KAOQIN_list.GetItemText(i, 6);
		CString str7 = KAOQIN_list.GetItemText(i, 7);
		CString str8 = KAOQIN_list.GetItemText(i, 8);
		CString str9 = KAOQIN_list.GetItemText(i, 9);
		CString str10 = KAOQIN_list.GetItemText(i, 10);
		CString str11 = KAOQIN_list.GetItemText(i, 11);
		CString str12 = KAOQIN_list.GetItemText(i, 12);
		CString str13 = KAOQIN_list.GetItemText(i, 13);

		int num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12, num13, totol;
		num2 = _ttoi(str2);
		num3 = _ttoi(str3);
		num4 = _ttoi(str4);
		num5 = _ttoi(str5);
		num6 = _ttoi(str6);
		num7 = _ttoi(str7);
		num8 = _ttoi(str8);
		num9 = _ttoi(str9);
		num10 = _ttoi(str10);
		num11 = _ttoi(str11);
		num12 = _ttoi(str12);
		num13 = _ttoi(str13);
		totol = num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9 + num10 + num11 + num12 + num13;
		CString str;
		str.Format("%d", totol);
		KAOQIN_list.SetItemText(i, 14, str);
	}
}
//int n = 0;
//CString str = _T("123");
//n = _ttoi(str);

//int n = 0;
//CString str;
//str.Format(_T(% d), n);

void KAOQIN::OnBnClickedButton4()//退出
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

//void KAOQIN::OnBnClickedButton12()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	My_Draw dlg;
//	dlg.DoModal();
//}
