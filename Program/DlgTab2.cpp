// DlgTab2.cpp : 实现文件
//

#include "stdafx.h"
#include "Program.h"
#include "DlgTab2.h"
#include "afxdialogex.h"


// CDlgTab2 对话框

IMPLEMENT_DYNAMIC(CDlgTab2, CDialogEx)

CDlgTab2::CDlgTab2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_TAB2, pParent)
{

}

CDlgTab2::~CDlgTab2()
{
}

void CDlgTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_FILECLEAR, m_cBigFileClear);
	DDX_Control(pDX, IDC_COMBO_FILENAME_SLE, m_cSelTime);
	DDX_Control(pDX, IDC_COMBO_SAMEFILE, m_cFindSameNameFile);
	DDX_Control(pDX, IDC_LIST_BIGFILECLEAR, m_cBigFile);
	DDX_Control(pDX, IDC_LIST_CONDITIONFIND, m_cConditionFind);
	DDX_Control(pDX, IDC_LIST_SMAEFILE, m_cSameFile);
	DDX_Control(pDX, IDC_COMBO1, m_cConditionFindCombo);
	DDX_Control(pDX, IDC_EDIT1, m_cConditionName);
	DDX_Control(pDX, IDC_EDIT3, m_cMinSize);
	DDX_Control(pDX, IDC_EDIT4, m_cMaxSize);
}


BEGIN_MESSAGE_MAP(CDlgTab2, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_FILESIZE, &CDlgTab2::OnBnClickedRadioFilesize)
	ON_BN_CLICKED(IDC_RADIO_FILETIME, &CDlgTab2::OnBnClickedRadioFiletime)
	ON_BN_CLICKED(IDC_RADIO_FILENAME, &CDlgTab2::OnBnClickedRadioFilename)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK_BIGFILE, &CDlgTab2::OnNMClickSyslinkBigfile)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK_SAMEFILE, &CDlgTab2::OnNMClickSyslinkSamefile)
	ON_BN_CLICKED(IDC_BUTTON_TAB2_FIND, &CDlgTab2::OnBnClickedButtonTab2Find)
	ON_BN_CLICKED(IDC_BUTTON_TBA2_CLEAR, &CDlgTab2::OnBnClickedButtonTba2Clear)
	ON_CBN_SELCHANGE(IDC_COMBO_FILENAME_SLE, &CDlgTab2::OnCbnSelchangeComboFilenameSle)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK_CONDITIONFIND, &CDlgTab2::OnNMClickSyslinkConditionfind)
	ON_BN_CLICKED(IDC_BUTTON_CONDITIONFIND, &CDlgTab2::OnBnClickedButtonConditionfind)
END_MESSAGE_MAP()


// CDlgTab2 消息处理程序



void CDlgTab2::OnBnClickedRadioFilesize()
{
	// TODO: 在此添加控件通知处理程序代码
	((CButton *)GetDlgItem(IDC_RADIO_FILESIZE))->SetCheck(true);
	((CButton *)GetDlgItem(IDC_RADIO_FILETIME))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIO_FILENAME))->SetCheck(false);
	selItem[0] = false;
	selItem[1] = false;
	selItem[2] = true;
}


void CDlgTab2::OnBnClickedRadioFiletime()
{
	// TODO: 在此添加控件通知处理程序代码
	((CButton *)GetDlgItem(IDC_RADIO_FILESIZE))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIO_FILETIME))->SetCheck(true);
	((CButton *)GetDlgItem(IDC_RADIO_FILENAME))->SetCheck(false);
	selItem[0] = true;
	selItem[1] = false;
	selItem[2] = false;
}


void CDlgTab2::OnBnClickedRadioFilename()
{
	// TODO: 在此添加控件通知处理程序代码
	((CButton *)GetDlgItem(IDC_RADIO_FILESIZE))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIO_FILETIME))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIO_FILENAME))->SetCheck(true);
	selItem[0] = false;
	selItem[1] = true;
	selItem[2] = false;
}




