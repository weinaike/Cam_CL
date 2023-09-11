// ssdic_sampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ssdic_sample.h"
#include "ssdic_sampleDlg.h"
#include "include/ssdic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define NOT_ETHERNET	1

////////////////////////////////////////////////////////////
//
// for C12081
//
#define	MEAS_CNT		1		// Measure frame count
#define	FRAME_V			64	// Frame vertical lines
#define	FRAME_H			64		// Frame horzontal pixels


// CAboutDlg dialog

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// dialog data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// Cssdic_sampleDlg dialog
Cssdic_sampleDlg::Cssdic_sampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cssdic_sampleDlg::IDD, pParent)
	, m_strSend(_T(""))
	, m_strReceive(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

Cssdic_sampleDlg::~Cssdic_sampleDlg()
{
	// delete buffer
	if(m_pTransBuffer != NULL)
	{
		delete m_pTransBuffer;
		m_pTransBuffer = NULL;
	}
}

void Cssdic_sampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_INIT, m_buttonInit);
	DDX_Control(pDX, IDC_BUTTON_ACQ, m_buttonAcq);
	DDX_Control(pDX, IDC_BUTTON_MON, m_buttonMon);
	DDX_Control(pDX, IDC_BUTTON_STOP, m_buttonStop);
	DDX_Control(pDX, IDC_BUTTON_TERM, m_buttonTerm);
	DDX_Control(pDX, IDC_RADIO_USB, m_buttonRdoUsb);
	DDX_Control(pDX, IDC_RADIO_CL, m_buttonRdoCl);
	DDX_Control(pDX, IDC_RADIO_UDP, m_buttonRdoUdp);
	DDX_Control(pDX, IDC_RADIO_TCP, m_buttonRdoTcp);
	DDX_Control(pDX, IDOK, m_buttonOK);
	DDX_Control(pDX, IDC_TRACE_FUNC, m_edtTraceFunc);
	DDX_Control(pDX, IDC_BUTTON_CHKFUNC, m_buttonChkFunc);
	DDX_Control(pDX, IDC_STC_CONNECT_START, m_stcConnectStat);
	DDX_Control(pDX, IDC_EDIT_SEND, edtSend);
	DDX_Control(pDX, IDC_EDIT_RECEIVE, m_edtReceive);
	DDX_Text(pDX, IDC_EDIT_SEND, m_strSend);
	DDX_Text(pDX, IDC_EDIT_RECEIVE, m_strReceive);
	DDX_Control(pDX, IDC_IPADDRESS1, m_IPAddress);
}

BEGIN_MESSAGE_MAP(Cssdic_sampleDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_INIT, OnBnClickedButtonInit)
	ON_BN_CLICKED(IDC_BUTTON_ACQ, OnBnClickedButtonAcq)
	ON_BN_CLICKED(IDC_BUTTON_MON, OnBnClickedButtonMon)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnBnClickedButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_TERM, OnBnClickedButtonTerm)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_CHKFUNC, &Cssdic_sampleDlg::OnBnClickedButtonChkfunc)
	ON_BN_CLICKED(IDC_BUTTON_STATE, &Cssdic_sampleDlg::OnBnClickedButtonState)
	ON_BN_CLICKED(IDC_BUTTON_SENDRECV, &Cssdic_sampleDlg::OnBnClickedButtonSendrecv)
END_MESSAGE_MAP()


// Cssdic_sampleDlg message handler

BOOL Cssdic_sampleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	m_buttonRdoUsb.SetCheck(0);		// set select USB is FALSE
	m_buttonRdoCl.SetCheck(1);		// set select Cameralink is TRUE
	m_buttonRdoUdp.SetCheck(0);		// set select Cameralink is TRUE
	m_buttonRdoTcp.SetCheck(0);		// set select Cameralink is TRUE
	m_pTransBuffer = NULL;			// Init buffer pointer

	ButtonEnable(0);

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void Cssdic_sampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void Cssdic_sampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR Cssdic_sampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

