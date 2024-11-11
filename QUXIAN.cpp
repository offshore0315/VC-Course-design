// QUXIAN.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "QUXIAN.h"
#include"KAOQIN.h"


// QUXIAN 对话框

IMPLEMENT_DYNAMIC(QUXIAN, CDialogEx)

QUXIAN::QUXIAN(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG14, pParent)
{

}

QUXIAN::~QUXIAN()
{
}

void QUXIAN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, m_picDraw, m_npicDraw);
}


BEGIN_MESSAGE_MAP(QUXIAN, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &QUXIAN::OnBnClickedButton1)
END_MESSAGE_MAP()


// QUXIAN 消息处理程序


BOOL QUXIAN::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect rectPicture;
	m_picDraw.GetClientRect(&rectPicture);
	CDC* pDC = m_picDraw.GetDC();
	CPen newPen;                  //用于创建新画笔
	CPen* pOldPen;                  //用于存放旧画笔
	CBrush newBrush;              //用于创建新画笔
	CBrush* pOldBrush;            //用于存放旧画笔        
	newBrush.CreateSolidBrush(RGB(0, 0, 0));    //新建黑色画刷
	pOldBrush = pDC->SelectObject(&newBrush); //选择新画刷并将旧画刷的指针保存在pOldBrush
	pDC->Rectangle(rectPicture); //黑色画刷为绘图控件，形成黑色背景
	pDC->SelectObject(pOldBrush);//恢复旧画刷
	newBrush.DeleteObject(); //删除新画刷

	newPen.CreatePen(PS_SOLID, 1, RGB(0, 255, 0));  //创建实心画笔，粗度为1，颜色为绿色
	pOldPen = pDC->SelectObject(&newPen);//选择新画笔，并将旧画笔的指针保存在pOldPen
/************************************************************************/
	/* 坐标轴                                                               */
	/************************************************************************/
	//x轴
	pDC->MoveTo(0, rectPicture.Height() / 2);
	pDC->LineTo(rectPicture.Width(), rectPicture.Height() / 2);
	//y轴
	pDC->MoveTo(rectPicture.Width() / 2, 0);
	pDC->LineTo(rectPicture.Width() / 2, rectPicture.Height());
	//x轴刻度

	for (int32_t i = rectPicture.Width() / 2 - 10; i > 0; i -= 10)
	{
		pDC->MoveTo(i, rectPicture.Height() / 2);
		pDC->LineTo(i, rectPicture.Height() / 2 - 5);
	}
	for (int32_t i = rectPicture.Width() / 2 + 10; i < rectPicture.Width() + 1; i += 10)
	{
		pDC->MoveTo(i, rectPicture.Height() / 2);
		pDC->LineTo(i, rectPicture.Height() / 2 - 5);

	}
	//y轴刻度
	for (int32_t i = rectPicture.Height() / 2 - 10; i > 0; i -= 10)
	{
		pDC->MoveTo(rectPicture.Width() / 2, i);
		pDC->LineTo(rectPicture.Width() / 2 + 5, i);
	}
	for (int32_t
		i = rectPicture.Height() / 2 + 10; i < rectPicture.Height(); i += 10)
	{
		pDC->MoveTo(rectPicture.Width() / 2, i);
		pDC->LineTo(rectPicture.Width() / 2 + 5, i);
	}
	pDC->SelectObject(pOldPen);//恢复旧画笔
	newPen.DeleteObject();//删除新画笔

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void QUXIAN::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}