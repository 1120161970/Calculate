#pragma once


// fs �Ի���

class fs : public CDialogEx
{
	DECLARE_DYNAMIC(fs)

public:
	fs(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~fs();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int n;
	CString o;
	afx_msg void OnBnClickedButton1();
	CString l;
	CString k;
	CString m;
	CString g;
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
