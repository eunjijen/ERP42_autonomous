
// ERP_42Dlg.h: 헤더 파일
//

#pragma once


// CERP42Dlg 대화 상자
class CERP42Dlg
 : public CDialogEx
{
// 생성입니다.
public:
	CERP42Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ERP_42_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strRAlive;
	CString m_strRAorM;
	CString m_strRBrake;
	CString m_strREnc0;
	CString m_strREnc1;
	CString m_strREnc2;
	CString m_strREnc3;
	CString m_strREstop;
	CString m_strREtx0;
	CString m_strREtx1;
	CString m_strRGear;
	CString m_strRR;
	CString m_strRSpeed0;
	CString m_strRSpeed1;
	CString m_strRSteer0;
	CString m_strRT;
	CString m_strRX;
	CString m_strTAlive;
	CString m_strTAorM;
	CString m_strTBrake;
	CString m_strTEstop;
	CString m_strTEtx0;
	CString m_strTEtx1;
	CString m_strTGear;
	CString m_strTSpeed0;
	CString m_strTS;
	CString m_strTSteer0;
	CString m_strTSpeed1;
	CString m_strTT;
	CString m_strTX;
	bool m_bAorM;
	int m_bEstop;
	afx_msg void OnRadioTxAuto();
	afx_msg void OnRadioTxManual();
	afx_msg void OnRadioTxOn();
	afx_msg void OnRadioTxOff();
	int m_intGear;
	afx_msg void OnRadioTxD();
	afx_msg void OnRadioTxN();
	afx_msg void OnRadioTxR();
	CButton m_btStart;
	CComboBox m_combo_txSpeed;
	CString m_str_txSpeed;
	CComboBox m_combo_txSteer;
	CString m_str_txSteer;
	CComboBox m_combo_txBrake;
	CString m_str_txBrake;
	afx_msg void OnCbnSelchangeComboTxSpeed();
	int m_int_tx_selspeed=0;
	afx_msg void OnCbnSelchangeComboTxSteer();
	int m_int_tx_selsteer=0;
	afx_msg void OnCbnSelchangeComboTxBrake();
	int m_int_tx_selbrake=0;
	CSpinButtonCtrl m_spinSpeed;
	CSpinButtonCtrl m_spinSteer;
	CSpinButtonCtrl m_spinBrake;
	afx_msg void OnDeltaposSpinTxSpeed(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinBrake(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinSteer(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_strTSteer11;
	CString m_strRSteer1;
	CString m_strTSteer1;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CString m_strRS;
	int m_nAliveData=0;
	afx_msg void OnComCom1();
	afx_msg void OnComCom2();
	afx_msg void OnComCom3();
	afx_msg void OnComCom4();
	afx_msg void OnComCom5();
	afx_msg void OnComCom6();
	afx_msg void OnComCom7();
	afx_msg void OnComCom8();
	afx_msg void OnComCom9();
	afx_msg void OnComCom10();
	afx_msg void OnComCom11();
	afx_msg void OnComCom12();
	int spinsteer;
	int m_checkdata;
//	afx_msg void OnUpdateComCom1(CCmdUI *pCmdUI);
//	afx_msg void OnUpdateComCom2(CCmdUI *pCmdUI);
};
