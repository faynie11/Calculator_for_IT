
// Calc_for_ele_projectDlg.h : header file
//

#pragma once


// CCalcforeleprojectDlg dialog
class CCalcforeleprojectDlg : public CDialogEx
{
// Construction
public:
	CCalcforeleprojectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALC_FOR_ELE_PROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton1();
	CComboBox system_conversion_to;
	CComboBox system_conversion_from;
	CString cstring_value_from;
	CString result;
};
