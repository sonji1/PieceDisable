
// FileSysInfo.h: interface for the CFileSysInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILESYSINFO_H__B85E18EA_5A5B_4129_A54C_D02D75AE6A24__INCLUDED_)
#define AFX_FILESYSINFO_H__B85E18EA_5A5B_4129_A54C_D02D75AE6A24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "stdafx.h"
#include <stdarg.h>


#define Def_MaxBlock1 	501
#define	Def_MaxPiece1	301


enum DATA_LOAD_SAVE_TYPE  { DATA_NO_SAVE_LOAD,	// �̻��
							DATA_SAVE, 			// 1
							DATA_LOAD 			// 2
};


enum UNIT  { sec=0, msec=1, usec=2, mA, uA, Mohm, Kohm, ohm, mohm, uohm };// sec=0, msec=1, usec=2 ����

class CFileSysInfo  
{

public:

	CFileSysInfo()
	{
	}

	int CFileSysInfo::LoadSaveView01(int type);
	int LoadSaveSub13(int type);				// for Block.ini <-> SysInfo03
	int LoadSaveSub25(int type);				// for Piece.ini <-> SysInfo25
	int LoadSaveSub19(int type, int nFileType);	// for BlockDis.ini <-> SysInfo19


//	virtual ~CFileSysInfo();
};



struct CSysInfoView01  //Path   FilePathJig
{ 

	char  m_pStrFileDri1[200]; //init sw load path
	char  m_pStrFilePath1[200]; //init sw load path
	char  m_pStrFilePathJig1[200]; //jig load
	char  m_pStrFilePathJig2[200]; // jig set
	char  m_pStrFilePathBDL[200]; //SYLEE121202
	char  m_pStrFileBDLName[200]; //SYLEE121202

};


struct CSysInfo03  //SETUP Block
{
	int m_nBlock;			// Block ���� : m_nRow * m_nCol
	int m_nRow;				// Block Row ����
	int m_nCol;				// Block Col ���� 
	int m_nData[Def_MaxBlock1][Def_MaxBlock1];	
							// Block No ��ġ data  [BlockRow][BlockCol]
							
	int m_nType;	 		// 1: A (X, Top Left)
							// 2: B (X, Top Right)
							// 3: C (X, Bottom Left)
							// 4: D (X, Bottom Right)
							// 5: E (Y, Top Left)
							// 6: F (Y, Top Right)
							// 7: G (Y, Bottom Left)
							// 8: H (Y, Bottom Right)
};


struct CSysInfo25  //SETUP piece
{
	int m_nBlock;			// Piece ���� : m_nRow * m_nCol
	int m_nRow;				// Piece Row ����
	int m_nCol;				// Piece Col ����
	int m_nData[Def_MaxPiece1][Def_MaxPiece1];	
							// Piece No ��ġ data  [PieceRow][PieceCol]
							
	int m_nType;	 		// 1: A (X, Top Left)
							// 2: B (X, Top Right)
							// 3: C (X, Bottom Left)
							// 4: D (X, Bottom Right)
							// 5: E (Y, Top Left)
							// 6: F (Y, Top Right)
							// 7: G (Y, Bottom Left)
							// 8: H (Y, Bottom Right)
	int m_nRowDel;
	int m_nColDel;
};


struct CSysInfo19  //SETUP Cell(Block-Piece)
{
	int m_nBlockTot;		// Block ���� 		
	int m_nPieceTot;		// Piece ���� 
	int m_nCellTotal;		// Block * Piece ���� 
	int m_nType;			// ������ 1
	int m_nUse;				// �� �κ��� 0�̸� m_nData�� ��� 0���� �ʱ�ȭ.
 	
	short m_nData[Def_MaxBlock1][Def_MaxPiece1]; 
							//[BlockCount][Piececount] // Disable Data : 0: Enable,  1: Disable

	int m_nCheck;//sylee131117
//	short m_nData1[200][200];
};



// �ܺ������� ���� ����
extern CFileSysInfo 	FileSysInfo01;		
extern CSysInfoView01	SysInfoView01;
extern CSysInfo03  		SysInfo03;
extern CSysInfo25  		SysInfo25;
extern CSysInfo19  		SysInfo19;


// Global �Լ�
extern	void		DoEvents(DWORD dwMilliseconds=0);
extern  void		Delay(UINT delaytime=0, UINT unit=usec);

#endif // !defined(AFX_FILESYSINFO_H__B85E18EA_5A5B_4129_A54C_D02D75AE6A24__INCLUDED_)
