// fs.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����һ����ҵ.h"
#include "fs.h"
#include "afxdialogex.h"
#include "iostream"
#include "cstdlib"
#include "ctime"
using namespace std;




// fs �Ի���

IMPLEMENT_DYNAMIC(fs, CDialogEx)

fs::fs(CWnd* pParent /*=NULL*/)
	: CDialogEx(fs::IDD, pParent)
	, n(0)
	, o(_T(""))
	, l(_T(""))
	, k(_T(""))
	, m(_T(""))
	, g(_T(""))
{

}

fs::~fs()
{
}

void fs::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT8, n);
	DDX_Text(pDX, IDC_EDIT9, o);
	DDX_Text(pDX, IDC_EDIT3, l);
	DDX_Text(pDX, IDC_EDIT2, k);
	DDX_Text(pDX, IDC_EDIT4, m);
	DDX_Text(pDX, IDC_EDIT1, g);
}


BEGIN_MESSAGE_MAP(fs, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &fs::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT4, &fs::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON2, &fs::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &fs::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &fs::OnBnClickedButton4)
END_MESSAGE_MAP()


// fs ��Ϣ�������

void fshj(int &a,int &b)//a--���ӣ�b--��ĸ  ��������
{
	int max=1;
	for(int i=2;i<=a;i++)
	{
		if(b%i==0&&a%i==0)
		{
			max=i;
		}
	}
	b=b/max;
	a/=max;

}


char signal[4]={'+','-','*','/'};
int fz,fm;
int fz2,fm2;
int inti;
int grade1=0;
int time2=0;

void fs::OnBnClickedButton1()//���ɷ�����������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	srand(time(NULL));

	inti=rand()%4;
	CString str;
	str.Format(_T("%c"),signal[inti]);
	k=str;
	while(1)
	{
	while(1)
	{
		fz=rand()%9+1;
		fm=rand()%9+1;
		if((!(fz>fm))&&(fz!=fm)) break;
	}//�����
	fshj(fz,fm);

	//int fz2,fm2;
	while(1)
	{
		fz2=rand()%9+1;
		fm2=rand()%9+1;
		if((!(fz2>fm2))&&(fz2!=fm2)) break;
	}//�����
	fshj(fz2,fm2);

	if(!(fz*fm2<fm*fz2)) break;

	}
	str.Format(_T("%d/%d"),fz,fm);
	g=str;

	CString str1;
	str1.Format(_T("%d/%d"),fz2,fm2);
	l=str1;


	UpdateData(false);
	time2++;
}


void fs::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	UpdateData(true);//����
	//Cstring -��char
	char data[100];
	memset(data,'0', sizeof(char) * 100); 
	int len=m.GetLength();
	memcpy(data,m,len+6);//�ٶ�
	for(int i=1;i<len;i++)
		data[i]=data[2*i];
	for(int i=len;i<len+6;i++) data[i]='\0';

	int fzs=0,fms=0,wz=0;
	for(int i=0;i<len;i++)
		if(data[i]=='/') { wz=i;break;}

	for(int i=0;i<wz;i++)
		fzs+=pow(10,(wz-i-1))*(data[i]-'0');
	for(int i=wz+1;i<len;i++)
		fms+=pow(10,(len-i-1))*(data[i]-'0');
	//��ȡ���ӷ�ĸ
	//data[i]-32;
	int fzj,fmj;
	if(inti==0)//+
	{
		fzj=fz*fm2+fm*fz2;
		fmj=fm*fm2;
		fshj(fzj,fmj);
		if((fzj==fzs)&&(fmj==fms)) grade1++;
	}
	else if ( inti == 1 )//-
	{
		fzj=fz*fm2-fm*fz2;
		fmj=fm*fm2;
		fshj(fzj,fmj);
		if((fzj==fzs)&&(fmj==fms)) grade1++;
	}
	else if ( inti == 2 )//*
	{
		fzj=fz*fz2;
		fmj=fm*fm2;
		fshj(fzj,fmj);
		if((fzj==fzs)&&(fmj==fms)) grade1++;
	}
	else// /
	{
		fzj=fz/fz2;
		fmj=fm/fm2;
		fshj(fzj,fmj);
		if((fzj==fzs)&&(fmj==fms)) grade1++;
	}

}



