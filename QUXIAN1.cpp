// QUXIAN1.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "QUXIAN1.h"


// QUXIAN1 对话框

IMPLEMENT_DYNAMIC(QUXIAN1, CDialogEx)

QUXIAN1::QUXIAN1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG14, pParent)
{

}

QUXIAN1::~QUXIAN1()
{
}

void QUXIAN1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_STATIC_QUXIAN, m_picDraw);
	DDX_Control(pDX, IDC_STATIC_QUXIAN, m_picdraw);
	//DDX_Control(pDX, IDC_STATIC_TEXT, m_static);
}


BEGIN_MESSAGE_MAP(QUXIAN1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &QUXIAN1::OnBnClickedButton1)
	ON_STN_CLICKED(IDC_STATIC_QUXIAN, &QUXIAN1::OnStnClickedStaticQuxian)
	ON_WM_CTLCOLOR()
	//ON_STN_CLICKED(IDC_STATIC_TEXT, &QUXIAN1::OnStnClickedStaticText)
END_MESSAGE_MAP()


// QUXIAN1 消息处理程序


void QUXIAN1::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


BOOL QUXIAN1::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//CRect rectPicture;
	//m_picdraw.GetClientRect(&rectPicture);
	////CWnd* pwnd = GetDlgItem(IDC_STATIC_QUXIAN);
	//CDC* pDC = m_picdraw.GetDC();
	//CPen newPen;                  //用于创建新画笔
	//CPen* pOldPen;                  //用于存放旧画笔

	//newPen.CreatePen(PS_SOLID, 1, RGB(0, 255, 0));  //创建实心画笔，粗度为1，颜色为绿色
	//pOldPen = pDC->SelectObject(&newPen);//选择新画笔，并将旧画笔的指针保存在pOldPen
	///************************************************************************/
	//	/* 坐标轴                                                               */
	//	/************************************************************************/
	//	//x轴
	//pDC->MoveTo(0, rectPicture.Height() / 2);
	//pDC->LineTo(rectPicture.Width(), rectPicture.Height() / 2);
	////y轴
	//pDC->MoveTo(rectPicture.Width() / 2, 0);
	//pDC->LineTo(rectPicture.Width() / 2, rectPicture.Height());
	////x轴刻度

	//for (int32_t i = rectPicture.Width() / 2 - 10; i > 0; i -= 10)
	//{
	//	pDC->MoveTo(i, rectPicture.Height() / 2);
	//	pDC->LineTo(i, rectPicture.Height() / 2 - 5);
	//}
	//for (int32_t i = rectPicture.Width() / 2 + 10; i < rectPicture.Width() + 1; i += 10)
	//{
	//	pDC->MoveTo(i, rectPicture.Height() / 2);
	//	pDC->LineTo(i, rectPicture.Height() / 2 - 5);

	//}
	////y轴刻度
	//for (int32_t i = rectPicture.Height() / 2 - 10; i > 0; i -= 10)
	//{
	//	pDC->MoveTo(rectPicture.Width() / 2, i);
	//	pDC->LineTo(rectPicture.Width() / 2 + 5, i);
	//}
	//for (int32_t
	//	i = rectPicture.Height() / 2 + 10; i < rectPicture.Height(); i += 10)
	//{
	//	pDC->MoveTo(rectPicture.Width() / 2, i);
	//	pDC->LineTo(rectPicture.Width() / 2 + 5, i);
	//}
	//pDC->SelectObject(pOldPen);//恢复旧画笔
	//newPen.DeleteObject();//删除新画笔
	pWnd = GetDlgItem(IDC_STATIC_QUXIAN);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void QUXIAN1::OnStnClickedStaticQuxian()
{
	////TODO: 在此添加控件通知处理程序代码
}


