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
	enum { IDD = IDD_PIECEDISABLE_DIALOG };
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
	int		m_nDisableBlock;
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnChangeEditDisableBlock();
	afx_msg void OnButtonBlockDisable();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
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

	short 	m_waDisCell[Def_MaxPiece1][Def_MaxPiece1][2];//[CellRow],[CellCol] : 화면에 표시할 cell의 x, y 정보
			// ex) nDisCell1[][][]      BlockCol 3, blockRow 2, pieceCol 2, pieceRow 3 인 경우	
			//             Col=1	Col=2	Col=3	Col=4	Col=5	Col=6
			// posRow=1	    1-1	     1-2	 2-1 	 2-2	 3-1	3-2
			// posRow=2	    1-3	     1-4	 2-3	 2-4	 3-3	3-4
			// posRow=3	    1-5	     1-6	 2-5	 2-6	 3-5	3-6
			// posRow=4	    4-1	     4-2	 5-1	 5-2	 6-1	6-2
			// posRow=5	    4-3	     4-4	 5-2	 5-3	 6-3	5-4
			// posRow=6	    4-5	     4-6	 5-4	 5-5	 6-5	6-6

	short 	m_waDisBlock[Def_MaxPiece1][Def_MaxPiece1] ;//[BlockRow][BlockCol]  SysInfo03.m_nData 읽어온 값
			// nDisBlock1[][] =	1	2	3	ex)	BlockCol 3, blockRow 2인 경우 
			// 					4	5	6
			 
	short 	m_waDisPiece[Def_MaxPiece1][Def_MaxPiece1] ;//[PieceRow][PieceCol] SysInfo25.m_nData 읽어온 값
			// nDisPiece1[][]=	1	2		ex)	PieceCol 2, pieceCol 3인 경우 
			// 					3	4
			// 					5	6



			// Drag시에 화면에서 회색표시할 부분,  m_waDisCell와 같은 구조 유지해야.
	short 	m_waDragData[301][Def_MaxPiece1]; // Drag Data : 0: Drag False,  1: Drag True
	bool	m_bDragMode;
	int		m_nStartCellRow;
	int		m_nStartCellCol;




	// 멤버 함수
	int 	InitMember();
	int 	InitView();
	int 	DisplayNo();
	void 	GraphDisplayBlock(int nCellNo); 	
	int 	FindCellForPoint(CPoint boxPt, int& rnCell);
	void 	CellToBlockPiece(int nCell, int& rnRow, int&rnCol, int& rnBlock, int& rnPiece);
	void 	RowColToCell(int nRow, int nCol, int& rnCell);
	void 	SetDrag(CPoint boxPt, int& rnRow, int& rnCol);
	void 	SetDrag2(int nCell);
	void 	ToggleDisable(CPoint boxPt);
	void 	SetDragAllToDisable();
	void 	SetDragAllToToggle();
	void 	SetDragAllToEnable();
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACE400PIECEDISABLEDLG_H__AD1FD072_55C6_4BC0_AAE3_FEE9DD48C267__INCLUDED_)
