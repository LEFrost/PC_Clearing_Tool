#pragma once


// CDlgTab3 �Ի���
#include "Function.h"
#include "afxwin.h"


class CDlgTab3 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTab3)

public:
	CDlgTab3(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTab3();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TAB3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadioFilecreate();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadioFoldercreate();
	CEdit m_cOutput;
	afx_msg void OnBnClickedButton2();
};
