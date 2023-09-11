// [File Name]  ssdic.h
//
// [Outline]   ssdic.dll Header File
//
// [Update history]  [New]     Wed Nov 07 13:53:52 2007
// 					 [Update]  Tue Oct 08 20:58:00 2007
//					 [Update]  Wed Jan 09 21:45:00 2007
//					 [Update]  Wed Apr 21 11:45:00 2010
//					 [Update]  Thr Jul 26 17:45:00 2012
//					 [Update]  Mon Sep 10 17:45:00 2012
//					 [Update]  Fri Aug 30 16:05:00 2013
//					 [Update]  Mon Sep 30 16:26:00 2013
//
///////////////////////////////////////////////////////////////////////////////
#if !defined(SSDIC_H__INCLUDED_)
#define SSDIC_H__INCLUDED_

// [Macros Definition]
#ifndef _SSDICCTRL_EXPORT
#define _SSDICCTRL_EXPORT	__declspec( dllimport )
#endif

#ifndef	_STDCALL
#define	_STDCALL			_stdcall
#endif

//#ifdef	__cplusplus
//extern	"C" {
//#endif

///////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------------
// Constant definition
//-----------------------------------------------------------------------------

// [Illegal Handle Definition]
#define SSDIC_INVALID_HANDLE	(-1)

// [Device Information Type definition]
#define SSDIC_DEVINFO_CONPANY_NAME	(1)		// Sales companies information
#define SSDIC_DEVINFO_PRODUCT_NAME	(2)		// Product name (serial number)
#define SSDIC_DEVINFO_BUS_NAME		(3)		// Bus Name (I/F)
#define SSDIC_DEVINFO_SYMBOL		(4)		// Camera identification (serial No.)
#define SSDIC_DEVINFO_CAMERA_VER	(5)		// Camera version (firmware)
#define SSDIC_DEVINFO_DRIVER_VER	(6)		// driver version

#define SSDIC_DEVINFO_CAMERA_TYPE	(10)	// Camera serial number
#define SSDIC_DEVINFO_SERIAL_NUMBER	(11)	// Serial number
#define SSDIC_DEVINFO_FIRM_VER		(12)	// Firmware Version
#define SSDIC_DEVINFO_CHIP_TYPE		(13)	// Chip type
#define SSDIC_DEVINFO_LOT_NUMBER	(14)	// Lot number
#define SSDIC_DEVINFO_CHIP_NUMBER	(15)	// Chip serial number

#define SSDIC_DEVINFO_INSPECT_DATE	(16)	// Inspection day
#define SSDIC_DEVINFO_USB_RATE		(17)	// USB transmission type (1.1/2.0)


#define	SSDIC_DEVINFO_INTERFACE_NAME	(18)	// Interface Type Name

#define SSDIC_DEVINFO_LIBRARY_VER	(101)	// library version
#define SSDIC_DEVINFO_CTL_LIB_VER	(102)	// I/F control library version

// [Binning information setting function]
#define SSDIC_BINING_INFO_FULLLINE	(5)		// Full line binning

// [Trigger information setting function]
#define SSDIC_TRIGMODE_INT1				(0)		// Internal triggering 1
#define SSDIC_TRIGMODE_EXT_ASYNC_EDGE	(1)		// External asynchronization edge
#define SSDIC_TRIGMODE_EXT_SYNC_EDGE	(2)		// External synchronization edge
#define SSDIC_TRIGMODE_EXT_SYNC_LEVEL	(3)		// External synchronization level
#define SSDIC_TRIGMODE_INT_TDI			(4)		// Internal TDI triggering 
#define SSDIC_TRIGMODE_EXT_TDI			(5)		// External TDI triggering 
#define SSDIC_TRIGMODE_INT2				(6)		// Internal triggering 2
#define SSDIC_TRIGMODE_EXT_LEVEL1		(7)		// External synchronization (EXTERNAL SYNCRONOUS LEVEL )
#define SSDIC_TRIGMODE_EXT_GATED		(8)		// External gatting (EXTERNAL GATING TRIGGER)
#define SSDIC_TRIGMODE_EXT_EDGE2		(9)		// External synchoronization edge 2
#define SSDIC_TRIGMODE_EXT_LEVEL2		(10)	// External synchoronization level 2
#define SSDIC_TRIGMODE_EXT_EDGE3		(11)	// External synchoronization level 3
#define SSDIC_TRIGMODE_EXT_EDGE2_ONE	(12)	// External synchoronization edge 2 oneshot
#define SSDIC_TRIGMODE_EXT_SYNC_GATED	(13)	// External synchoronization gatting
#define SSDIC_TRIGMODE_GS_INT			(14)	// Internal triggering
#define SSDIC_TRIGMODE_GS_EDGE1			(15)	// External asynchronization edge
#define SSDIC_TRIGMODE_GS_EDGE2			(16)	// External synchronization edge
#define SSDIC_TRIGMODE_GS_EDGE3			(17)	// External synchronization edge
#define SSDIC_TRIGMODE_GS_LEVEL1		(18)	// External asynchronization level
#define SSDIC_TRIGMODE_GS_LEVEL2		(19)	// External synchronization level
#define SSDIC_TRIGMODE_GS_GATE			(20)	// External asynchronization gating
#define SSDIC_TRIGMODE_RS_INT			(21)	// Internal triggering
#define SSDIC_TRIGMODE_RS_EDGE1			(22)	// External asynchronization edge
#define SSDIC_TRIGMODE_RS_EDGE2			(23)	// External synchronization edge
#define SSDIC_TRIGMODE_RS_EDGE3			(24)	// External asynchronization edge
#define SSDIC_TRIGMODE_RS_LEVEL1		(25)	// External asynchronization level
#define SSDIC_TRIGMODE_RS_LEVEL2		(26)	// External synchronization level
#define SSDIC_TRIGMODE_RS_GATE			(27)	// External asynchronization gating
#define SSDIC_TRIGMODE_MS_INT			(28)	// Internal triggering
#define SSDIC_TRIGMODE_MS_EDGE1			(29)	// External asynchronization edge
#define SSDIC_TRIGMODE_MS_EDGE2			(30)	// External synchronization edge
#define SSDIC_TRIGMODE_MS_EDGE3			(31)	// External asynchronization edge
#define SSDIC_TRIGMODE_MS_LEVEL1		(32)	// External asynchronization level
#define SSDIC_TRIGMODE_MS_LEVEL2		(33)	// External synchronization level
#define SSDIC_TRIGMODE_MS_GATE			(34)	// External asynchronization gating

#define SSDIC_TRIGPOL_POSITIVE		(0)		// the trigger polarity positive
#define SSDIC_TRIGPOL_NEGATIVE		(1)		// the trigger polarity negative

#define SSDIC_TRIGTRM_BNC			(0)		// Termnal BNC only
#define SSDIC_TRIGTRM_CLC			(1)		// Termnal Cameralink connector only
#define SSDIC_TRIGTRM_AND			(2)		// Termnal AND of BNC with CLC connector
#define SSDIC_TRIGTRM_OR			(3)		// Termnal OR of BNC with CLC connector

// [External output information setting function]
#define SSDIC_OUTMODE_OUTPUT		(0)		// External output done
#define SSDIC_OUTMODE_NOT			(1)		// External output not done
#define SSDIC_OUTMODE_AUTO			(2)		// Automatic output

#define SSDIC_OUTMODE_POSITIVE		(0)		// Polarity positive
#define SSDIC_OUTMODE_NEGATIVE		(1)		// Polarity negative

#define SSDIC_OUTMODE_BNC			(0)		// BNC only


// [LED control information set function]
#define SSDIC_LED_OFF				(0)		// OFF
#define SSDIC_LED_ON				(1)		// ON

// [Transfer frequency get function]
#define SSDIC_TRANSFREQ_HOLIZONTAL	(1)		// Horizontal
#define SSDIC_TRANSFREQ_FRAMERATE	(2)		// Frame rate

// [Standard time unit get function]
#define SSDIC_STDTIME_MSMS			(0)		// Storage time=[mSec]、External trigger output=[mSec]
#define SSDIC_STDTIME_USUS			(1)		// Storage time=[uSec]、External trigger output =[uSec]
#define SSDIC_STDTIME_MSUS			(2)		// Storage time =[mSec]、External trigger output =[uSec]
#define SSDIC_STDTIME_CLOCK			(3)		// Clock count both "Storage time" and "External trigger output"

