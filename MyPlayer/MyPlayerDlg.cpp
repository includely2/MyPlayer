
// MyPlayerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyPlayer.h"
#include "MyPlayerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMyPlayerDlg 对话框



CMyPlayerDlg::CMyPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MYPLAYER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CIRCLE, m_circle);
	DDX_Control(pDX, IDC_OPEN, m_open);
	DDX_Control(pDX, IDC_PAUSE, m_pause);
	DDX_Control(pDX, IDC_PLAY, m_play);
	DDX_Control(pDX, IDC_FILENAME, m_filename);
	DDX_Control(pDX, IDC_MP3, m_mp3);
	DDX_Control(pDX, IDC_STOP, m_stop);
	DDX_Control(pDX, IDC_PROGRESS, m_progress);
	DDX_Control(pDX, IDC_VOICE, m_voice);
}

BEGIN_MESSAGE_MAP(CMyPlayerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MP3, &CMyPlayerDlg::OnBnClickedMp3)
	ON_BN_CLICKED(IDC_MAV, &CMyPlayerDlg::OnBnClickedMav)
	ON_BN_CLICKED(IDC_CIRCLE, &CMyPlayerDlg::OnBnClickedCircle)
	ON_BN_CLICKED(IDC_AVI, &CMyPlayerDlg::OnBnClickedAvi)
	ON_BN_CLICKED(IDC_OPEN, &CMyPlayerDlg::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_PLAY, &CMyPlayerDlg::OnBnClickedPlay)
	ON_BN_CLICKED(IDC_PAUSE, &CMyPlayerDlg::OnBnClickedPause)
	ON_BN_CLICKED(IDC_STOP, &CMyPlayerDlg::OnBnClickedStop)
	ON_WM_TIMER()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_VOICE, &CMyPlayerDlg::OnNMCustomdrawVoice)
END_MESSAGE_MAP()


// CMyPlayerDlg 消息处理程序

BOOL CMyPlayerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	this->m_play.EnableWindow(FALSE);
	this->m_pause.EnableWindow(FALSE);
	this->m_circle.EnableWindow(FALSE);
	this->m_stop.EnableWindow(FALSE);
	this->m_mp3.SetCheck(TRUE);
	this->m_voice.EnableWindow(FALSE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMyPlayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMyPlayerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMyPlayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyPlayerDlg::OnBnClickedMp3()
{
	// TODO: 在此添加控件通知处理程序代码
	this->m_mediaType = 1;
}


void CMyPlayerDlg::OnBnClickedMav()
{
	// TODO: 在此添加控件通知处理程序代码
	this->m_mediaType = 2;
}


void CMyPlayerDlg::OnBnClickedAvi()
{
	// TODO: 在此添加控件通知处理程序代码
	this->m_mediaType = 3;
}


void CMyPlayerDlg::OnBnClickedCircle()
{
	// TODO: 在此添加控件通知处理程序代码
	mciSendCommand(
		m_wDeviceID,//需要的设备ID
		MCI_PLAY,//此命令播放设备
		MCI_DGV_PLAY_REPEAT,
		(DWORD)(LPVOID(&playParms)));//传递MCI_PLAY_PARMS参数
}



void CMyPlayerDlg::OnBnClickedOpen()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog flDlg(TRUE);
	if (flDlg.DoModal() == IDOK)
	{
		CString fileName = flDlg.GetPathName();
		m_filename.SetWindowTextW(fileName);
		LPCTSTR mediaType = _T("MPEGvideo");
		switch (this->m_mediaType)
		{
		case 1:
			break;
		case 2:
			mediaType = _T("waveaudio");
			break;
		case 3:
			mediaType = _T("avivideo");
			break;
		}

		this->m_open.EnableWindow(FALSE);
		this->m_pause.EnableWindow(TRUE);
		this->m_play.EnableWindow(TRUE);
		this->m_circle.EnableWindow(TRUE);
		this->m_stop.EnableWindow(TRUE);
		this->m_voice.EnableWindow(TRUE);
		LPCTSTR pwStr = (LPCTSTR)fileName;

		openParms.lpstrDeviceType = mediaType;//MP3的文件设备ID为MPEGvideo
		openParms.lpstrElementName = pwStr;//MP3文件的存放路径

		//发送命令
		mciSendCommand(
			NULL,//打开设备不需要设备ID
			MCI_OPEN,//MCI_OPEN,此命令表示打开设备
			MCI_OPEN_ELEMENT | MCI_OPEN_TYPE | MCI_WAIT,
			(DWORD)(LPVOID(&openParms)));//传递MCI_OPEN_PARMS参数

		playParms.dwFrom = 0;
		m_wDeviceID = openParms.wDeviceID;
		//播放设备
		mciSendCommand(
			m_wDeviceID,//需要的设备ID
			MCI_PLAY,//此命令播放设备
			MCI_FROM,//等待播放文件结束，然后返回
			(DWORD)(LPVOID(&playParms)));//传递MCI_PLAY_PARMS参数

		statusParms.dwItem = MCI_STATUS_LENGTH;
		mciSendCommand(m_wDeviceID, MCI_STATUS, MCI_WAIT | MCI_STATUS_ITEM, (DWORD)(LPVOID(&statusParms)));
		m_progress.SetRange32(0, statusParms.dwReturn);
		SetTimer(1, 1000, NULL);
			
		m_voice.SetRange(0, 1000);
		m_voice.SetPos(500);
	}
}


