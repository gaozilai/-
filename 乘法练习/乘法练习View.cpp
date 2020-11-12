
// 乘法练习View.cpp: C乘法练习View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "乘法练习.h"
#endif

#include "乘法练习Doc.h"
#include "乘法练习View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C乘法练习View

IMPLEMENT_DYNCREATE(C乘法练习View, CEditView)

BEGIN_MESSAGE_MAP(C乘法练习View, CEditView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C乘法练习View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
    ON_COMMAND(ID_FILE_NEW, &C乘法练习View::OnFileNew)
    ON_WM_CREATE()
END_MESSAGE_MAP()

// C乘法练习View 构造/析构

C乘法练习View::C乘法练习View() noexcept
{
}

C乘法练习View::~C乘法练习View()
{
}

BOOL C乘法练习View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// 启用换行

	return bPreCreated;
}


// C乘法练习View 打印


void C乘法练习View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C乘法练习View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认 CEditView 准备
	return CEditView::OnPreparePrinting(pInfo);
}

void C乘法练习View::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 默认 CEditView 开始打印
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void C乘法练习View::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 默认 CEditView 结束打印
	CEditView::OnEndPrinting(pDC, pInfo);
}

void C乘法练习View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C乘法练习View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C乘法练习View 诊断

#ifdef _DEBUG
void C乘法练习View::AssertValid() const
{
	CEditView::AssertValid();
}

void C乘法练习View::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

C乘法练习Doc* C乘法练习View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C乘法练习Doc)));
	return (C乘法练习Doc*)m_pDocument;
}
#endif //_DEBUG


// C乘法练习View 消息处理程序


void C乘法练习View::OnFileNew()
{
    CString strCF[72];
    for (int i = 2; i <= 9 ; i++)
    {
        CString* pLn = &strCF[(i - 2) * 9];
    	for (int j = 1; j <= 9 ; j++)
    	{
            CString str;
            str.Format(_T("         %d x %d = "), i, j);
            pLn[j - 1] = str;
    	}
    }


    srand(GetTickCount());
    for (int i = 0; i < 1000 ; i++)
    {
        int r = rand() % 72;
        CString str = strCF[0];
        strCF[0] = strCF[r];
        strCF[r] = str;
    }

    CEdit& theEdit = GetEditCtrl();
    theEdit.SetFocus();
    theEdit.SetSel(0, -1);
    theEdit.ReplaceSel(0);


    for (int i = 0; i < 72 ; i++)
    {
        int nLen = theEdit.GetWindowTextLength();
        theEdit.SetSel(nLen, nLen);
        if (i % 4 == 0)
        {
            theEdit.ReplaceSel(_T("\r\n\r\n") + strCF[i]);
        }
        else
        {
            theEdit.ReplaceSel(strCF[i]);
        }
    }
}




int C乘法练习View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CEditView::OnCreate(lpCreateStruct) == -1)
        return -1;

    CEdit& theEdit = GetEditCtrl();
    theEdit.SetReadOnly(TRUE);
    m_Font.CreateFont(-22, 0, 0, 0, FW_NORMAL, 0, 0, 0, GB2312_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, FIXED_PITCH | FF_DONTCARE, _T("微软雅黑"));
    theEdit.SetFont(&m_Font);

    return 0;
}
