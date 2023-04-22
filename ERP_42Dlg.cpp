
// ERP_42Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ERP_42.h"
#include "ERP_42Dlg.h"
#include "afxdialogex.h"
#include "ERP_42_code.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CERP42Dlg 대화 상자



CERP42Dlg::CERP42Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ERP_42_DIALOG, pParent)
	, m_strRAlive(_T(""))
	, m_strRAorM(_T(""))
	, m_strRBrake(_T(""))
	, m_strREnc0(_T(""))
	, m_strREnc1(_T(""))
	, m_strREnc2(_T(""))
	, m_strREnc3(_T(""))
	, m_strREstop(_T(""))
	, m_strREtx0(_T(""))
	, m_strREtx1(_T(""))
	, m_strRGear(_T(""))
	, m_strRR(_T(""))
	, m_strRSpeed0(_T(""))
	, m_strRSpeed1(_T(""))
	, m_strRSteer0(_T(""))
	, m_strRSteer1(_T(""))
	, m_strRT(_T(""))
	, m_strRX(_T(""))
	, m_strTAlive(_T(""))
	, m_strTAorM(_T(""))
	, m_strTBrake(_T(""))
	, m_strTEstop(_T(""))
	, m_strTEtx0(_T(""))
	, m_strTEtx1(_T(""))
	, m_strTGear(_T(""))
	, m_strTSpeed0(_T(""))
	, m_strTS(_T(""))
	, m_strTSteer0(_T(""))
	, m_strTSpeed1(_T(""))
	, m_strTT(_T(""))
	, m_strTX(_T(""))
	, m_str_txSpeed(_T(""))
	, m_str_txSteer(_T(""))
	, m_str_txBrake(_T(""))
	, m_strTSteer11(_T(""))
	, m_strTSteer1(_T(""))
	, m_strRS(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CERP42Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RX_ALIVE, m_strRAlive);
	DDX_Text(pDX, IDC_EDIT_RX_AorM, m_strRAorM);
	DDX_Text(pDX, IDC_EDIT_RX_BRAKE, m_strRBrake);
	DDX_Text(pDX, IDC_EDIT_RX_ENC0, m_strREnc0);
	DDX_Text(pDX, IDC_EDIT_RX_ENC1, m_strREnc1);
	DDX_Text(pDX, IDC_EDIT_RX_ENC2, m_strREnc2);
	DDX_Text(pDX, IDC_EDIT_RX_ENC3, m_strREnc3);
	DDX_Text(pDX, IDC_EDIT_RX_ESTOP, m_strREstop);
	DDX_Text(pDX, IDC_EDIT_RX_ETX0, m_strREtx0);
	DDX_Text(pDX, IDC_EDIT_RX_ETX1, m_strREtx1);
	DDX_Text(pDX, IDC_EDIT_RX_GEAR, m_strRGear);
	DDX_Text(pDX, IDC_EDIT_RX_SPEED0, m_strRSpeed0);
	DDX_Text(pDX, IDC_EDIT_RX_SPEED1, m_strRSpeed1);
	DDX_Text(pDX, IDC_EDIT_RX_STEER0, m_strRSteer0);
	DDX_Text(pDX, IDC_EDIT_RX_T, m_strRT);
	DDX_Text(pDX, IDC_EDIT_RX_X, m_strRX);
	DDX_Text(pDX, IDC_EDIT_TX_ALIVE, m_strTAlive);
	DDX_Text(pDX, IDC_EDIT_TX_AorM, m_strTAorM);
	DDX_Text(pDX, IDC_EDIT_TX_BRAKE, m_strTBrake);
	DDX_Text(pDX, IDC_EDIT_TX_ESTOP, m_strTEstop);
	DDX_Text(pDX, IDC_EDIT_TX_ETX0, m_strTEtx0);
	DDX_Text(pDX, IDC_EDIT_TX_ETX1, m_strTEtx1);
	DDX_Text(pDX, IDC_EDIT_TX_GEAR, m_strTGear);
	DDX_Text(pDX, IDC_EDIT_TX_S, m_strTS);
	DDX_Text(pDX, IDC_EDIT_TX_SPEED0, m_strTSpeed0);
	DDX_Text(pDX, IDC_EDIT_TX_STEER0, m_strTSteer0);
	DDX_Text(pDX, IDC_EDIT_TX_SPEED1, m_strTSpeed1);
	DDX_Text(pDX, IDC_EDIT_TX_T, m_strTT);
	DDX_Text(pDX, IDC_EDIT_TX_X, m_strTX);
	DDX_Control(pDX, IDC_COMBO_TX_SPEED, m_combo_txSpeed);
	DDX_CBString(pDX, IDC_COMBO_TX_SPEED, m_str_txSpeed);
	DDX_Control(pDX, IDC_COMBO_TX_STEER, m_combo_txSteer);
	DDX_CBString(pDX, IDC_COMBO_TX_STEER, m_str_txSteer);
	DDX_Control(pDX, IDC_COMBO_TX_BRAKE, m_combo_txBrake);
	DDX_CBString(pDX, IDC_COMBO_TX_BRAKE, m_str_txBrake);
	DDX_Control(pDX, IDC_SPIN_TX_SPEED, m_spinSpeed);
	DDX_Control(pDX, IDC_SPIN_STEER, m_spinSteer);
	DDX_Control(pDX, IDC_SPIN_BRAKE, m_spinBrake);
	DDX_Text(pDX, IDC_EDIT_TX_STEER11, m_strTSteer11);
	DDX_Text(pDX, IDC_EDIT_RX_STEER1, m_strRSteer1);
	DDX_Text(pDX, IDC_EDIT_TX_STEER1, m_strTSteer1);
	DDX_Text(pDX, IDC_EDIT_RX_S, m_strRS);
}