// [Measurement processing state acquire function]
#define SSDIC_MEASURESTATE_START	(0)		// Start
#define SSDIC_MEASURESTATE_STOP		(1)		// Stop

// [Integration capacity set function]
#define SSDIC_INTEGCAPACITY_00		(0)		// 0.05 [pF]
#define SSDIC_INTEGCAPACITY_01		(1)		// 0.1 [pF]
#define SSDIC_INTEGCAPACITY_02		(2)		// 0.2 [pF]
#define SSDIC_INTEGCAPACITY_05		(3)		// 0.5 [pF]
#define SSDIC_INTEGCAPACITY_10		(4)		// 1.0 [pF]
#define SSDIC_INTEGCAPACITY_20		(5)		// 2.0 [pF]
#define SSDIC_INTEGCAPACITY_50		(6)		// 5.0 [pF]
#define SSDIC_INTEGCAPACITY_100		(7)		// 10.0 [pF]

// [Setting of camera correction function]
#define SSDIC_CALIBRATION_OFF		(0)		// OFF
#define SSDIC_CALIBRATION_ON		(1)		// ON

// [Setting of Deffective pixel correction switch function]
#define SSDIC_CORRDEFECTPIX_OFF		(0)		// OFF
#define SSDIC_CORRDEFECTPIX_ON		(1)		// ON

// [Setting of Deffective pixel correction mode function]
#define SSDIC_DEFECTPIX_SET			(0)		// Send correction data to devixe function
#define SSDIC_DEFECTPIX_SAVE		(1)		// Save to EEPROM function in device
#define SSDIC_DEFECTPIX_RESET		(2)		// Reset correction data on RAM in device

// [Setting of Sensor Over Clock function]
#define	SSDIC_OVER_CLOCK_NONE_128	(0)		// None Over Clock of 128-pixels/port.
#define	SSDIC_OVER_CLOCK_EXIST_128	(1)		// Exist 50-pixels Over Clock of 128-pixels/port.
#define	SSDIC_OVER_CLOCK_NONE_256	(2)		// None Over Clock of 256-pixels/port.
#define	SSDIC_OVER_CLOCK_EXIST_256	(3)		// Exist 50-pixels Over Clock of 256-pixels/port.

// [Binning mode]
#define	SSDIC_BINNING_MODE_FULLLINE			(5)		// full line binning
#define	SSDIC_BINNING_MODE_AREA				(3)		// area binning
#define	SSDIC_BINNING_MODE_LINEPIXEL		(1)		// line and pixel binning
#define	SSDIC_BINNING_MODE_AREA_EXTRUCTION	(2)		// area extruction

// [Binning sub mode]
#define	SSDIC_BINNING_AREA_1X1			(1)		// area binning 1x1
#define	SSDIC_BINNING_AREA_2X2			(2)		// area binning 2x2
#define	SSDIC_BINNING_AREA_4X4			(4)		// area binning 4x4
#define	SSDIC_BINNING_AREA_8X8			(8)		// area binning 8x8
#define	SSDIC_BINNING_AREA_16X16		(16)		// area binning 16x16
#define	SSDIC_BINNING_LINEPIX_ANY		(0)		// line and pixel binning any point
#define	SSDIC_BINNING_LINEPIX_X1		(1)		// line and pixel binning x1
#define	SSDIC_BINNING_LINEPIX_X2		(2)		// line and pixel binning x2
#define	SSDIC_BINNING_LINEPIX_X4		(4)		// line and pixel binning x4
#define	SSDIC_BINNING_LINEPIX_X8		(8)		// line and pixel binning x8
#define	SSDIC_BINNING_LINEPIX_X16		(16)		// line and pixel binning x16

#define MAX_SSDIC_BINNING_LINEPIX_POINTS	(1024)	// Max binning points

// Definition Sensor output TAP type
#define SSDIC_TAP_A						(0)		// Low noise TAP
#define SSDIC_TAP_B						(1)		// High speed TAP

// Search device interface type
#define	SSDIC_IF_USB					(0x00000001)	// USB
#define SSDIC_IF_CL						(0x00000002)	// CameraLink 
#define SSDIC_IF_ETHERNET				(0x00000004)	// Ethernet (Reserve)
#define SSDIC_IF_TCP					(0x00000004)	// TCP[Ethernet] (Reserve)
#define SSDIC_IF_UDPP					(0x00000008)	// UDP (Reserve)
#define SSDIC_IF_GENI					(0x00000010)	// GenICam
//#define SSDIC_IF_TCPUDP					(0x00000020)	// TCP and UDP

//Data Receive Mode
#define SSDIC_DATA_RECV_TCP				(0x00000000)	//TCP
#define SSDIC_DATA_RECV_UDP				(0x00000001)	//UDP

// Temperature control type definition.
#define	SSDIC_COOLING_FAN				(1)		// FAN start.
#define	SSDIC_COOLING_COOL				(2)		// Cooling start
#define	SSDIC_COOLING_FANCOOL			(3)		// FAN and Cooling start.
#define	SSDIC_COOLING_STOP				(5)		// Stop cooling.

///////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------------
// Type Definition
//-----------------------------------------------------------------------------

// [Discrimination Handle Type Definition]
typedef	LONG HDEVIF;

// [Measure CallBack Function and Event Code Definition]
typedef VOID (CALLBACK* PMEAS_EVENT)( INT nEventNo, PVOID pArgData, PVOID pContext );
#define SSDIC_MEAS_EVENT_TRANS_COMP		(0)		// Transfer Complete Event
#define SSDIC_MEAS_EVENT_FRAME_RATE		(1)		// Frame Rate Event
#define SSDIC_MEAS_EVENT_ABORT_PROC		(2)		// Abort Process Event
#define SSDIC_MEAS_EVENT_FRAME_NUMB		(3)		// Frame Number Event
#define SSDIC_MEAS_EVENT_LOST_DATA		(4)		// Lost Data Event

// [Measure Parameter Structure]
typedef struct tagSSDICCTRL_ACQ_INFO{
	ULONG nWidth;				// Measure Data Width
	ULONG nHeight;				// Measure Data Height
	ULONG nFrameBytes;			// Measure Data Size
	ULONG nFrameCount;			// Measure Data Count
	PMEAS_EVENT pMeasRoutine;	// CallBack Function
	PVOID pMeasContext;			// CallBack Function Use Variable
	INT   nFrmRateMode;			// Reserve * "0" Set
	//{{{ K.Mizuno 20160912 結局使われていないようなので、元に戻す
	//// *********************************************************
	//// APR.2016.12 Changed the function of "bDataLost".
	////            This item was change the "reserve" to "MultiLine Mode"
	////            (False:Software-MultiLine, True:Hardware-MultiLine)
	//// ********************************************************
	//// BOOL  bDataLost;			// Reserve * "FALSE" Set
	//BOOL  bMultiLine;			// MultiLine Mode (False:SW / True:HW)
	//							// default is "FALSE"
	//// ********************************************************
	BOOL  bDataLost;			// Reserve * "FALSE" Set
	//}}} K.Mizuno 20160912
	PVOID pTransBuffer;			// Exchanges Buffer
} SSDICCTRL_ACQ_INFO, *PSSDICCTRL_ACQ_INFO;

typedef struct tagSSDICCTRL_MON_INFO{
	ULONG nWidth;				// Measure Data Width
	ULONG nHeight;				// Measure Data Height
	ULONG nFrameBytes;			// Measure Data Size
	ULONG nFrameCount;			// Measure Data Count
	ULONG nEventPerFrame;		// Event Notice Timing
	PMEAS_EVENT pMeasRoutine;	// CallBack Function
	PVOID pMeasContext;			// CallBack Function Use Variable
	INT   nFrmRateMode;			// Reserve * "0" Set
	//{{{ K.Mizuno 20160912 結局使われていないようなので、元に戻す
	//// *********************************************************
	//// APR.2016.12 Changed the function of "bDataLost".
	////            This item was change the "reserve" to "MultiLine Mode"
	////            (False:Software-MultiLine, True:Hardware-MultiLine)
	//// ********************************************************
	//// BOOL  bDataLost;			// Reserve * "FALSE" Set
	//BOOL  bMultiLine;			// MultiLine Mode (False:SW / True:HW)
	//							// default is "FALSE"
	//// ********************************************************
	BOOL  bDataLost;			// Reserve * "FALSE" Set
	//}}} K.Mizuno 20160912
	INT	  nMonType;				// Reserve * "1" Set
	BOOL  bBlockRead;			// Reserve * "FALSE" Set
} SSDICCTRL_MON_INFO, *PSSDICCTRL_MON_INFO;

