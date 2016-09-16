// DlgTab2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Program.h"
#include "DlgTab2.h"
#include "afxdialogex.h"


// CDlgTab2 �Ի���

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


// CDlgTab2 ��Ϣ�������



void CDlgTab2::OnBnClickedRadioFilesize()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	((CButton *)GetDlgItem(IDC_RADIO_FILESIZE))->SetCheck(true);
	((CButton *)GetDlgItem(IDC_RADIO_FILETIME))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIO_FILENAME))->SetCheck(false);
	CDlgFileSize m_cDlgFileSize;
	m_cDlgFileSize.DoModal();
}


void CDlgTab2::OnBnClickedRadioFiletime()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	((CButton *)GetDlgItem(IDC_RADIO_FILESIZE))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIO_FILETIME))->SetCheck(true);
	((CButton *)GetDlgItem(IDC_RADIO_FILENAME))->SetCheck(false);
}


void CDlgTab2::OnBnClickedRadioFilename()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	((CButton *)GetDlgItem(IDC_RADIO_FILESIZE))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIO_FILETIME))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIO_FILENAME))->SetCheck(true);
}




BOOL CDlgTab2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
#pragma region �����ʼ��

	getDisk(&m_cBigFileClear);
	getDisk(&m_cFindSameNameFile);
#pragma endregion

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
