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

	int found_count = 0; //���Ҽ�����  

	int file_fliter_len = CString(*(fileCount->strExt)).GetLength(); //�ļ���չ������


	if (fileCount->strDir->Right(1) != "\\")
	{
		*(fileCount->strDir) += "\\";
	}
	*(fileCount->strDir) += "*.*";


	BOOL fSuccess = fileFinder.FindFile(*(fileCount->strDir));

	while (fSuccess)
	{
		fSuccess = fileFinder.FindNextFile();

		if (fileFinder.IsDots()) { //. �� .. �ļ�
			continue;
		}

		if (fileFinder.IsDirectory()) //�ݹ鷽ʽ������һ��Ŀ¼ 
		{
			CString dir_path = fileFinder.GetFilePath();//��ȡĿ¼
			*(fileCount->strDir) = dir_path;
			found_count += FileCount(fileCount);
		}
		else
		{

			CString strFilePath = fileFinder.GetFilePath();//��ȡ�ļ�·��
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
				fileCount->pList->SetItemText(0, 2, strFilePath); //�����б� 

				found_count++; //������������  
				CString s;
				s.Format(_T("%i"), found_count);
				fileCount->cEdit->SetWindowText(s);
			}

		}
	}

	fileFinder.Close(); //�ر��ļ�
	return(found_count); //������������Ŀ  
}
