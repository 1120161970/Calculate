#pragma once


// zx �Ի���

class zx : public CDialogEx
{
	DECLARE_DYNAMIC(zx)

public:
	zx(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~zx();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int a;
	CString b;
	int c;
	double d;
	int e;
	CString f;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
};
