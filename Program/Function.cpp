#include "Function.h"
#include "stdafx.h"

void getDisk(CComboBox *m_cComboBox)
{

TCHAR buf[100];
DWORD len = GetLogicalDriveStrings(sizeof(buf) / sizeof(TCHAR), buf);
CString strDisks;
for (TCHAR* s = buf; *s; s += _tcslen(s) + 1)
{
	CString strDisks;
	LPCTSTR sDrivePath = s; //单个盘符 
	m_cComboBox->ModifyStyle(CBS_SORT, 0);
	m_cComboBox->AddString(sDrivePath);
	strDisks += sDrivePath;
	strDisks += " ";
}
}