typedef struct tagSSDIC_SENSOR_INFO
{
	CString	strSensorName;			// Sensor Name
	INT     nTypeCode;				// Type code
	INT		nPixelsPerLine;			// Pixel number
	INT		nLinesPerFrame;			// Line number
	//---> C1580X対応 センサ情報追加 2019.12.10 ActySystem ohyama
	INT		nHFrontDummy;			// Horizontal Front Dummy
	INT		nHBackDummy;			// Horizontal Back Dummy
	INT		nVFrontDummy;			// Virtical Front Dummy
	INT		nVBackDummy;			// Virtical Back Dummy
	//<--- C1580X対応 センサ情報追加 2019.12.10 ActySystem ohyama
}SSDIC_SENSOR_INFO, *pSSDIC_SENSOR_INFO;

// [Binning Position]
// Coordinate
typedef struct tagSSDIC_BINPOS
{
	LONG	x;
	LONG	y;
} SSDIC_BINPOS, *PSSDIC_BINPOS;

// Binning point definition
typedef struct tagSSDIC_BINNINGPOINT
{
	LONG	lPos;
	BOOL	bMask;
} SSDIC_BINNINGPOINT, *PSSDIC_BINNINGPOINT;

typedef struct tagSSDIC_BINNING_INFO
{
	// dummy
	//BOOL	bDummyValid;			// valid flag for dummy area masking (Reserved)
	BOOL	bDummyMask;				// dummy area mask flag
	// binning
	//BOOL	bBinningValid;			// valid flag for binning (Reserved)
	LONG	lBinningMode;			// binning mode
	LONG	lAreaMode;				// area binning mode
	SSDIC_BINPOS	tAreaExt[2];			// area extruction coordinate
	// line pixel binning parameter
	BOOL	bLineBinningExist;		// line binning used flag
	LONG	lLineBinningMode;		// line binning mode
	LONG	lLineBinningCount;		// line binning point count
	SSDIC_BINNINGPOINT tLineBinning[MAX_SSDIC_BINNING_LINEPIX_POINTS];		// line binning point list [caution : including last line setting]
	// ------
	BOOL	bPixelBinningExist;		// pixel binning used flag
	LONG	lPixelBinningMode;		// pixel binning mode
	LONG	lPixelBinningCount;		// pixel binning point count
	SSDIC_BINNINGPOINT tPixelBinning[MAX_SSDIC_BINNING_LINEPIX_POINTS];		// pixel binning point list [caution : including last pixel setting]
	// ------
	LONG	lImageCapWidth;			// current capture width (pixel count including dummy area)
	LONG	lImageCapHeight;		// current capture height (line count including dummy area)
} SSDIC_BINNING_INFO, *PSSDIC_BINNING_INFO;

//-----------------------------------------------------------------------------
//  Target list structure.   IP-Address & Port-Number (for TCP/IP)  2014.03.31
//-----------------------------------------------------------------------------
typedef struct tag_SSDIC_TARGET_INFO 
{
	BYTE	byIPAddr[4];			// IP Address
	WORD	wCmdPort;				// Command port number
	WORD	wDataPort;				// Data port number
} SSDIC_TARGET_INFO, *PSSDIC_TARGET_INFO;

//-----------------------------------------------------------------------------
// # Error Code List
//	[Error Code] - 0x0000 -- 0x0FFF
//-----------------------------------------------------------------------------
#define SSDIC_BASECODE					(0x0000)				// ModuleCtrl Err Code Base

// [Error Code]
#define SSDIC_ERR_NONE					(SSDIC_BASECODE)			// There is no error (normal termination)
#define SSDIC_ERR_NOT_INITIALIZE		(SSDIC_BASECODE + 0x01) 	// Initialization is not done
#define SSDIC_ERR_ALREADY_INITIALIZE	(SSDIC_BASECODE + 0x02) 	// Initialization has already been done
#define SSDIC_ERR_INVALID_PARAMETER		(SSDIC_BASECODE + 0x03) 	// The parameter is illegal.
#define SSDIC_ERR_MEMORY_ALLOCATE		(SSDIC_BASECODE + 0x05)		// The memory allocation error occurred
#define SSDIC_ERR_CAM_FILE_READ			(SSDIC_BASECODE + 0x0B)		// It failed in the camera file reading
#define SSDIC_ERR_IFDLL_LOAD			(SSDIC_BASECODE + 0x0C)		// Error occurs while reading the I/F library
#define SSDIC_ERR_IFDLL_INIT			(SSDIC_BASECODE + 0x0D)		// Fails in the I/F library initialization
#define SSDIC_ERR_MISSING_IFDLL_FUNC	(SSDIC_BASECODE + 0x0E)		// Fails because of the processing of the I/F library
#define SSDIC_ERR_GET_VERSION			(SSDIC_BASECODE + 0x14)		// Fails in the version acquisition
#define SSDIC_ERR_DEVICE_SEARCH			(SSDIC_BASECODE + 0x15)		// Fails in the device search
#define SSDIC_ERR_ALREADY_CONNCTED		(SSDIC_BASECODE + 0x16)		// The device has already been connected
#define SSDIC_ERR_CONNECT_DEVICE		(SSDIC_BASECODE + 0x17)		// The error occurred by the device connection
#define SSDIC_ERR_GET_DEV_INFO			(SSDIC_BASECODE + 0x18)		// Fails because of the acquisition of device information
#define SSDIC_ERR_NOT_ACCESS			(SSDIC_BASECODE + 0x19)		// Can not access device
#define SSDIC_ERR_COMMAND_CTRL			(SSDIC_BASECODE + 0x1E)		// Fails because of the command control
#define SSDIC_ERR_INVALID_CTRL			(SSDIC_BASECODE + 0x1F)		// This control doesn't correspond
#define SSDIC_ERR_CAPTURE				(SSDIC_BASECODE + 0x20)		// Fails in the data measurement
#define SSDIC_ERR_COOLING_ON			(SSDIC_BASECODE + 0x21)		// 
#define SSDIC_ERR_COOLING_OFF			(SSDIC_BASECODE + 0x22)		// 


//-----------------------------------------------------------------------------
// Function Definition
//-----------------------------------------------------------------------------


// ****************************************************************************
// for Library
// ****************************************************************************

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_GetVersion (Get DLL Version)
//
// [Summary]		Get SSDIC version string
//
// [Parameters]		None
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note] 			This function is executed first without fail. Only one process can be used in OS.
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetVersion(CHAR* pszInfo, LONG lSize);

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_Initialize (Initialize function)
//
// [Summary]		Initializes the library
//
// [Parameters]		None
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note] 			This function is executed first without fail. Only one process can be used in OS.
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_Initialize( VOID );

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_Terminate (Terminate function)
//
// [Summary]  		Library resource is opened and device driver is closed.
//
// [Parameters]  	None
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			Please call it when the end of the program or this library becomes unnecessary.
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_Terminate( VOID );

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetLastError (Get latest error code function)
//
// [Summary]  		Get the latest error code.
//
// [Parameters]  	[i] hDevice	: Handle to identify the target device.
//
// [Return value]  	It is the latest error code. Please see the error
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetLastError(HDEVIF hDevice);