HBRUSH QUXIAN1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void QUXIAN1::OnStnClickedStaticText()
{
	// TODO: 在此添加控件通知处理程序代码
}
void QUXIAN1::OnPoint() {
	CPaintDC dc(this);
	//////////////////////////////////////////////////////////////////////////
	//*******画坐标图*******
	//////////////////////////////////////////////////////////////////////////
	CRect rect;
	GetDlgItem(IDC_STATIC_QUXIAN)->GetClientRect(rect);
	rect.Width();
	rect.Height();
	//用rect.Width()替代nxLength，rect.Height()替代nyLength
	int nxLength = 400;
	int nyLength = 300;
	int nxDivisionNumber = 7;
	int nyDivisionNumber = 6;
	int nMeshLength;
	CString str;
	int i;
	CWnd* pWnd = GetDlgItem(IDC_STATIC_QUXIAN);
	CDC* pDC = pWnd->GetDC();
	pWnd->Invalidate();
	pWnd->UpdateWindow();
	pDC->Rectangle(0, 0, nxLength, nyLength);
	CPen* pPenRed = new CPen; //创建画笔对象
	pPenRed->CreatePen(PS_SOLID, 1, RGB(255, 0, 0)); //红色画笔
	CPen* pPenGreen = new CPen; //创建画笔对象
	pPenGreen->CreatePen(PS_SOLID, 1, RGB(0, 255, 0));//绿色画笔
	CPen* pPenBlue = new CPen; //创建画笔对象
	pPenBlue->CreatePen(PS_DOT, 1, RGB(0, 0, 255)); //蓝色画笔
	CPen* pPenBlack = new CPen; //创建画笔对象
	pPenBlack->CreatePen(PS_SOLID, 1, RGB(0, 0, 0)); //黑色画笔
	//选中黑色画笔，并保存当前画笔
	CGdiObject* pOldPen = pDC->SelectObject(pPenBlack);
	pDC->MoveTo(30, 10); //绘制坐标轴
	pDC->LineTo(30, nyLength - 30); //垂直轴
	pDC->LineTo(nxLength - 10, nyLength - 30); //水平轴
	//横坐标箭头
	pDC->MoveTo(nxLength - 10 - 10, nyLength - 30 - 3);
	pDC->LineTo(nxLength - 10, nyLength - 30);
	pDC->LineTo(nxLength - 10 - 10, nyLength - 30 + 3);
	pDC->LineTo(nxLength - 10 - 10, nyLength - 30 - 3);
	//纵坐标箭头
	pDC->MoveTo(27, 20);
	pDC->LineTo(30, 10);
	pDC->LineTo(33, 20);
	pDC->LineTo(27, 20);
	//横坐标数字
	nMeshLength = (nxLength - 40) / (nxDivisionNumber + 1);
	for (i = 0; i < nxDivisionNumber + 1; i++) {
		str.Format("%d", i);
		pDC->TextOut(27 + i * nMeshLength, nyLength - 27, str);
	}
	//横坐标标识
	str.Format("时间");
	pDC->TextOut(nxLength - 33, nyLength - 27, str);
	//纵坐标数字
	nMeshLength = (nyLength - 40) / (nyDivisionNumber + 1);
	for (i = 0; i < nyDivisionNumber + 1; i++) {
		str.Format("%d", i * 25);
		pDC->TextOut(3, nyLength - 40 - i * nMeshLength, str);
	}
	//纵坐标标识
	str.Format("直径");
	pDC->TextOut(1, 3, str);
	//网格线
	pDC->SelectObject(pPenBlue);
	nMeshLength = (nxLength - 40) / (nxDivisionNumber + 1);
	for (i = 1; i < nxDivisionNumber + 2; i++) {
		pDC->MoveTo(30 + i * nMeshLength, nyLength - 30);
		pDC->LineTo(30 + i * nMeshLength, 10);
	}
	nMeshLength = (nyLength - 40) / (nyDivisionNumber + 1);
	for (i = 1; i < nyDivisionNumber + 2; i++) {
		pDC->MoveTo(30, nyLength - 30 - i * nMeshLength);
		pDC->LineTo(nxLength - 10, nyLength - 30 - i * nMeshLength);
	}
	//恢复以前的画笔
	pDC->SelectObject(pOldPen);
	delete pPenRed;
	delete pPenGreen;
	delete pPenBlue;
	delete pPenBlack;
}