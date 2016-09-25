#pragma once
class CClearPro
{
public:
	CClearPro();
	~CClearPro();
	CString *strDir = new CString();
	CString *strExt = new CString();
	CListCtrl * pList = new CListCtrl();
	HWND* hWnd = new HWND();
	bool suffixIsCheck[8] = { false, false, false ,false, false ,false ,false ,false };

	static void ClearPro(CClearPro * clearPro);
	static void ClearFile(CClearPro* clearPro);
};