// ****************************************************************************
// for Device
// ****************************************************************************

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_DeviceSearch (Device search function)
//
// [Summary]		The device is searched, and the number of devices is returned.
//
// [Parameters]		[o] plDevCount : Specifies the address of a variable to store the number
//								  	of devices searched that may be connected.
//
// [Return value]	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SearchDevice( LONG* plDevCount );

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_DeviceSearch (Device search function)
//
// [Summary]		The device is searched, and the number of devices is returned.
//
// [Parameters]		[i] nDemandIF : Search interface type. (USB/CL)
//					[o] plDevCount : Specifies the address of a variable to store the number
//								  	of devices searched that may be connected.
//
// [Return value]	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SearchDeviceEx( INT nDemandIF, LONG* plDevCount );

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_GetDeviceInfo (Device information acquisition function)
//
// [Summary]  		Device information and essential information of the library are acquired.
//
// [Parameters]  	[i] lIndex :	The index number of the acquired device is specified.
//			 		[i] nType  :	The information type of the acquired device is specified.
//									*"3.3 Parameter definition" Reference
//			 		[o] pszInfo:	The address in the buffer where acquired information is stored is specified.
//			 		[i] lSize  :	Buffer size is set.
//
// [Return value] 	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			When the number of connected devices changes, execute it without fail.
//					The connection closed device is not counted.
//
// [history] 		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetDeviceInfo( LONG lIndex, INT nType, CHAR* pszInfo, LONG lSize );

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetConnectDevInfo (Acquisition of connection status of device function)
//
// [Summary]  		Connection status of device (Camera) is acquired.
//
// [Parameters]  	[i] hDevice	: The acquired device identification handle is specified.
//			 		[o] pnInfo	: The address of the variable that stores the connection status of the device is
//								  specified.
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetConnectDevInfo( HDEVIF hDevice, INT nType,
										CHAR* pszInfo, LONG lSize ) ;

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_Connect (Connection function)
//
// [Summary]		Connects the device.
//
// [Parameters]  	[i] lIndex		: The index number of the acquired device is specified.
//			 		[o] phDevice	: The address where the connected device identification handle is stored is
//									  specified.
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			The identification handle is different from the handle generally used with Windows.
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_Connect( LONG lIndex, HDEVIF *phDevice );

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_Disconnect (Disconnect function)
//
// [Summary]  		Disconnects the device.
//
// [Parameters]		[i] hDevice	: handle of the device to be disconnected is specified.
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_Disconnect( HDEVIF hDevice );

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_RebootDevice (Reboot function)
//
// [Summary]  		Reboots the device.
//
// [Parameters]		[i] hDevice	: handle of the device to be rebooted is specified.
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_RebootDevice( HDEVIF hDevice );

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetDataReceiveMode (Acquisition of connection status of ethernet port)
//
// [Summary]  		Connection status of ethernet port (Camera) is acquired.
//
// [Parameters]  	[i] hDevice				: The acquired device identification handle is specified.
//			 		[o] plDataReceiveMode	: The address of the variable that stores the connection status 
//								  of the ethernet port(TCP/UDP).
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetDataReceiveMode(HDEVIF hDevice, LONG* plDataReceiveMode) ;

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_SetDataReceiveMode (Acquisition of connection status of ethernet port)
//
// [Summary]  		Connection status of ethernet port (Camera) is set.
//
// [Parameters]  	[i] hDevice				: The acquired device identification handle is specified.
//			 		[i] lDataReceiveMode	: The variable that stores the connection status 
//								  of the ethernet port(TCP/UDP).
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetDataReceiveMode(HDEVIF hDevice, LONG lDataReceiveMode) ;

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetBitPerPixel (Bit size information get function)
//
// [Summary]  		The bit size is acquired to about one pixel of the measurement data.
//
// [Parameters]  	[i] hDevice		: Handle to the device identification to start the measurement.
//			 		[o] plBitSize 	: The address of the variable that stores the current bit size set is specified.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history] 	 	[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetBitPerPixel(HDEVIF hDevice, LONG *plBitSize);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_SetBitPerPixel (Bit size information set function)
//
// [Summary]  		The bit size is set to about one pixel of the measurement data.
//
// [Parameters]  	[i] hDevice		: Handle to the device identification to start the measurement.
//			 		[i] lBitSize 	: The bit size set is specified.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history] 	 	[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetBitPerPixel(HDEVIF hDevice, LONG lBitSize);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetBytePerPixel (Byte size information get funcion)
//
// [Summary]  		Byte size is acquired to for one pixel of the measurement data.
//
// [Parameters]  	[i] hDevice		: Handle to the device identification to start the measurement.
//			 		[o] plByteSize	: The address of the variable that stores current byte size set is specified.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetBytePerPixel(HDEVIF hDevice, LONG *plByteSize);


// ****************************************************************************
// for Control cameras
// ****************************************************************************

//----------------------------------------------------------------------------
// [Function Name]  ssdic_GetBinningCmdVersion (Get binning command version)
//
// [Summary]  		Get binning command version.
//
// [Parameters]  	[i] hDevice	: device identification handle is specified.
//			 		[o] plMode  : The variable address where the command version is stored is specified.
//									000 : old version [C10854, C11512 series, C11514]
//									100 : new version [C12081]
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//					
//
// [Note]  			None
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL  ssdic_GetBinningCmdVersion(HDEVIF hDevice, LONG* plVersion);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_SetBinning (Set binning parameter function)
//
// [Summary]  		Set binning information.
//
// [Parameters]  	[i] hDevice	: device identification handle is specified.
//			 		[i] lMode  	: Binning mode to be set is specified.
//			 		[i] lMask1    : Front dummy mask pixel count to be set is specified.
//			 		[i] szFormat1 : The character string1 of the binning format for the specified mode
//							to be set is specified.
//			 		[i] lBuffSize1: The size of the buffer1 of the format to be set is specified.
//			 		[i] lMask2    : Back dummy mask pixel count to be set is specified.
//			 		[i] szFormat2 : The character string2 of the binning format for the specified mode
//							to be set is specified.
//			 		[i] lBuffSize2: The size of the buffer2 of the format to be set is specified.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL  ssdic_SetBinning(HDEVIF hDevice, LONG lMode,
								LONG lMask1, CHAR* szFormat1, LONG lBuffSize1,
								LONG lMask2, CHAR* szFormat2, LONG lBuffSize2);
_SSDICCTRL_EXPORT  LONG _STDCALL  ssdic_SetBinning_Ex(HDEVIF hDevice, SSDIC_BINNING_INFO* ptblBinning); 

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetBinning (Binning information acquisition function)
//
// [Summary]  		External output information acquisition is done.
//
// [Parameters]  	[i] hDevice		: device identification handle is specified.
//			 		[o] plMode    : The variable address where the binning mode set now is stored is specified.
//			 		[o] plMask1   : The variable address where the front dummy mask pixel count set now is stored is specified.
//			 		[o] szFormat1 : The variable address where the character string1 set now is stored is specified.
//			 		[i] lBuffSize1: The size of the buffer1 of the format to be set is specified.
//			 		[o] plMask2   : The variable address where the back dummy mask pixel count set now is stored is specified.
//			 		[o] szFormat2 : The variable address where the character string2 set now is stored is specified.
//			 		[i] lBuffSize2: The size of the buffer2 of the format to be set is specified.
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL  ssdic_GetBinning(HDEVIF hDevice, LONG* plMode,
								LONG* plMask1, CHAR *szFormat1, LONG lBuffSize1,
								LONG* plMask2, CHAR *szFormat2, LONG lBuffSize2);
_SSDICCTRL_EXPORT  LONG _STDCALL  ssdic_GetBinning_Ex(HDEVIF hDevice, SSDIC_BINNING_INFO* ptblBinning); 

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_SetGain (Set gain value function)
//
// [Summary]  		Set gain value.
//
// [Parameters]  	[i] hDevice	: device identification handle is specified.
//			 		[i] lGain : gain value to be set is specified.
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetGain(HDEVIF hDevice, LONG lGain);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetGain (Get gain value function)
//
// [Summary]  		Get gain value.
//
// [Parameters]  	[i] hDevice	: device identification handle is specified.
//			 		[o] plGain: The address of the variable that stores the gain value set now is specified.
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetGain(HDEVIF hDevice, LONG* plGain);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_SetOffset (Set offset value function)
//
// [Summary]  		Set offset value.
//
// [Parameters]  	[i] hDevice	: device identification handle is specified.
//			 		[i] lOffset : offset value to be set is specified.
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetOffset(HDEVIF hDevice, LONG lOffset);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetOffset (Get offset value function)
//
// [Summary]  		Get offset value.
//
// [Parameters]  	[i] hDevice	: device identification handle is specified.
//			 		[o] plOffset: The address of the variable that stores the offset value set now is specified.
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetOffset(HDEVIF hDevice, LONG* plOffset);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_SetTrigger (Trigger information setting function)
//
// [Summary]  		Trigger information setting is carried out.
//
// [Parameters]  	[i] hDevice	: device identification handle is specified.
//			 		[i] lMode  	: Trigger mode to be set is specified.
//			 		[i] lExpTime  : The exposure time to be set is specified.
//			 		[i] lPolarity : The trigger polarity to be set is specified.
//			 		[i] lWaitTime : The Wait time to be set is specified.
//			 		[i] lTerminal : The input terminal type to be set is specified.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetTrigger(HDEVIF hDevice, LONG lMode, 
								LONG lExpTime, LONG lPolarity, LONG lWaitTime, LONG lTerminal);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetTrigger (Trigger information acquisition function)
//
// [Summary]  		Trigger information acquisition is carried out.
//
// [Parameters]  	[i] hDevice	: device identification handle is specified.
//			 		[o] plMode  : The variable address where the trigger mode set now is stored is specified.
//			 		[o] plExpTime 	: The variable address where the exposure time set now is stored is specified.
//			 		[o] plPolarity	: The variable address where the trigger polarity set now is stored is specified.
//			 		[o] plWaitTime	: The variable address where the Wait time set now is stored is specified.
//			 		[o] plTerminal	: The variable address where the input terminal type set now is stored is specified.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetTrigger(HDEVIF hDevice, LONG* plMode, 
								LONG* plExpTime, LONG* plPolarity, LONG* plWaitTime, LONG* plTerminal);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_SetOutputSignal (External output information setting function)
//
// [Summary]  		External output information setting is done.
//
// [Parameters]  	[i] hDevice		: device identification handle is specified.
//			 		[i] lMode  		: Output mode to be set is specified.
//			 		[i] lPolarity  	: Polarity to be set is specified.
//			 		[i] lParameter1 : Delay time to be set is specified.
//			 		[i] lParameter2 : Pulse width be set is specified.
//			 		[i] lOutputType : Terminal type be set is specified.
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetOutputSignal( HDEVIF hDevice, LONG lMode, LONG lPolarity,
								LONG lParameter1, LONG lParameter2,
								LONG lOutputType);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetOutputSignal (External output information acquisition function)
//
// [Summary]  		External output information acquisition is done.
//
// [Parameters]  	[i] hDevice		: device identification handle is specified.
//			 		[o] plMode  	: The variable address where the output mode set now is stored is specified.
//			 		[o] plPolarity  : The variable address where the polarity set now is stored is specified.
//			 		[o] plParameter1: The variable address where the delay time set now is stored is specified.
//			 		[o] plParameter2: The variable address where the pulse width set now is stored is specified.
//			 		[o] plOutputType: The variable address where the terminal type set now is stored is specified.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL  ssdic_GetOutputSignal( HDEVIF hDevice, LONG* plMode, LONG* plPolarity,
								LONG* plParameter1, LONG* plParameter2,
								LONG* plOutputType);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_SetLEDCtrl (LED control information set function)
//
// [Summary]  		LED lighting settings.
//
// [Parameters]  	[i] hDevice		: Handle to identify the target device.
//			 		[i] lMode  		: Set LED control mode setting.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetLEDCtrl(HDEVIF hDevice, LONG lMode);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetLEDCtrl (LED control information set function)
//
// [Summary]  		Get the LED lighting settings.
//
// [Parameters]  	[i] hDevice		: Handle to identify the target device.
//			 		[o] plMode  	: The variable address where the LED control mode is stored is specified.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetLEDCtrl(HDEVIF hDevice, LONG *plMode);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetTransferFreq (Transfer frequency get function)
//
// [Summary]  		Get Horizontal / vertical transfer frequency.
//
// [Parameters]  	[i] hDevice		: Handle to identify the target device.
//			 		[i] lType  		: The direction type of the acquired transfer frequency is specified.
//			 		[o] pdblFreq	: Specifies the address of a variable to store the transfer frequency.
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetTransferFreq (HDEVIF hDevice, LONG lType, DOUBLE *pdblFreq);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_SaveParameter (Save device parameter function)
//
// [Summary]  		The setting of the circuit is written to EEPROM.
//
// [Parameters]  	[i] hDevice		: Handle to identify the target device.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SaveParameter(HDEVIF hDevice);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_LoadParameter (Load device parameter)
//
// [Summary]  		Reads EEPROM chip from the circuit configuration.
//
// [Parameters]  	[i] hDevice		: Handle to identify the target device.
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_LoadParameter (HDEVIF hDevice);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_SetBaseTimeUnit (Standard time unit set function)
//
// [Summary]  		Setting of standard time unit.
//
// [Parameters]  	[i] hDevice		: Handle to identify the target device.
//			 		[i] lMode  		: Sets the standard time unit to be set.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetBaseTimeUnit(HDEVIF hDevice, LONG lMode);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetBaseTimeUnit (Standard time unit get function)
//
// [Summary]  		Get of standard time unit.
//
// [Parameters]  	[i] hDevice		: Handle to identify the target device.
//			 		[o] plMode  	: Specifies the address of a variable that contains the standard time unit.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetBaseTimeUnit(HDEVIF hDevice, LONG *plMode);

//----------------------------------------------------------------------------
// [Function Name]  ssdic_StartAcquire (Acquisition measurement start function)
//
// [Summary]  		Start the acquisition measurement.
//
// [Parameters]  	[i] hDevice		: Handle to the device identification to start the measurement.
//			 		[i] pAcqInfo	: Parameterer information for the Acquisition measurement is specified.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_StartAcquire( HDEVIF hDevice, PSSDICCTRL_ACQ_INFO pAcqInfo );

//----------------------------------------------------------------------------
// [Function Name]  ssdic_StartMonitor (Monitoring measurement start function)
//
// [Summary]  		Start the monitor measurement.
//
// [Parameters]  	[i] hDevice		: Handle to the device identification to start the measurement.
//			 		[i] pMonInfo	: Monitoring will provide information for measuring parameters.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_StartMonitor( HDEVIF hDevice, PSSDICCTRL_MON_INFO pMonInfo );

//----------------------------------------------------------------------------
// [Function Name]  ssdic_StopCaptureDataTransfer (Stop the data transfer in the camera)
//
// [Summary]  		Stop the transfer of measure data.
//
// [Parameters]  	[i] hDevice 	: Handle to the device identification to retrieve
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG _STDCALL ssdic_StopMeasureDataTransfer(HDEVIF hDevice);

//----------------------------------------------------------------------------
// [Function Name]  ssdic_AbortMeasure (Measurement data acquisition abort function)
//
// [Summary]  		Abort the acquisition of measurement data.
//
// [Parameters]  	[i] hDevice 	: Handle to the device identification to retrieve
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG _STDCALL ssdic_AbortMeasure(HDEVIF hDevice);

//----------------------------------------------------------------------------
// [Function Name]  ssdic_GetMeasureState (Measurement processing state acquire function)
//
// [Summary]  		Acquire the state of the measurement process.
//
// [Parameters]  	[i] hDevice		: Handle to the device identification to obtain.
//           		[o] plState		: Specifies the address to store the type of measurement that indicates the
//								  		processing state.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note] 			None
//
// [history] 		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetMeasureState(HDEVIF hDevice, LONG* plState);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetMeasureSize (Get the capture frame size)
//
// [Summary]  		The pixel size of the measurement data is acquired.
//
// [Parameters]  	[i] hDevice		: Handle to the device identification to start the measurement.
//			 		[o] plHorSize 	: the address of the variable that stores the current horizontal pixel size set is specified
//			 		[o] plVerSize 	: the address of the variable that stores the current vertical pixel size set is specified.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetMeasureSize(HDEVIF hDevice, LONG *plHorSize, LONG *plVerSize);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_SetIntegralCapacity (Integration capacity set function)
//
// [Summary]  		Settings indicate the type of integration capacity
//
// [Parameters]  	[i] hDevice		: Handle to identify the target device.
//			 		[i] lType 		: Settings indicate the type of integration capacity
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG _STDCALL ssdic_SetIntegralCapacity(HDEVIF hDevice, LONG lType);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetIntegralCapacity (Integration capacity get function)
//
// [Summary]  		Get the type of integration capacity.
//
// [Parameters]  	[i] hDevice		: Handle to identify the target device.
//			 		[o] plType  	: Specifies the address of a variable that indicates
//										the integration capacity to store.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG _STDCALL ssdic_GetIntegralCapacity(HDEVIF hDevice, LONG *plType);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_SetOverClock (Sensor over lock setting function)
//
// [Summary]  		Settings indicate the type of Over clock
//
// [Parameters]  	[i] hDevice		: Handle to identify the target device.
//			 		[i] lType 		: Settings indicate the Over clock
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG _STDCALL ssdic_SetOverClock(HDEVIF hDevice, LONG lType);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetOverClock (Sensor over clock getting function)
//
// [Summary]  		Get the type of iover clock.
//
// [Parameters]  	[i] hDevice		: Handle to identify the target device.
//			 		[o] plType  	: Specifies the address of a variable that indicates
//										the Over Clock to store.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG _STDCALL ssdic_GetOverClock(HDEVIF hDevice, LONG *plType);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_SetTGPulseWidth (Transfer Gate Pulse Width setting function)
//
// [Summary]  		Settings indicate the Pulse Width of Transfer Gate
//
// [Parameters]  	[i] hDevice		: Handle to identify the target device.
//			 		[i] lWidth 		: Settings indicate the Transfer Gate Pulse Width
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG _STDCALL ssdic_SetTGPulseWidth(HDEVIF hDevice, LONG lWidth);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetTGPulseWidth (Transfer Gate Pulse Width getting function)
//
// [Summary]  		Get the Pulse Width of Transfer Gate.
//
// [Parameters]  	[i] hDevice		: Handle to identify the target device.
//			 		[o] plWidth  	: Specifies the address of a variable that indicates
//										the Pulse Width to store.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG _STDCALL ssdic_GetTGPulseWidth(HDEVIF hDevice, LONG *plWidth);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_SetSensorOutputTAP (Set horizontal shift registor TAP for CCD)
//
// [Summary]  		Settings indicate the horizontal shift registor TAP for CCD
//
// [Parameters]  	[i] hDevice		: Handle to identify the target device.
//			 		[i] lOutputTap	: Output TAP.
//										0 -> TAP-A
//										1 -> TAP-B
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG _STDCALL ssdic_SetSensorOutputTAP(HDEVIF hDevice, LONG lOutputTap);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetSensorOutputTAP (Get horizontal shift registor TAP for CCD)
//
// [Summary]  		Get the horizontal shift registor TAP for CCD
//
// [Parameters]  	[i] hDevice		: Handle to identify the target device.
//			 		[o] plOutputTap	: Output TAP.
//										0 -> TAP-A
//										1 -> TAP-B
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG _STDCALL ssdic_GetSensorOutputTAP(HDEVIF hDevice, LONG* plOutputTap);

