// CHOOSE.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CHOOSE.h"
#include"LOGINDlg.h"
#include"CHOOSE1.h"
#include"CHOOSE2.h"


// CHOOSE 对话框

IMPLEMENT_DYNAMIC(CHOOSE, CDialogEx)

CHOOSE::CHOOSE(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG15, pParent)
{

}

CHOOSE::~CHOOSE()
{
}

void CHOOSE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_treechoose);
}


BEGIN_MESSAGE_MAP(CHOOSE, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CHOOSE::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CHOOSE::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CHOOSE::OnBnClickedButton3)
	//ON_BN_CLICKED(IDC_BUTTON4, &CHOOSE::OnBnClickedButton4)
	//ON_BN_CLICKED(IDC_BUTTON5, &CHOOSE::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CHOOSE::OnBnClickedButton6)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SYSCOMMAND()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CHOOSE::OnTvnSelchangedTree1)
END_MESSAGE_MAP()


// CHOOSE 消息处理程序


void CHOOSE::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	HTREEITEM selItem = m_treechoose.GetSelectedItem();//获得树中选中节点
	if (selItem == NULL)		//如果没有选中节点，返回
		return;
	if (selItem == m_treechoose.GetRootItem())	//如果选中了根节点
	{
		AfxMessageBox(_T("请选择学院专业班级"));
	}
	if (selItem != m_treechoose.GetRootItem())	//如果未选中根节点
	{
		CDialogEx::OnOK();
		LOGINDlg logindlg;
		logindlg.DoModal();//弹出主对话框
	}
}


void CHOOSE::OnBnClickedButton2()
{
	CDialog::OnOK(); // 消掉子窗口

	CMFCApplication1Dlg dlg; // 弹出登陆页面
	if (dlg.DoModal() != IDOK)
	{
		CHOOSE::OnClose(); // 实现关闭程序的功能
	}
}


BOOL CHOOSE::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作

	//插入根节点
	HTREEITEM hRoot = m_treechoose.InsertItem("大学管理", TVI_ROOT);
	HTREEITEM hFamily = m_treechoose.InsertItem("控计学院", hRoot);
	HTREEITEM hFriend = m_treechoose.InsertItem("电气学院", hRoot);
	HTREEITEM hClassmate = m_treechoose.InsertItem("外国语学院", hRoot);
	HTREEITEM h1 = m_treechoose.InsertItem("信安2001", hFamily);
	HTREEITEM h2 = m_treechoose.InsertItem("电气2001", hFriend);
	HTREEITEM h3 = m_treechoose.InsertItem("外语2001", hClassmate);

	ExpandAllltem(hRoot);

	return TRUE;


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}




void CHOOSE::OnBnClickedButton3()//添加
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	// TODO: 在此添加控件通知处理程序代码
	HTREEITEM selItem = m_treechoose.GetSelectedItem();//获得树中选中节点
	if (selItem == NULL)		//如果没有选中节点，返回
		return;
	if (selItem == m_treechoose.GetRootItem())	//如果选中了根节点
	{
		DWORD_PTR data = m_treechoose.GetItemData(selItem); //获得选中节点关联数据
		CHOOSE1 dlg;
		if (dlg.DoModal() == IDOK)//显示添加人员对话框，并判断是否单击确定按钮
		{
			//在选中节点下添加新节点
			HTREEITEM item = m_treechoose.InsertItem(dlg.m_strxueyuan, selItem);
			CString* pString = new CString(dlg.m_strxueyuan);
			m_treechoose.SetItemData(item, (DWORD_PTR)pString); //设置关联数据
			RefreshList(selItem);
		}
	}

	if (selItem != m_treechoose.GetRootItem())	//如果未选中根节点
	{
		DWORD_PTR data = m_treechoose.GetItemData(selItem); //获得选中节点关联数据

		CHOOSE2 dlg;
		if (dlg.DoModal() == IDOK)//显示添加人员对话框，并判断是否单击确定按钮
		{
			//在选中节点下添加新节点
			HTREEITEM item = m_treechoose.InsertItem(dlg.m_strzhuanye, selItem);
			RefreshList(selItem);
		}
	}

	UpdateData(FALSE);
}


void CHOOSE::OnBnClickedButton6()//删除
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	HTREEITEM selItem = m_treechoose.GetSelectedItem();	//获得树中选中节点
	if (selItem == NULL) 				//如果没有选中节点，返回
		return;
	if (selItem == m_treechoose.GetRootItem())
	{
		// 如果选中了根节点，返回
		AfxMessageBox(_T("root"));
		return;
	}
	DWORD_PTR data = m_treechoose.GetItemData(selItem); //获得选中节点关联数据
	if (data != NULL)
	{
		CHOOSE2 dlg = (CHOOSE2*)data;
		if (AfxMessageBox(_T("确定要删除") + m_treechoose.GetItemText(selItem) + _T("?"), MB_OKCANCEL) == IDOK)
		{
			HTREEITEM parent = m_treechoose.GetParentItem(selItem);
			CString* pString = (CString*)data;
			delete pString;
			m_treechoose.DeleteItem(selItem); 	//删除节点
			RefreshList(parent);
		}
	}
	if (data == NULL)
	{
		if (AfxMessageBox(_T("确定要删除") + m_treechoose.GetItemText(selItem) + _T("?"), MB_OKCANCEL) == IDOK)
		{
			CString* pString = (CString*)data;
			delete pString;
			m_treechoose.DeleteItem(selItem); 	//删除节点
		}
	}
	UpdateData(FALSE);
}


void CHOOSE::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()

}


HCURSOR CHOOSE::OnQueryDragIcon()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return CDialogEx::OnQueryDragIcon();
}


void CHOOSE::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnSysCommand(nID, lParam);
}


void CHOOSE::OnTvnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
void CHOOSE::RefreshList(HTREEITEM parent) {
	int index = 0;
	HTREEITEM child = m_treechoose.GetChildItem(parent);
	while (child != NULL) {
		CString name = m_treechoose.GetItemText(child);
		DWORD_PTR p = m_treechoose.GetItemData(child);
		CString* pNumber = (CString*)p;

		index++;
		child = m_treechoose.GetNextSiblingItem(child);

	}
}

void CHOOSE::ExpandAllltem(HTREEITEM parent) {
	int index = 0;


	///////////将树展开/////////////
	m_treechoose.Expand(parent, TVE_EXPAND);
	HTREEITEM child = m_treechoose.GetChildItem(parent);
	while (child) {
		/*CString name = m_treePhone.GetItemText(child);
		DWORD_PTR p = m_treePhone.GetItemData(child);
		CString* pNumber = (CString*)p;

		m_list.InsertItem(index, name);
		m_list.SetItemText(index, 1, (*pNumber));
		index++;*/
		ExpandAllltem(child);
		child = m_treechoose.GetNextSiblingItem(child);
	}

}
