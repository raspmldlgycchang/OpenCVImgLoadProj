
// OpenCVImgLoadDlg.h: 헤더 파일
//

#pragma once


// COpenCVImgLoadDlg 대화 상자
#include "GY_MemDC.h"

class COpenCVImgLoadDlg : public CDialogEx
{
private:
	int m_top_margin, m_cx_margin, m_cy_margin;
	CRect m_cur_hist_rect; // 현재 대화상자 크기
	CString m_file_path;
	CImage m_image;
	GY_MemDC m_gy_memDC;
public:
	COpenCVImgLoadDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPENCVIMGLOAD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void Test();
	void ShowImage(CDC *pDC, int a_fixed_pos_x=0, int a_fixed_pos_y=0, int a_use_fixed_pos = 0);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
};