//----------------------------------------------------------------------------
// [Function Name]  ssdic_SetCorrectData
//
// [Summary]  		The correction data is set in the camera.
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//           		[i] nPixelCnt   : Number of pixels
//           		[i] pbCoefData  : Coefficient data
//           		[i] pbOffData   : Offset data
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetCorrectData( HDEVIF hDevice, int nPixelCnt, WORD *pnCoefficient, WORD *pnOffset );

//----------------------------------------------------------------------------
// [Function Name]  ssdic_SetCorrectSwitch (Setting of camera correction function)
//
// [Summary]  		ON/OFF of the correction function in the camera is set.
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//           		[i] bSwitch     : ON/OFF of the correction function is specified.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetCorrectSwitch(HDEVIF hDevice, BOOL bSwitch);

//----------------------------------------------------------------------------
// [Function Name]  ssdic_GetCorrectSwitch (Camera correction get function)
//
// [Summary]  		The setting of the correction function with the camera is acquired.
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//           		[o] pbSwitch    : The address of the variable that stores the correction
// 										function setting value is specified.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note] 			None
//
// [history] 	 	[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetCorrectSwitch(HDEVIF hDevice, BOOL *pbSwitch);

//----------------------------------------------------------------------------
// [Function Name]  ssdic_SetDefectPixCalibSwitch
//
// [Summary]  		ON/OFF of defect pixel correction function is set.
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//           		[i] bSwitch     : Correction function switch
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note]			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetDefectPixCalibSwitch(HDEVIF hDevice, BOOL bSwitch);

//----------------------------------------------------------------------------
// [Function Name]  ssdic_GetDefectPixCalibSwitch
//
// [Summary]  		Get defect pixel correction function of switch (ON/OFF)
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//           		[o] pbSwitch    : Correction function switch
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetDefectPixCalibSwitch(HDEVIF hDevice, BOOL *pbSwitch);

//----------------------------------------------------------------------------
// [Function Name]  ssdic_SetDefectPixCalibData
//
// [Summary]  		The defective pixel calibration data is set in the camera.
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//           		[i] nPixelCnt   : Number of pixels
//           		[i] pbCalibData : Calibration data
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetDefectPixCalibData( HDEVIF hDevice, LONG lSize, LONG* plPixelIndex );

//----------------------------------------------------------------------------
// [Function Name]  ssdic_GetDefectPixCalibData
//
// [Summary]  		Get the defective pixel calibration data.
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//           		[o] pnPixelCnt  : Specifies the address of a variable that indicates
//										the defective pixel count to store.
//           		[0] pbCalibData : Specifies the address of a variable that indicates
//										the defective pixel data to store.
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetDefectPixCalibData( HDEVIF hDevice, LONG& lSize, LONG* plPixelIndex );

//----------------------------------------------------------------------------
// [Function Name]  ssdic_ClearDefectPixCalibData
//
// [Summary]  		Clear the defective pixel calibration data in the camera.
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_ClearDefectPixCalibData( HDEVIF hDevice );

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetSensorTemp (Sensor temperature get function)
//
// [Summary]  		Get the sensor temperature.
//
// [Parameters]  	[i] hDevice		: Handle to identify the target device.
//			 		[i] lChannel	: Specify the channel number to get sensor temp.
//			 		[o] pdblTemp	: Specifies the address of a variable to hold the temperature inside the sensor.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG _STDCALL ssdic_GetSensorTemp(HDEVIF hDevice, LONG lChannel, DOUBLE *pdblTemp);

//----------------------------------------------------------------------------
// [Function Name]  ssdic_SetCoolingControl
//
// [Summary]  		Sets the cooling contril.
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//					[i] bOnOff		: Specify the cooling control from among the
//									  following modes.
//
//										SSDIC_COOLING_STOP				(0)		// Stop cooling.
//										SSDIC_COOLING_FAN				(1)		// FAN start.
//										SSDIC_COOLING_COOL				(2)		// Cooling start
//										SSDIC_COOLING_FANCOOL			(3)		// FAN and Stop cooling.
//										SSDIC_COOLING_AUTO				(4)		// Stop cooling.
//										SSDIC_COOLING_ABORT				(5)		// Stop cooling.
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetCoolingControl (HDEVIF hDevice, LONG lMode);

//----------------------------------------------------------------------------
// [Function Name]  ssdic_GetCoolingControl
//
// [Summary]  		Retrieve the cooling control.
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//					[o] lpOnOff		: Specify the address of the variable where
//									  the currently set the cooling control is
//									  to be stored.
//									  SSDIC_COOLING_CONTROL_OFF : Cooling OFF
//									  SSDIC_COOLING_CONTROL_ON : Cooling ON
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetCoolingControl (HDEVIF hDevice, LONG *plMode);


//----------------------------------------------------------------------------
// [Function Name]  ssdic_LoadCoolingTemperature
//
// [Summary]  		Load the cooling temperature from ROM.
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_LoadCoolingTemperature (HDEVIF hDevice);

//----------------------------------------------------------------------------
// [Function Name]  ssdic_SaveCoolingTemperature
//
// [Summary]  		Save the cooling temperature to Rom in camera.
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SaveCoolingTemperature (HDEVIF hDevice);

//----------------------------------------------------------------------------
// [Function Name]  ssdic_GetCoolingTemperature
//
// [Summary]  		Retrieve the preset cooling temperature.
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//					[o] pValue		: Specify the address of the variable where
//									  the cooling temperature is to be stored.
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetCoolingTemperature (HDEVIF hDevice, INT *pValue );

//----------------------------------------------------------------------------
// [Function Name]  ssdic_GetFanStatus
//
// [Summary]  		Retrieve the status of FAN.
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//					[o] plStatus	: Specify the status of FAN.
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetFanStatus(HDEVIF hDevice, LONG *plStatus);

//----------------------------------------------------------------------------
// [Function Name]  ssdic_SetCoolingTemperature
//
// [Summary]  		Sets the cooling temperature.
//
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetCoolingTemperature (HDEVIF hDevice, INT nValue );

//----------------------------------------------------------------------------
// [Function Name]  ssdic_GetCoolingTemperatureCurrent
//
// [Summary]  		Retrieve the current temperature.
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//					[i] pValue		: Specify the address of the variable where
//									  the current temperature is to be stored.
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetCoolingTemperatureCurrent (HDEVIF hDevice, INT *pValue );

//----------------------------------------------------------------------------
// [Function Name]  ssdic_GetCoolingTemperatureCurrent
//
// [Summary]  		Retrieve the cooling status.
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//					[i] pValue		: Specify the address of the variable where
//									  the cooling status is to be stored.
//								SSDIC_COOLING_STATUS_NORMAL :Temperature is tolerance level.
//								SSDIC_COOLING_STATUS_LOWER  :Temperature is lower than tolerance level.
//								SSDIC_COOLING_STATUS_HIGHER :Temperature is higher than tolerance level.
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetCoolingStatus (HDEVIF hDevice, INT *pValue );


