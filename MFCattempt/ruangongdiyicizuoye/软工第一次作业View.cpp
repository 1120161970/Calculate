
// ����һ����ҵView.cpp : C����һ����ҵView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "����һ����ҵ.h"
#endif

#include "����һ����ҵDoc.h"
#include "����һ����ҵView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C����һ����ҵView

IMPLEMENT_DYNCREATE(C����һ����ҵView, CView)

BEGIN_MESSAGE_MAP(C����һ����ҵView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C����һ����ҵView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C����һ����ҵView ����/����

C����һ����ҵView::C����һ����ҵView()
{
	// TODO: �ڴ˴���ӹ������

}

C����һ����ҵView::~C����һ����ҵView()
{
}

BOOL C����һ����ҵView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C����һ����ҵView ����

void C����һ����ҵView::OnDraw(CDC* /*pDC*/)
{
	C����һ����ҵDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C����һ����ҵView ��ӡ


void C����һ����ҵView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C����һ����ҵView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C����һ����ҵView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C����һ����ҵView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void C����һ����ҵView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C����һ����ҵView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C����һ����ҵView ���

#ifdef _DEBUG
void C����һ����ҵView::AssertValid() const
{
	CView::AssertValid();
}

void C����һ����ҵView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C����һ����ҵDoc* C����һ����ҵView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C����һ����ҵDoc)));
	return (C����һ����ҵDoc*)m_pDocument;
}
#endif //_DEBUG


// C����һ����ҵView ��Ϣ�������
