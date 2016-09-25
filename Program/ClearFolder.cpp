#include "stdafx.h"
#include "ClearFolder.h"


CClearFolder::CClearFolder()
{
}


CClearFolder::~CClearFolder()
{
}

int CClearFolder::ClearFolder(CClearFolder * clearStruct)
{
	if (clearStruct->strDir->IsEmpty())
		return 0;
	//   首先删除文件及子文件夹     
	CFileFind ff;
	BOOL bFound = ff.FindFile(*(clearStruct->strDir) + L"\\*", 0);
	while (bFound)
	{
		bFound = ff.FindNextFile();
		if (ff.GetFileName() == "." || ff.GetFileName() == "..")
			continue;
		//   去掉文件(夹)只读等属性     
		SetFileAttributes(ff.GetFilePath(), FILE_ATTRIBUTE_NORMAL);
		if (ff.IsDirectory())
		{
			*(clearStruct->strDir) = ff.GetFilePath();
			clearStruct->cEdit->SetWindowTextW(*(clearStruct->strDir));
			//   递归删除子文件夹
			ClearFolder(clearStruct);
			RemoveDirectory(ff.GetFilePath());

		}
		else
		{
			//   删除文件     
			clearStruct->cEdit->SetWindowTextW(*(clearStruct->strDir));

			DeleteFile(ff.GetFilePath());
		}
	}
	ff.Close();
	clearStruct->cEdit->SetWindowText(L"");
	//   然后删除该文件夹     
	//RemoveDirectory(strDir);     
	return -1;

}