//----------------------------------------------------------------------------
// [Function Name]  ssdic_SetCurrentImageSizeToCameraLink
//
// [Summary]  		Set the current image pixel size to cameralink.
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note] 			This functio is for binning camera.
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG _STDCALL ssdic_SetCurrentImageSizeToCameraLink(HDEVIF hDevice);



//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetTempState
//
// [Summary]  		Retrieve the current temperature information.
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//					[o] pdblTemp1	: Specify the address of the variable where 
//										the sensor temperature to be store.
//					[o] pdblTemp2	: Specify the address of the variable where 
//										the temperature of thermistor1 to be store.
//					[o] pdblTemp3	: Specify the address of the variable where 
//										the temperature of thermistor2 to be store.
//					[o] plState		: Specify the address of the variable where
//									  the cooling status is to be stored.
//										1 : Temperature is tolerance level.
//										2 : Temperature is lower than tolerance level.
//										3 : Temperature is higher than tolerance level.
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note]
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetTempState(HDEVIF hDevice, DOUBLE *pdblTemp1, 
									DOUBLE *pdblTemp2, DOUBLE *pdblTemp3, LONG *plState);

//----------------------------------------------------------------------------
// [Function Name]  ssdic_ClrTargetAddressList
//
// [Summary]  		Clear ip-address table
//
// [Parameters]  	[i] 
//
// [Return value]   error code
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG	_STDCALL ssdic_ClrTargetAddressList();

//----------------------------------------------------------------------------
// [Function Name]  ssdic_AddTargetAddress
//
// [Summary]  		Add new address to address list.
//
// [Parameters]  	[i] byIPAddress : IP address for connecte
//					[i] wCmdPort	: command pooer number for delete
//					[i] wDataPort	: command command number for delete
//
// [Return value]   error code
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG	_STDCALL ssdic_AddTargetAddress(BYTE* pbyIPAddress, WORD wCmdPort);

//----------------------------------------------------------------------------
// [Function Name]  ssdic_DelTargetAddress
//
// [Summary]  		Remove target from address list.
//
// [Parameters]  	[i] byIPAddress : IP address for delete
//					[i] wCmdPort	: command pooer number for delete
//					[i] wDataPort	: command command number for delete
//
// [Return value]   error code
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG	_STDCALL ssdic_DelTargetAddress(BYTE* pbyIPAddress, WORD wCmdPort);

//----------------------------------------------------------------------------
// [Function Name]  ssdic_GetIPAddress
//
// [Summary]  		Get IP-Address and others.
//
// [Parameters]  	[i] hDevice		: device handle
//					[o] pbyIPAddress: IP-Address is store
//					[o] pbySubnet   : subnet masks is store
//					[o] pbyGateway  : default gateway is store
//					[o] pwCmdPort   : command port number is store
//
// [Return value]   error code
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG _STDCALL ssdic_GetIPAddress(HDEVIF hDevice, BYTE* pbyIPAddress, BYTE* pbySubnet, BYTE* pbyGateway, WORD* pwCmdPort);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_SetIPAddress
//
// [Summary]  		Set IP-Address and others.
//
// [Parameters]  	[i] hDevice		: device handle
//					[i] pbyIPAddress: IP-Address for set
//					[i] pbySubnet   : subnet masks for set
//					[i] pbyGateway  : default gateway for set
//					[i] wCmdPort    : command port number for set
//
// [Return value]   error code
//
// [Note] 			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG _STDCALL ssdic_SetIPAddress(HDEVIF hDevice, BYTE* pbyIPAddress, BYTE* pbySubnet, BYTE* pbyGateway, WORD wCmdPort);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetMACAddress
//
// [Summary]  		Get MAC-Address and others.
//
// [Parameters]  	[i] hDevice		 : device handle
//					[o] pbyMACAddress: MAC-Address is store
//
// [Return value]   error code
//
// [Note] 			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG _STDCALL ssdic_GetMACAddress(HDEVIF hDevice, BYTE* pbyMACAddress);

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_GetConnectIF (Device connect information acquisition function)
//
// [Summary]  		Get cominucationo interface with device.
//
// [Parameters]  	[i] hDevice	: The acquired device identification handle is specified.
//			 		[o] pnInfo	: The address of the variable that stores the device connection information of the device is specified.
//
// [Return value] 	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			When the number of connected devices changes, execute it without fail.
//					The connection closed device is not counted.
//
// [history] 		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetConnectIF(HDEVIF hDevice, INT* pnIFType );

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_SetPortType 
//
// [Summary]  		Set selected port count
//
// [Parameters]  	[i] hDevice		: Handle to identify the target device.
//			 		[i] lPortNum	: select port count
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG _STDCALL ssdic_SetPortNumber(HDEVIF hDevice, LONG lPortNum);

//-----------------------------------------------------------------------------
// [Function Name]  ssdic_GetPortType
//
// [Summary]  		Get current port number.
//
// [Parameters]  	[i] hDevice		: Handle to identify the target device.
//			 		[o] plPortNum	: current port count.
//
// [Return value]   If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]  			None
//
// [history]  		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG _STDCALL ssdic_GetPortNumber(HDEVIF hDevice, LONG* plPortNum);

//	{{{	HI_20140806	SpecifyDeviceを利用可能に変更
//-----------------------------------------------------------------------------
// [Function Name]	ssdic_GetDeviceSymbol (Device Symbol acquisition function)
//
// [Summary]  		Device information and essential information of the library are acquired.
//
// [Parameters]  	[i] lIndex    :	The index number of the acquired device is specified.
//                  [i] nDemandIF :
//			 		[o] pszInfo   :	The address in the buffer where acquired information is stored is specified.
//			 		[i] lSize     :	Buffer size is set.
//
// [Return value] 	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			When the number of connected devices changes, execute it without fail.
//					The connection closed device is not counted.
//
// [history] 		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetDeviceSymbol( LONG lIndex, INT nDemandIF, CHAR* pszInfo, LONG lSize );

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_GetDeviceModel (Device Model acquisition function)
//
// [Summary]  		Device information and essential information of the library are acquired.
//
// [Parameters]  	[i] pszSymbol :
//                  [i] nDemandIF :
//			 		[o] pszInfo   :	The address in the buffer where acquired information is stored is specified.
//			 		[i] lSize     :	Buffer size is set.
//
// [Return value] 	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			When the number of connected devices changes, execute it without fail.
//					The connection closed device is not counted.
//
// [history] 		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetDeviceModel( LONG lIndex, INT nDemandIF, CHAR* pszInfo, LONG lSize );

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_GetDeviceSerialNum (Device Serial Number acquisition function)
//
// [Summary]  		Device information and essential information of the library are acquired.
//
// [Parameters]  	[i] pszSymbol :
//                  [i] nDemandIF :
//			 		[o] pszInfo   :	The address in the buffer where acquired information is stored is specified.
//			 		[i] lSize     :	Buffer size is set.
//
// [Return value] 	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			When the number of connected devices changes, execute it without fail.
//					The connection closed device is not counted.
//
// [history] 		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetDeviceSerialNum( LONG lIndex, INT nDemandIF, CHAR* pszInfo, LONG lSize );

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_CreateEffectDeviceList
//
// [Summary]  		
//
// [Parameters]  	[i] nDemandIF :
//                  [i] nType     :
//
// [Return value] 	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			When the number of connected devices changes, execute it without fail.
//					The connection closed device is not counted.
//
// [history] 		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_CreateEffectDeviceList( INT nDemandIF, LONG* nType );

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_DeleteEffectDeviceList
//
// [Summary]  		
//
// [Parameters]  	[i] nDemandIF :
//
// [Return value] 	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			When the number of connected devices changes, execute it without fail.
//					The connection closed device is not counted.
//
// [history] 		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_DeleteEffectDeviceList( INT nDemandIF );

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_ClrTargetDeviceList
//
// [Summary]  		
//
// [Parameters]  	
//
// [Return value] 	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			When the number of connected devices changes, execute it without fail.
//					The connection closed device is not counted.
//
// [history] 		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_ClrTargetDeviceList();

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_SetTargetDevice
//
// [Summary]  		
//
// [Parameters]  	[i] szSymbol   :
//                  [i] nSize      :
//
// [Return value] 	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			When the number of connected devices changes, execute it without fail.
//					The connection closed device is not counted.
//
// [history] 		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetTargetDevice( LPSTR szSymbol, INT nSize);
//	}}}	HI_20140806	SpecifyDeviceを利用可能に変更

