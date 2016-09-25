#include "stdafx.h"
#include "FileCount.h"


CFileCount::CFileCount()
{
}


CFileCount::~CFileCount()
{
}

int CFileCount::FileCount(CFileCount * fileCount)
{
	CFileFind fileFinder;

	int found_count = 0; //查找计数器  

	int file_fliter_len = CString(*(fileCount->strExt)).GetLength(); //文件扩展名长度


	if (fileCount->strDir->Right(1) != "\\")
	{
		*(fileCount->strDir) += "\\";
	}
	*(fileCount->strDir) += "*.*";


	BOOL fSuccess = fileFinder.FindFile(*(fileCount->strDir));

	while (fSuccess)
	{
		fSuccess = fileFinder.FindNextFile();

		if (fileFinder.IsDots()) { //. 或 .. 文件
			continue;
		}

		if (fileFinder.IsDirectory()) //递归方式搜索下一级目录 
		{
			CString dir_path = fileFinder.GetFilePath();//获取目录
			*(fileCount->strDir) = dir_path;
			found_count += FileCount(fileCount);
		}
		else
		{

			CString strFilePath = fileFinder.GetFilePath();//获取文件路径
			CString strExtTmp = strFilePath.Right(file_fliter_len);
			CFileStatus cfs;
			ULONGLONG size;
			if (CFile::GetStatus(strFilePath, cfs))
				size = cfs.m_size / 1024;
			CString s;
			s.Format(_T("%iKB"), size);
			if (strFilePath.GetLength() > file_fliter_len)

			{
				fileCount->pList->InsertItem(0, fileFinder.GetFileName());
				fileCount->pList->SetItemText(0, 1, s);
				fileCount->pList->SetItemText(0, 2, strFilePath); //插入列表 

				found_count++; //搜索计数增加  
				CString s;
				s.Format(_T("%i"), found_count);
				fileCount->cEdit->SetWindowText(s);
			}

		}
	}

	fileFinder.Close(); //关闭文件
	return(found_count); //返回搜索到数目  
}
