
// MyPlayerDlg.h : 头文件
//

#pragma once
#include "Mmsystem.h"
#include "windows.h"
#include "afxwin.h"
#include "Digitalv.h"
#include "afxcmn.h"
#pragma comment(lib, "winmm.lib")

// CMyPlayerDlg 对话框
class CMyPlayerDlg : public CDialogEx
{
// 构造
public:
	CMyPlayerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYPLAYER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_circle;
	CButton m_open;
	CButton m_pause;
	CButton m_play;
	int m_mediaType = 0;
	MCI_OPEN_PARMS openParms;//MCI_OPEN命令需要参数结构体
	MCI_PLAY_PARMS playParms;//MCI_PLAY命令需要的参数结构体
	MCI_STATUS_PARMS statusParms;//状态
	MCI_DGV_SETAUDIO_PARMS volumeParms;
	DWORD m_wDeviceID;
	CEdit m_filename;
	CButton m_mp3;
	CButton m_stop;
	afx_msg void OnBnClickedMp3();
	afx_msg void OnBnClickedMav();
	afx_msg void OnBnClickedCircle();
	afx_msg void OnBnClickedAvi();
	afx_msg void OnBnClickedOpen();
	afx_msg void OnBnClickedPlay();
	afx_msg void OnBnClickedPause();
	afx_msg void OnBnClickedStop();
	CProgressCtrl m_progress;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnNMCustomdrawVoice(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl m_voice;
};
