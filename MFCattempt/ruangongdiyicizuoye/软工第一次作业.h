
// 软工第一次作业.h : 软工第一次作业 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// C软工第一次作业App:
// 有关此类的实现，请参阅 软工第一次作业.cpp
//

class C软工第一次作业App : public CWinAppEx
{
public:
	C软工第一次作业App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C软工第一次作业App theApp;
