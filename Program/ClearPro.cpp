#include "stdafx.h"
#include "ClearPro.h"


CClearPro::CClearPro()
{
}


CClearPro::~CClearPro()
{
}

void CClearPro::ClearPro(CClearPro * clearPro)
{
	CFileFind fileFinder;
	int found_count = 0;

	if (clearPro->strDir->Right(1) != "\\")
	{
		*(clearPro->strDir) += "\\";
	}
	*(clearPro->strDir) += "*.*";
	BOOL fSuccess = fileFinder.FindFile((*clearPro->strDir));


	while (fSuccess)
	{
		fSuccess = fileFinder.FindNextFile();
		if (fileFinder.IsDots())
			continue;
		if (fileFinder.IsDirectory())
		{

			CString dir_path = fileFinder.GetFilePath();
			*(clearPro->strDir) = dir_path;
			ClearPro(clearPro);
		}
		else
		{
			CString strFilePath = fileFinder.GetFilePath();
			/*CFileStatus fileStatus;
			ULONGLONG size;
			if (CFile::GetStatus(strFilePath, fileStatus))
			size = fileStatus.m_size;*/

			CString strExtTmp = strFilePath.Right(3);
			if (strFilePath.GetLength() > 3)
			{
				if (strExtTmp == "tmp"&&clearPro->suffixIsCheck[0])
					clearPro->pList->InsertItem(0, strFilePath);
				else if (strExtTmp == "_mp"&&clearPro->suffixIsCheck[1])
					clearPro->pList->InsertItem(0, strFilePath);

				else if (strExtTmp == "log"&&clearPro->suffixIsCheck[2])
					clearPro->pList->InsertItem(0, strFilePath);


				else if (strExtTmp == "gid"&&clearPro->suffixIsCheck[3])
					clearPro->pList->InsertItem(0, strFilePath);

				else if (strExtTmp == "chk"&&clearPro->suffixIsCheck[4])
					clearPro->pList->InsertItem(0, strFilePath);


				else if (strExtTmp == "old"&&clearPro->suffixIsCheck[5])
					clearPro->pList->InsertItem(0, strFilePath);


				else if (strExtTmp == "pf"&&clearPro->suffixIsCheck[6])
					clearPro->pList->InsertItem(0, strFilePath);


				else if (strExtTmp == "diz"&&clearPro->suffixIsCheck[7])
					clearPro->pList->InsertItem(0, strFilePath);

				else
				{
				}
				//PostMessage(WM_UPDATEMY_DATA);
			}
		}

	}

	fileFinder.Close(); //关闭文件
}

void CClearPro::ClearFile(CClearPro * clearPro)
{
	int nitem = clearPro->pList->GetItemCount();
	if (nitem == 0)
	{
		MessageBox(*(clearPro->hWnd),_T("清先查找文件"),NULL,0);
	}
	else
	{
		for (int i = 0; i < nitem; i++)
		{

			CString path = clearPro->pList->GetItemText(0, 0);

			clearPro->pList->DeleteItem(0);
			DeleteFile(path);

		}
	}

}
