// DlgTab1.cpp : 实现文件
//

#include "stdafx.h"
#include "Program.h"
#include "DlgTab1.h"
#include "afxdialogex.h"


// CDlgTab1 对话框

IMPLEMENT_DYNAMIC(CDlgTab1, CDialogEx)

CDlgTab1::CDlgTab1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_TAB1, pParent)
{

}

CDlgTab1::~CDlgTab1()
{
}

void CDlgTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_CLEAR_PRO, m_cClearPro);
	DDX_Control(pDX, IDC_LIST_CLEARPRO, m_cClearProList);
	DDX_Control(pDX, IDC_CHECK_SYSTEMFILE, m_cSystemTempFile);
	DDX_Control(pDX, IDC_CHECK_WEBFILE, m_cUserLocalFile);
	DDX_Control(pDX, IDC_EDIT_PRORESSBAR, m_cProgress);
}


BEGIN_MESSAGE_MAP(CDlgTab1, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK_CLEARPRO, &CDlgTab1::OnNMClickSyslinkClearpro)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR_EASY, &CDlgTab1::OnBnClickedButtonClearEasy)
	ON_BN_CLICKED(IDC_BUTTON_SELDISK, &CDlgTab1::OnBnClickedButtonSeldisk)
	ON_BN_CLICKED(IDC_CHECK_TMP, &CDlgTab1::OnBnClickedCheckTmp)
	ON_BN_CLICKED(IDC_CHECK_LOG, &CDlgTab1::OnBnClickedCheckLog)
	ON_BN_CLICKED(IDC_CHECK_MP, &CDlgTab1::OnBnClickedCheckMp)
	ON_BN_CLICKED(IDC_CHECK_GID, &CDlgTab1::OnBnClickedCheckGid)
	ON_BN_CLICKED(IDC_CHECK_CHK, &CDlgTab1::OnBnClickedCheckChk)
	ON_BN_CLICKED(IDC_CHECK_OLD, &CDlgTab1::OnBnClickedCheckOld)
	ON_BN_CLICKED(IDC_CHECK_PF, &CDlgTab1::OnBnClickedCheckPf)
	ON_BN_CLICKED(IDC_CHECK_DIZ, &CDlgTab1::OnBnClickedCheckDiz)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR_PRO, &CDlgTab1::OnBnClickedButtonClearPro)
END_MESSAGE_MAP()


// CDlgTab1 消息处理程序



BOOL CDlgTab1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
#pragma region 界面初始化
	getDisk(&m_cClearPro);

	m_cClearProList.InsertColumn(1, _T("路径"), LVCFMT_LEFT, 500);

#pragma endregion

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgTab1::OnNMClickSyslinkClearpro(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	getDisk(&m_cClearPro);
}

//bool isUse = false;
void CDlgTab1::OnBnClickedButtonClearEasy()
{
	// TODO: Add your control notification handler code here
	HANDLE handle1, handle2;
	ClearStruct* clearStruct = new ClearStruct();
	clearStruct->cEdit = &m_cProgress;

	wchar_t path1[100];
	SHGetSpecialFolderPath(0, path1, CSIDL_WINDOWS, 0);
	CString temp1;
	temp1 = path1;
	temp1 += "\\Temp";
	//MessageBox(temp);


	wchar_t path2[100];
	SHGetSpecialFolderPath(0, path2, CSIDL_APPDATA, 0);
	int temp;
	for (int i = 0; i < sizeof(path2) / sizeof(int); i++)
		if (path2[i] == '\0')
		{

			temp = i;
			break;
		}
	//Local\Temp

	path2[temp - 7] = '\0';
	CString s(path2);

	s += "Local\\Temp";
	if (m_cSystemTempFile.GetCheck()&&!m_cUserLocalFile.GetCheck())
	{
		*(clearStruct->strDir) = temp1;

		handle1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ClearFolder, clearStruct, 0, 0);

	}
	else if (m_cUserLocalFile.GetCheck()&&!m_cSystemTempFile.GetCheck())
	{
		*(clearStruct->strDir) = s;

		handle2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ClearFolder, clearStruct, 0, 0);


	}
	else if (m_cSystemTempFile.GetCheck() && m_cUserLocalFile.GetCheck())
	{
		*(clearStruct->strDir) = temp1;

		handle1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ClearFolder, clearStruct, 0, 0);
		*(clearStruct->strDir) = s;

		handle2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ClearFolder, clearStruct, 0, 0);

	}
	else
	{
		MessageBox(_T("请选择清理项"));
	}
}

