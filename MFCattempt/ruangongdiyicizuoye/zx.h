#pragma once


// zx 对话框

class zx : public CDialogEx
{
	DECLARE_DYNAMIC(zx)

public:
	zx(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~zx();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
