
// MusicPlayerDlg.h : ͷ�ļ�
//

#pragma once

#include "mp3.h"
#include "afxwin.h"
#include "afxcmn.h"

#define SINGLE 1
#define R_SINGLE 2
#define ALL 3
#define R_ALL 4

// CMPlayerDlg �Ի���
class CMPlayerDlg : public CDialogEx
{
// ����
public:
	CMPlayerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MPLAYER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	int hour;
	int minute;
	int second;
	int ch;
	int cm;
	int cs;
	afx_msg void OnLbnSelchangeList();
	CListBox list;
	afx_msg void OnBnClickedPlay();
	afx_msg void OnBnClickedAdd();
	Mp3 player;
	afx_msg void OnBnClickedPause();
	afx_msg void OnBnClickedStop();
	afx_msg void OnBnClickedDelete();
	CSliderCtrl vol;
	afx_msg void OnCustomdrawSliderVol(NMHDR *pNMHDR, LRESULT *pResult);
	int volume;
	CSliderCtrl process;
	afx_msg void OnCustomdrawSliderTime(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int totaltime;
	afx_msg void OnReleasedcaptureSliderTime(NMHDR *pNMHDR, LRESULT *pResult);
	int currenttime;
	afx_msg void OnBnClickedBtnNext();
	afx_msg void OnBnClickedBtnBack();
	afx_msg void OnDblclkList();
	int mode;
	afx_msg void OnBnClickedBtnMode();
};
