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
	DDX_Control(pDX, IDC_EDIT1, m_cFront);
	DDX_Control(pDX, IDC_EDIT2, m_cLast);
	DDX_Control(pDX, IDC_EDIT3, m_cNum);
}


BEGIN_MESSAGE_MAP(CDlgTab3, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_FILECREATE, &CDlgTab3::OnBnClickedRadioFilecreate)
	ON_BN_CLICKED(IDC_RADIO_FOLDERCREATE, &CDlgTab3::OnBnClickedRadioFoldercreate)
	ON_BN_CLICKED(IDC_BUTTON_MAKEFILE, &CDlgTab3::OnBnClickedButtonMakefile)
	ON_BN_CLICKED(IDC_BUTTON_VIEWPATH, &CDlgTab3::OnBnClickedButtonViewpath)
	ON_BN_CLICKED(IDC_RADIO_DOC, &CDlgTab3::OnBnClickedRadioDoc)
	ON_BN_CLICKED(IDC_RADIO_PPT, &CDlgTab3::OnBnClickedRadioPpt)
	ON_BN_CLICKED(IDC_RADIO_XLS, &CDlgTab3::OnBnClickedRadioXls)
	ON_BN_CLICKED(IDC_RADIO_TXT, &CDlgTab3::OnBnClickedRadioTxt)
END_MESSAGE_MAP()


// CDlgTab3 ��Ϣ�������



void CDlgTab3::OnBnClickedRadioFilecreate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//((CMFCButton*)GetDlgItem(IDC_RADIO_FILECREATE))

	((CMFCButton*)GetDlgItem(IDC_RADIO_DOC))->ShowWindow(true);
	((CMFCButton*)GetDlgItem(IDC_RADIO_PPT))->ShowWindow(true);
	((CMFCButton*)GetDlgItem(IDC_RADIO_XLS))->ShowWindow(true);
	((CMFCButton*)GetDlgItem(IDC_RADIO_TXT))->ShowWindow(true);
	isCreatFile = true;
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
	((CMFCButton*)GetDlgItem(IDC_RADIO_DOC))->ShowWindow(false);
	((CMFCButton*)GetDlgItem(IDC_RADIO_PPT))->ShowWindow(false);
	((CMFCButton*)GetDlgItem(IDC_RADIO_XLS))->ShowWindow(false);
	((CMFCButton*)GetDlgItem(IDC_RADIO_TXT))->ShowWindow(false);
	isCreatFile = false;
}



void CDlgTab3::OnBnClickedButtonMakefile()
{
	// TODO: Add your control notification handler code here
	CFolderAndFileCreate* create = new CFolderAndFileCreate();
	HWND *hwnd = new HWND();
	create->hWnd = hwnd;
	CString temp;
	m_cNum.GetWindowText(temp);
	create->Num = _ttoi(temp);
	m_cFront.GetWindowText(create->fristName);
	m_cLast.GetWindowText(create->lastName);
	m_cOutput.GetWindowText(*(create->strDir));
	if (isCreatFile)
	{
		if (strExt.IsEmpty())
			MessageBox(L"ѡ���ļ�����");
		else
		{

			*(create->strExt)=strExt;
			create->FileCreate(create);
		}
	}
	else
	{
		create->FolderCreate(create);

	}


}


void CDlgTab3::OnBnClickedButtonViewpath()
{
	// TODO: Add your control notification handler code here
	getFolderPath(&m_cOutput, &m_hWnd);

}


void CDlgTab3::OnBnClickedRadioDoc()
{
	// TODO: Add your control notification handler code here
	strExt = ".doc";
}


void CDlgTab3::OnBnClickedRadioPpt()
{
	// TODO: Add your control notification handler code here
	strExt = ".ppt";
}


void CDlgTab3::OnBnClickedRadioXls()
{
	// TODO: Add your control notification handler code here
	strExt = ".xls";
}


void CDlgTab3::OnBnClickedRadioTxt()
{
	// TODO: Add your control notification handler code here
	strExt = ".txt";
}
