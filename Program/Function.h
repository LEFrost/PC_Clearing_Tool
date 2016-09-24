#pragma once
#include "stdafx.h"
#include "afxdialogex.h"

struct ClearStruct
{
	CString *strDir = new CString();
	CString *strExt = new CString();
	CEdit* cEdit = new CEdit();
	CListCtrl * pList = new CListCtrl();
	bool suffixIsCheck[8] = { false, false, false ,false, false ,false ,false ,false };
};

void getDisk(CComboBox *m_cComboBox);
void getFolderPath(CEdit *,HWND*);
CString getLocalTemp();
int ClearFolder(ClearStruct* clearStruct);
void FindBigFile(ClearStruct * BigStruct);
void ClearPro(ClearStruct * clearPro);