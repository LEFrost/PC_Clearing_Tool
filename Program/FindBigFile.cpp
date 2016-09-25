#include "stdafx.h"
#include "FindBigFile.h"


CFindBigFile::CFindBigFile()
{
}


CFindBigFile::~CFindBigFile()
{
}

void CFindBigFile::FindBigFile(CFindBigFile * BigStruct)
{
	CFileFind fileFinder;
	int found_count = 0;
	int file_filer_len = CString(*(BigStruct->strExt)).GetLength();

	if (BigStruct->strDir->Right(1) != "\\")
	{
		*(BigStruct->strDir) += "\\";
	}
	*(BigStruct->strDir) += "*.*";
	BOOL fSuccess = fileFinder.FindFile((*BigStruct->strDir));


	while (fSuccess)
	{
		fSuccess = fileFinder.FindNextFile();
		if (fileFinder.IsDots())
			continue;
		if (fileFinder.IsDirectory())
		{

			CString dir_path = fileFinder.GetFilePath();
			int file_filer_len = CString(*(BigStruct->strExt)).GetLength();
			*(BigStruct->strDir) = dir_path;
			FindBigFile(BigStruct);
		}
		else
		{
			CString strFilePath = fileFinder.GetFilePath();
			CFileStatus fileStatus;
			ULONGLONG size;
			if (CFile::GetStatus(strFilePath, fileStatus))
				size = fileStatus.m_size;
			CString strExtTmp = strFilePath.Right(file_filer_len);
			if (strFilePath.GetLength() > file_filer_len&&size > 1024 * 1024 * 1024)
			{
				CString s;
				s.Format(_T("%I64uMB"), size / 1024 / 1024);
				BigStruct->pList->InsertItem(0, s);
				BigStruct->pList->SetItemText(0, 1, strFilePath);
			}
		}
	}
	fileFinder.Close();
}
