#include "Function.h"
#include "stdafx.h"

void getDisk(CComboBox *m_cComboBox)
{
	m_cComboBox->ResetContent();
	TCHAR buf[100];
	/*DWORD len =*/ GetLogicalDriveStrings(sizeof(buf) / sizeof(TCHAR), buf);
	CString strDisks;
	for (TCHAR* s = buf; *s; s += _tcslen(s) + 1)
	{
		CString strDisks;
		LPCTSTR sDrivePath = s; //单个盘符 
		m_cComboBox->ModifyStyle(CBS_SORT, 0);
		m_cComboBox->AddString(sDrivePath);
	
	}
}

void getFolderPath(CEdit *m_cEdit,HWND* m_hWnd)
{
	BROWSEINFO bi;
	ZeroMemory(&bi, sizeof(bi));
	CString m_FileDir;
	bi.hwndOwner = *m_hWnd;
	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
	BOOL bRet = FALSE;
	TCHAR szFolder[MAX_PATH];
	szFolder[0] = _T('/0');
	if (pidl)
	{
		if (SHGetPathFromIDList(pidl, szFolder))
			bRet = TRUE;
		IMalloc *pMalloc = NULL;
		if (SUCCEEDED(SHGetMalloc(&pMalloc)) && pMalloc)
		{
			pMalloc->Free(pidl);
			pMalloc->Release();
		}
	}
	m_FileDir = szFolder;
	m_cEdit->SetWindowTextW(m_FileDir);
}