BEGIN_MESSAGE_MAP(CERP42Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDC_RADIO_TX_AUTO, &CERP42Dlg::OnRadioTxAuto)
	ON_COMMAND(IDC_RADIO_TX_MANUAL, &CERP42Dlg::OnRadioTxManual)
	ON_COMMAND(IDC_RADIO_TX_ON, &CERP42Dlg::OnRadioTxOn)
	ON_COMMAND(IDC_RADIO_TX_OFF, &CERP42Dlg::OnRadioTxOff)
	ON_COMMAND(IDC_RADIO_TX_D, &CERP42Dlg::OnRadioTxD)
	ON_COMMAND(IDC_RADIO_TX_N, &CERP42Dlg::OnRadioTxN)
	ON_COMMAND(IDC_RADIO_TX_R, &CERP42Dlg::OnRadioTxR)
	ON_CBN_SELCHANGE(IDC_COMBO_TX_SPEED, &CERP42Dlg::OnCbnSelchangeComboTxSpeed)
	ON_CBN_SELCHANGE(IDC_COMBO_TX_STEER, &CERP42Dlg::OnCbnSelchangeComboTxSteer)
	ON_CBN_SELCHANGE(IDC_COMBO_TX_BRAKE, &CERP42Dlg::OnCbnSelchangeComboTxBrake)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TX_SPEED, &CERP42Dlg::OnDeltaposSpinTxSpeed)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_BRAKE, &CERP42Dlg::OnDeltaposSpinBrake)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_STEER, &CERP42Dlg::OnDeltaposSpinSteer)
	ON_WM_TIMER()
	ON_COMMAND(ID_COM_COM1, &CERP42Dlg::OnComCom1)
	ON_COMMAND(ID_COM_COM2, &CERP42Dlg::OnComCom2)
	ON_COMMAND(ID_COM_COM3, &CERP42Dlg::OnComCom3)
	ON_COMMAND(ID_COM_COM4, &CERP42Dlg::OnComCom4)
	ON_COMMAND(ID_COM_COM5, &CERP42Dlg::OnComCom5)
	ON_COMMAND(ID_COM_COM6, &CERP42Dlg::OnComCom6)
	ON_COMMAND(ID_COM_COM7, &CERP42Dlg::OnComCom7)
	ON_COMMAND(ID_COM_COM8, &CERP42Dlg::OnComCom8)
	ON_COMMAND(ID_COM_COM9, &CERP42Dlg::OnComCom9)
	ON_COMMAND(ID_COM_COM10, &CERP42Dlg::OnComCom10)
	ON_COMMAND(ID_COM_COM11, &CERP42Dlg::OnComCom11)
	ON_COMMAND(ID_COM_COM12, &CERP42Dlg::OnComCom12)
END_MESSAGE_MAP()


// CERP42Dlg 메시지 처리기

