
// ����һ����ҵView.h : C����һ����ҵView ��Ľӿ�
//

#pragma once


class C����һ����ҵView : public CView
{
protected: // �������л�����
	C����һ����ҵView();
	DECLARE_DYNCREATE(C����һ����ҵView)

// ����
public:
	C����һ����ҵDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C����һ����ҵView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ����һ����ҵView.cpp �еĵ��԰汾
inline C����һ����ҵDoc* C����һ����ҵView::GetDocument() const
   { return reinterpret_cast<C����һ����ҵDoc*>(m_pDocument); }
#endif

