#include "stdafx.h"
#include "FindFileForCondition.h"


CFindFileForCondition::CFindFileForCondition()
{
}


CFindFileForCondition::~CFindFileForCondition()
{
}

void CFindFileForCondition::FindFileForTime(CFindFileForCondition * fileTime)
{
	CFileFind fileFinder;
	int found_count = 0;
	int file_filer_len = CString(*(fileTime->strExt)).GetLength();

	if (fileTime->strDir->Right(1) != "\\")
	{
		*(fileTime->strDir) += "\\";
	}
	*(fileTime->strDir) += "*.*";
	BOOL fSuccess = fileFinder.FindFile((*fileTime->strDir));


	while (fSuccess)
	{
		fSuccess = fileFinder.FindNextFile();
		if (fileFinder.IsDots())
			continue;
		if (fileFinder.IsDirectory())
		{

			CString dir_path = fileFinder.GetFilePath();
			int file_filer_len = CString(*(fileTime->strExt)).GetLength();
			*(fileTime->strDir) = dir_path;
			FindFileForTime(fileTime);
		}
		else
		{
			CString strFilePath = fileFinder.GetFilePath();
			CFileStatus fileStatus;
			CTime ct;
			ct = CTime::GetCurrentTime();
			long nowTime = ct.GetTime();
			long LfileTime;
			if (CFile::GetStatus(strFilePath, fileStatus))
				LfileTime = fileStatus.m_mtime.GetTime();
			CString strExtTmp = strFilePath.Right(file_filer_len);
			if (strFilePath.GetLength() > file_filer_len && ((nowTime - LfileTime) <= (fileTime->timeDifference)))
			{

				fileTime->pList->InsertItem(0, strFilePath);
			}
		}
	}
	fileFinder.Close();
}

void CFindFileForCondition::FindFileForName(CFindFileForCondition * fileName)
{
	CFileFind fileFinder;
	int found_count = 0;
	int file_filer_len = CString(*(fileName->strExt)).GetLength();

	if (fileName->strDir->Right(1) != "\\")
	{
		*(fileName->strDir) += "\\";
	}
	*(fileName->strDir) += "*.*";
	BOOL fSuccess = fileFinder.FindFile((*fileName->strDir));


	while (fSuccess)
	{
		fSuccess = fileFinder.FindNextFile();
		if (fileFinder.IsDots())
			continue;
		if (fileFinder.IsDirectory())
		{

			CString dir_path = fileFinder.GetFilePath();
			int file_filer_len = CString(*(fileName->strExt)).GetLength();
			*(fileName->strDir) = dir_path;
			FindFileForName(fileName);
		}
		else
		{
			CString strFilePath = fileFinder.GetFilePath();
			CString strExtTmp = strFilePath.Right(file_filer_len);
			if (strFilePath.GetLength() > file_filer_len)
			{

				if (fileName->Name == fileFinder.GetFileTitle())
					fileName->pList->InsertItem(0, strFilePath);

			}
		}
	}
	fileFinder.Close();
}

void CFindFileForCondition::FindFileForSize(CFindFileForCondition * fileSize)
{
	CFileFind fileFinder;
	int found_count = 0;
	int file_filer_len = CString(*(fileSize->strExt)).GetLength();

	if (fileSize->strDir->Right(1) != "\\")
	{
		*(fileSize->strDir) += "\\";
	}
	*(fileSize->strDir) += "*.*";
	BOOL fSuccess = fileFinder.FindFile((*fileSize->strDir));


	while (fSuccess)
	{
		fSuccess = fileFinder.FindNextFile();
		if (fileFinder.IsDots())
			continue;
		if (fileFinder.IsDirectory())
		{

			CString dir_path = fileFinder.GetFilePath();
			int file_filer_len = CString(*(fileSize->strExt)).GetLength();
			*(fileSize->strDir) = dir_path;
			FindFileForSize(fileSize);
		}
		else
		{

			CString strFilePath = fileFinder.GetFilePath();
			long min = _ttoi(fileSize->minSize);
			long max = _ttoi(fileSize->maxSize);

			CFileStatus fileStatus;
			ULONGLONG size;
			if (CFile::GetStatus(strFilePath, fileStatus))
				size = fileStatus.m_size / 1024 / 1024;

			CString strExtTmp = strFilePath.Right(file_filer_len);
			if (strFilePath.GetLength() > file_filer_len&&size <= max&&size >= min)
			{

				fileSize->pList->InsertItem(0, strFilePath);

			}
		}
	}
	fileFinder.Close();
}