///////////////////////////////////////////////////////////////////////
//
//	Initialize
//
///////////////////////////////////////////////////////////////////////
void Cssdic_sampleDlg::OnBnClickedButtonInit()
{
	LONG lRet = SSDIC_ERR_NONE;
	HDEVIF	hHandle = SSDIC_INVALID_HANDLE;
	CString strErrorMsg;
	LONG	lDeviceCount = 0;
	CHAR	cSerialNum[1024];
	CWaitCursor wait;

	lRet = ssdic_Initialize();
	if (SSDIC_ERR_NONE != lRet) {
		strErrorMsg.Format(_T("Initialize Error = [%d]"), lRet);
		AfxMessageBox(strErrorMsg);
		Terminate();
		return;		
	}

	INT nIFType = 0;
	// Get connect interface and connect
	if(m_buttonRdoUsb.GetCheck() != 0)
	{
		nIFType = SSDIC_IF_USB;
	}
	else if(m_buttonRdoCl.GetCheck() != 0)
	{
		nIFType = SSDIC_IF_CL;
	}
	else if(m_buttonRdoUdp.GetCheck() != 0)
	{
		nIFType = SSDIC_IF_UDPP;
	}
	else if(m_buttonRdoTcp.GetCheck() != 0)
	{
		BYTE	ipAddress[4] = {172,21,2,139};
		m_IPAddress.GetAddress(ipAddress[0], ipAddress[1], ipAddress[2], ipAddress[3]);
		WORD	nCmdPort = 64000;
		lRet = ssdic_ClrTargetAddressList();
		if (SSDIC_ERR_NONE != lRet) {
			strErrorMsg.Format(_T("ssdic_ClrTartgetAddressList Error = [%d]"), lRet);
			AfxMessageBox(strErrorMsg);
			Terminate();
			return;		
		}
		lRet = ssdic_AddTargetAddress(ipAddress, nCmdPort);
		if (SSDIC_ERR_NONE != lRet) {
			strErrorMsg.Format(_T("ssdic_AddTartgetAddress Error = [%d]"), lRet);
			AfxMessageBox(strErrorMsg);
			Terminate();
			return;		
		}
		nIFType = SSDIC_IF_ETHERNET;
	}
	else
	{
		return;		
	}

	lRet = ssdic_SearchDeviceEx(nIFType, &lDeviceCount);
	if (SSDIC_ERR_NONE != lRet) {
		strErrorMsg.Format(_T("SearchDevice Error = [%d]"), lRet);
		AfxMessageBox(strErrorMsg);
		Terminate();
		return;		
	}
	TRACE(_T("Device Count = [%d]\n"), lDeviceCount);

	// Updating Device Info Array
	for(LONG lDev = 0; lDev < lDeviceCount; lDev++){
		// Getting Device Serial Number
		for (int nSerialCount = 0 ; nSerialCount < 2 ; nSerialCount++) {
			lRet = ssdic_GetDeviceInfo(lDev, SSDIC_DEVINFO_SERIAL_NUMBER,
										cSerialNum,
										sizeof(cSerialNum));
			if (SSDIC_ERR_NONE == lRet) {
				break;
			}
		}
		if(SSDIC_ERR_NONE != lRet){
			// Skip the Device in case of error
			continue;
		}
	}
	if (SSDIC_ERR_NONE != lRet) {
		strErrorMsg.Format(_T("GetDeviceInfo Error = [%d]"), lRet);
		AfxMessageBox(strErrorMsg);
		Terminate();
		return;
	}

	lRet = ssdic_Connect(0, &hHandle);
	if (SSDIC_ERR_NONE != lRet) {
		strErrorMsg.Format(_T("Connect Error = [%d]"), lRet);
		AfxMessageBox(strErrorMsg);
		Terminate();
		return;		
	}
	
	// alloc capture buffer
	m_pTransBuffer = new WORD[FRAME_V*FRAME_H*MEAS_CNT];
	if(m_pTransBuffer == NULL)
	{
		AfxMessageBox(_T("Capture buffer allocate error!!"));
		Terminate();
		return;		
	}

	// backup handle
	m_hHandle = hHandle;

	ButtonEnable(1);
}

///////////////////////////////////////////////////////////////////////
//
//	Measure start and stop
//
///////////////////////////////////////////////////////////////////////
void Cssdic_sampleDlg::OnBnClickedButtonAcq()
{
	LONG	lRet = SSDIC_ERR_NONE;
	HDEVIF	hHandle = m_hHandle;
	CString strErrorMsg;
	LONG	lTrigger = 0;
	LONG	lExpTime = 0;
	LONG	lPolarity = 0;
	LONG	lWaitTime = 0;
	LONG	lTerminal = 0;

	// Set trigger
	lRet = ssdic_GetTrigger(hHandle, &lTrigger, &lExpTime, &lPolarity, &lWaitTime, &lTerminal);
	if (lRet != SSDIC_ERR_NONE) {
		strErrorMsg.Format(_T("ssdic_GetTrigger Error = [%d]"), lRet);
		AfxMessageBox(strErrorMsg);
	}
	lTrigger = SSDIC_TRIGMODE_INT1; 
	lRet = ssdic_SetTrigger(hHandle, lTrigger, lExpTime, lPolarity, lWaitTime, lTerminal);
	if (lRet != SSDIC_ERR_NONE) {
		strErrorMsg.Format(_T("ssdic_SetTrigger Error = [%d]"), lRet);
		AfxMessageBox(strErrorMsg);
	}

	// Get frame size
	LONG lHoriPix = 0;
	LONG lVertPix = 0;
	lRet = ssdic_GetMeasureSize(hHandle, &lHoriPix, &lVertPix);
	if (SSDIC_ERR_NONE != lRet) {
		strErrorMsg.Format(_T("ssdic_GetMeasureSize Error = [%d]"), lRet);
		AfxMessageBox(strErrorMsg);
	}

	// Measure parameter (ACQUISITION)
	SSDICCTRL_ACQ_INFO acqInfo;
	acqInfo.nWidth = lHoriPix;
	acqInfo.nHeight = lVertPix;
	acqInfo.nFrameBytes = lHoriPix*lVertPix*2;
	acqInfo.nFrameCount = MEAS_CNT;				// 10 frame
	acqInfo.pMeasRoutine = CallbackAcquire;		// Callback function
	acqInfo.pMeasContext = this;
	acqInfo.nFrmRateMode = 1;					// Reserve
	acqInfo.bDataLost = FALSE;					// Reserve
	acqInfo.pTransBuffer = m_pTransBuffer;

	lRet = ssdic_StartAcquire(hHandle, &acqInfo);
	if (SSDIC_ERR_NONE != lRet) {
		strErrorMsg.Format(_T("StartAcquire Error = [%d]"), lRet);
		AfxMessageBox(strErrorMsg);
	}

	//Sleep(2000);
	//ssdic_AbortMeasure(hHandle);

	ButtonEnable(2);
}

void Cssdic_sampleDlg::OnBnClickedButtonMon()
{
	LONG	lRet = SSDIC_ERR_NONE;
	HDEVIF	hHandle = m_hHandle;
	CString strErrorMsg;
	LONG	lTrigger = 0;
	LONG	lExpTime = 0;
	LONG	lPolarity = 0;
	LONG	lWaitTime = 0;
	LONG	lTerminal = 0;

	// Set trigger
	lRet = ssdic_GetTrigger(hHandle, &lTrigger, &lExpTime, &lPolarity, &lWaitTime, &lTerminal);
	if (lRet != SSDIC_ERR_NONE) {
		strErrorMsg.Format(_T("ssdic_GetTrigger Error = [%d]"), lRet);
		AfxMessageBox(strErrorMsg);
	}
	lTrigger = SSDIC_TRIGMODE_INT1; 
	lRet = ssdic_SetTrigger(hHandle, lTrigger, lExpTime, lPolarity, lWaitTime, lTerminal);
	if (lRet != SSDIC_ERR_NONE) {
		strErrorMsg.Format(_T("ssdic_SetTrigger Error = [%d]"), lRet);
		AfxMessageBox(strErrorMsg);
	}

	// Get frame size
	LONG lHoriPix = 0;
	LONG lVertPix = 0;
	lRet = ssdic_GetMeasureSize(hHandle, &lHoriPix, &lVertPix);
	if (SSDIC_ERR_NONE != lRet) {
		strErrorMsg.Format(_T("ssdic_GetMeasureSize Error = [%d]"), lRet);
		AfxMessageBox(strErrorMsg);
	}

	// Measure parameter (ACQUISITION)
	SSDICCTRL_MON_INFO monInfo;
	monInfo.nWidth = lHoriPix;
	monInfo.nHeight = lVertPix;
	monInfo.nFrameBytes = lHoriPix*lVertPix*2;
	monInfo.nFrameCount = 1;					// Fix "1"
	monInfo.nEventPerFrame = 1;					// Reserve
	monInfo.pMeasRoutine = CallbackMonitor;
	monInfo.pMeasContext = this;
	monInfo.nFrmRateMode = 1;					// Reserve				
	monInfo.bDataLost = FALSE;					// Reserve	
	monInfo.nMonType = 1;						// Reserve
	monInfo.bBlockRead = FALSE;

	lRet = ssdic_StartMonitor(hHandle, &monInfo);
	if (SSDIC_ERR_NONE != lRet) {
		strErrorMsg.Format(_T("StartMonitor Error = [%d]"), lRet);
		AfxMessageBox(strErrorMsg);
	}

	ButtonEnable(2);
}

void Cssdic_sampleDlg::OnBnClickedButtonStop()
{
	LONG	lRet = SSDIC_ERR_NONE;
	HDEVIF	hHandle = m_hHandle;
	CString strErrorMsg;

	lRet = ssdic_AbortMeasure(hHandle);
	if (SSDIC_ERR_NONE != lRet) {
		strErrorMsg.Format(_T("Measure stop Error = [%d]"), lRet);
		AfxMessageBox(strErrorMsg);
	}

	ButtonEnable(1);
}

///////////////////////////////////////////////////////////////////////
//
//	Callback function
//
///////////////////////////////////////////////////////////////////////
VOID CALLBACK Cssdic_sampleDlg::CallbackAcquire( INT nEventNo, PVOID pArgData, PVOID pContext )
{
	Cssdic_sampleDlg *pDlg = (Cssdic_sampleDlg*)pContext;

	ULONG	nCompFrameNo = 0;
	DOUBLE	dblFrameRate = 0.0;
	DWORD	dwFrameNo = 0;
	WORD	nFrameNo = 0;
	WORD	nFrameMax = 0;

	CString	strEventMessage;

	switch(nEventNo) {
		case SSDIC_MEAS_EVENT_TRANS_COMP:	// Transfer Complete Event	
			if (pArgData != NULL) {
				nCompFrameNo = *((ULONG*)pArgData);
			}
			strEventMessage.Format(_T("Acquire Transfer Complete [%d]\n"), nCompFrameNo);
			if (NULL != pDlg) {
				LONG lHoriPix = 0;
				LONG lVertPix = 0;
				LONG lRet = ssdic_GetMeasureSize(pDlg->m_hHandle, &lHoriPix, &lVertPix);
				if (SSDIC_ERR_NONE == lRet) {
					FILE	*fp = NULL;
					fp = fopen("Acquire.csv", "wt");
					if (fp) {
						ULONG nIdx = 0;
						for (ULONG nFrame = 0 ; nFrame < MEAS_CNT ; nFrame++) {
							fprintf(fp, "Frame Number : %d\n", nFrame);
							for (ULONG nV = 0 ; nV < lVertPix ; nV++) {
								for (ULONG nH = 0 ; nH < lHoriPix ; nH++) {
									fprintf(fp, "%d, ", pDlg->m_pTransBuffer[nIdx++]);
								}
								fprintf(fp, "\n");
							}
						}
						fclose(fp);
					}
				}
				pDlg->ButtonEnable(1);
			}
			break;
		case SSDIC_MEAS_EVENT_FRAME_RATE:	// Frame Rate Event
			dblFrameRate = *((DOUBLE*)pArgData);
			strEventMessage.Format(_T("Frame Rate [%f]\n"), dblFrameRate);
			break;
		case SSDIC_MEAS_EVENT_ABORT_PROC:	// Abort Process Event
			strEventMessage = _T("Abort Process\n");
			if (NULL != pDlg) {
				ssdic_StopMeasureDataTransfer(pDlg->m_hHandle);
			}
			break;
		case SSDIC_MEAS_EVENT_FRAME_NUMB:	// Frame Number Event
			if (pArgData != NULL) {
				dwFrameNo = *((DWORD*)pArgData);
				nFrameNo = HIWORD(dwFrameNo);
				nFrameMax = LOWORD(dwFrameNo);
			}
			strEventMessage.Format(_T("Frame Number [%d / %d]\n"), nFrameNo, nFrameMax);
			break;
		case SSDIC_MEAS_EVENT_LOST_DATA:	// Lost Data Event
			strEventMessage = _T("Lost Data\n");
			break;
		default:
			strEventMessage = _T("Unkown Event\n");
			break;
	}

	CString	strInfoMessage;
	strInfoMessage.Format(_T("nEventNo = [%02d], pArgData = [%08X], pContext = [%08X]\n"), nEventNo, pArgData, pContext);
	TRACE(strEventMessage);
	TRACE(strInfoMessage);

	return;
}

