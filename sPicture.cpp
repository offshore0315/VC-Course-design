// sPicture.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "sPicture.h"


// sPicture 对话框

IMPLEMENT_DYNAMIC(sPicture, CDialogEx)

sPicture::sPicture(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG10, pParent)
{

}

sPicture::~sPicture()
{
}

void sPicture::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(sPicture, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &sPicture::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &sPicture::OnBnClickedButton2)
END_MESSAGE_MAP()


// sPicture 消息处理程序


void sPicture::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Invalidate();    //刷新窗口,以便清除上一次显示的图片
	int width, height;
	CImage  image;
	CRect   rect;
	//创建打开图片的文件路径对话框
	CFileDialog dlg(TRUE, NULL, NULL, 0, _T("All Files (*.*)|*.*|BMP (*.bmp)|*.bmp|DIB (*.dib)|*.dib|EMF (*.emf)|*.emf|GIF (*.gif)|*.gif|ICO (*.ico)|*.ico|JPG (*.jpg)|*.jpg|WMF (*.wmf)|*.wmf||"), NULL);
	if (dlg.DoModal() == IDOK)
	{
		CString FilePathName = dlg.GetPathName();
		image.Load(FilePathName);
		CDC* pDC = GetDlgItem(IDC_EDIT1)->GetDC();//获取picture的DC  
		HDC hDC = pDC->GetSafeHdc();// 获取 HDC(设备句柄) 来进行绘图操作
		GetDlgItem(IDC_EDIT1)->GetClientRect(&rect);//获取Picture Control控件的大小
		//获取图片的宽 高度  
		width = image.GetWidth();
		height = image.GetHeight();
		// 求出picture control的宽和高
		int rect_w = rect.Width();
		int rect_h = rect.Height();
		//当图片比绘图区域小
		if (width <= rect.Width() && height <= rect.Width())
		{
			int tx = (int)(rect_w - width) / 2;   // 使图片的显示位置正好在控件的正中  
			int ty = (int)(rect_h - height) / 2;
			SetRect(rect, tx, ty, tx + width, ty + width);   //设置新的矩阵区域
			image.Draw(hDC, rect);//将图片绘制到picture表示的区域内  
			ReleaseDC(pDC);
		}
		//当图片比绘图区域大，这里默认是图片控件较长，只判断了图片和控件的宽度比较
		else if (height > rect_h)
		{
			double scale = (double)rect_h / (double)height; //缩放的比例因子
			int tx = (int)(rect_w - width * scale) / 2;
			int ty = 0;
			SetRect(rect, tx, ty, tx + width * scale, rect_h); //设置新的矩阵区域
			image.Draw(hDC, rect);//将图片绘制到picture表示的区域内  
			ReleaseDC(pDC);
		}
	}
}


void sPicture::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
