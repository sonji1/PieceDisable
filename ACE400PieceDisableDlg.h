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
	int		m_nBlockCol;		// block의 열(col) 갯수 
	int		m_nBlockRow;		// block의 행(row) 갯수
	int		m_nBlockTot;		// block의 총 갯수

	int		m_nPieceCol;		// 1개 block의 sub piece 열(col) 수
	int		m_nPieceRow;		// 1개 block의 sub piece 행(row) 수
	int		m_nPieceTot;		// 1개 block의 sub piece 갯수

	int		m_nCellCol;			// 화면에 출력되는 cell(piece)의 열 수
	int		m_nCellRow;			// 화면에 출력되는 cell(piece)의 줄 수
	int		m_nCellTot;			// 화면에 출력되는 cell(piece)의 총 갯수 : m_nBlockTot * m_nPieceTot
	int		m_nCellDelCol;
	int		m_nCellDelRow;
	BOOL	m_bUsePieceDisable;	// Piece Disable 기능 자체 On/Off
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
	afx_msg void OnButtonFileLoad();
	afx_msg void OnButtonFileSave();
	afx_msg void OnButtonFileView();
	afx_msg void OnButtonEnableAll();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()



public:

	// 멤버 변수 
	CRect 	m_saRectCell[5001];

	//short 	nBlockRes[5001];
	//int 	nPieceXGap, nPieceYGap;
	//int 	nBlockXGap, nBlockYGap ;
	
	int 	m_nDisPMaxX, m_nDisPMaxY;
	int 	m_nCellXGap, m_nCellYGap;

	short 	m_waDisCell[Def_MaxPiece1][Def_MaxPiece1][2];//Y,X, [BLOCK,PIECE]
	short 	m_waDisBlock[Def_MaxPiece1][Def_MaxPiece1] ;//Y,X, => BLOCK
	short 	m_waDisPiece[Def_MaxPiece1][Def_MaxPiece1] ;//Y,X, => BLOCK




	// 멤버 함수
	int 	InitMember();
	int 	InitView();
	int 	DisplayNo();
	void 	GraphDisplayBlock(int nCellNo); 	
	void 	ToggleDisable(CPoint boxPt);
	void 	CellToBlockPiece(int nCell, int& rnRow, int&rnCol, int& rnBlock, int& rnPiece);
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACE400PIECEDISABLEDLG_H__AD1FD072_55C6_4BC0_AAE3_FEE9DD48C267__INCLUDED_)