BOOL CERP42Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	//Radio Button 초기화
	((CButton*)GetDlgItem(IDC_RADIO_TX_AUTO))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO_TX_OFF))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO_TX_N))->SetCheck(TRUE);

	m_spinSpeed.SetRange(0, 200);
	m_spinSteer.SetRange(-2000, 2000);
	m_spinBrake.SetRange(0, 33);

	
	AutoManual(0x01);
	Brake(1);


	m_combo_txSpeed.AddString(_T("1"));
	m_combo_txSpeed.AddString(_T("5"));
	m_combo_txSpeed.AddString(_T("10"));
	m_combo_txSpeed.AddString(_T("20"));
	m_combo_txSpeed.AddString(_T("30"));
	m_combo_txSpeed.AddString(_T("40"));
	m_combo_txSpeed.AddString(_T("50"));

	m_combo_txSteer.AddString(_T("1"));
	m_combo_txSteer.AddString(_T("5"));
	m_combo_txSteer.AddString(_T("10"));
	m_combo_txSteer.AddString(_T("20"));
	m_combo_txSteer.AddString(_T("30"));
	m_combo_txSteer.AddString(_T("40"));
	m_combo_txSteer.AddString(_T("50"));
	m_combo_txSteer.AddString(_T("100"));

	m_combo_txBrake.AddString(_T("1"));
	m_combo_txBrake.AddString(_T("5"));
	m_combo_txBrake.AddString(_T("10"));
	SetTimer(0, 1, NULL);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CERP42Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CERP42Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CERP42Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CERP42Dlg::OnRadioTxAuto()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_bAorM = true;
	AutoManual(m_bAorM);
	m_strTAorM.Format(_T("%d"), Sendbuf[3]);
	UpdateData(FALSE);
}


void CERP42Dlg::OnRadioTxManual()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_bAorM = false;
	AutoManual(m_bAorM);
	m_strTAorM.Format(_T("%d"), Sendbuf[3]);
	UpdateData(FALSE);
}


void CERP42Dlg::OnRadioTxOn()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_bEstop = true;
	EStop(m_bEstop);
	m_strTEstop.Format(_T("%d"), Sendbuf[4]);
	UpdateData(FALSE);
}


void CERP42Dlg::OnRadioTxOff()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_bEstop = false;
	EStop(m_bEstop);
	m_strTEstop.Format(_T("%d"), Sendbuf[4]);
	UpdateData(FALSE);
}


void CERP42Dlg::OnRadioTxD()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_intGear = 0;
	Gear(m_intGear);
	m_strTGear.Format(_T("%d"), Sendbuf[5]);
	UpdateData(FALSE);
}


void CERP42Dlg::OnRadioTxN()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_intGear = 1;
	Gear(m_intGear);
	m_strTGear.Format(_T("%d"), Sendbuf[5]);
	UpdateData(FALSE);
}


void CERP42Dlg::OnRadioTxR()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_intGear = 2;
	Gear(m_intGear);
	m_strTGear.Format(_T("%d"), Sendbuf[5]);
	UpdateData(FALSE);
}



void CERP42Dlg::OnCbnSelchangeComboTxSpeed()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_combo_txSpeed.GetCurSel() == 0) 
		m_int_tx_selspeed = 1;
	else if (m_combo_txSpeed.GetCurSel() == 1)
		m_int_tx_selspeed = 5;
	else if (m_combo_txSpeed.GetCurSel() == 2)
		m_int_tx_selspeed = 10;
	else if (m_combo_txSpeed.GetCurSel() == 3)
		m_int_tx_selspeed = 20;
	else if (m_combo_txSpeed.GetCurSel() == 4)
		m_int_tx_selspeed = 30;
	else if (m_combo_txSpeed.GetCurSel() == 5)
		m_int_tx_selspeed = 40;
	else if (m_combo_txSpeed.GetCurSel() == 6)
		m_int_tx_selspeed = 50;
}


void CERP42Dlg::OnCbnSelchangeComboTxSteer()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_combo_txSteer.GetCurSel() == 0)
		m_int_tx_selsteer = 1;
	else if (m_combo_txSteer.GetCurSel() == 1)
		m_int_tx_selsteer = 5;
	else if (m_combo_txSteer.GetCurSel() == 2)
		m_int_tx_selsteer = 10;
	else if (m_combo_txSteer.GetCurSel() == 3)
		m_int_tx_selsteer = 20;
	else if (m_combo_txSteer.GetCurSel() == 4)
		m_int_tx_selsteer = 30;
	else if (m_combo_txSteer.GetCurSel() == 5)
		m_int_tx_selsteer = 40;
	else if (m_combo_txSteer.GetCurSel() == 6)
		m_int_tx_selsteer = 50;
	else if (m_combo_txSteer.GetCurSel() == 7)
		m_int_tx_selsteer = 100;
}


