// GY_MemDC.cpp: 구현 파일
//

#include "pch.h"
#include "OpenCVImgLoad.h"
#include "GY_MemDC.h"


// GY_MemDC

IMPLEMENT_DYNAMIC(GY_MemDC, CWnd)

GY_MemDC::GY_MemDC()
{

}

GY_MemDC::~GY_MemDC()
{
}

void GY_MemDC::Create(CWnd * ap_wnd, int a_width, int a_height)
{
	if (m_width && m_height)
		m_memBitmap.DeleteObject();
	CClientDC dc(ap_wnd);
	m_width = a_width;
	m_height = a_height;
	m_memDC.CreateCompatibleDC(&dc);
	m_memBitmap.CreateCompatibleBitmap(&dc, m_width, m_height);
	p_old_bitmap = m_memDC.SelectObject(&m_memBitmap);


}

void GY_MemDC::SetBitmap(CImage * ap_image, CString a_file_path)
{
	if (NULL != mh_imgBmp) {
		::SelectObject(m_memDC.m_hDC, mh_oldBmp);
		::DeleteObject(mh_imgBmp);
	}
	if (!a_file_path.IsEmpty()) {
		mh_imgBmp = (HBITMAP)LoadImage(AfxGetInstanceHandle(), a_file_path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		HDC h_screen_dc = ::GetDC(NULL);
		HGDIOBJ h_screen_bitmap = ::GetCurrentObject(h_screen_dc, OBJ_BITMAP);
		BITMAP bmp_info;
		GetObject(h_screen_dc, sizeof(BITMAP), &bmp_info);
		if (mh_imgBmp != NULL) {
			GetObject(mh_imgBmp, sizeof(BITMAP), &m_bmp_info);
			mh_oldBmp = (HBITMAP)SelectObject(m_memDC.m_hDC, mh_imgBmp);
			GetObject(mh_imgBmp, sizeof(BITMAP), &bmp_info);
		}

		::ReleaseDC(NULL, h_screen_dc);
	}
	
	
	
}


BEGIN_MESSAGE_MAP(GY_MemDC, CWnd)
END_MESSAGE_MAP()



// GY_MemDC 메시지 처리기


