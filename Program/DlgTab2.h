#pragma once


// CDlgTab2 对话框
#include "DlgFileSize.h"
#include "Function.h"
#include "afxwin.h"
#include "afxcmn.h"


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
	CListCtrl m_cBigFile;
	CListCtrl m_cConditionFind;
	CListCtrl m_cSameFile;
	afx_msg void OnNMClickSyslinkBigfile(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkSamefile(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonTab2Find();
	afx_msg void OnBnClickedButtonTba2Clear();
	afx_msg void OnCbnSelchangeComboFilenameSle();
	int selItem[3] = { false,false,false };
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnNMClickSyslinkBigfile2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeComboFileclear();
	afx_msg void OnNMClickSyslinkConditionfind(NMHDR *pNMHDR, LRESULT *pResult);
	CComboBox m_cConditionFindCombo;
	afx_msg void OnBnClickedButtonConditionfind();
	CEdit m_cConditionName;
	CEdit m_cMinSize;
	CEdit m_cMaxSize;
	afx_msg void OnLvnItemchangedListConditionfind(NMHDR *pNMHDR, LRESULT *pResult);
};