VOID CALLBACK Cssdic_sampleDlg::CallbackMonitor( INT nEventNo, PVOID pArgData, PVOID pContext )
{
	Cssdic_sampleDlg *pDlg = (Cssdic_sampleDlg*)pContext;
	ULONG	nCompFrameNo = 0;
	DOUBLE	dblFrameRate = 0.0;
	DWORD	dwFrameNo = 0;
	WORD	nFrameNo = 0;
	WORD	nFrameMax = 0;
	WORD	wData = 0;
	CString	strEventMessage = _T("");

	switch(nEventNo)
	{
		case SSDIC_MEAS_EVENT_TRANS_COMP:	// Transfer Complete Event	
			if (pArgData != NULL) {
				WORD* pData = (WORD*)pArgData;
				strEventMessage.Format(_T("Monitor Transfer Complete [%d]\n"), nCompFrameNo);
				if (NULL != pDlg) {
					LONG lHoriPix = 0;
					LONG lVertPix = 0;
					LONG lRet = ssdic_GetMeasureSize(pDlg->m_hHandle, &lHoriPix, &lVertPix);
					if (SSDIC_ERR_NONE == lRet) {
						FILE	*fp = NULL;
						fp = fopen("Monitor.csv", "wt");
						if (fp) {
							ULONG nIdx = 0;
							for (ULONG nV = 0 ; nV < lVertPix ; nV++) {
								for (ULONG nH = 0 ; nH < lHoriPix ; nH++) {
									fprintf(fp, "%d, ", pData[nIdx++]);
								}
								fprintf(fp, "\n");
							}
							fclose(fp);
						}
					}
				}
			}
			break;
		case SSDIC_MEAS_EVENT_ABORT_PROC:	// Abort Process Event
			strEventMessage = _T("Abort Process\n");
			if (NULL != pDlg && pDlg->m_hHandle != 0) {
				ssdic_StopMeasureDataTransfer(pDlg->m_hHandle);
			}
			break;
		case SSDIC_MEAS_EVENT_FRAME_NUMB:	// Frame Number Event
			if (pArgData != NULL) {
				dwFrameNo = *((DWORD*)pArgData);
				nFrameNo = HIWORD(dwFrameNo);
				nFrameMax = LOWORD(dwFrameNo);
			}
			strEventMessage.Format(_T("Frame Number [%d / %d]\n"), nFrameNo, nFrameMax);
			break;
		case SSDIC_MEAS_EVENT_FRAME_RATE:	// Frame Rate Event
			dblFrameRate = *((DOUBLE*)pArgData);
			strEventMessage.Format(_T("Frame Rate [%f]\n"), dblFrameRate);
			break;
		case SSDIC_MEAS_EVENT_LOST_DATA:	// Lost Data Event
			strEventMessage = _T("Lost Data\n");
			break;
		default:
			strEventMessage = _T("Unkown Event\n");
			break;
	}

	CString	strInfoMessage;
	strInfoMessage.Format(_T("nEventNo = [%02d], pArgData = [%08X], pContext = [%08X]\n"), nEventNo, pArgData, pContext);
	TRACE(strEventMessage);
	TRACE(strInfoMessage);
}
///////////////////////////////////////////////////////////////////////
//
//	Terminate
//
///////////////////////////////////////////////////////////////////////
void Cssdic_sampleDlg::Terminate()
{
	ssdic_Disconnect(m_hHandle);
	ssdic_Terminate();
	// delete buffer
	if(m_pTransBuffer != NULL)
	{
		delete m_pTransBuffer;
		m_pTransBuffer = NULL;
	}

}

void Cssdic_sampleDlg::OnBnClickedOk()
{
	Terminate();
	OnOK();
}

void Cssdic_sampleDlg::OnBnClickedButtonTerm()
{
	Terminate();
	ButtonEnable(0);
}

