#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "Function.h"
#include "FileCount.h"

// CDlgTab4 �Ի���

class CDlgTab4 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTab4)

public:
	CDlgTab4(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTab4();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TAB4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_cFileCountList;
	afx_msg void OnLvnItemchangedListFilecount(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_cSelPath;
	afx_msg void OnBnClickedButton();
	afx_msg void OnBnClickedButtonStart();
	CEdit m_cCount;
};
