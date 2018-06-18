#pragma once


// fs 对话框

class fs : public CDialogEx
{
	DECLARE_DYNAMIC(fs)

public:
	fs(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~fs();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