///////////////////////////////////////////////////////////////////////
//
//	Enable / Disable for button
//
//		unFlag	: 0	: Enable, Initialize button
//				: 1 : Enable, Measure & Termnate button
//				: 2 : Disable, all
//
///////////////////////////////////////////////////////////////////////
void Cssdic_sampleDlg::ButtonEnable(UINT unFlag)
{
	BOOL	bInit = FALSE;
	BOOL	bMeas = FALSE;
	BOOL	bTerm = FALSE;
	BOOL	bExit = FALSE;
	BOOL	bStop = FALSE;
	BOOL	bTest = FALSE;
	switch(unFlag) {
		case 0:
			bInit = TRUE;
			bExit = TRUE;
			break;
		case 1:
			bMeas = TRUE;
			bTerm = TRUE;
			bTest = TRUE;
			break;
		case 2:
			bStop = TRUE;
			break;
		default:
			break;
	}

	m_buttonRdoCl.EnableWindow(bInit);
	m_buttonRdoUsb.EnableWindow(bInit);
	m_buttonRdoUdp.EnableWindow(bInit);
	m_buttonRdoTcp.EnableWindow(bInit);
	m_buttonInit.EnableWindow(bInit);
	m_buttonAcq.EnableWindow(bMeas);
	m_buttonMon.EnableWindow(bMeas);
	m_buttonStop.EnableWindow(bStop);
	m_buttonTerm.EnableWindow(bTerm);
	m_buttonOK.EnableWindow(bExit);
	m_buttonChkFunc.EnableWindow(bTest&(!bStop));
}