void fs::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);//����
	//Cstring -��char
	char data[100];
	memset(data,'0', sizeof(char) * 100); 
	int len=m.GetLength();
	memcpy(data,m,len+6);//�ٶ�
	for(int i=1;i<len;i++)
		data[i]=data[2*i];
	for(int i=len;i<len+6;i++) data[i]='\0';

	int fzs=0,fms=0,wz=0;
	for(int i=0;i<len;i++)
		if(data[i]=='/') { wz=i;break;}

	for(int i=0;i<wz;i++)
		fzs+=pow(10,(wz-i-1))*(data[i]-'0');
	for(int i=wz+1;i<len;i++)
		fms+=pow(10,(len-i-1))*(data[i]-'0');
	//��ȡ���ӷ�ĸ

	//data[i]-32;
	int fzj,fmj;
	if(inti==0)//+
	{
		fzj=fz*fm2+fm*fz2;
		fmj=fm*fm2;
		fshj(fzj,fmj);
		if(((fzj==fzs)&&(fmj==fms))||((fzj==fzs)&&(fms==1))) MessageBox(L"�ش���ȷ��",L"�鿴����", MB_ICONEXCLAMATION );
		else
			MessageBox(L"����һ�Σ�",L"�鿴����", MB_ICONEXCLAMATION );
	}
	else if ( inti == 1 )//-
	{
		fzj=fz*fm2-fm*fz2;
		fmj=fm*fm2;
		fshj(fzj,fmj);
		if(((fzj==fzs)&&(fmj==fms))||((fzj==fzs)&&(fms==1))) MessageBox(L"�ش���ȷ��",L"�鿴����", MB_ICONEXCLAMATION );
		else
			MessageBox(L"����һ�Σ�",L"�鿴����", MB_ICONEXCLAMATION );
	}
	else if ( inti == 2 )//*
	{
		fzj=fz*fz2;
		fmj=fm*fm2;
		fshj(fzj,fmj);
		if(((fzj==fzs)&&(fmj==fms))||((fzj==fzs)&&(fms==1))) MessageBox(L"�ش���ȷ��",L"�鿴����", MB_ICONEXCLAMATION );
		else
			MessageBox(L"����һ�Σ�",L"�鿴����", MB_ICONEXCLAMATION );
	}
	else// /
	{
		fzj=fz*fm2;
		fmj=fm*fz2;
		fshj(fzj,fmj);
		if(((fzj==fzs)&&(fmj==fms))||((fzj==fzs)&&(fms==1))) MessageBox(L"�ش���ȷ��",L"�鿴����", MB_ICONEXCLAMATION );
		else
			MessageBox(L"����һ�Σ�",L"�鿴����", MB_ICONEXCLAMATION );
	}

}


void fs::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//data[i]-32;
	int fzj,fmj;
	if(inti==0)//+
	{
		fzj=fz*fm2+fm*fz2;
		fmj=fm*fm2;
		fshj(fzj,fmj);
		CString str;
		if(fmj==1) str.Format(_T("%d"),fzj);
		else
		str.Format(_T("%d/%d"),fzj,fmj);
		MessageBox(str,L"�˶Դ�", MB_ICONEXCLAMATION );
	}
	else if ( inti == 1 )//-
	{
		fzj=fz*fm2-fm*fz2;
		fmj=fm*fm2;
		fshj(fzj,fmj);

		CString str;
		if(fmj==1) str.Format(_T("%d"),fzj);
		else
		str.Format(_T("%d/%d"),fzj,fmj);
		MessageBox(str,L"�˶Դ�", MB_ICONEXCLAMATION );
	}
	else if ( inti == 2 )//*
	{
		fzj=fz*fz2;
		fmj=fm*fm2;
		fshj(fzj,fmj);

		CString str;
		if(fmj==1) str.Format(_T("%d"),fzj);
		else
		str.Format(_T("%d/%d"),fzj,fmj);
		MessageBox(str,L"�˶Դ�", MB_ICONEXCLAMATION );
	}
	else// /
	{
		fzj=fz*fm2;
		fmj=fm*fz2;
		fshj(fzj,fmj);

		CString str;
		if(fmj==1) str.Format(_T("%d"),fzj);
		else
		str.Format(_T("%d/%d"),fzj,fmj);
		MessageBox(str,L"�˶Դ�", MB_ICONEXCLAMATION );
	}

}


void fs::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	n=grade1;
	CString str;
	str.Format(_T("%.2f"),(((float)grade1)*100)/time2);
	str+="%";
	o=str;
	UpdateData(false);
}
