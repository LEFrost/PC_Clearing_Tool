// DlgTab1.cpp : 实现文件
//

#include "stdafx.h"
#include "Program.h"
#include "DlgTab1.h"
#include "afxdialogex.h"


// CDlgTab1 对话框

IMPLEMENT_DYNAMIC(CDlgTab1, CDialogEx)

CDlgTab1::CDlgTab1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_TAB1, pParent)
{

}

CDlgTab1::~CDlgTab1()
{
}

void CDlgTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_CLEAR_PRO, m_cClearPro);
	DDX_Control(pDX, IDC_LIST_CLEARPRO, m_cClearProList);
}


BEGIN_MESSAGE_MAP(CDlgTab1, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK_CLEARPRO, &CDlgTab1::OnNMClickSyslinkClearpro)
END_MESSAGE_MAP()


// CDlgTab1 消息处理程序



BOOL CDlgTab1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
#pragma region 界面初始化
	getDisk(&m_cClearPro);

	m_cClearProList.InsertColumn(0, _T("文件名"),LVCFMT_LEFT,100);
	m_cClearProList.InsertColumn(1, _T("路径"), LVCFMT_LEFT, 200);

#pragma endregion

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgTab1::OnNMClickSyslinkClearpro(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	getDisk(&m_cClearPro);
}
