// LOGINDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "LOGINDlg.h"
#include"XUEYUAN.h"
#include"ZHUANYE.h"
#include"AddDlg.h"
#include"FindDlg.h"
#include"MFCApplication1Dlg.h"
#include"CSaveHelper.h"
#include"sPicture.h"
#include"KAOQIN.h"


// LOGINDlg 对话框

IMPLEMENT_DYNAMIC(LOGINDlg, CDialogEx)

LOGINDlg::LOGINDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

LOGINDlg::~LOGINDlg()
{
}

void LOGINDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, Student_list);
}


BEGIN_MESSAGE_MAP(LOGINDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON5, &LOGINDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON9, &LOGINDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &LOGINDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON1, &LOGINDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &LOGINDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &LOGINDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &LOGINDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &LOGINDlg::OnBnClickedButton6)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, &LOGINDlg::OnNMDblclkList1)
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_BUTTON11, &LOGINDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &LOGINDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &LOGINDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON15, &LOGINDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON14, &LOGINDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON7, &LOGINDlg::OnBnClickedButton7)
	//ON_BN_CLICKED(IDC_BUTTON8, &LOGINDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


void LOGINDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialog* dplg = (CDialog*)AfxGetMainWnd(); // 获得子窗口的指针
	dplg->DestroyWindow(); // 利用指针是操作子窗口（自我销毁）
	CDialogEx::OnClose();
}


BOOL LOGINDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	// 数据进行 “行列” 排序 和 表头设置
	// 1. 表头设置（InsertColumn(下标，表头，向右对齐0，宽度)）

	Student_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES | LVS_EX_FLATSB); // 扩展样式，整行选中加复选框
	Student_list.InsertColumn(0, _T("姓名"), 0, 200);
	Student_list.InsertColumn(1, _T("学号"), 0, 200);
	Student_list.InsertColumn(2, _T("性别"), 0, 200);
	Student_list.InsertColumn(3, _T("年龄"), 0, 200);
	Student_list.InsertColumn(4, _T("专业"), 0, 200);
	Student_list.InsertColumn(5, _T("联系方式"), 0, 200);

	CString a, b, c, d, e, f;
	for (int i = 0; i < 8; i++)
	{
		a.Format(_T("姓名%d"), i);
		b.Format(_T("学号%d"), i);
		c.Format(_T("男"));
		d.Format(_T("年龄%d"), i);
		e.Format(_T("专业%d"), i);
		f.Format(_T("1313245986%d"), i);
		Student_list.InsertItem(i, a);
		Student_list.SetItemText(i, 1, b);
		Student_list.SetItemText(i, 2, c);
		Student_list.SetItemText(i, 3, d);
		Student_list.SetItemText(i, 4, e);
		Student_list.SetItemText(i, 5, f);
	}
	Student_list.InsertItem(8, _T("目前页面为"));
	Student_list.SetItemText(8, 1, _T("示范数据"));
	Student_list.SetItemText(8, 2, _T("请选择全选键"));
	Student_list.SetItemText(8, 3, _T("进行“删除”"));
	Student_list.SetItemText(8, 4, _T("然后打开你所需要的"));
	Student_list.SetItemText(8, 5, _T("信息"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

// 全部选中功能
void LOGINDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < Student_list.GetItemCount(); i++)
	{
		Student_list.SetCheck(i, TRUE);
	}
}

//实现反选功能
void LOGINDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < Student_list.GetItemCount(); i++)
	{
		Student_list.SetCheck(i, !Student_list.GetCheck(i));
	}
}

//院系管理
void LOGINDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	XUEYUAN dlg;
	dlg.DoModal();
}

//专业管理
void LOGINDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	ZHUANYE dlg;
	dlg.DoModal();
}