//	{{{	HI_20140828	CLのデバイス情報を取得
//-----------------------------------------------------------------------------
// [Function Name]	ssdic_SetTargetDeviceCL
//
// [Summary]  		
//
// [Parameters]  	[i] szSymbol   :
//
// [Return value] 	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			When the number of connected devices changes, execute it without fail.
//					The connection closed device is not counted.
//
// [history] 		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetTargetDeviceCL( LPSTR szSymbol);

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_ClearTargetDeviceCL
//
// [Summary]  		
//
// [Parameters]  	
//
// [Return value] 	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			When the number of connected devices changes, execute it without fail.
//					The connection closed device is not counted.
//
// [history] 		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_ClearTargetDeviceCL();
//	}}}	HI_20140828	CLのデバイス情報を取得

//-----------------------------------------------------------------------------
//【関数名】 ssdic_CreateEffectCLDeviceList ： I/F指定デバイスリスト作成(CL)
//
//【内  容】 デバイスリストを作成して、デバイス数を返す。
//
//【引  数】 [i] nIdx       : 設定Index
//			 [o] plDevCount : デバイス数。
//
//【戻り値】 正常に終了した場合は 0、それ以外の場合は エラーコド を戻します。
//
//【備　考】 
//
//【履  歴】 [新規]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_CreateEffectCLDeviceList( INT nIdx, LONG* plDevCount );

//----------------------------------------------------------------------------
// [Function Name]  ssdic_ClrTargetAddressList
//
// [Summary]  		Clear ip-address table
//
// [Parameters]  	[i] 
//
// [Return value]   error code
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG	_STDCALL ssdic_ClrTargetAddressList();

//----------------------------------------------------------------------------
// [Function Name]  ssdic_AddTargetAddress
//
// [Summary]  		Add new address to address list.
//
// [Parameters]  	[i] byIPAddress : IP address for connecte
//					[i] wCmdPort	: command pooer number for delete
//					[i] wDataPort	: command command number for delete
//
// [Return value]   error code
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG	_STDCALL ssdic_AddTargetAddress(BYTE* pbyIPAddress, WORD wCmdPort);

//	{{{	HI_20140829	Pleora iPortを利用可能に変更
//----------------------------------------------------------------------------
// [Function Name]  ssdic_ClrTargetAddressUDPList
//
// [Summary]  		Clear ip-address table(Pleora)
//
// [Parameters]  	[i] 
//
// [Return value]   error code
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG	_STDCALL ssdic_ClrTargetAddressUDPList();

//----------------------------------------------------------------------------
// [Function Name]  ssdic_AddTargetAddressUDP
//
// [Summary]  		Add new address to address list.(Pleora)
//
// [Parameters]  	[i] byIPAddress : IP address for connecte
//
// [Return value]   error code
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT LONG	_STDCALL ssdic_AddTargetAddressUDP(BYTE* pbyIPAddress);
//	}}}	HI_20140829	Pleora iPortを利用可能に変更

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_SetTargetDeviceGen
//
// [Summary]  		
//
// [Parameters]  	[i] szSymbol   :
//                  [i] nSize      :
//
// [Return value] 	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			When the number of connected devices changes, execute it without fail.
//					The connection closed device is not counted.
//
// [history] 		[New]
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetTargetDeviceGen( LPSTR szSymbol, INT nSize);

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_CheckConnection (Disconnect function)
//
// [Summary]  		Confirm the connection is alive or not.
//
// [Parameters]		[i] hDevice	: handle of the device to be disconnected is specified.
//			 		[o] pbConnection 	: The address of the variable that stores the flag of connection alive.
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			None
//
// [history]  		[New] 2014.09.22
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetConnectStat(HDEVIF hDevice, BOOL* pbConnection);

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_SendRecv (Device connect information acquisition function)
//
// [Summary]  		Send and receive packetwith device.
//
// [Parameters]  	[i] hDevice	: The acquired device identification handle is specified.
//					[i] pszSendData : The address of the send packet string.
//					[i] lSendSize   : The size of send packet.
//					[i] pszRecvData : The address of the receive packet buffer.
//					[i] lSendSize   : The size of receive packet buffer.
//
// [Return value] 	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			When the number of connected devices changes, execute it without fail.
//					The connection closed device is not counted.
//
// [history] 		[New] 2014.9.22
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SendRecvCmd(HDEVIF hDevice, CHAR* pszSendData, LONG lSendSize, CHAR* pszRecvData, LONG lRecvSize);

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_CheckConnection (Disconnect function)
//
// [Summary]  		Confirm the connection is alive or not.
//
// [Parameters]		[i] hDevice	: handle of the device to be disconnected is specified.
//			 		[o] pbConnection 	: The address of the variable that stores the flag of connection alive.
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			None
//
// [history]  		[New] 2014.09.22
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetConnectState(HDEVIF hDevice);

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_SetMultiLineFlag
//
// [Summary]  		
//
// [Parameters]		[i] hDevice			: handle of the device to be disconnected is specified.
//			 		[o] bMultiLineFlag 	: 
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			None
//
// [history]  		[New] 2016.03.29
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetMultiLineFlag(HDEVIF hDevice, BOOL bMultiLineFlag);

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_SetUseMemory
//
// [Summary]  		
//
// [Parameters]		[i] hDevice			: handle of the device to be disconnected is specified.
//			 		[i] bUse		 	: use flag for device memory
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			None
//
// [history]  		[New] 2016.08.08
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetUseMemory(HDEVIF hDevice, BOOL bUse);

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_GetUseMemory
//
// [Summary]  		
//
// [Parameters]		[i] hDevice			: handle of the device to be disconnected is specified.
//			 		[o] pbUse		 	: use flag for device memory
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			None
//
// [history]  		[New] 2016.11.30
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetUseMemory(HDEVIF hDevice, BOOL* pbUse);

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_GetAreaExtraction
//
// [Summary]  		
//
// [Parameters]		[i] hDevice			: handle of the device to be disconnected is specified.
//					[o] pPixel			: Pixel increment
//					[o] pStartPixel		: Output start pixel number
//					[o] pEndPixel		: Output end pixel number
//					[o] pPixelNumber	: Number of output pixels
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			None
//
// [history]  		[New] 2019.11.05
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetAreaExtraction(HDEVIF hDevice, int* pPixel, int* pStartPixel, int* pEndPixel, int* pPixelNumber);

//-----------------------------------------------------------------------------
// [Function Name]	ssdic_SetAreaExtraction
//
// [Summary]  		
//
// [Parameters]		[i] hDevice			: handle of the device to be disconnected is specified.
//					[i] nPixel			: Pixel increment
//					[i] nStartPixel		: Output start pixel number
//					[i] nEndPixel		: Output end pixel number
//					[i] nPixelNumber	: Number of output pixels
//
// [Return value]  	If successful then SSDIC_ERR_NONE (0), otherwise an error.
//
// [Note]			None
//
// [history]  		[New] 2019.11.05
//-----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetAreaExtraction(HDEVIF hDevice, int nPixel, int nStartPixel, int nEndPixel, int nPixelNumber);

//----------------------------------------------------------------------------
// [Function Name]  ssdic_GetUserCorrectData
//
// [Summary]  		The correction data is get
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//           		[i] nPixelCnt   : Number of pixels
//           		[i] pbCoefData  : Coefficient data
//           		[i] pbOffData   : Offset data
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_GetUserCorrectData( HDEVIF hDevice, int nPixelCnt, WORD *pnCoefficient, WORD *pnOffset );

//----------------------------------------------------------------------------
// [Function Name]  ssdic_SetUserCorrectData
//
// [Summary]  		The correction data is set in the camera.
//
// [Parameters]  	[i] hDevice     : Handle to identify the target device.
//           		[i] nPixelCnt   : Number of pixels
//           		[i] pbCoefData  : Coefficient data
//           		[i] pbOffData   : Offset data
//
// [Return value]   It is the latest error code. Please see the error
//
// [Note] 			None
//
// [history]  		[New]
//----------------------------------------------------------------------------
_SSDICCTRL_EXPORT  LONG _STDCALL ssdic_SetUserCorrectData( HDEVIF hDevice, int nPixelCnt, WORD *pnCoefficient, WORD *pnOffset );

//#ifdef	__cplusplus
//};
//#endif

#endif//SSDIC_H__INCLUDED_
