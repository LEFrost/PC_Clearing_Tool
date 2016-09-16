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
}


BEGIN_MESSAGE_MAP(CDlgTab1, CDialogEx)
END_MESSAGE_MAP()


// CDlgTab1 消息处理程序



BOOL CDlgTab1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	getDisk(&m_cClearPro);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
