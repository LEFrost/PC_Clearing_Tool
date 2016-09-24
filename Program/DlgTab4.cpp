// DlgTab4.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Program.h"
#include "DlgTab4.h"
#include "afxdialogex.h"


// CDlgTab4 �Ի���

IMPLEMENT_DYNAMIC(CDlgTab4, CDialogEx)

CDlgTab4::CDlgTab4(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_TAB4, pParent)
{

}

CDlgTab4::~CDlgTab4()
{
}

void CDlgTab4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_FILECOUNT, m_cFileCountList);
	DDX_Control(pDX, IDC_EDIT1, m_cSelPath);
	DDX_Control(pDX, IDC_EDIT_COUNT, m_cCount);
}


BEGIN_MESSAGE_MAP(CDlgTab4, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_, &CDlgTab4::OnBnClickedButton)
	ON_BN_CLICKED(IDC_BUTTON_START, &CDlgTab4::OnBnClickedButtonStart)
END_MESSAGE_MAP()


// CDlgTab4 ��Ϣ�������


BOOL CDlgTab4::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��


#pragma region �����ʼ��

	m_cFileCountList.InsertColumn(0, _T("����"), LVCFMT_LEFT, 50);
	m_cFileCountList.InsertColumn(1, _T("��С"), LVCFMT_LEFT, 100);
	m_cFileCountList.InsertColumn(2, _T("·��"), LVCFMT_LEFT, 500);

#pragma endregion

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}





void CDlgTab4::OnBnClickedButton()
{
	// TODO: Add your control notification handler code here
	getFolderPath(&m_cSelPath, &m_hWnd);
}


void CDlgTab4::OnBnClickedButtonStart()
{
	// TODO: Add your control notification handler code here
	m_cFileCountList.DeleteAllItems();

	ClearStruct* fileCount = new ClearStruct();
	fileCount->pList = &m_cFileCountList;
	m_cSelPath.GetWindowText(*(fileCount->strDir));
	fileCount->cEdit = &m_cCount;
	HANDLE handle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)FileCount, fileCount, 0, 0);
}