void Cssdic_sampleDlg::OnBnClickedButtonChkfunc()
{

	LONG	lRet = SSDIC_ERR_NONE;
	LONG	lVal = 0;
	LONG	lVal0 = 0;
	LONG	lVal1 = 0;
	LONG	lVal2 = 0;
	LONG	lVal3 = 0;
	INT		nVal = 0;
	DOUBLE	dblVal = 0.0;
	CHAR	szVal[256] = {0};
	CHAR	szVal0[256] = {0};
	SSDIC_BINNING_INFO	stBinTbl;
	CString	strMsg = _T("");
	CString	strWk = _T("");

	m_edtTraceFunc.SetWindowText(strMsg);

	lRet = ssdic_GetDeviceInfo	(0, 0, szVal, sizeof(szVal));
	strWk.Format(_T("%04X = ssdic_GetDeviceInfo()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_GetConnectDevInfo(m_hHandle, SSDIC_DEVINFO_LIBRARY_VER, szVal, sizeof(szVal));
	strWk.Format(_T("%04X = ssdic_GetConnectDevInfo()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);

	lRet = ssdic_LoadParameter	(m_hHandle);
	strWk.Format(_T("%04X = ssdic_LoadParameter()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_LoadCoolingTemperature(m_hHandle);
	strWk.Format(_T("%04X = ssdic_LoadCoolingTemperature()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);

	lRet = ssdic_GetBitPerPixel	(m_hHandle, &lVal);
	strWk.Format(_T("%04X = ssdic_GetBitPerPixel()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_GetBytePerPixel(m_hHandle, &lVal);
	strWk.Format(_T("%04X = ssdic_GetBytePerPixel()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_GetTransferFreq(m_hHandle, 0, &dblVal);
	strWk.Format(_T("%04X = ssdic_GetTransferFreq()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);

	lRet = ssdic_GetGain	(m_hHandle, &lVal);
	strWk.Format(_T("%04X = ssdic_GetGain()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_SetGain	(m_hHandle, lVal);
	strWk.Format(_T("%04X = ssdic_SetGain()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);

	lRet = ssdic_GetOffset	(m_hHandle, &lVal);
	strWk.Format(_T("%04X = ssdic_GetOffset()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_SetOffset	(m_hHandle, lVal);
	strWk.Format(_T("%04X = ssdic_SetOffset()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);

	lRet = ssdic_GetTrigger	(m_hHandle, &lVal, &lVal0, &lVal1, &lVal2, &lVal3);
	strWk.Format(_T("%04X = ssdic_GetTrigger()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_SetTrigger	(m_hHandle, lVal, lVal0, lVal1, lVal2, lVal3);
	strWk.Format(_T("%04X = ssdic_SetTrigger()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);

	lRet = ssdic_GetOutputSignal(m_hHandle, &lVal, &lVal0, &lVal1, &lVal2, &lVal3);
	strWk.Format(_T("%04X = ssdic_GetOutputSignal()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_SetOutputSignal(m_hHandle, lVal, lVal0, lVal1, lVal2, lVal3);
	strWk.Format(_T("%04X = ssdic_SetOutputSignal()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);

	lRet = ssdic_GetBinningCmdVersion(m_hHandle, &lVal);
	strWk.Format(_T("%04X = ssdic_GetBinningCmdVersion()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_GetBinning	(m_hHandle, &lVal, &lVal0, szVal, sizeof(szVal), &lVal1, szVal0, sizeof(szVal0));
	strWk.Format(_T("%04X = ssdic_GetBinning()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_SetBinning	(m_hHandle, lVal, lVal0, szVal, sizeof(szVal), lVal1, szVal0, sizeof(szVal0));
	strWk.Format(_T("%04X = ssdic_SetBinning()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_GetBinning_Ex	(m_hHandle, &stBinTbl);
	strWk.Format(_T("%04X = ssdic_GetBinning_Ex()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_SetBinning_Ex	(m_hHandle, &stBinTbl);
	strWk.Format(_T("%04X = ssdic_SetBinning_Ex()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);

	lRet = ssdic_GetSensorOutputTAP(m_hHandle, &lVal);
	strWk.Format(_T("%04X = ssdic_GetSensorOutputTAP()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_SetSensorOutputTAP(m_hHandle, lVal);
	strWk.Format(_T("%04X = ssdic_SetSensorOutputTAP()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);

	lRet = ssdic_GetLEDCtrl	(m_hHandle, &lVal);
	strWk.Format(_T("%04X = ssdic_GetLEDCtrl()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_SetLEDCtrl	(m_hHandle, lVal);
	strWk.Format(_T("%04X = ssdic_SetLEDCtrl()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);

	lRet = ssdic_GetBaseTimeUnit(m_hHandle, &lVal);
	strWk.Format(_T("%04X = ssdic_GetBaseTimeUnit()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_SetBaseTimeUnit(m_hHandle, lVal);
	strWk.Format(_T("%04X = ssdic_SetBaseTimeUnit()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);

	lRet = ssdic_GetCoolingControl(m_hHandle, &lVal);
	strWk.Format(_T("%04X = ssdic_GetCoolingControl()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_SetCoolingControl(m_hHandle, lVal);
	strWk.Format(_T("%04X = ssdic_SetCoolingControl()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_GetCoolingTemperature(m_hHandle, &nVal);
	strWk.Format(_T("%04X = ssdic_GetCoolingTemperature()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_SetCoolingTemperature(m_hHandle, nVal);
	strWk.Format(_T("%04X = ssdic_SetCoolingTemperature()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_GetCoolingTemperatureCurrent(m_hHandle, &nVal);
	strWk.Format(_T("%04X = ssdic_GetCoolingTemperatureCurrent()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_GetCoolingStatus(m_hHandle, &nVal);
	strWk.Format(_T("%04X = ssdic_GetCoolingStatus()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_GetFanStatus	(m_hHandle, &lVal);
	strWk.Format(_T("%04X = ssdic_GetFanStatus()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);

	lRet = ssdic_SaveParameter	(m_hHandle);
	strWk.Format(_T("%04X = ssdic_SaveParameter()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
	lRet = ssdic_SaveCoolingTemperature(m_hHandle);
	strWk.Format(_T("%04X = ssdic_SaveCoolingTemperature()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);

	lRet = ssdic_GetLastError	(m_hHandle);
	strWk.Format(_T("%04X = ssdic_GetLastError()\r\n"), lRet);
	strMsg += strWk;
	m_edtTraceFunc.SetWindowText(strMsg);
}

void Cssdic_sampleDlg::OnBnClickedButtonState()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	CString strConnectState = _T("");
	if(m_hHandle == SSDIC_INVALID_HANDLE)
	{
		strConnectState = _T("Not connected Camera");
	}
	else
	{
		LONG lRet = ssdic_GetConnectState(m_hHandle);
		if(lRet == SSDIC_ERR_NONE)
		{
			strConnectState = _T("Connected to Camera");
		}
		else
		{
			strConnectState = _T("Disonnected to Camera");
		}
	}
	m_stcConnectStat.SetWindowText(strConnectState);
}

void Cssdic_sampleDlg::OnBnClickedButtonSendrecv()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	UpdateData(TRUE);
	char* pszSend;
	char szReceive[256];
	m_strSend += _T("\r\n");
	pszSend = (LPTSTR)(LPCTSTR)m_strSend;
	LONG lRet = ssdic_SendRecvCmd(m_hHandle, pszSend, strlen(pszSend), szReceive,sizeof(szReceive) );
	m_edtReceive.SetWindowText(CString(szReceive));
}
