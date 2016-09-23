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
END_MESSAGE_MAP()


// CDlgTab1 消息处理程序



BOOL CDlgTab1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
#pragma region 界面初始化
	getDisk(&m_cClearPro);

	m_cClearProList.InsertColumn(0, _T("文件名"), LVCFMT_LEFT, 100);
	m_cClearProList.InsertColumn(1, _T("路径"), LVCFMT_LEFT, 200);

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

bool isUse = false;
void CDlgTab1::OnBnClickedButtonClearEasy()
{
	// TODO: Add your control notification handler code here
	HANDLE handle;
	ClearStruct* clearStruct = new ClearStruct();
	clearStruct->cEdit = &m_cProgress;
	if (m_cSystemTempFile.GetCheck())
	{
		wchar_t path[100];
		SHGetSpecialFolderPath(0, path, CSIDL_WINDOWS, 0);
		CString temp;
		temp = path;
		temp += "\\Temp";
		//MessageBox(temp);
		*(clearStruct->strDir) = temp;
		handle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ClearFolder, clearStruct, 0, 0);
		isUse = true;
	}
	else if (m_cUserLocalFile.GetCheck())
	{
		wchar_t path[100];
		SHGetSpecialFolderPath(0, path, CSIDL_APPDATA, 0);
		int temp;;
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
		*(clearStruct->strDir) = s;
		handle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ClearFolder, clearStruct, 0, 0);

		isUse = true;

	}
	else if (m_cSystemTempFile.GetCheck() && m_cUserLocalFile.GetCheck())
	{
		isUse = true;
	}
	else
	{
		MessageBox(_T("请选择清理项"));
	}
	DWORD code;
	bool res = GetExitCodeThread(handle, &code);
	for (;true;)
	{

		if (!res&&code == STILL_ACTIVE/*!isUse*/)
		{

		}
		else
		{
			m_cProgress.SetWindowTextW(_T(""));
			
			return;
		}
	}

}