BOOL CDlgTab2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
#pragma region 界面初始化

	getDisk(&m_cBigFileClear);
	getDisk(&m_cFindSameNameFile);
	getDisk(&m_cConditionFindCombo);
	m_cBigFile.InsertColumn(0, _T("大小"), LVCFMT_LEFT, 100);
	m_cBigFile.InsertColumn(1, _T("路径"), LVCFMT_LEFT, 500);
	m_cConditionFind.InsertColumn(0, _T("路径"), LVCFMT_LEFT, 500);
	m_cSameFile.InsertColumn(0, _T("文件名"), LVCFMT_LEFT, 100);
	m_cSameFile.InsertColumn(1, _T("路径"), LVCFMT_LEFT, 200);

	m_cSelTime.AddString(_T("一天之内"));
	m_cSelTime.AddString(_T("三天之内"));
	m_cSelTime.AddString(_T("一周之内"));
	m_cSelTime.AddString(_T("一月之内"));
#pragma endregion

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgTab2::OnNMClickSyslinkBigfile(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	getDisk(&m_cBigFileClear);
}


void CDlgTab2::OnNMClickSyslinkSamefile(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	getDisk(&m_cFindSameNameFile);
}


void CDlgTab2::OnBnClickedButtonTab2Find()
{
	// TODO: Add your control notification handler code here
	m_cBigFile.DeleteAllItems();
	CFindBigFile * FindBig = new CFindBigFile();
	FindBig->pList = &m_cBigFile;
	m_cBigFileClear.GetWindowText(*(FindBig->strDir));
	HANDLE handle;
	handle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)FindBig->FindBigFile, FindBig, 0, 0);
}


void CDlgTab2::OnBnClickedButtonTba2Clear()
{
	// TODO: Add your control notification handler code here

	int nSelect = m_cBigFile.GetSelectedCount();
	if (nSelect == 0)
	{
		MessageBox(L"NO");
	}
	else
	{
		POSITION pos = m_cBigFile.GetFirstSelectedItemPosition();
		if (pos == NULL)
		{
			return;
		}
		else
		{
			while (pos)
			{
				int nItem = m_cBigFile.GetNextSelectedItem(pos);
				CString path = m_cBigFile.GetItemText(nItem, 1);

				m_cBigFile.DeleteItem(nItem);
				DeleteFile(path);

				pos = m_cBigFile.GetFirstSelectedItemPosition();
			}
		}

	}
}

static CFindFileForCondition* fileCondition = new CFindFileForCondition();
void CDlgTab2::OnCbnSelchangeComboFilenameSle()
{
	// TODO: Add your control notification handler code here
	int nItem;
	nItem = m_cSelTime.GetCurSel();
	int dayTemp;
	switch (nItem)
	{
	case 0:
		dayTemp = 24 * 60 * 60;
		break;
	case 1:
		dayTemp = 24 * 60 * 60 * 3;
		break;
	case 2:
		dayTemp = 24 * 60 * 60 * 7;
		break;
	case 3:
		dayTemp = 24 * 60 * 60 * 30;
		break;
	default:
		break;
	}
	
	fileCondition->timeDifference = dayTemp;
}





void CDlgTab2::OnNMClickSyslinkConditionfind(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	getDisk(&m_cBigFileClear);

}


void CDlgTab2::OnBnClickedButtonConditionfind()
{
	HANDLE handle;
	// TODO: Add your control notification handler code here
	m_cConditionFind.DeleteAllItems();
	m_cConditionFindCombo.GetWindowText(*(fileCondition->strDir));
	fileCondition->pList = &m_cConditionFind;
	if (selItem[0])
	{
		handle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)fileCondition->FindFileForTime, fileCondition, 0, 0);

	}
	else if(selItem[1])
	{
		m_cConditionName.GetWindowText(fileCondition->Name);
		handle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)fileCondition->FindFileForName, fileCondition, 0, 0);
	}
	else if(selItem[2])
	{
		m_cMinSize.GetWindowText(fileCondition->minSize);
		m_cMaxSize.GetWindowTextW(fileCondition->maxSize);
		long i = _ttoi64(fileCondition->minSize);
		long x = _ttoi64(fileCondition->maxSize);
		if (fileCondition->minSize.IsEmpty()|| fileCondition->maxSize.IsEmpty())
			MessageBox(L"请输入值域");
		else
		{

			if (i < 0 || x < 0)
				MessageBox(L"不能输入小于零的数");
			else
			{
				if (i > x)
					MessageBox(L"最小值不能大于最小值");
				else
				{
					handle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)fileCondition->FindFileForSize, fileCondition, 0, 0);

				}
			}
		}
	}
	else
	{
		MessageBox(L"请选择查找方法");
	}
}


