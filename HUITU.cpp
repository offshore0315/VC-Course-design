// HUITU.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "HUITU.h"


// HUITU 对话框

IMPLEMENT_DYNAMIC(HUITU, CDialogEx)

HUITU::HUITU(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HUITU, pParent)
{

}

HUITU::~HUITU()
{
}

void HUITU::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HUITU, CDialogEx)
	ON_STN_CLICKED(IDC_MYSTATIC, &HUITU::OnStnClickedMystatic)
	ON_BN_CLICKED(IDC_BUTTON1, &HUITU::OnBnClickedButton1)
END_MESSAGE_MAP()


// HUITU 消息处理程序


BOOL HUITU::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	pWnd = GetDlgItem(IDC_MYSTATIC);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void HUITU::OnPaint() {
	CPaintDC dc(this); // device context for painting 

	CString str;

	int i, j;

	int x, y;

	//强制更新绘图, 不可少, 否则绘图会出错

			//使static控件区域无效

	pWnd->Invalidate();

	//更新窗口, 此时才真正向系统发送重绘消息, 没有这句你可以试下, 绝对出问题

	pWnd->UpdateWindow();

	CDC* pDC = pWnd->GetDC();                   //获取控件的CDC指针

	pDC->Rectangle(0, 0, 380, 390);                   //画一个矩形框

	CPen* pPenRed = new CPen(); //创建画笔对象

	pPenRed->CreatePen(PS_SOLID, 1, RGB(255, 0, 0)); //红色画笔

	CPen* pPen = NULL;

	//选中当前红色画笔,并保存以前的画笔

	CGdiObject* pOldPen = pDC->SelectObject(pPenRed);

	pDC->MoveTo(20, 20); //绘制坐标轴

	pDC->LineTo(20, 360); //竖起轴

	pDC->LineTo(360, 360); //水平轴

	//写X轴刻度值

	for (i = 0; i <= 10; i++)

	{

		str.Format("%d", i);

		pDC->TextOut(17 + 30 * i, 365, str);

		//绘制X轴刻度

		pDC->MoveTo(i * 30 + 20, 360);

		pDC->LineTo(i * 30 + 20, 355);

	}

	//写Y轴刻度值

	for (i = 1; i <= 10; i++)

	{

		str.Format("%d", i);

		pDC->TextOut(2, 360 - 30 * i - 5, str);

		//绘制Y轴刻度

		pDC->MoveTo(25, 360 - 30 * i);

		pDC->LineTo(20, 360 - 30 * i);

	}

	//绘制X箭头

	pDC->MoveTo(350, 357);

	pDC->LineTo(360, 360);

	pDC->LineTo(350, 363);

	//绘制Y箭头 

	pDC->MoveTo(17, 30);

	pDC->LineTo(20, 20);                   //绘制左边箭头

	pDC->LineTo(23, 30); //绘制右边箭头

	//恢复以前的画笔

	pDC->SelectObject(pOldPen);

	delete pPenRed;

	if (pPen != NULL)

		delete pPen;

	ReleaseDC(pDC);
}

void HUITU::OnStnClickedMystatic()
{
	// TODO: 在此添加控件通知处理程序代码
}


void HUITU::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
