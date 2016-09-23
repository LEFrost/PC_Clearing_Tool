#pragma once
#include "stdafx.h"
#include "afxdialogex.h"

struct ClearStruct
{
	CString *strDir=new CString();
	CEdit* cEdit=new CEdit();
};

void getDisk(CComboBox *m_cComboBox);
void getFolderPath(CEdit *,HWND*);
CString getLocalTemp();
void ClearFolder(ClearStruct* clearStruct);