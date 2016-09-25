#pragma once
class CFindBigFile
{
public:
	CFindBigFile();
	~CFindBigFile();
	CString *strDir = new CString();
	CListCtrl * pList = new CListCtrl();
	CString *strExt = new CString();

	static	void FindBigFile(CFindBigFile * BigStruct);

};