void CMyPlayerDlg::OnBnClickedPlay()
{
	// TODO: 在此添加控件通知处理程序代码
	//暂停后播放设备
	mciSendCommand(
		m_wDeviceID,//需要的设备ID
		MCI_RESUME,
		MCI_WAIT,
		(DWORD)(LPVOID(&playParms)));//传递MCI_PLAY_PARMS参数	
}


void CMyPlayerDlg::OnBnClickedPause()
{
	// TODO: 在此添加控件通知处理程序代码
	mciSendCommand(
		m_wDeviceID,//需要的设备ID
		MCI_PAUSE,//此命令播放设备
		MCI_WAIT,//等待播放文件结束，然后返回
		(DWORD)(LPVOID(&playParms)));//传递MCI_PLAY_PARMS参数
}


void CMyPlayerDlg::OnBnClickedStop()
{
	// TODO: 在此添加控件通知处理程序代码
	//关闭设备
	mciSendCommand(
		m_wDeviceID,
		MCI_CLOSE,
		NULL,
		NULL);
	m_filename.SetWindowTextW(NULL);
	this->m_open.EnableWindow(TRUE);
	this->m_play.EnableWindow(FALSE);
	this->m_pause.EnableWindow(FALSE);
	this->m_stop.EnableWindow(FALSE);
	this->m_circle.EnableWindow(FALSE);
	this->m_voice.EnableWindow(FALSE);
	this->m_voice.SetPos(0);
	KillTimer(1);
	m_progress.SetPos(0);
}


void CMyPlayerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	statusParms.dwItem = MCI_STATUS_POSITION;
	mciSendCommand(m_wDeviceID, MCI_STATUS, MCI_WAIT | MCI_STATUS_ITEM, (DWORD)(LPVOID(&statusParms)));
	m_progress.SetPos(statusParms.dwReturn);
	CDialogEx::OnTimer(nIDEvent);
}


void CMyPlayerDlg::OnNMCustomdrawVoice(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	
	volumeParms.dwItem = MCI_DGV_SETAUDIO_VOLUME;
	volumeParms.dwValue = m_voice.GetPos();
	mciSendCommand(m_wDeviceID,
		MCI_SETAUDIO,
		MCI_DGV_SETAUDIO_ITEM | MCI_DGV_SETAUDIO_VALUE,
		(DWORD)(LPVOID(&volumeParms)));
	
	*pResult = 0;
}
