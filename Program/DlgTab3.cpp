// DlgTab3.cpp : 实现文件
//

#include "stdafx.h"
#include "Program.h"
#include "DlgTab3.h"
#include "afxdialogex.h"


// CDlgTab3 对话框

IMPLEMENT_DYNAMIC(CDlgTab3, CDialogEx)

CDlgTab3::CDlgTab3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_TAB3, pParent)
{

}

CDlgTab3::~CDlgTab3()
{
}

void CDlgTab3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgTab3, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_FILECREATE, &CDlgTab3::OnBnClickedRadioFilecreate)
	ON_BN_CLICKED(IDC_RADIO_FOLDERCREATE, &CDlgTab3::OnBnClickedRadioFoldercreate)
END_MESSAGE_MAP()


// CDlgTab3 消息处理程序



void CDlgTab3::OnBnClickedRadioFilecreate()
{
	// TODO: 在此添加控件通知处理程序代码
	//((CMFCButton*)GetDlgItem(IDC_RADIO_FILECREATE))
	((CMFCButton*)GetDlgItem(IDC_RADIO_DOC))->ShowWindow(false);
	((CMFCButton*)GetDlgItem(IDC_RADIO_PPT))->ShowWindow(false);
	((CMFCButton*)GetDlgItem(IDC_RADIO_XLS))->ShowWindow(false);
	((CMFCButton*)GetDlgItem(IDC_RADIO_TXT))->ShowWindow(false);

}


BOOL CDlgTab3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	((CMFCButton*)GetDlgItem(IDC_RADIO_DOC))->ShowWindow(false);
	((CMFCButton*)GetDlgItem(IDC_RADIO_PPT))->ShowWindow(false);
	((CMFCButton*)GetDlgItem(IDC_RADIO_XLS))->ShowWindow(false);
	((CMFCButton*)GetDlgItem(IDC_RADIO_TXT))->ShowWindow(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgTab3::OnBnClickedRadioFoldercreate()
{
	// TODO: 在此添加控件通知处理程序代码
	((CMFCButton*)GetDlgItem(IDC_RADIO_DOC))->ShowWindow(true);
	((CMFCButton*)GetDlgItem(IDC_RADIO_PPT))->ShowWindow(true);
	((CMFCButton*)GetDlgItem(IDC_RADIO_XLS))->ShowWindow(true);
	((CMFCButton*)GetDlgItem(IDC_RADIO_TXT))->ShowWindow(true);
}