HANDLE clearPro_handle;
void CDlgTab1::OnBnClickedButtonSeldisk()
{
	m_cClearProList.DeleteAllItems();
	m_cClearPro.GetWindowText(*(clearPro->strDir));
	clearPro->pList = &m_cClearProList;
	bool temp = false;//查看是否勾选
	for (int i = 0; i < 8; i++)
	{
		if (clearPro->suffixIsCheck[i])
		{
			temp = true;
			break;

		}
	}
	if (temp)
	{
		clearPro_handle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ClearPro, clearPro, 0, 0);
	}
	else
	{
		MessageBox(L"请勾选所要清理的文件后缀!!!");
	}
	//m_cClearProList.DeleteAllItems();
	//// TODO: Add your control notification handler code here
	//ClearStruct * FindBig = new ClearStruct();
	//FindBig->pList = &m_cClearProList;
	//m_cClearPro.GetWindowText(*(FindBig->strDir));
	//HANDLE handle;
	//handle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)FindBigFile, FindBig, 0, 0);
}



void CDlgTab1::OnBnClickedCheckTmp()
{
	// TODO: Add your control notification handler code here
	if (!clearPro->suffixIsCheck[0])
		clearPro->suffixIsCheck[0] = true;
	else
		clearPro->suffixIsCheck[0] = false;
}


void CDlgTab1::OnBnClickedCheckLog()
{
	// TODO: Add your control notification handler code here
	if (!clearPro->suffixIsCheck[2])
		clearPro->suffixIsCheck[2] = true;
	else
		clearPro->suffixIsCheck[2] = false;
}


void CDlgTab1::OnBnClickedCheckMp()
{
	// TODO: Add your control notification handler code here
	if (!clearPro->suffixIsCheck[1])
		clearPro->suffixIsCheck[1] = true;
	else
		clearPro->suffixIsCheck[1] = false;
}


void CDlgTab1::OnBnClickedCheckGid()
{
	// TODO: Add your control notification handler code here
	if (!clearPro->suffixIsCheck[3])
		clearPro->suffixIsCheck[3] = true;
	else
		clearPro->suffixIsCheck[3] = false;
}


void CDlgTab1::OnBnClickedCheckChk()
{
	// TODO: Add your control notification handler code here
	if (!clearPro->suffixIsCheck[4])
		clearPro->suffixIsCheck[4] = true;
	else
		clearPro->suffixIsCheck[4] = false;
}


void CDlgTab1::OnBnClickedCheckOld()
{
	// TODO: Add your control notification handler code here
	if (!clearPro->suffixIsCheck[5])
		clearPro->suffixIsCheck[5] = true;
	else
		clearPro->suffixIsCheck[5] = false;
}


void CDlgTab1::OnBnClickedCheckPf()
{
	// TODO: Add your control notification handler code here
	if (!clearPro->suffixIsCheck[6])
		clearPro->suffixIsCheck[6] = true;
	else
		clearPro->suffixIsCheck[6] = false;
}


void CDlgTab1::OnBnClickedCheckDiz()
{
	// TODO: Add your control notification handler code here
	if (!clearPro->suffixIsCheck[7])
		clearPro->suffixIsCheck[7] = true;
	else
		clearPro->suffixIsCheck[7] = false;
}




void CDlgTab1::OnBnClickedButtonClearPro()
{
	// TODO: Add your control notification handler code here
	int nitem = m_cClearProList.GetItemCount();
	if (nitem == 0)
	{
		MessageBox(L"清先查找文件");
	}
	else
	{
		for (int i = 0; i < nitem; i++)
		{

			CString path = m_cClearProList.GetItemText(0, 0);

			m_cClearProList.DeleteItem(0);
			DeleteFile(path);

		}
	}

}

