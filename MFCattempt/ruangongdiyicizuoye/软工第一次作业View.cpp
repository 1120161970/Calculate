
// 软工第一次作业View.cpp : C软工第一次作业View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "软工第一次作业.h"
#endif

#include "软工第一次作业Doc.h"
#include "软工第一次作业View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C软工第一次作业View

IMPLEMENT_DYNCREATE(C软工第一次作业View, CView)

BEGIN_MESSAGE_MAP(C软工第一次作业View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C软工第一次作业View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C软工第一次作业View 构造/析构

C软工第一次作业View::C软工第一次作业View()
{
	// TODO: 在此处添加构造代码

}

C软工第一次作业View::~C软工第一次作业View()
{
}

BOOL C软工第一次作业View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C软工第一次作业View 绘制

void C软工第一次作业View::OnDraw(CDC* /*pDC*/)
{
	C软工第一次作业Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C软工第一次作业View 打印


void C软工第一次作业View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C软工第一次作业View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C软工第一次作业View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C软工第一次作业View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C软工第一次作业View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C软工第一次作业View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C软工第一次作业View 诊断

#ifdef _DEBUG
void C软工第一次作业View::AssertValid() const
{
	CView::AssertValid();
}

void C软工第一次作业View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C软工第一次作业Doc* C软工第一次作业View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C软工第一次作业Doc)));
	return (C软工第一次作业Doc*)m_pDocument;
}
#endif //_DEBUG


// C软工第一次作业View 消息处理程序
