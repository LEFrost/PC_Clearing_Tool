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
}


BEGIN_MESSAGE_MAP(CDlgTab2, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_FILESIZE, &CDlgTab2::OnBnClickedRadioFilesize)
	ON_BN_CLICKED(IDC_RADIO_FILETIME, &CDlgTab2::OnBnClickedRadioFiletime)
	ON_BN_CLICKED(IDC_RADIO_FILENAME, &CDlgTab2::OnBnClickedRadioFilename)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK_BIGFILE, &CDlgTab2::OnNMClickSyslinkBigfile)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK_SAMEFILE, &CDlgTab2::OnNMClickSyslinkSamefile)
END_MESSAGE_MAP()


// CDlgTab2 消息处理程序



void CDlgTab2::OnBnClickedRadioFilesize()
{
	// TODO: 在此添加控件通知处理程序代码
	((CButton *)GetDlgItem(IDC_RADIO_FILESIZE))->SetCheck(true);
	((CButton *)GetDlgItem(IDC_RADIO_FILETIME))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIO_FILENAME))->SetCheck(false);
	CDlgFileSize m_cDlgFileSize;
	m_cDlgFileSize.DoModal();
}


void CDlgTab2::OnBnClickedRadioFiletime()
{
	// TODO: 在此添加控件通知处理程序代码
	((CButton *)GetDlgItem(IDC_RADIO_FILESIZE))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIO_FILETIME))->SetCheck(true);
	((CButton *)GetDlgItem(IDC_RADIO_FILENAME))->SetCheck(false);
}


void CDlgTab2::OnBnClickedRadioFilename()
{
	// TODO: 在此添加控件通知处理程序代码
	((CButton *)GetDlgItem(IDC_RADIO_FILESIZE))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIO_FILETIME))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIO_FILENAME))->SetCheck(true);
}




BOOL CDlgTab2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
#pragma region 界面初始化

	getDisk(&m_cBigFileClear);
	getDisk(&m_cFindSameNameFile);
	m_cBigFile.InsertColumn(0, _T("文件名"), LVCFMT_LEFT, 100);
	m_cBigFile.InsertColumn(1, _T("大小"), LVCFMT_LEFT, 50);
	m_cBigFile.InsertColumn(2, _T("路径"), LVCFMT_LEFT, 200);
	m_cConditionFind.InsertColumn(0, _T("文件名"), LVCFMT_LEFT, 100);
	m_cConditionFind.InsertColumn(1, _T("路径"), LVCFMT_LEFT, 200);
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
