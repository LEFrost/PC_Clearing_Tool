#pragma once
#include "afxwin.h"
#include "Function.h"
#include "afxcmn.h"

// CDlgTab1 �Ի���

class CDlgTab1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTab1)

public:
	CDlgTab1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTab1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TAB1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheckWebfile();
	afx_msg void OnBnClickedCheckSystemfile();
	virtual BOOL OnInitDialog();
	CComboBox m_cClearPro;
	CListCtrl m_cClearProList;
	afx_msg void OnNMClickSyslinkClearpro(NMHDR *pNMHDR, LRESULT *pResult);
};
