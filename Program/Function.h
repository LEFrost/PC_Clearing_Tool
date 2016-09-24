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
	long timeDifference;
	CString Name;
	CString minSize;
	CString maxSize;
};

void getDisk(CComboBox *m_cComboBox);
void getFolderPath(CEdit *,HWND*);
CString getLocalTemp();
int ClearFolder(ClearStruct* clearStruct);
void FindBigFile(ClearStruct * BigStruct);
void ClearPro(ClearStruct * clearPro);
void FindFileForTime(ClearStruct* fileTime);
void FindFileForName(ClearStruct* fileName); 
void FindFileForSize(ClearStruct* fileName);