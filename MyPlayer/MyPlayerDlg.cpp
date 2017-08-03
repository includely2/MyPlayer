
// MyPlayerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyPlayer.h"
#include "MyPlayerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMyPlayerDlg �Ի���



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


// CMyPlayerDlg ��Ϣ�������

BOOL CMyPlayerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	this->m_play.EnableWindow(FALSE);
	this->m_pause.EnableWindow(FALSE);
	this->m_circle.EnableWindow(FALSE);
	this->m_stop.EnableWindow(FALSE);
	this->m_mp3.SetCheck(TRUE);
	this->m_voice.EnableWindow(FALSE);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMyPlayerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMyPlayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyPlayerDlg::OnBnClickedMp3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->m_mediaType = 1;
}


void CMyPlayerDlg::OnBnClickedMav()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->m_mediaType = 2;
}


void CMyPlayerDlg::OnBnClickedAvi()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->m_mediaType = 3;
}


void CMyPlayerDlg::OnBnClickedCircle()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	mciSendCommand(
		m_wDeviceID,//��Ҫ���豸ID
		MCI_PLAY,//��������豸
		MCI_DGV_PLAY_REPEAT,
		(DWORD)(LPVOID(&playParms)));//����MCI_PLAY_PARMS����
}



void CMyPlayerDlg::OnBnClickedOpen()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

		openParms.lpstrDeviceType = mediaType;//MP3���ļ��豸IDΪMPEGvideo
		openParms.lpstrElementName = pwStr;//MP3�ļ��Ĵ��·��

		//��������
		mciSendCommand(
			NULL,//���豸����Ҫ�豸ID
			MCI_OPEN,//MCI_OPEN,�������ʾ���豸
			MCI_OPEN_ELEMENT | MCI_OPEN_TYPE | MCI_WAIT,
			(DWORD)(LPVOID(&openParms)));//����MCI_OPEN_PARMS����

		playParms.dwFrom = 0;
		m_wDeviceID = openParms.wDeviceID;
		//�����豸
		mciSendCommand(
			m_wDeviceID,//��Ҫ���豸ID
			MCI_PLAY,//��������豸
			MCI_FROM,//�ȴ������ļ�������Ȼ�󷵻�
			(DWORD)(LPVOID(&playParms)));//����MCI_PLAY_PARMS����

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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��ͣ�󲥷��豸
	mciSendCommand(
		m_wDeviceID,//��Ҫ���豸ID
		MCI_RESUME,
		MCI_WAIT,
		(DWORD)(LPVOID(&playParms)));//����MCI_PLAY_PARMS����	
}


void CMyPlayerDlg::OnBnClickedPause()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	mciSendCommand(
		m_wDeviceID,//��Ҫ���豸ID
		MCI_PAUSE,//��������豸
		MCI_WAIT,//�ȴ������ļ�������Ȼ�󷵻�
		(DWORD)(LPVOID(&playParms)));//����MCI_PLAY_PARMS����
}


void CMyPlayerDlg::OnBnClickedStop()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�ر��豸
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	statusParms.dwItem = MCI_STATUS_POSITION;
	mciSendCommand(m_wDeviceID, MCI_STATUS, MCI_WAIT | MCI_STATUS_ITEM, (DWORD)(LPVOID(&statusParms)));
	m_progress.SetPos(statusParms.dwReturn);
	CDialogEx::OnTimer(nIDEvent);
}


void CMyPlayerDlg::OnNMCustomdrawVoice(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	volumeParms.dwItem = MCI_DGV_SETAUDIO_VOLUME;
	volumeParms.dwValue = m_voice.GetPos();
	mciSendCommand(m_wDeviceID,
		MCI_SETAUDIO,
		MCI_DGV_SETAUDIO_ITEM | MCI_DGV_SETAUDIO_VALUE,
		(DWORD)(LPVOID(&volumeParms)));
	
	*pResult = 0;
}
