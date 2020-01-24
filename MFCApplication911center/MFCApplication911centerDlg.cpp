
// MFCApplication911centerDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication911center.h"
#include "MFCApplication911centerDlg.h"
#include "afxdialogex.h"
#include "Client.h"
#include "Event.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <vector>


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx{
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
public:
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


// CMFCApplication911centerDlg dialog



CMFCApplication911centerDlg::CMFCApplication911centerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION911CENTER_DIALOG, pParent)
	, m_strEmergencyList(_T(""))
	, m_ClientName(_T(""))
	, m_ClientLastName(_T(""))
	, m_ClientCity(_T(""))
	, m_ClientAddress(_T(""))
	, m_ClientReport(_T(""))
	, m_ClientPhone(_T(""))
	, m_ClientGender(_T("Unknown"))
	, m_Activity_log(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication911centerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_EMERGENCY_LIST, m_comboBoxControlEmergency);
	DDX_CBString(pDX, IDC_COMBO_EMERGENCY_LIST, m_strEmergencyList);
	DDX_Text(pDX, IDC_CALLER_NAME, m_ClientName);
	DDX_Text(pDX, IDC_CALLER_LAST_NAME, m_ClientLastName);
	DDX_Text(pDX, IDC_CALLER_CITY, m_ClientCity);
	DDX_Text(pDX, IDC_CALLER_ADDRESS, m_ClientAddress);
	DDX_Text(pDX, IDC_CALLER_REPORT, m_ClientReport);
	DDX_Text(pDX, IDC_EDIT6, m_ClientPhone);

	DDX_Text(pDX, IDC_ACTICITY_LOG, m_Activity_log);
	DDX_Control(pDX, IDC_CALLER_REPORT, c_ClientReport);
	DDX_Control(pDX, IDC_CALLER_NAME, c_ClientName);
	DDX_Control(pDX, IDC_CALLER_LAST_NAME, c_ClientLastName);
	DDX_Control(pDX, IDC_CALLER_CITY, c_clientCity);
	DDX_Control(pDX, IDC_EDIT6, c_ClientPhone);
	DDX_Control(pDX, IDC_CALLER_ADDRESS, c_ClientAddress);
}

BEGIN_MESSAGE_MAP(CMFCApplication911centerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO_EMERGENCY_LIST, &CMFCApplication911centerDlg::OnCbnSelchangeComboEmergency)
	ON_BN_CLICKED(IDC_CALLER_BUTTON_START, &CMFCApplication911centerDlg::OnBnClickedCallerButtonStart)

	ON_BN_CLICKED(IDC_RADIO1, &CMFCApplication911centerDlg::OnBnClickedRadioEventFormMale)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCApplication911centerDlg::OnBnClickedRadioEventFormFemale)
END_MESSAGE_MAP()


// CMFCApplication911centerDlg message handlers

BOOL CMFCApplication911centerDlg::OnInitDialog()
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
	addEventsToComboBox();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication911centerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication911centerDlg::OnPaint()
{
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);

	CFont font;
	font.CreatePointFont(500, _T("Arial"));
	CFont* oldFont = dc.SelectObject(&font);
	dc.SetBkMode(TRANSPARENT);

	CString string = _T("911 Center");
	rect.OffsetRect(8, 8);
	dc.SetTextColor(RGB(255, 0, 0));
	dc.DrawText(string, &rect, DT_TOP | DT_CENTER);

	rect.OffsetRect(-3, -3);
	dc.SetTextColor(RGB(0, 96, 255));
	dc.DrawText(string, &rect, DT_TOP | DT_CENTER);
	dc.SelectObject(oldFont);

}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication911centerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication911centerDlg::OnCbnSelchangeComboEmergency(){
	// TODO: Add your control notification handler code here
	m_comboBoxControlEmergency.GetLBText(m_comboBoxControlEmergency.GetCurSel(), m_strEmergencyList);
	
}


void CMFCApplication911centerDlg::OnBnClickedCallerButtonStart(){
	CString str1;
	int tempPhone=0;

	//get all inboxes (can put it on function)
	c_ClientReport.GetWindowTextW(m_ClientReport);
	c_ClientName.GetWindowTextW(m_ClientName);
	c_ClientLastName.GetWindowTextW(m_ClientLastName);
	c_clientCity.GetWindowTextW(m_ClientCity);
	c_ClientAddress.GetWindowTextW(m_ClientAddress);
	m_comboBoxControlEmergency.GetWindowTextW(m_strEmergencyList);
	//get phone number 
	c_ClientPhone.GetWindowTextW(m_ClientPhone);

	//turn it into int
	tempPhone = _tstoi(m_ClientPhone);
	
	Client temp(m_ClientName, m_ClientLastName, m_ClientGender,m_ClientAddress,m_ClientCity, tempPhone,m_ClientReport, m_strEmergencyList);

	str1 = temp.getName() +" "+ temp.getLastName()+temp.getGender()+" "+temp.getEmergency();

	m_Activity_log.SetString(str1); // update the activity log . 
	UpdateData(FALSE); // clear all texts 
	
	// TODO: Add your control notification handler code here
}



void CMFCApplication911centerDlg::OnBnClickedRadioEventFormMale(){
	m_ClientGender = "Male";
}


void CMFCApplication911centerDlg::OnBnClickedRadioEventFormFemale()
{
	m_ClientGender = "Female";
}

bool CMFCApplication911centerDlg::openEvent(){

	return false;
}

bool CMFCApplication911centerDlg::CloseEvent()
{
	return false;
}

void CMFCApplication911centerDlg::HandleEvent()
{

}

//adding all events to combobox 
void CMFCApplication911centerDlg::addEventsToComboBox()
{
	//need to add here all the list of emergency types
	vector<CString> temp;
	temp.push_back(_T("Robbery"));
	temp.push_back(_T("Fire"));
	temp.push_back(_T("Event with casualties"));
	temp.push_back(_T("Injurie"));
	temp.push_back(_T("Smoke in a building"));
	temp.push_back(_T("Car crash"));
	temp.push_back(_T("Homicede"));
	temp.push_back(_T("Animal Rescue"));

	for (int i = 0; i<temp.size(); i++) {
		m_strEmergencyList.Format(temp[i], i);
		m_comboBoxControlEmergency.AddString(m_strEmergencyList);
	}

}