void LOGINDlg::OnBnClickedButton3()//添加
{
	// TODO: 在此添加控件通知处理程序代码
	AddDlg dlg;//创建对话框
	if (IDCANCEL == dlg.DoModal()) // 弹出对话框
	{
		return;
	}
	/*TODO:可以在这个位置进行信息的判断，
	1.学号要唯一
	2.输入不允许为空
	（并且要有提示功能，提示1.xxx不允许为空 2. 添加数据重复并取消添加）


	增加窗口的功能要增加新的学生信息，然后返回到系统主页面（主窗口）当中
	  因此应该要创建窗口之间的传递对象*/


	int nCount = Student_list.GetItemCount();

	if (dlg.sName.IsEmpty())
	{
		AfxMessageBox(_T("姓名不能为空!!!"));
		return;
	}

	if (dlg.sID.IsEmpty())
	{
		AfxMessageBox(_T("学号不能为空"));
		return;
	}

	if (dlg.sSex.IsEmpty())
	{
		AfxMessageBox(_T("性别不能为空"));
		return;
	}

	if (dlg.sAge.IsEmpty())
	{
		AfxMessageBox(_T("年龄不能为空"));
		return;
	}

	if (dlg.sMajor.IsEmpty())
	{
		AfxMessageBox(_T("专业不能为空"));
		return;
	}
	if (dlg.sPhone.IsEmpty())
	{
		AfxMessageBox(_T("联系方式不能为空"));
		return;
	}


	// 判断学号是否唯一
	for (int i = 0; i < nCount; i++)
	{
		if (dlg.sID == Student_list.GetItemText(i, 1))
		{
			AfxMessageBox(_T("学号重复，请输入正确的学号"));
			return;
		}
	}
	// 编辑信息
	Student_list.InsertItem(nCount, dlg.sName);
	Student_list.SetItemText(nCount, 1, dlg.sID);
	Student_list.SetItemText(nCount, 2, dlg.sSex);
	Student_list.SetItemText(nCount, 3, dlg.sAge);
	Student_list.SetItemText(nCount, 4, dlg.sMajor);
	Student_list.SetItemText(nCount, 5, dlg.sPhone);

}


void LOGINDlg::OnBnClickedButton4()//删除
{
	// TODO: 在此添加控件通知处理程序代码
	/*
	删除功能
	1. 实现对已添加的学生信息进行删除。如果当前系统中没有相应的记录，则提示为空，并且返回操作
	即可在查询的基础上查询是否有相应信息
	2. 同时也可以通过在界面直接选择单选框，然后点击删除
	*/
	int nCount = Student_list.GetItemCount();
	int flag = 1;
	for (int i = 0; i < nCount; i++) // 判断是否与单选框得选中，然后再进行删除方式的切换
	{
		if (Student_list.GetCheck(i) == 1)
		{
			flag = 0;
		}

	}
	if (flag)
	{
		LOGINDlg::OnBnClickedButton5();
		for (int i = 0; i < Student_list.GetItemCount(); i++) // 遍历每一项，判断是否被选中
		{
			BOOL state = Student_list.GetCheck(i);
			if (state)
			{
				Student_list.DeleteItem(i); // 删除选定的项目
				i--;  // 因为for循环的原因，会导致程序从1.3.5.7.9这样子去判断每一项的状态，因此让程序返回一项判断，实现每一个项目的一个一个判断
			}
		}
	}
	if (!flag)
	{
		for (int i = 0; i < Student_list.GetItemCount(); i++) // 遍历每一项，判断是否被选中
		{
			BOOL state = Student_list.GetCheck(i);
			if (state)
			{
				Student_list.DeleteItem(i); // 删除选定的项目
				i--;  // 因为for循环的原因，会导致程序从1.3.5.7.9这样子去判断每一项的状态，因此让程序返回一项判断，实现每一个项目的一个一个判断
			}
		}
	}
}

