
// SketcherView.cpp : CSketcherView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Sketcher.h"
#endif

#include "SketcherDoc.h"
#include "SketcherView.h"
#include "Elements.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSketcherView

IMPLEMENT_DYNCREATE(CSketcherView, CView)

BEGIN_MESSAGE_MAP(CSketcherView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSketcherView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CSketcherView 构造/析构

CSketcherView::CSketcherView()
	: m_FirstPoint(CPoint(0,0))
	, m_SecondPoint(CPoint(0,0))
	, m_pTempElement(NULL)
{
	// TODO: 在此处添加构造代码
	//MessageBox( NULL , TEXT("CSketcherView类构造") , NULL);

}

CSketcherView::~CSketcherView()
{
	//MessageBox( NULL , TEXT("CSketcherView类析构") , NULL);
}

BOOL CSketcherView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSketcherView 绘制

void CSketcherView::OnDraw(CDC* pDC)
{
	CSketcherDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CPen aPen;
	aPen.CreatePen(PS_SOLID,2,RGB(255,0,0));
	CPen* pOldPen=pDC->SelectObject(&aPen);

	pDC->MoveTo(50,50);
	pDC->LineTo(100,100);
	pDC->MoveTo(150,100);
	pDC->LineTo(150,25);
	pDC->Ellipse(200,100,400,300);
	pDC->Ellipse(500,100,800,300);
	pDC->Arc(900,100,1000,200,950,100,950,200);

	CBrush aBrush;
	aBrush.CreateHatchBrush(HS_DIAGCROSS,RGB(255,0,0));
	CBrush* pOldBrush=pDC->SelectObject(&aBrush);
	pDC->MoveTo(50,50);
}


// CSketcherView 打印


void CSketcherView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSketcherView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSketcherView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSketcherView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CSketcherView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSketcherView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSketcherView 诊断

#ifdef _DEBUG
void CSketcherView::AssertValid() const
{
	CView::AssertValid();
}

void CSketcherView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSketcherDoc* CSketcherView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSketcherDoc)));
	return (CSketcherDoc*)m_pDocument;
}
#endif //_DEBUG


// CSketcherView 消息处理程序


void CSketcherView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//CView::OnLButtonDown(nFlags, point);
	m_FirstPoint=point;
}


void CSketcherView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//CView::OnLButtonUp(nFlags, point);
}


void CSketcherView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//CView::OnMouseMove(nFlags, point);
	if(nFlags & MK_LBUTTON)
	{
		m_SecondPoint=point;
	}
}
