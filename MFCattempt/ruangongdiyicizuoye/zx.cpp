// zx.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����һ����ҵ.h"
#include "zx.h"
#include "afxdialogex.h"
#include "cstdlib"
#include "ctime"
#include "iostream"
using namespace std;

// zx �Ի���

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


// zx ��Ϣ�������

char single[4]={'+','-','*','/'};
int cou;
int grade=0;//fenshu 
int i1,i2;//����������
int time1=0;//cishu 

void zx::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	srand(time(NULL));

	cou=rand()%4;
	while(1)
	{
	i1=rand()%90+10;
	i2=rand()%90+10;
	if(!(i1<i2&&cou==1)) break;
	}//������ָ���
	
	a=i1;
	c=i2;


	//str.Format(_T("%d"), s);
	CString str;
	str.Format(_T("%c"),single[cou]);//������Σ�ֻ����������ҽ��
	b=str;

	time1++;
	UpdateData(false);
}


void zx::OnEnChangeEdit4()//�ۼƷ�����
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

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



	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

/* 
1.MessageBox("����һ����򵥵���Ϣ��"); 
2.MessageBox("����һ���б������Ϣ��","����"); 
3.MessageBox("����һ��ȷ�� ȡ������Ϣ��","����", MB_OKCANCEL ); 
4.MessageBox("����һ���������Ϣ��","����", MB_ICONEXCLAMATION ); 
5.MessageBox("����һ���������Ե���Ϣ��","����", MB_ICONEXCLAMATION|MB_OKCANCEL ); 
6.if(MessageBox("һ�ֳ��õ�Ӧ��","����",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDCANCEL) 
return; 
*/



void zx::OnBnClickedButton3()//�ж�����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		UpdateData(true);

	if(cou==0)//+
	{
		if(d==i1+i2) MessageBox(L"�ش���ȷ��",L"�鿴����", MB_ICONEXCLAMATION );
		else
			MessageBox(L"����һ�Σ�",L"�鿴����", MB_ICONEXCLAMATION );
	}
	else if (cou==1)//-
	{
		if(d==i1-i2) MessageBox(L"�ش���ȷ��",L"�鿴����", MB_ICONEXCLAMATION );
		else
			MessageBox(L"����һ�Σ�",L"�鿴����", MB_ICONEXCLAMATION );
	}
	else if (cou ==2)//*
	{
		if(d==i1*i2) MessageBox(L"�ش���ȷ��",L"�鿴����", MB_ICONEXCLAMATION );
		else
			MessageBox(L"����һ�Σ�",L"�鿴����", MB_ICONEXCLAMATION );
	}
	else// /
	{
		if(d==i1/i2) MessageBox(L"�ش���ȷ��",L"�鿴����", MB_ICONEXCLAMATION );
		else
			MessageBox(L"����һ�Σ�",L"�鿴����", MB_ICONEXCLAMATION );	
	}

}


void zx::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		
	if(cou==0)//+
	{
		CString str;
		str.Format(_T("%d"),i1+i2);
		MessageBox(str,L"��ȷ��", MB_ICONEXCLAMATION );	
	}
	else if (cou==1)//-
	{
		CString str;
		str.Format(_T("%d"),i1-i2);
		MessageBox(str,L"��ȷ��", MB_ICONEXCLAMATION );	
	}
	else if (cou ==2)//*
	{
		CString str;
		str.Format(_T("%d"),i1*i2);
		MessageBox(str,L"��ȷ��", MB_ICONEXCLAMATION );	
	}
	else// /
	{
		CString str;
		str.Format(_T("%.2f"),(float)i1/i2);
		MessageBox(str,L"��ȷ��", MB_ICONEXCLAMATION );	
	}


}


void zx::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	e=grade;
	CString str;
	str.Format(_T("%.2f"),((float)grade/time1)*100);
	str+="%";
	f=str;

	UpdateData(false);

}