void LOGINDlg::OnBnClickedButton5()//查询
{
	// TODO: 在此添加控件通知处理程序代码
	int nCount = Student_list.GetItemCount();
	for (int i = 0; i < nCount; i++) // 清空上次所选项
	{
		// ((CButton*)GetDlgItem(IDC_RADIO))->SetCheck(0);
		if (Student_list.GetCheck(i) == 1)
		{
			Student_list.SetCheck(i, 0);
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
			if ((Student_list.GetItemText(i, 1) == dlg.fID || Student_list.GetItemText(i, 0) == dlg.fName))
			{
				Student_list.SetCheck(i);  // 避免了在用姓名查找时因为名字重复而导致漏选的情况
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


void LOGINDlg::OnBnClickedButton6()//修改
{
	// TODO: 在此添加控件通知处理程序代码
	/*
		修改时注意学号的唯一性，而且输入的内容不能为空，如果重复或者为空这给予相关体现
		1.可以选择选中框进行修改
		2.也可双击学生信息，自动弹出修改窗口，进行修改
	*/
	for (int i = 0; i < Student_list.GetItemCount(); i++) // 遍历每一项，判断是否被选中
	{
		BOOL state = Student_list.GetCheck(i);
		if (state)
		{
			AddDlg dlg;
			if (IDCANCEL == dlg.DoModal()) // 弹出对话框
			{
				return;
			}

			if (dlg.sName.IsEmpty())
			{
				AfxMessageBox(_T("姓名不能为空!!!"));
				return;
			}

			if (dlg.sID.IsEmpty())
			{
				AfxMessageBox(_T("学号不能为空"));
				return;
			}

			if (dlg.sSex.IsEmpty())
			{
				AfxMessageBox(_T("性别不能为空"));
				return;
			}

			if (dlg.sAge.IsEmpty())
			{
				AfxMessageBox(_T("年龄不能为空"));
				return;
			}

			if (dlg.sMajor.IsEmpty())
			{
				AfxMessageBox(_T("专业不能为空"));
				return;
			}
			if (dlg.sPhone.IsEmpty())
			{
				AfxMessageBox(_T("联系方式不能为空"));
				return;
			}

			//// 判断学号是否唯一
			//int nCount = Student_list.GetItemCount();
			//for (int i = 0; i < nCount; i++)
			//{
			//	if (dlg.sID == Student_list.GetItemText(i, 1))
			//	{
			//		AfxMessageBox(_T("学号重复，请输入正确的学号"));
			//		return;
			//	}
			//}

			// 对已有信息进行修改（编辑），即在选定的项上，因此不用用InestItem(),直接用SetItemText() 即可
			Student_list.SetItemText(i, 0, dlg.sName);
			Student_list.SetItemText(i, 1, dlg.sID);
			Student_list.SetItemText(i, 2, dlg.sSex);
			Student_list.SetItemText(i, 3, dlg.sAge);
			Student_list.SetItemText(i, 4, dlg.sMajor);
			Student_list.SetItemText(i, 5, dlg.sPhone);
		}
	}
}


void LOGINDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialogEx::OnLButtonDblClk(nFlags, point);
}

// 实现用户交互功能的函数
void LOGINDlg::OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast <LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	int i = pNMItemActivate->iItem;

	AddDlg dlg;
	if (IDCANCEL == dlg.DoModal()) // 弹出对话框
	{
		return;
	}
	if (dlg.sName.IsEmpty())
	{
		AfxMessageBox(_T("姓名不能为空!!!"));
		return;
	}

	if (dlg.sID.IsEmpty())
	{
		AfxMessageBox(_T("学号不能为空"));
		return;
	}

	if (dlg.sSex.IsEmpty())
	{
		AfxMessageBox(_T("性别不能为空"));
		return;
	}

	if (dlg.sAge.IsEmpty())
	{
		AfxMessageBox(_T("年龄不能为空"));
		return;
	}

	if (dlg.sMajor.IsEmpty())
	{
		AfxMessageBox(_T("专业不能为空"));
		return;
	}
	if (dlg.sPhone.IsEmpty())
	{
		AfxMessageBox(_T("联系方式不能为空"));
		return;
	}

	//// 判断学号是否唯一
	//int nCount = Student_list.GetItemCount();
	//for (int i = 0; i < nCount; i++)
	//{
	//	if (dlg.sID == Student_list.GetItemText(i, 1))
	//	{
	//		AfxMessageBox(_T("学号重复，请输入正确的学号"));
	//		return;
	//	}
	//}

	Student_list.SetItemText(i, 0, dlg.sName);
	Student_list.SetItemText(i, 1, dlg.sID);
	Student_list.SetItemText(i, 2, dlg.sSex);
	Student_list.SetItemText(i, 3, dlg.sAge);
	Student_list.SetItemText(i, 4, dlg.sMajor);
	Student_list.SetItemText(i, 5, dlg.sPhone);
}

//打开文件按钮
void LOGINDlg::OnBnClickedButton11()
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
			Student_list.InsertItem(i, cs.Left(x));
			for (int j = 1; j < 5; j++)
			{
				int x2 = cs.Find("#", x1 + 1);
				Student_list.SetItemText(i, j, cs.Mid(x1 + 1, x2 - x1 - 1));
				x1 = x2;
				if (j == 4)
				{
					Student_list.SetItemText(i, j + 1, cs.Right(cs.GetLength() - x1 - 1));
					j++;
				}
			}
			i++;
		}
	}
}

