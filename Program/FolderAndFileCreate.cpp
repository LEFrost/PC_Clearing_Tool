#include "stdafx.h"
#include "FolderAndFileCreate.h"


CFolderAndFileCreate::CFolderAndFileCreate()
{
}


CFolderAndFileCreate::~CFolderAndFileCreate()
{
}

void CFolderAndFileCreate::FolderCreate(CFolderAndFileCreate * folderName)
{
	CString strFolderPath = *(folderName->strDir);
	if (!PathIsDirectory(strFolderPath))
	{
		MessageBox(*(folderName->hWnd), _T("路径不存在"), _T("警告!!"), 0);
	}
	else
	{
		CString tempPath;
		for (int i = 0; i < folderName->Num; i++)
		{
			tempPath = strFolderPath;
			CString s;
			s.Format(_T("(%i)"), i + 1);
			tempPath += "\\";
			tempPath += folderName->fristName + s + folderName->lastName;
			CreateDirectory(tempPath, NULL);
		}
	}
}

void CFolderAndFileCreate::FileCreate(CFolderAndFileCreate * fileName)
{
	CString strFolderPath = *(fileName->strDir);
	if (!PathIsDirectory(strFolderPath))
	{
		MessageBox(*(fileName->hWnd), _T("路径不存在"), _T("警告!!"), 0);
	}
	else
	{
		CString tempPath;
		for (int i = 0; i < fileName->Num; i++)
		{
			tempPath = strFolderPath;
			CString s;
			s.Format(_T("(%i)"), i + 1);
			tempPath += "\\";
			tempPath += fileName->fristName + s + fileName->lastName + *(fileName->strExt);
			CFile mFile(tempPath, CFile::modeWrite | CFile::modeCreate);

		}
	}
}
