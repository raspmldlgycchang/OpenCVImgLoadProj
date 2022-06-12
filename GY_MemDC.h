#pragma once


// GY_MemDC

class GY_MemDC : public CWnd
{
	DECLARE_DYNAMIC(GY_MemDC)
private:
	CDC m_memDC;
	CBitmap m_memBitmap;
	CBitmap* p_old_bitmap;
	int m_width, m_height;
	CString m_bmpFilePath;
	BITMAP m_bmp_info;
	HBITMAP mh_imgBmp, mh_oldBmp;
	CImage dest_image;

public:
	GY_MemDC();
	virtual ~GY_MemDC();
	void Create(CWnd*ap_wnd, int a_width, int a_height);
	void SetBitmap(CImage* ap_image, CString a_file_path);

protected:
	DECLARE_MESSAGE_MAP()
};


