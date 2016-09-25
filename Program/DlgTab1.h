#pragma once
#include "afxwin.h"
#include "Function.h"
#include "afxcmn.h"
#include "ClearPro.h"
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
	afx_msg void OnBnClickedButtonClearEasy();
	CButton m_cSystemTempFile;
	CButton m_cUserLocalFile;
	CEdit m_cProgress;
	afx_msg void OnBnClickedButtonSeldisk();
	afx_msg void OnBnClickedCheck5();
	CClearPro* clearPro = new CClearPro();

	afx_msg void OnBnClickedCheckTmp();
	afx_msg void OnBnClickedCheckLog();
	afx_msg void OnBnClickedCheckMp();
	afx_msg void OnBnClickedCheckGid();
	afx_msg void OnBnClickedCheckChk();
	afx_msg void OnBnClickedCheckOld();
	afx_msg void OnBnClickedCheckPf();
	afx_msg void OnBnClickedCheckDiz();
	afx_msg void OnBnClickedButtonClearPro();
};
