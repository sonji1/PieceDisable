// ACE400PieceDisableDlg.h : header file
//

#if !defined(AFX_ACE400PIECEDISABLEDLG_H__AD1FD072_55C6_4BC0_AAE3_FEE9DD48C267__INCLUDED_)
#define AFX_ACE400PIECEDISABLEDLG_H__AD1FD072_55C6_4BC0_AAE3_FEE9DD48C267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FileSysInfo.h"


//------------------
// Define & enum
//------------------

enum CELL_TYPE { 	CELL_ENABLE, 		// 0
					CELL_DISABLE  		// 1
};

/////////////////////////////////////////////////////////////////////////////
// CACE400PieceDisableDlg dialog

class CACE400PieceDisableDlg : public CDialog
{
// Construction
public:
	CACE400PieceDisableDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CACE400PieceDisableDlg)
	enum { IDD = IDD_ACE400PIECEDISABLE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CACE400PieceDisableDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CACE400PieceDisableDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()



public:

	// ¸â¹ö º¯¼ö 
	CRect 	m_Block[10001];

	short 	nBlockRes[5001];
	int 	nDisPMaxX, nDisPMaxY;
	int 	nBlockMaxX,nBlockMaxY, nBlockXGap, nBlockYGap, nBlockMax ;
	int 	nPieceMaxX,nPieceMaxY, nPieceXGap, nPieceYGap, nPieceMax ;
	int 	nCellMaxX,nCellMaxY, nCellXGap, nCellYGap, nCellMax;

	short 	nDisCell1[Def_MaxPiece1][Def_MaxPiece1][2];//Y,X, [BLOCK,PIECE]
	short 	nDisBlock1[Def_MaxPiece1][Def_MaxPiece1] ;//Y,X, => BLOCK
	short 	nDisPiece1[Def_MaxPiece1][Def_MaxPiece1] ;//Y,X, => BLOCK




	// ¸â¹ö ÇÔ¼ö
	int 	InitMember();
	int 	InitView();
	int 	DisplayNo();
	void 	GraphDisplayBlock(int nCellNo); 	
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACE400PIECEDISABLEDLG_H__AD1FD072_55C6_4BC0_AAE3_FEE9DD48C267__INCLUDED_)
