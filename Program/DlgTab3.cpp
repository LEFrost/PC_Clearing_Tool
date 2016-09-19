// DlgTab3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Program.h"
#include "DlgTab3.h"
#include "afxdialogex.h"

// CDlgTab3 �Ի���

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
	DDX_Control(pDX, IDC_EDIT4, m_cOutput);
}


BEGIN_MESSAGE_MAP(CDlgTab3, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_FILECREATE, &CDlgTab3::OnBnClickedRadioFilecreate)
	ON_BN_CLICKED(IDC_RADIO_FOLDERCREATE, &CDlgTab3::OnBnClickedRadioFoldercreate)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTab3::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDlgTab3 ��Ϣ�������



void CDlgTab3::OnBnClickedRadioFilecreate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//((CMFCButton*)GetDlgItem(IDC_RADIO_FILECREATE))
	((CMFCButton*)GetDlgItem(IDC_RADIO_DOC))->ShowWindow(false);
	((CMFCButton*)GetDlgItem(IDC_RADIO_PPT))->ShowWindow(false);
	((CMFCButton*)GetDlgItem(IDC_RADIO_XLS))->ShowWindow(false);
	((CMFCButton*)GetDlgItem(IDC_RADIO_TXT))->ShowWindow(false);

}


BOOL CDlgTab3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	((CMFCButton*)GetDlgItem(IDC_RADIO_DOC))->ShowWindow(false);
	((CMFCButton*)GetDlgItem(IDC_RADIO_PPT))->ShowWindow(false);
	((CMFCButton*)GetDlgItem(IDC_RADIO_XLS))->ShowWindow(false);
	((CMFCButton*)GetDlgItem(IDC_RADIO_TXT))->ShowWindow(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgTab3::OnBnClickedRadioFoldercreate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	((CMFCButton*)GetDlgItem(IDC_RADIO_DOC))->ShowWindow(true);
	((CMFCButton*)GetDlgItem(IDC_RADIO_PPT))->ShowWindow(true);
	((CMFCButton*)GetDlgItem(IDC_RADIO_XLS))->ShowWindow(true);
	((CMFCButton*)GetDlgItem(IDC_RADIO_TXT))->ShowWindow(true);
}


void CDlgTab3::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	getFolderPath(&m_cOutput, &m_hWnd);
}
