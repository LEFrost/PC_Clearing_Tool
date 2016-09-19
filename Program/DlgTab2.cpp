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
	m_cBigFile.InsertColumn(0, _T("�ļ���"), LVCFMT_LEFT, 100);
	m_cBigFile.InsertColumn(1, _T("��С"), LVCFMT_LEFT, 50);
	m_cBigFile.InsertColumn(2, _T("·��"), LVCFMT_LEFT, 200);
	m_cConditionFind.InsertColumn(0, _T("�ļ���"), LVCFMT_LEFT, 100);
	m_cConditionFind.InsertColumn(1, _T("·��"), LVCFMT_LEFT, 200);
	m_cSameFile.InsertColumn(0, _T("�ļ���"), LVCFMT_LEFT, 100);
	m_cSameFile.InsertColumn(1, _T("·��"), LVCFMT_LEFT, 200);

	m_cSelTime.AddString(_T("һ��֮��"));
	m_cSelTime.AddString(_T("����֮��"));
	m_cSelTime.AddString(_T("һ��֮��"));
	m_cSelTime.AddString(_T("һ��֮��"));
#pragma endregion

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
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
