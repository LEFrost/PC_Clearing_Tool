#pragma once
#include "afxwin.h"
#include "Function.h"
#include "afxcmn.h"

// CDlgTab1 对话框

class CDlgTab1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTab1)

public:
	CDlgTab1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgTab1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TAB1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheckWebfile();
	afx_msg void OnBnClickedCheckSystemfile();
	virtual BOOL OnInitDialog();
	CComboBox m_cClearPro;
	CListCtrl m_cClearProList;
	afx_msg void OnNMClickSyslinkClearpro(NMHDR *pNMHDR, LRESULT *pResult);
};
