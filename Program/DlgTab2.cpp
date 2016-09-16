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
}


BEGIN_MESSAGE_MAP(CDlgTab2, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_FILESIZE, &CDlgTab2::OnBnClickedRadioFilesize)
	ON_BN_CLICKED(IDC_RADIO_FILETIME, &CDlgTab2::OnBnClickedRadioFiletime)
	ON_BN_CLICKED(IDC_RADIO_FILENAME, &CDlgTab2::OnBnClickedRadioFilename)
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
#pragma endregion

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
