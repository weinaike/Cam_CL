// ssdic_sampleDlg.h : header file
//

#pragma once
#include "include/ssdic.h"
#include "afxwin.h"
#include "afxcmn.h"


// Cssdic_sampleDlg dialog
class Cssdic_sampleDlg : public CDialog
{
// construction
public:
	Cssdic_sampleDlg(CWnd* pParent = NULL);	// constructor
	~Cssdic_sampleDlg();					// destructor

// dialog data
	enum { IDD = IDD_SSDIC_SAMPLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

private:
	WORD*	m_pTransBuffer;
	volatile HDEVIF	m_hHandle;
	static VOID CALLBACK CallbackAcquire( INT nEventNo, PVOID pArgData, PVOID pContext );
	static VOID CALLBACK CallbackMonitor( INT nEventNo, PVOID pArgData, PVOID pContext );
	void	Terminate();
	void	ButtonEnable(UINT unFlag);

// implementation
protected:
	HICON m_hIcon;

	// message allocation function
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButtonAcq();
	afx_msg void OnBnClickedButtonMon();
	afx_msg void OnBnClickedButtonStop();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonInit();
	afx_msg void OnBnClickedButtonTerm();
	afx_msg void OnBnClickedButtonCutom();
	CButton m_buttonInit;
	CButton m_buttonAcq;
	CButton m_buttonMon;
	CButton m_buttonStop;
	CButton m_buttonTerm;
	CButton m_buttonRdoUsb;
	CButton m_buttonRdoCl;
	CButton m_buttonRdoUdp;
	CButton m_buttonRdoTcp;
	CButton m_buttonCustom;
	CButton m_buttonOK;
	afx_msg void OnBnClickedButtonChkfunc();
	CEdit m_edtTraceFunc;
	CButton m_buttonChkFunc;
	afx_msg void OnBnClickedButtonState();
	CStatic m_stcConnectStat;
	CEdit edtSend;
	CEdit m_edtReceive;
	afx_msg void OnBnClickedButtonSendrecv();
	CString m_strSend;
	CString m_strReceive;
	CIPAddressCtrl m_IPAddress;
};
