
// OpenCVImgLoadDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "OpenCVImgLoad.h"
#include "OpenCVImgLoadDlg.h"
#include "afxdialogex.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// COpenCVImgLoadDlg 대화 상자



COpenCVImgLoadDlg::COpenCVImgLoadDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OPENCVIMGLOAD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COpenCVImgLoadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COpenCVImgLoadDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()


// COpenCVImgLoadDlg 메시지 처리기

BOOL COpenCVImgLoadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	SetBackgroundColor(RGB(255, 255, 0));
	CRect win_rect, client_rect;
	GetWindowRect(win_rect);
	GetClientRect(client_rect);
	m_cx_margin = win_rect.Width() - client_rect.Width() + 4;
	m_cy_margin = win_rect.Height() - client_rect.Height() + 4;
	GetDlgItem(IDC_OPEN_BTN)->GetWindowRect(win_rect);
	ScreenToClient(win_rect);
	m_top_margin = win_rect.bottom;
	// SetWindowPos(NULL, 0,0,)
	// 테스트 코드
	// Test();
	CenterWindow();
	// 윈도우 창 크기 확인
	// GetWindowRect(m_cur_hist_rect);

	// m_file_path에 이미지가 없다면 default_path를 삽입
	CString default_path = L"Lenna.png";
	if (m_file_path.IsEmpty())	m_file_path = default_path;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void COpenCVImgLoadDlg::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	if (IsIconic())
	{

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		POINT fixed_pos = { 2,m_cy_margin + m_top_margin + 2 };
		ShowImage(&dc, 1, fixed_pos.x, fixed_pos.y);
		// CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR COpenCVImgLoadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void COpenCVImgLoadDlg::Test()
{
	Mat img = imread("Lenna.png");

	imshow("test", img);
	waitKey(0);
}

void COpenCVImgLoadDlg::ShowImage(CDC *pDC, int a_fixed_pos_x, int a_fixed_pos_y, int a_use_fixed_pos)
{
	m_image.Draw(*pDC, a_fixed_pos_x, a_fixed_pos_y);
}



void COpenCVImgLoadDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	lpMMI->ptMinTrackSize = CPoint(1280, 1024);
	lpMMI->ptMaxTrackSize = CPoint(1280, 1024);
	CDialogEx::OnGetMinMaxInfo(lpMMI);
}
