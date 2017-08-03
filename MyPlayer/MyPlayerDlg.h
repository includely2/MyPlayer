
// MyPlayerDlg.h : ͷ�ļ�
//

#pragma once
#include "Mmsystem.h"
#include "windows.h"
#include "afxwin.h"
#include "Digitalv.h"
#include "afxcmn.h"
#pragma comment(lib, "winmm.lib")

// CMyPlayerDlg �Ի���
class CMyPlayerDlg : public CDialogEx
{
// ����
public:
	CMyPlayerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYPLAYER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
	MCI_OPEN_PARMS openParms;//MCI_OPEN������Ҫ�����ṹ��
	MCI_PLAY_PARMS playParms;//MCI_PLAY������Ҫ�Ĳ����ṹ��
	MCI_STATUS_PARMS statusParms;//״̬
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