void CERP42Dlg::OnCbnSelchangeComboTxBrake()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_combo_txBrake.GetCurSel() == 0)
		m_int_tx_selbrake = 1;
	else if (m_combo_txBrake.GetCurSel() == 1)
		m_int_tx_selbrake = 5;
	else if (m_combo_txBrake.GetCurSel() == 2)
		m_int_tx_selbrake = 10;
}


void CERP42Dlg::OnDeltaposSpinTxSpeed(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//https://blog.naver.com/lanivi/221140427952
	pNMUpDown->iDelta *= m_int_tx_selspeed;

	*pResult = 0;
}


void CERP42Dlg::OnDeltaposSpinBrake(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pNMUpDown->iDelta *= m_int_tx_selbrake;

	*pResult = 0;
}

void CERP42Dlg::OnDeltaposSpinSteer(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pNMUpDown->iDelta *= m_int_tx_selsteer;

	if (pNMUpDown->iDelta < 0) {
		spinsteer -= m_int_tx_selsteer;
	}
	else {
		spinsteer += m_int_tx_selsteer;
	}
	*pResult = 0;
}

void CERP42Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_strRS.Format(("%d"), rx_d[0]);
	GetDlgItem(IDC_EDIT_RX_S)->SetWindowText(m_strRS);
	m_strRT.Format(("%d"), rx_d[1]);
	GetDlgItem(IDC_EDIT_RX_T)->SetWindowText(m_strRT);
	m_strRX.Format(("%d"), rx_d[2]);
	GetDlgItem(IDC_EDIT_RX_X)->SetWindowText(m_strRX);
	m_strRAorM.Format(("%d"), rx_d[3]);
	GetDlgItem(IDC_EDIT_RX_AorM)->SetWindowText(m_strRAorM);
	m_strREstop.Format(("%d"), rx_d[4]);
	GetDlgItem(IDC_EDIT_RX_ESTOP)->SetWindowText(m_strREstop);
	m_strRGear.Format(("%d"), rx_d[5]);
	GetDlgItem(IDC_EDIT_RX_GEAR)->SetWindowText(m_strRGear);
	m_strRSpeed0.Format(("%d"), rx_d[6]);
	GetDlgItem(IDC_EDIT_RX_SPEED0)->SetWindowText(m_strRSpeed0);
	m_strRSpeed1.Format(("%d"), rx_d[7]);
	GetDlgItem(IDC_EDIT_RX_SPEED1)->SetWindowText(m_strRSpeed1);
	m_strRSteer0.Format(("%d"), rx_d[8]);
	GetDlgItem(IDC_EDIT_RX_STEER0)->SetWindowText(m_strRSteer0);
	m_strRSteer1.Format(("%d"), rx_d[9]);
	GetDlgItem(IDC_EDIT_RX_STEER1)->SetWindowText(m_strRSteer1);
	m_strRBrake.Format(("%d"), rx_d[10]);
	GetDlgItem(IDC_EDIT_RX_BRAKE)->SetWindowText(m_strRBrake);
	m_strREnc0.Format(("%d"), rx_d[11]);
	GetDlgItem(IDC_EDIT_RX_ENC0)->SetWindowText(m_strREnc0);
	m_strREnc1.Format(("%d"), rx_d[12]);
	GetDlgItem(IDC_EDIT_RX_ENC1)->SetWindowText(m_strREnc1);
	m_strREnc2.Format(("%d"), rx_d[13]);
	GetDlgItem(IDC_EDIT_RX_ENC2)->SetWindowText(m_strREnc2);
	m_strREnc3.Format(("%d"), rx_d[14]);
	GetDlgItem(IDC_EDIT_RX_ENC3)->SetWindowText(m_strREnc3);
	m_strRAlive.Format(("%d"), rx_d[15]);
	GetDlgItem(IDC_EDIT_RX_ALIVE)->SetWindowText(m_strRAlive);
	m_strREtx0.Format(("%d"), rx_d[16]);
	GetDlgItem(IDC_EDIT_RX_ETX0)->SetWindowText(m_strREtx0);
	m_strREtx1.Format(("%d"), rx_d[17]);
	GetDlgItem(IDC_EDIT_RX_ETX1)->SetWindowText(m_strREtx1);
	
	m_strTS.Format(("%d"), Sendbuf[0]);
	GetDlgItem(IDC_EDIT_RX_ETX1)->SetWindowText(m_strTS);
	m_strTT.Format(("%d"), Sendbuf[1]);
	GetDlgItem(IDC_EDIT_RX_ETX1)->SetWindowText(m_strTT);
	m_strTX.Format(("%d"), Sendbuf[2]);
	m_strTAorM.Format(_T("%d"), Sendbuf[3]);
	m_strTEstop.Format(_T("%d"), Sendbuf[4]);
	m_strTGear.Format(_T("%d"), Sendbuf[5]);
	GetDlgItem(IDC_EDIT_RX_ETX1)->SetWindowText(m_strTX);
	m_strTSpeed0.Format(("%d"), Sendbuf[6]);
	GetDlgItem(IDC_EDIT_RX_ETX1)->SetWindowText(m_strTSpeed0);
	m_strTAlive.Format(("%d"), Sendbuf[11]);
	GetDlgItem(IDC_EDIT_RX_ETX1)->SetWindowText(m_strTAlive);
	m_strTEtx0.Format(("%d"), Sendbuf[12]);
	GetDlgItem(IDC_EDIT_RX_ETX1)->SetWindowText(m_strTEtx0);
	m_strTEtx1.Format(("%d"), Sendbuf[13]);
	GetDlgItem(IDC_EDIT_RX_ETX1)->SetWindowText(m_strTEtx1);

	if (spinsteer > 2000)
		spinsteer = 2000;
	else if (spinsteer < -2000)
		spinsteer = -2000;
	Steering(spinsteer);
	m_strTSteer1.Format(("%d"), spinsteer);
	m_strTSteer0.Format(("%d"), Sendbuf[8]);
	m_strTSteer11.Format(("%d"), Sendbuf[9]);
	GetDlgItem(IDC_EDIT_TX_STEER0)->SetWindowText(m_strTSteer0);
	GetDlgItem(IDC_EDIT_TX_STEER11)->SetWindowText(m_strTSteer11);
	GetDlgItem(IDC_EDIT_TX_STEER1)->SetWindowText(m_strTSteer1);
	
	int spinspeed = m_spinSpeed.GetPos();
	if (spinspeed > 200)
		spinspeed = 200;
	else if (spinspeed < 0)
		spinspeed = 0;
	Speed(spinspeed);
	m_strTSpeed1.Format(("%d"), spinspeed);
	GetDlgItem(IDC_EDIT_TX_SPEED1)->SetWindowText(m_strTSpeed1);

	int spinbrake = m_spinBrake.GetPos();
	if (spinbrake > 33)
		spinbrake = 33;
	else if (spinbrake < 0)
		spinbrake = 0;
	Brake(spinbrake);
	m_strTBrake.Format(("%d"), spinbrake);
	GetDlgItem(IDC_EDIT_TX_BRAKE)->SetWindowText(m_strTBrake);

	m_nAliveData=Alive(m_nAliveData);
	UpdateData(FALSE);
	Rec = RecData();
	SendData(Sendbuf);

	CDialogEx::OnTimer(nIDEvent);
}


