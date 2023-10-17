
// MfcImageDlg.h : header file
//

#pragma once


// CMfcImageDlg dialog
class CMfcImageDlg : public CDialogEx
{
private:
	CImage m_image;
	BOOL ValidImgPos(int x, int y);
	BOOL Dis2Point(CPoint point1, CPoint point2);
	// Construction
public:
	CMfcImageDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCIMAGE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnImage();
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedBtnLoad();
	void UpdateDisplay();
	void MoveRect();
	afx_msg void OnBnClickedBtnAction();
	void DrawCircle(unsigned char* fm, int x, int y, int nRadius, int nColor);
	void MoveCircle();
};
