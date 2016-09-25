// DlgFileSize.cpp : 实现文件
//

#include "stdafx.h"
#include "Program.h"
#include "DlgFileSize.h"
#include "afxdialogex.h"


// CDlgFileSize 对话框

IMPLEMENT_DYNAMIC(CDlgFileSize, CDialogEx)

CDlgFileSize::CDlgFileSize(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_FILESIZE_SEL_PAGE, pParent)
{

}

CDlgFileSize::~CDlgFileSize()
{
}

void CDlgFileSize::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgFileSize, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_FILESIZE_OK, &CDlgFileSize::OnBnClickedButtonFilesizeOk)
	ON_BN_CLICKED(IDC_BUTTON_FILESIZE_CANCEL, &CDlgFileSize::OnBnClickedButtonFilesizeCancel)
END_MESSAGE_MAP()


// CDlgFileSize 消息处理程序


void CDlgFileSize::OnBnClickedButtonFilesizeOk()
{
	// TODO: 大小的页面传值\
	this->OnOK();
}


void CDlgFileSize::OnBnClickedButtonFilesizeCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	this->OnOK();
}