void CERP42Dlg::OnComCom1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	char szPort[15] = "\\\\.\\com1";
	Open(szPort);
}


void CERP42Dlg::OnComCom2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	char szPort[15] = "\\\\.\\com2";
	Open(szPort);
}


void CERP42Dlg::OnComCom3()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	char szPort[15] = "\\\\.\\com3";
	Open(szPort);
}


void CERP42Dlg::OnComCom4()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	char szPort[15] = "\\\\.\\com4";
	Open(szPort);
}


void CERP42Dlg::OnComCom5()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	char szPort[15] = "\\\\.\\com5";
	Open(szPort);
}


void CERP42Dlg::OnComCom6()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	char szPort[15] = "\\\\.\\com6";
	Open(szPort);
}


void CERP42Dlg::OnComCom7()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	char szPort[15] = "\\\\.\\com7";
	Open(szPort);
}


void CERP42Dlg::OnComCom8()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	char szPort[15] = "\\\\.\\com8";
	Open(szPort);
}


void CERP42Dlg::OnComCom9()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	char szPort[15] = "\\\\.\\com9";
	Open(szPort);
}


void CERP42Dlg::OnComCom10()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	char szPort[15] = "\\\\.\\com10";
	Open(szPort);
}


void CERP42Dlg::OnComCom11()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	char szPort[15] = "\\\\.\\com11";
	Open(szPort);
		
}


void CERP42Dlg::OnComCom12()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	char szPort[15] = "\\\\.\\com12";
	Open(szPort);
}

