#pragma once


// CDlgFileSize �Ի���

class CDlgFileSize : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgFileSize)

public:
	CDlgFileSize(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgFileSize();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FILESIZE_SEL_PAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonFilesizeOk();
	afx_msg void OnBnClickedButtonFilesizeCancel();
};
