// zx.cpp : 实现文件
//

#include "stdafx.h"
#include "软工第一次作业.h"
#include "zx.h"
#include "afxdialogex.h"
#include "cstdlib"
#include "ctime"
#include "iostream"
using namespace std;

// zx 对话框

IMPLEMENT_DYNAMIC(zx, CDialogEx)

zx::zx(CWnd* pParent /*=NULL*/)
	: CDialogEx(zx::IDD, pParent)
	, a(0)
	, b(_T(""))
	, c(0)
	, d(0)
	, e(0)
	, f(_T(""))
{

}

zx::~zx()
{
}

void zx::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
	DDX_Text(pDX, IDC_EDIT3, c);
	DDX_Text(pDX, IDC_EDIT4, d);
	DDX_Text(pDX, IDC_EDIT6, e);
	DDX_Text(pDX, IDC_EDIT7, f);
}


BEGIN_MESSAGE_MAP(zx, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &zx::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT4, &zx::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON3, &zx::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &zx::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &zx::OnBnClickedButton4)
END_MESSAGE_MAP()


// zx 消息处理程序

char single[4]={'+','-','*','/'};
int cou;
int grade=0;//fenshu 
int i1,i2;//两个操作数
int time1=0;//cishu 

void zx::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	srand(time(NULL));

	cou=rand()%4;
	while(1)
	{
	i1=rand()%90+10;
	i2=rand()%90+10;
	if(!(i1<i2&&cou==1)) break;
	}//不会出现负数
	
	a=i1;
	c=i2;


	//str.Format(_T("%d"), s);
	CString str;
	str.Format(_T("%c"),single[cou]);//类比整形，只能死马当活马医了
	b=str;

	time1++;
	UpdateData(false);
}


void zx::OnEnChangeEdit4()//累计分数！
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

//#1015
	UpdateData(true);

	if(cou==0)//+
	{
		if(d==i1+i2) grade++;
	}
	else if (cou==1)//-
	{
		if(d==i1-i2) grade++;
	}
	else if (cou ==2)//*
	{
		if (d==i1*i2) grade++;
	}
	else// /
	{
		if (d==i1/i2) grade++;
	}



	// TODO:  在此添加控件通知处理程序代码
}

/* 
1.MessageBox("这是一个最简单的消息框！"); 
2.MessageBox("这是一个有标题的消息框！","标题"); 
3.MessageBox("这是一个确定 取消的消息框！","标题", MB_OKCANCEL ); 
4.MessageBox("这是一个警告的消息框！","标题", MB_ICONEXCLAMATION ); 
5.MessageBox("这是一个两种属性的消息框！","标题", MB_ICONEXCLAMATION|MB_OKCANCEL ); 
6.if(MessageBox("一种常用的应用","标题",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDCANCEL) 
return; 
*/



void zx::OnBnClickedButton3()//判断正误
{
	// TODO: 在此添加控件通知处理程序代码
		UpdateData(true);

	if(cou==0)//+
	{
		if(d==i1+i2) MessageBox(L"回答正确！",L"查看正误", MB_ICONEXCLAMATION );
		else
			MessageBox(L"再试一次！",L"查看正误", MB_ICONEXCLAMATION );
	}
	else if (cou==1)//-
	{
		if(d==i1-i2) MessageBox(L"回答正确！",L"查看正误", MB_ICONEXCLAMATION );
		else
			MessageBox(L"再试一次！",L"查看正误", MB_ICONEXCLAMATION );
	}
	else if (cou ==2)//*
	{
		if(d==i1*i2) MessageBox(L"回答正确！",L"查看正误", MB_ICONEXCLAMATION );
		else
			MessageBox(L"再试一次！",L"查看正误", MB_ICONEXCLAMATION );
	}
	else// /
	{
		if(d==i1/i2) MessageBox(L"回答正确！",L"查看正误", MB_ICONEXCLAMATION );
		else
			MessageBox(L"再试一次！",L"查看正误", MB_ICONEXCLAMATION );	
	}

}


void zx::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
		
	if(cou==0)//+
	{
		CString str;
		str.Format(_T("%d"),i1+i2);
		MessageBox(str,L"正确答案", MB_ICONEXCLAMATION );	
	}
	else if (cou==1)//-
	{
		CString str;
		str.Format(_T("%d"),i1-i2);
		MessageBox(str,L"正确答案", MB_ICONEXCLAMATION );	
	}
	else if (cou ==2)//*
	{
		CString str;
		str.Format(_T("%d"),i1*i2);
		MessageBox(str,L"正确答案", MB_ICONEXCLAMATION );	
	}
	else// /
	{
		CString str;
		str.Format(_T("%.2f"),(float)i1/i2);
		MessageBox(str,L"正确答案", MB_ICONEXCLAMATION );	
	}


}


void zx::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	e=grade;
	CString str;
	str.Format(_T("%.2f"),((float)grade/time1)*100);
	str+="%";
	f=str;

	UpdateData(false);

}