// 保存文件按钮
void LOGINDlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	// 建立一个CFileDialog文件对象（对话框），再进行文件的读取，再做出相应的操作。但应该注意的是，“.txt”会报错，因为字符分字符集和多字节储存
	// (对象状态，文件类型，文件名字，覆盖功能，文件格式过滤，文件指针（这里不需要，用（空）NULL代表）)
	CFileDialog fDlg(FALSE, ".txt", "saveData", OFN_OVERWRITEPROMPT, "文本文档(*.txt)|*.txt|保存的数据(*.dat)|*.dat|所有文件(*.*)|*.*||", NULL);

	if (fDlg.DoModal() == IDOK) // 判断文件是否打开成功
	{
		CStdioFile file(fDlg.GetPathName(), CFile::modeWrite | CFile::modeCreate); // 创建一个操作文件的对象（所获取的文件路径，文件的读取方式，写与新建并写入）

		for (int i = 0; i < Student_list.GetItemCount(); i++)  // 实现每一行数据的保持，写入文件，并且以逗号隔开
		{
			CString cs = ""; // 创建一个接受字符的空变量
			for (int j = 0; j < 6; j++)
			{
				cs += Student_list.GetItemText(i, j) + "#";
				if (j == 4)
				{
					cs += Student_list.GetItemText(i, 5) + "\n";
					j = 6;
				}
			}
			file.WriteString(cs); // 每一行写入一次
		}
		file.Close(); // 关闭文件流
		AfxMessageBox(_T("保存学生信息成功"));
	}
}

// 注销按钮
void LOGINDlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK(); // 消掉子窗口

	CMFCApplication1Dlg dlg; // 弹出登陆页面
	if (dlg.DoModal() != IDOK)
	{
		LOGINDlg::OnClose(); // 实现关闭程序的功能
	}
}

//学生照片存储(因为手头没有真实信息，所以先行存储样例或者存储空白图片)
#define boxlength 10
#define boxwidth 10
void LOGINDlg::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码
	/*CString fileName = "Test.bmp";
	CString  strFilter = "BMP(*.bmp)|*.bmp|JPG|*.jpg|PNG | *.png ||";

	CFileDialog dlg(FALSE, "bmp", fileName, 6UL, strFilter);
	if (dlg.DoModal() == IDOK)
	{
		CSaveHelper obj;
		if (obj.Save(this, dlg.GetPathName()) > 0)
		{
			MessageBox("图片已保存", "温馨提示");
		}
	}*/

	CClientDC dc(this);
	CRect rect;
	//GetClientRect(&rect);  //获取画布大小
	rect.left = 0;
	rect.right = boxlength;//boxlength为宏定义
	rect.top = 0;
	rect.bottom = boxwidth;
	HBITMAP hbitmap = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);
	//创建位图
	HDC hdc = CreateCompatibleDC(dc);      //创建DC，以便将图像保存为不同的格式
	HBITMAP hOldMap = (HBITMAP)SelectObject(hdc, hbitmap);
	//将位图选入DC，并保存返回值 
	BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, dc, 0, 0, SRCCOPY);
	//将屏幕DC的图像复制到内存DC中
	CImage image;
	image.Attach(hbitmap); //将位图转化为一般图像
	CString saveFilePath;
	{
		CString  strFilter = _T("位图文件(*.bmp)|*.bmp|JPEG 图像文件|*.jpg|GIF图像文件 |*.gif| PNG图像文件 |*.png|其他格式(*.*)| *.* ||");
		CFileDialog dlg(FALSE, _T("bmp"), _T("Picture01.bmp"), NULL, strFilter);
		if (dlg.DoModal() != IDOK)
			return;
		CString strFileName; //文件扩展名
		CString strExtension;
		strFileName = dlg.m_ofn.lpstrFile;
		if (dlg.m_ofn.nFileExtension = 0)
		{
			switch (dlg.m_ofn.nFilterIndex)
			{
			case 1:
				strExtension = "bmp"; break;
			case 2:
				strExtension = "jpg"; break;
			case 3:
				strExtension = "gif"; break;
			case 4:
				strExtension = "png"; break;
			default:
				break;
			}
			strFileName = strFileName + "." + strExtension;
		}
		saveFilePath = strFileName;
	}
	HRESULT hResult = image.Save(saveFilePath);     //保存图像
	image.Detach();
	SelectObject(hdc, hOldMap);
	AfxMessageBox(_T("保存学生照片信息成功"));
}

//学生照片查看
void LOGINDlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	sPicture dlg;
	dlg.DoModal();
}

void LOGINDlg::OnBnClickedButton7()//学生考勤管理
{
	// TODO: 在此添加控件通知处理程序代码
	KAOQIN dlg;
	dlg.DoModal();
}

//void LOGINDlg::OnBnClickedButton8()//出勤率曲线生成
//{
//	// TODO: 在此添加控件通知处理程序代码
//}
