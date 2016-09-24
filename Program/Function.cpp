#include "Function.h"
#include "stdafx.h"

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
struct ClearStruct
{
	CString *strDir = new CString();
	CString *strExt = new CString();
	CEdit* cEdit = new CEdit();
	CListCtrl * pList = new CListCtrl();
	bool suffixIsCheck[8] = { false, false, false ,false, false ,false ,false ,false };
};
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
