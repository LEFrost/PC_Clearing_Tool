#pragma once


// CDlgTab3 对话框
#include "Function.h"
#include "afxwin.h"


class CDlgTab3 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTab3)

public:
	CDlgTab3(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgTab3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TAB3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadioFilecreate();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadioFoldercreate();
	CEdit m_cOutput;
	afx_msg void OnBnClickedButton2();
};
