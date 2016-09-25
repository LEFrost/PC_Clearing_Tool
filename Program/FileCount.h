#pragma once
class CFileCount
{
public:
	CFileCount();
	~CFileCount();
	CString *strDir = new CString();
	CString *strExt = new CString();
	CEdit* cEdit = new CEdit();
	CListCtrl * pList = new CListCtrl();
public:

	static	int FileCount(CFileCount* fileCount);
};

