#pragma once


// CDlgTab2 对话框
#include "DlgFileSize.h"
#include "Function.h"
#include "afxwin.h"


class CDlgTab2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTab2)

public:
	CDlgTab2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgTab2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TAB2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedRadioFilesize();
	afx_msg void OnBnClickedRadioFiletime();
	afx_msg void OnBnClickedRadioFilename();
	afx_msg void OnLbnSelchangeList3();
	virtual BOOL OnInitDialog();
	CComboBox m_cBigFileClear;
	CComboBox m_cSelTime;
	CComboBox m_cFindSameNameFile;
};
