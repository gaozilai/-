
// 乘法练习View.h: C乘法练习View 类的接口
//

#pragma once


class C乘法练习View : public CEditView
{
protected: // 仅从序列化创建
	C乘法练习View() noexcept;
	DECLARE_DYNCREATE(C乘法练习View)

// 特性
public:
	C乘法练习Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C乘法练习View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    CFont m_Font;
    // 生成的消息映射函数
protected:
    afx_msg void OnFileNew();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // 乘法练习View.cpp 中的调试版本
inline C乘法练习Doc* C乘法练习View::GetDocument() const
   { return reinterpret_cast<C乘法练习Doc*>(m_pDocument); }
#endif

