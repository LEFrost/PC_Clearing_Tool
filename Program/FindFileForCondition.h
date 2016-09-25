#pragma once
class CFindFileForCondition
{
public:
	CFindFileForCondition();
	~CFindFileForCondition();
	CString *strDir = new CString();
	CString *strExt = new CString();
	CListCtrl * pList = new CListCtrl();
	long timeDifference;
	CString Name;
	CString minSize;
	CString maxSize;
static	void FindFileForTime(CFindFileForCondition* fileTime);
static	void FindFileForName(CFindFileForCondition* fileName);
static	void FindFileForSize(CFindFileForCondition* fileSize);
};

