#pragma once
class CClearFolder
{
public:
	CClearFolder();
	~CClearFolder();
public:
	CString *strDir = new CString();
	CEdit* cEdit = new CEdit();
static	int ClearFolder(CClearFolder* clearStruct);

};

