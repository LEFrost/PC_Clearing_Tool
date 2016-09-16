#pragma once


// CDlgFileSize 对话框

class CDlgFileSize : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgFileSize)

public:
	CDlgFileSize(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgFileSize();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FILESIZE_SEL_PAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonFilesizeOk();
	afx_msg void OnBnClickedButtonFilesizeCancel();
};
