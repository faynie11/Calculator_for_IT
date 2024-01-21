
// Calc_for_ele_projectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Calc_for_ele_project.h"
#include "Calc_for_ele_projectDlg.h"
#include "afxdialogex.h"
#include "Conversions.h"
#include <algorithm>
#include <sstream>
#include <atlconv.h>
#include <atlstr.h>
#include <string>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define _AFXDLL


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalcforeleprojectDlg dialog



CCalcforeleprojectDlg::CCalcforeleprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALC_FOR_ELE_PROJECT_DIALOG, pParent)
	, cstring_value_from(_T(""))
	, result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalcforeleprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, system_conversion_to);
	DDX_Control(pDX, IDC_COMBO1, system_conversion_from);
	DDX_Text(pDX, IDC_EDIT1, cstring_value_from);
	DDX_Text(pDX, IDC_EDIT2, result);
}

BEGIN_MESSAGE_MAP(CCalcforeleprojectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT2, &CCalcforeleprojectDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalcforeleprojectDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CCalcforeleprojectDlg message handlers

BOOL CCalcforeleprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalcforeleprojectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalcforeleprojectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalcforeleprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalcforeleprojectDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CCalcforeleprojectDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);

	CString data;
	CString finalData;

	int nIndex = system_conversion_from.GetCurSel(); //Pobieranie danych z comboboxa nr1
	system_conversion_from.GetLBText(nIndex, data);

	int finalIndex = system_conversion_to.GetCurSel(); //Pobieranie danych z comboboxa nr2
	system_conversion_to.GetLBText(finalIndex, finalData);

	std::string Converions_value = CT2A(cstring_value_from); //Pobranie wartosci z editcontrola
	

	std::string system_from = CT2A(data); //konwersja na stringa z CStringa z pierwszego comboxa
	std::string system_to = CT2A(finalData);
	
	Conversions System_Converions;
	
	if (system_from == "Dec" && system_to == "Bin") {

		for (int i = 0; i < Converions_value.size(); i++) {
			char c = Converions_value[i];
			if (!(c >= '0' && c <= '9')) {
				MessageBox(_T("Type right Decimal number!"), _T("Error"), MB_OK | MB_ICONERROR);
				result = "Error";
				break;
			}
			else {
				std::string dec_bin = System_Converions.DecimalToBinary(Converions_value);
				result = dec_bin.c_str();
			}
		}
	}
	else if (system_from == "Dec" && system_to == "Oct") {

		for (int i = 0; i < Converions_value.size(); i++) {
			char c = Converions_value[i];
			if (!(c >= '0' && c <= '9')) {
				MessageBox(_T("Type right Decimal number!"), _T("Error"), MB_OK | MB_ICONERROR);
				result = "Error";
				break;
			}
			else {
				std::string dec_oct = System_Converions.DecimalToOctal(Converions_value);
				result = dec_oct.c_str();
			}
		}
	}
	else if (system_from == "Dec" && system_to == "Hex") {

		for (int i = 0; i < Converions_value.size(); i++) {
			char c = Converions_value[i];
			if (!(c >= '0' && c <= '9')) {
				MessageBox(_T("Type right Decimal number!"), _T("Error"), MB_OK | MB_ICONERROR);
				result = "Error";
				break;
			}
			else {
				std::string dec_hex = System_Converions.DecimalToHexadecimal(Converions_value);
				result = dec_hex.c_str();
			}
		}
	}
	else if (system_from == "Bin" && system_to == "Dec") {

		for (int i = 0; i < Converions_value.size(); i++) {
			char c = Converions_value[i];
			if (c != '0' && c != '1') {
				MessageBox(_T("Type right binary number!"), _T("Error"), MB_OK | MB_ICONERROR);
				result = "Error";
				break;
			}
			else {
				std::string bin_dec = System_Converions.BinaryToDecimal(Converions_value);
				result = bin_dec.c_str();
			}
		}
	}
	else if (system_from == "Bin" && system_to == "Oct") {

		for (int i = 0; i < Converions_value.size(); i++) {
			char c = Converions_value[i];
			if (c != '0' && c != '1') {
				MessageBox(_T("Type right binary number!"), _T("Error"), MB_OK | MB_ICONERROR);
				result = "Error";
				break;
			}
			else {
				std::string bin_dec = System_Converions.BinaryToDecimal(Converions_value);
				std::string bin_oct = System_Converions.DecimalToOctal(bin_dec);
				result = bin_oct.c_str();
			}
		}

	}
	else if (system_from == "Bin" && system_to == "Hex") {
		for (int i = 0; i < Converions_value.size(); i++) {
			char c = Converions_value[i];
			if (c != '0' && c != '1') {
				MessageBox(_T("Type right binary number!"), _T("Error"), MB_OK | MB_ICONERROR);
				result = "Error";
				break;
			}
			else {
				std::string bin_dec = System_Converions.BinaryToDecimal(Converions_value);
				std::string dec_hex = System_Converions.DecimalToHexadecimal(bin_dec);
				result = dec_hex.c_str();
			}
		}
	}
	else if (system_from == "Oct" && system_to == "Dec") {

		for (int i = 0; i < Converions_value.size(); i++) {
			char c = Converions_value[i];
			if (!(c >= '0' && c <= '7')) {
				MessageBox(_T("Type right Octal number!"), _T("Error"), MB_OK | MB_ICONERROR);
				result = "Error";
				break;
			}
			else {
				std::string oct_dec = System_Converions.OctalToDecimal(Converions_value);
				result = oct_dec.c_str();
			}
		}
	}
	else if (system_from == "Oct" && system_to == "Bin") {

		for (int i = 0; i < Converions_value.size(); i++) {
			char c = Converions_value[i];
			if (!(c >= '0' && c <= '7')) {
				MessageBox(_T("Type right Octal number!"), _T("Error"), MB_OK | MB_ICONERROR);
				result = "Error";
				break;
			}
			else {
				std::string oct_dec = System_Converions.OctalToDecimal(Converions_value);
				std::string dec_bin = System_Converions.DecimalToBinary(oct_dec);
				result = dec_bin.c_str();
			}
		}
	}
	else if (system_from == "Oct" && system_to == "Hex") {

		for (int i = 0; i < Converions_value.size(); i++) {
			char c = Converions_value[i];
			if (!(c >= '0' && c <= '7')) {
				MessageBox(_T("Type right Octal number!"), _T("Error"), MB_OK | MB_ICONERROR);
				result = "Error";
				break;
			}
			else {
				std::string oct_dec = System_Converions.OctalToDecimal(Converions_value);
				std::string dec_hex = System_Converions.DecimalToHexadecimal(oct_dec);
				result = dec_hex.c_str();
			}
		}
	}
	else if (system_from == "Hex" && system_to == "Dec") {

		for (int i = 0; i < Converions_value.size(); i++) {
			char c = Converions_value[i];
			if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) {
				MessageBox(_T("Type right HexaDecimal number! Please use upper letters!"), _T("Error"), MB_OK | MB_ICONERROR);
				result = "Error";
				break;
			}
			else {
				std::string hex_dec = System_Converions.HexadecimalToDecimal(Converions_value);
				result = hex_dec.c_str();
			}
		}
	}
	else if (system_from == "Hex" && system_to == "Bin") {

		for (int i = 0; i < Converions_value.size(); i++) {
			char c = Converions_value[i];
			if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) {
				MessageBox(_T("Type right HexaDecimal number! Please use upper letters!"), _T("Error"), MB_OK | MB_ICONERROR);
				result = "Error";
				break;
			}
			else {
				std::string hex_dec = System_Converions.HexadecimalToDecimal(Converions_value);
				std::string dec_bin = System_Converions.DecimalToBinary(hex_dec);
				result = dec_bin.c_str();
			}
		}
	}
	else if (system_from == "Hex" && system_to == "Oct") {

		for (int i = 0; i < Converions_value.size(); i++) {
			char c = Converions_value[i];
			if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) {
				MessageBox(_T("Type right HexaDecimal number! Please use upper letters!"), _T("Error"), MB_OK | MB_ICONERROR);
				result = "Error";
				break;
			}
			else {
				std::string hex_dec = System_Converions.HexadecimalToDecimal(Converions_value);
				std::string dec_bin = System_Converions.DecimalToOctal(hex_dec);
				result = dec_bin.c_str();
			}
		}
	}
	else if (system_from == system_to) {

		result = Converions_value.c_str();
		MessageBox(_T("It makes non sense"), _T("Error"), MB_OK | MB_ICONERROR);

	}
	


	UpdateData(FALSE);
}
