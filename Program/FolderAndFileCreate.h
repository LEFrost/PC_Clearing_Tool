#pragma once
class CFolderAndFileCreate
{
public:
	CFolderAndFileCreate();
	~CFolderAndFileCreate();

	HWND *hWnd;
	int Num;//�ļ�����
	CString fristName;
	CString lastName;
	CString *strDir = new CString();
	CString *strExt = new CString();
static	void FolderCreate(CFolderAndFileCreate* folderName);
static	void FileCreate(CFolderAndFileCreate* fileName);

};

