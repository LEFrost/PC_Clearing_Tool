// DlgFileSize.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Program.h"
#include "DlgFileSize.h"
#include "afxdialogex.h"


// CDlgFileSize �Ի���

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


// CDlgFileSize ��Ϣ�������


void CDlgFileSize::OnBnClickedButtonFilesizeOk()
{
	// TODO: ��С��ҳ�洫ֵ\
	this->OnOK();
}


void CDlgFileSize::OnBnClickedButtonFilesizeCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->OnOK();
}
