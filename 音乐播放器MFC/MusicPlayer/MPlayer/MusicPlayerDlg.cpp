
// MPlayerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MusicPlayer.h"
#include "MusicPlayerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMPlayerDlg �Ի���



CMPlayerDlg::CMPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMPlayerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(MAKEINTRESOURCE(IDI_ICON));
	hour=0;
	minute=0;
	second=0;
	cs=0;
	ch=0;
	cm=0;
	mode=SINGLE;
}

void CMPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, list);
	DDX_Control(pDX, IDC_SLIDER_VOL, vol);
	DDX_Control(pDX, IDC_SLIDER_TIME, process);
}

BEGIN_MESSAGE_MAP(CMPlayerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()
	ON_LBN_SELCHANGE(IDC_LIST, &CMPlayerDlg::OnLbnSelchangeList)
	ON_BN_CLICKED(IDC_PLAY, &CMPlayerDlg::OnBnClickedPlay)
	ON_BN_CLICKED(IDC_ADD, &CMPlayerDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_PAUSE, &CMPlayerDlg::OnBnClickedPause)
	ON_BN_CLICKED(IDC_STOP, &CMPlayerDlg::OnBnClickedStop)
	ON_BN_CLICKED(IDC_DELETE, &CMPlayerDlg::OnBnClickedDelete)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_VOL, &CMPlayerDlg::OnCustomdrawSliderVol)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_TIME, &CMPlayerDlg::OnCustomdrawSliderTime)
	ON_WM_TIMER()
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_TIME, &CMPlayerDlg::OnReleasedcaptureSliderTime)
	ON_BN_CLICKED(IDC_BTN_NEXT, &CMPlayerDlg::OnBnClickedBtnNext)
	ON_BN_CLICKED(IDC_BTN_BACK, &CMPlayerDlg::OnBnClickedBtnBack)
	ON_LBN_DBLCLK(IDC_LIST, &CMPlayerDlg::OnDblclkList)
	ON_BN_CLICKED(IDC_BTN_MODE, &CMPlayerDlg::OnBnClickedBtnMode)
END_MESSAGE_MAP()


// CMPlayerDlg ��Ϣ�������

BOOL CMPlayerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	process.SetRange(0,100);
	vol.SetRange(0,1000);
	vol.SetPos(vol.GetRangeMax());
	CString temp;
	temp.Format("���ֲ���ʱ��: %d:%d:%d / %d:%d:%d",ch,cm,cs,hour,minute,second);
	SetDlgItemText(IDC_STATIC_TIME,temp);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMPlayerDlg::OnPaint()
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
HCURSOR CMPlayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL CMPlayerDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CBitmap bitmap;
	bitmap.LoadBitmapA(MAKEINTRESOURCE(IDB_BG));
	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);
	dcCompatible.SelectObject(&bitmap);
	CRect rc;
	GetClientRect(&rc);
	BITMAP bmp;
	bitmap.GetBitmap(&bmp);
	pDC->StretchBlt(0,0,rc.Width(),rc.Height(),&dcCompatible,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
	return TRUE;
}


