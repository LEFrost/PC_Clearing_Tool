
// ProgramDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "DlgTab1.h"
#include "DlgTab2.h"
#include "DlgTab3.h"
#include "DlgTab4.h"

// CProgramDlg 对话框
class CProgramDlg : public CDialogEx
{
// 构造
public:
	CProgramDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROGRAM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_cTabMain;
	CDlgTab1 m_cDlgTab1;
	CDlgTab2 m_cDlgTab2;
	CDlgTab3 m_cDlgTab3;
	CDlgTab4 m_cDlgTab4;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
