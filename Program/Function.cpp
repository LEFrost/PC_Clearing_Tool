#include"stdafx.h"
#include"Function.h"

//
//struct ClearStruct
//{
//	CString *strDir = new CString();
//	CString *strExt = new CString();
//	CEdit* cEdit = new CEdit();
//	CListCtrl * pList = new CListCtrl();
//	bool suffixIsCheck[8] = { false, false, false ,false, false ,false ,false ,false };
//	long timeDifference;
//	CString Name;
//	CString minSize;
//	CString maxSize;
//	HWND *hWnd;
//	int Num;
//	CString fristName;
//	CString lastName;
//};


void getDisk(CComboBox *m_cComboBox)
{
	m_cComboBox->ResetContent();
	TCHAR buf[100];
	/*DWORD len =*/ GetLogicalDriveStrings(sizeof(buf) / sizeof(TCHAR), buf);
	CString strDisks;
	for (TCHAR* s = buf; *s; s += _tcslen(s) + 1)
	{
		CString strDisks;
		LPCTSTR sDrivePath = s; //单个盘符 
		m_cComboBox->ModifyStyle(CBS_SORT, 0);
		m_cComboBox->AddString(sDrivePath);

	}
}

void getFolderPath(CEdit *m_cEdit, HWND* m_hWnd)
{
	BROWSEINFO bi;
	ZeroMemory(&bi, sizeof(bi));
	CString m_FileDir;
	bi.hwndOwner = *m_hWnd;
	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
	BOOL bRet = FALSE;
	TCHAR szFolder[MAX_PATH];
	szFolder[0] = _T('/0');
	if (pidl)
	{
		if (SHGetPathFromIDList(pidl, szFolder))

			bRet = TRUE;
		IMalloc *pMalloc = NULL;
		if (SUCCEEDED(SHGetMalloc(&pMalloc)) && pMalloc)
		{
			pMalloc->Free(pidl);
			pMalloc->Release();
		}
	}
	m_FileDir = szFolder;
	m_cEdit->SetWindowTextW(m_FileDir);
}

CString getLocalTemp()
{
	wchar_t path[100];
	SHGetSpecialFolderPath(0, path, CSIDL_APPDATA, 0);
	int temp;
	for (int i = 0; i < sizeof(path) / sizeof(int); i++)
		if (path[i] == '\0')
		{

			temp = i;
			break;
		}
	//Local\Temp

	path[temp - 7] = '\0';
	CString s(path);

	s += "Local\\Temp";
	return s;
}

//使用strDir、cEdit
int ClearFolder(ClearStruct* clearStruct)
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
//使用strDir、pList
void FindBigFile(ClearStruct * BigStruct)
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
//使用strDir、strExt、pList
void ClearPro(ClearStruct * clearPro)
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

void FindFileForTime(ClearStruct * fileTime)
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
//strExt、strDir、Name、pList
void FindFileForName(ClearStruct * fileName)
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
			FindFileForTime(fileName);
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
//strExt、strDir、minSize、maxSize、pList
void FindFileForSize(ClearStruct * fileSize)
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
//hWnd、fristName、lastName、strDir
void FolderCreate(ClearStruct * fileCreate)
{
	CString strFolderPath = *(fileCreate->strDir);
	if (!PathIsDirectory(strFolderPath))
	{
		MessageBox(*(fileCreate->hWnd), _T("路径不存在"), _T("警告!!"), 0);
	}
	else
	{
		CString tempPath;
		for (int i = 0; i < fileCreate->Num; i++)
		{
			tempPath = strFolderPath;
			CString s;
			s.Format(_T("(%i)"),i+1);
			tempPath += "\\";
			tempPath += fileCreate->fristName + s + fileCreate->lastName;
			CreateDirectory(tempPath, NULL);
		}
	}
}
//strDir、strExt、fristName、lastName、Num
void FileCreate(ClearStruct * fileName)
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
			tempPath += fileName->fristName + s + fileName->lastName+*(fileName->strExt);
			CFile mFile(tempPath, CFile::modeWrite | CFile::modeCreate);

		}
	}
}

int FileCount(ClearStruct * fileCount)
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
				fileCount->pList->SetItemText(0,1, s);
				fileCount->pList->SetItemText(0,2,strFilePath); //插入列表 

				found_count++; //搜索计数增加  
				CString s;
				s.Format(_T("%i"), found_count);
				fileCount->cEdit->SetWindowText(s)  ;
			}

		}
	}

	fileFinder.Close(); //关闭文件
	return(found_count); //返回搜索到数目  
}