void CMPlayerDlg::OnLbnSelchangeList()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMPlayerDlg::OnBnClickedPlay()
{
	
	CString temp;
	GetDlgItemText(IDC_PAUSE,temp);
	if(temp.Compare("��������")==0)
	{
		SetDlgItemText(IDC_PAUSE,"��ͣ");
    }
	CString filename;
	int index=list.GetCurSel();
	if(index==-1)
	{
		MessageBox("��Ǹ����ǰû������ѡ�У�����ӻ�ѡ��");
		return;
	}
	
	list.GetText(index,filename);
	SetDlgItemText(IDC_FILENAME,filename);
	player.Stop();
	player.Open(m_hWnd,filename);
	player.Play();
	KillTimer(0);
	SetTimer(0,1000,NULL);
	hour=minute=second=ch=cm=cs=0;
	temp.Format("���ֲ���ʱ��: %d:%d:%d / %d:%d:%d",ch,cm,cs,hour,minute,second);
	SetDlgItemText(IDC_STATIC_TIME,temp);
	process.SetPos(0);

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMPlayerDlg::OnBnClickedAdd()
{
	char fliter[]="�����ļ�(*.mp3;*.wma;*.wav)\0*.mp3;*.wma;*.wav\0"
		"�����ļ�(*.*)\0*.*\0\0";
	CFileDialog fdlg(TRUE);
	fdlg.m_ofn.lpstrFilter=fliter;
	if(IDOK==fdlg.DoModal())
	{
		CString path=fdlg.GetPathName();
		CString file=fdlg.GetFileName();
		list.InsertString(list.GetCount(),path);
		list.SetCurSel(list.GetCount()-1);
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMPlayerDlg::OnBnClickedPause()
{
	CString temp;
	GetDlgItemText(IDC_PAUSE,temp);
	if(temp.Compare("��ͣ")==0)
	{
		player.Pause();
		SetDlgItemText(IDC_PAUSE,"��������");
		KillTimer(0);
    }
	else if(temp.Compare("��������")==0)
	{
		player.resume();
		SetDlgItemText(IDC_PAUSE,"��ͣ");
		SetTimer(0,1000,NULL);
    }
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMPlayerDlg::OnBnClickedStop()
{
	KillTimer(0);
	CString temp;
	GetDlgItemText(IDC_PAUSE,temp);
	if(temp.Compare("��������")==0)
	{
		SetDlgItemText(IDC_PAUSE,"��ͣ");
    }
	player.Stop();
	hour=0;
	minute=0;
	second=0;
	ch=0;
	cm=0;
	cs=0;
	temp.Format("���ֲ���ʱ��: %d:%d:%d / %d:%d:%d",ch,cm,cs,hour,minute,second);
	SetDlgItemText(IDC_STATIC_TIME,temp);
	process.SetPos(0);
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}




void CMPlayerDlg::OnBnClickedDelete()
{
	list.DeleteString(list.GetCurSel());
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMPlayerDlg::OnCustomdrawSliderVol(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	volume=vol.GetPos();
	player.SetVolume(volume);
	CString Vtemp;
	Vtemp.Format("������С: %d%%",volume/10);
	SetDlgItemText(IDC_STATIC_VOL,Vtemp);
	*pResult = 0;
}


void CMPlayerDlg::OnCustomdrawSliderTime(NMHDR *pNMHDR, LRESULT *pResult)
{
	
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CMPlayerDlg::OnTimer(UINT_PTR nIDEvent)
{
	CString temp;
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nIDEvent==0)
	{
		int index;
		totaltime=player.info(MCI_STATUS_LENGTH);
		currenttime=player.info(MCI_STATUS_POSITION);
		if(currenttime>=totaltime)
		{
			switch(mode)
			{
			case SINGLE:
				player.SeekTo(0);
				OnBnClickedStop();
				break;
			case R_SINGLE:
				player.SeekTo(0);
				OnBnClickedPlay();
				break;
			case ALL:
				index=list.GetCurSel();
				if(index<list.GetCount()-1)
				{
					OnBnClickedBtnNext();
				}
				else
				{
					player.SeekTo(0);
					OnBnClickedStop();
				}
				break;
			case R_ALL:
				index=list.GetCurSel();
				if(index<list.GetCount()-1)
				{
					OnBnClickedBtnNext();
				}
				else
				{
					list.SetCurSel(0);
					OnBnClickedPlay();
				}
				break;
			}
			return;
		}

	    totaltime=totaltime/1000;
	    hour=totaltime/3600;
	    minute=(totaltime/60)%60;
    	second=totaltime%60;

		currenttime=currenttime/1000;
		process.SetPos((currenttime*100)/totaltime);
		ch=currenttime/3600;
		cm=(currenttime/60)%60;
		cs=currenttime%60;
		
		temp.Format("���ֲ���ʱ��: %d:%d:%d / %d:%d:%d",ch,cm,cs,hour,minute,second);
		SetDlgItemText(IDC_STATIC_TIME,temp);
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CMPlayerDlg::OnReleasedcaptureSliderTime(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetTimer(0,1000,NULL);
	CString temp;
	GetDlgItemText(IDC_PAUSE,temp);
	DWORD time=player.info(MCI_STATUS_LENGTH);
	DWORD currenttime;
	currenttime=time*(process.GetPos())/100;
	player.SeekTo(currenttime);
	player.Play();
	if(temp.Compare("��������")==0)
	{
		SetDlgItemText(IDC_PAUSE,"��ͣ");
    }
	*pResult = 0;
}


void CMPlayerDlg::OnBnClickedBtnNext()
{	
	CString filename;
	CString temp;
	int index;
	index=list.GetCurSel();
	index+=1;
	if(index==list.GetCount())
	{
		MessageBox("�������һ����");
		return;
	}
	list.SetCurSel(index);
	OnBnClickedPlay();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMPlayerDlg::OnBnClickedBtnBack()
{
	int index;
	index=list.GetCurSel();
	index-=1;
	if(index<0)
	{
		MessageBox("û��������");
		return;
	}
	list.SetCurSel(index);
	OnBnClickedPlay();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMPlayerDlg::OnDblclkList()
{
	OnBnClickedPlay();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMPlayerDlg::OnBnClickedBtnMode()
{
	switch(mode)
	{
	case SINGLE:
		mode=R_SINGLE;
		SetDlgItemText(IDC_BTN_MODE,"����ģʽ������ѭ��");
		break;
	case R_SINGLE:
		mode=ALL;
		SetDlgItemText(IDC_BTN_MODE,"����ģʽ��ȫ������");
		break;
	case ALL:
		mode=R_ALL;
		SetDlgItemText(IDC_BTN_MODE,"����ģʽ��ȫ��ѭ��");
		break;
	case R_ALL:
		mode=SINGLE;
		SetDlgItemText(IDC_BTN_MODE,"����ģʽ����������");
		break;
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
