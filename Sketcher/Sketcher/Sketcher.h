
// Sketcher.h : Sketcher Ӧ�ó������ͷ�ļ�
//
#pragma once
#include "SketcherConstants.h"
#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSketcherApp:
// �йش����ʵ�֣������ Sketcher.cpp
//

class CSketcherApp : public CWinAppEx
{
public:
	CSketcherApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSketcherApp theApp;