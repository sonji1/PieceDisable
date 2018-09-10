// ACE400PieceDisableDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ACE400PieceDisable.h"
#include "ACE400PieceDisableDlg.h"
#include "FileSysInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CACE400PieceDisableDlg dialog

CACE400PieceDisableDlg::CACE400PieceDisableDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CACE400PieceDisableDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CACE400PieceDisableDlg)
	m_nBlockCol = 0;
	m_nBlockRow = 0;
	m_nBlockTot = 0;
	m_nPieceCol = 0;
	m_nPieceRow = 0;
	m_nPieceTot = 0;
	m_nCellCol = 0;
	m_nCellRow = 0;
	m_nCellTot = 0;
	m_nCellDelCol = 0;
	m_nCellDelRow = 0;
	m_bUsePieceDisable = FALSE;
	m_nDisableBlock = 0;
	m_bDragMode = FALSE;
	m_nStartCellRow = -1;
	m_nStartCellCol = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CACE400PieceDisableDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CACE400PieceDisableDlg)
	DDX_Text(pDX, IDC_EDIT_BLOCK_COL, m_nBlockCol);
	DDX_Text(pDX, IDC_EDIT_BLOCK_ROW, m_nBlockRow);
	DDX_Text(pDX, IDC_EDIT_BLOCK_TOT, m_nBlockTot);
	DDX_Text(pDX, IDC_EDIT_PIECE_COL, m_nPieceCol);
	DDX_Text(pDX, IDC_EDIT_PIECE_ROW, m_nPieceRow);
	DDX_Text(pDX, IDC_EDIT_PIECE_TOT, m_nPieceTot);
	DDX_Text(pDX, IDC_EDIT_CELL_COL, m_nCellCol);
	DDX_Text(pDX, IDC_EDIT_CELL_ROW, m_nCellRow);
	DDX_Text(pDX, IDC_EDIT_CELL_TOT, m_nCellTot);
	DDX_Text(pDX, IDC_EDIT_CELL_DEL_COL, m_nCellDelCol);
	DDX_Text(pDX, IDC_EDIT_CELL_DEL_ROW, m_nCellDelRow);
	DDX_Check(pDX, IDC_CHECK1, m_bUsePieceDisable);
	DDX_Text(pDX, IDC_EDIT_DISABLE_BLOCK, m_nDisableBlock);
	DDV_MinMaxInt(pDX, m_nDisableBlock, 0, 301);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CACE400PieceDisableDlg, CDialog)
	//{{AFX_MSG_MAP(CACE400PieceDisableDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SHOWWINDOW()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_FILE_LOAD, OnButtonFileLoad)
	ON_BN_CLICKED(IDC_BUTTON_FILE_SAVE, OnButtonFileSave)
	ON_BN_CLICKED(IDC_BUTTON_FILE_VIEW, OnButtonFileView)
	ON_BN_CLICKED(IDC_BUTTON_ENABLE_ALL, OnButtonEnableAll)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_EN_CHANGE(IDC_EDIT_DISABLE_BLOCK, OnChangeEditDisableBlock)
	ON_BN_CLICKED(IDC_BUTTON_DISABLE, OnButtonBlockDisable)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CACE400PieceDisableDlg message handlers

BOOL CACE400PieceDisableDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	




	// TODO: Add extra initialization here
	
	// 1초 주기로 Graphic을 그리기 위한 Timer 설정
	SetTimer ( 	0,			// OnTimer 수행시 받을 Timer Id
				500,		// 500ms 즉, 0.5 sec 주기
				NULL);		// Timer 수신시 자동수행할 CallBack Function은 NULL로 설정.
				
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


 

void CACE400PieceDisableDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 0)
	{

		for(int cell = 1; cell <= m_nCellTot; cell++) //test  display
		{  
			GraphDisplayBlock(cell); //display-no1			 
		}
	
		// Drag 하는 도중에만 실시간으로 화면이 변경되도록 한다. 
		if (m_bDragMode != TRUE)
			KillTimer(0);		// 1회성으로 쓰기 위해  Timer 받고 해당 Timer Id를 반환한다.
								// 1회성으로 쓰지 않으면 화면이 500ms sec 주기로 계속 깜박이게 된다.
	}	
	
	CDialog::OnTimer(nIDEvent);
}



void CACE400PieceDisableDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CACE400PieceDisableDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CACE400PieceDisableDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


// 창이 새로 보일때 때마다 초기화해야 하는 멤버들은 다음의 OnShowWindow()의 TODO 밑에서 초기화한다. 
void CACE400PieceDisableDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here
	
	if(bShow == TRUE)
	{	
		if (InitMember() == FALSE)
			return ;
	
		if (InitView() == FALSE)
			return ;
	
	

	}
	
}

int CACE400PieceDisableDlg::InitMember() 
{

	return TRUE;
}

int CACE400PieceDisableDlg::InitView() 
{

	UpdateData(TRUE);


	int nLine1, nLine2;

	FileSysInfo01.LoadSaveView01(DATA_LOAD);		// Load	SysInfoView01.m_pStrFileBDLName

	if (FileSysInfo01.LoadSaveSub13(DATA_LOAD) == FALSE)		// Load Block.ini
		return -1;

    if (FileSysInfo01.LoadSaveSub25(DATA_LOAD) == FALSE) 		// Load Piece.ini	
    	return -1;

	// 기존  BlockDis.ini 를 Load (기존 data를 활용해서 새 BlockDis.ini를 만들어야)
	if (FileSysInfo01.LoadSaveSub19(DATA_LOAD,1) == FALSE)		
		return -1;

 	
	//m_nDisPMaxX=545;   
	//m_nDisPMaxY=510;   
	
	m_nDisPMaxX=720;   	// Cell Display영역.  기존 Auto 대비 1.5배 사이즈로 확대  
	m_nDisPMaxY=670;   

	nLine1=0;   
	nLine2=nLine1/2;  //nLine1  +시 축소 / - 100 확대 됨??????

   
   	// 화면에 반영되는 value형 control 값
	m_nBlockCol = SysInfo03.m_nCol;		
	m_nBlockRow = SysInfo03.m_nRow; 
	m_nBlockTot = m_nBlockCol * m_nBlockRow;

	m_nPieceCol = SysInfo25.m_nCol; 
	m_nPieceRow = SysInfo25.m_nRow;  
	m_nPieceTot = m_nPieceCol * m_nPieceRow;

	m_nCellCol  = m_nBlockCol * m_nPieceCol - SysInfo25.m_nColDel; 
	m_nCellRow  = m_nBlockRow * m_nPieceRow - SysInfo25.m_nRowDel; 
	m_nCellTot   = m_nCellCol * m_nCellRow;
	m_nCellDelCol = SysInfo25.m_nColDel;
	m_nCellDelRow = SysInfo25.m_nRowDel;

	m_bUsePieceDisable = SysInfo19.m_nUse; 
	
 
	
	if(m_nCellCol > 0)
		m_nCellXGap = m_nDisPMaxX / m_nCellCol;
	else
		m_nCellXGap = 1;
	
	if(m_nCellRow > 0)
		m_nCellYGap = m_nDisPMaxY / m_nCellRow;
	else
		m_nCellYGap =1;
		

	//------------------
	// Range Check
	
	//ASSERT(m_nCellTot > 0 && m_nCellTot <= 5000);				
	//ASSERT(m_nBlockTot > 0 && m_nBlockTot < Def_MaxPiece1);		
	//ASSERT(m_nPieceTot > 0 && m_nPieceTot < Def_MaxPiece1);		
	//ASSERT(m_nCellRow > 0 && m_nCellRow < Def_MaxPiece1);		
	//ASSERT(m_nCellCol > 0 && m_nCellCol < Def_MaxPiece1);		
	
	CString strTemp;
	if (m_nCellTot < 1 || m_nCellTot > 5000)				
	{
		strTemp.Format("InitView(): m_nCellTot=%d Range Over! (1 <= m_nCellTot <= 5000)\n", m_nCellTot);
		AfxMessageBox(strTemp, MB_ICONSTOP);
		return FALSE;
	}
	if (m_nBlockTot < 1 || m_nBlockTot >= Def_MaxBlock1)
	{
		strTemp.Format("InitView(): m_nBlockTot=%d Range Over! (1 <= m_nBlockTot <= %d)\n", m_nBlockTot, (Def_MaxBlock1 -1));
		AfxMessageBox(strTemp, MB_ICONSTOP);
		return FALSE;
	}
	if (m_nPieceTot < 1 || m_nPieceTot >= Def_MaxPiece1)
	{
		strTemp.Format("InitView(): m_nPieceTot=%d Range Over! (1 <= m_nPieceTot <= %d)\n", m_nPieceTot, (Def_MaxPiece1 -1));
		AfxMessageBox(strTemp, MB_ICONSTOP);
		return FALSE;
	}

	if (m_nCellRow < 1 || m_nCellRow >= Def_MaxPiece1)
	{
		strTemp.Format("InitView(): m_nCellRow=%d Range Over! (1 <= m_nCellRow <= %d)\n", m_nCellRow, (Def_MaxPiece1 -1));
		AfxMessageBox(strTemp, MB_ICONSTOP);
		return FALSE;
	}

	if (m_nCellCol < 1 || m_nCellCol >= Def_MaxPiece1)
	{
		strTemp.Format("InitView(): m_nCellCol=%d Range Over! (1 <= m_nCellCol <= %d)\n", m_nCellCol, (Def_MaxPiece1-1));
		AfxMessageBox(strTemp, MB_ICONSTOP);
		return FALSE;
	}
	

	//-------------------------------
	// m_saRectCell[] 정보를 생성
	int k;
	for(int i=1; i<= m_nCellRow ; i++)
	{    
 	   for( int j=1; j<= m_nCellCol ; j++) // m_nBlockRow-> m_nCellRow
 	   {  
			if( i==1 && j==1 )		// 최초 설정
			{
				 m_saRectCell[1].left   = 0  ;
				 m_saRectCell[1].right  = m_nCellXGap - nLine2 ;
				 m_saRectCell[1].top    = 0 ;  //k max 200
			 	 m_saRectCell[1].bottom = m_nCellYGap - nLine2 ;
			}
			else
			{  //k max 200
				 k=(int)(m_nCellCol*(i-1)+j);
				 m_saRectCell[k].left=   m_saRectCell[1].left + (m_saRectCell[1].right*(j-1)) ;
				 m_saRectCell[k].right=  m_saRectCell[k].left +  m_saRectCell[1].right ;
			 	 m_saRectCell[k].top= (long)( m_saRectCell[1].top  + (m_saRectCell[1].bottom*(i-1))) ;  
			 	 m_saRectCell[k].bottom= m_saRectCell[k].top  +  m_saRectCell[1].bottom ;
			}
		}
	}



	//--------------------------------------
	// 화면에 그려지는 모양 데이터를 설정
	DisplayNo();

	UpdateData(FALSE);

	return TRUE;
}


// 화면에 그려지는 모양인 m_waDisCell[][][]에 block, piece 번호등의 번호를 설정.
int CACE400PieceDisableDlg::DisplayNo()  
{	

 
	int posCol,posRow;

	::ZeroMemory(m_waDisCell, sizeof(m_waDisCell)); 	// 화면에 표시될 cell 정보
	::ZeroMemory(m_waDisBlock,sizeof(m_waDisBlock));
	::ZeroMemory(m_waDisPiece,sizeof(m_waDisPiece));

	::ZeroMemory(m_waDragData,sizeof(m_waDragData));	// Drag시 회색표시할 부분.
  

	//--------------------------------------------------
	// block map read
	posCol=posRow=0;
	int blockRow, blockCol;

	ASSERT(m_nBlockRow >0 && m_nBlockRow < Def_MaxPiece1);		// Range Check!
	ASSERT(m_nBlockCol >0 && m_nBlockCol < Def_MaxPiece1);		// Range Check!

	for(blockRow=1;   blockRow <= m_nBlockRow;  blockRow++)
	{	
		for(blockCol=1;   blockCol <= m_nBlockCol;  blockCol++)
			m_waDisBlock[blockRow][blockCol] = SysInfo03.m_nData[blockRow-1][blockCol-1];
	}

	//--------------------------------------------------
	// PIECE map read
	posCol=posRow=0;
	int pieceRow, pieceCol;

	ASSERT(m_nPieceRow >0 && m_nPieceRow < Def_MaxPiece1);		// Range Check!
	ASSERT(m_nPieceCol >0 && m_nPieceCol < Def_MaxPiece1);		// Range Check!

	for(pieceRow=1;   pieceRow <= m_nPieceRow;  pieceRow++)
	{	
		for(pieceCol=1;   pieceCol<=m_nPieceCol;  pieceCol++)
			m_waDisPiece[pieceRow][pieceCol] = SysInfo25.m_nData[pieceRow-1][pieceCol-1];
	}


	//--------------------------------------------------
	// Display mapping

	posCol=posRow=0;

	for(blockRow=1;   blockRow<=m_nBlockRow;  blockRow++)
	{		
		for(blockCol=1;   blockCol<=m_nBlockCol;  blockCol++)
		{
		    for(pieceRow=1;   pieceRow<=m_nPieceRow;  pieceRow++)
		    {
				for(pieceCol=1;  pieceCol<=m_nPieceCol; pieceCol++)
				{
					posCol = (blockCol-1) * m_nPieceCol + pieceCol;		// display Col
					posRow = (blockRow-1) * m_nPieceRow + pieceRow;		// display Row

					m_waDisCell[posRow][posCol][0]=m_waDisBlock[blockRow][blockCol];// [1,1],[2,1]		// block No
					m_waDisCell[posRow][posCol][1]=m_waDisPiece[pieceRow][pieceCol];// [1,1~3] [2,1~3]	// piece No
				}
			}

		}
	}
/////////////////////////////////////////////////////////////////


	m_waDisBlock[0][1]=m_nBlockRow;
	m_waDisBlock[0][2]=m_nBlockCol;
	m_waDisPiece[0][1]=m_nPieceRow;
	m_waDisPiece[0][2]=m_nPieceCol;


	return TRUE;   	               
}




void CACE400PieceDisableDlg::GraphDisplayBlock(int nCell)
{
	CRect AllRect;
 	RECT Rect;
	CString strMsg;
	int nFontS,nFontW;
	COLORREF bkColor;
 
 
 
	if( nCell >  m_nCellTot) 
		return; 

	UpdateData(TRUE);
 
	CDC  *pDC;
	CWnd* pWnd;
	pWnd = (CStatic*)GetDlgItem(IDC_STATIC_GRAPH);
	pDC = pWnd->GetDC();
 
	//-------------------------------
	// 폰트 지정
	
    if (m_nCellCol<=2 && m_nCellRow<=2){ 
        nFontW=FW_THIN;			// 가늘게
        nFontS=10;				// font size denominator이므로 값이 작을 수록 크게 출력된다.
	}
	else if (m_nCellCol<=4 && m_nCellRow<=4){
        nFontW=FW_THIN;	
        nFontS=20; 
	}
	else if (m_nCellCol<=5 && m_nCellRow<=10){
        nFontW=FW_THIN;
        nFontS=30; 
	}
	else if (m_nCellCol<=8 && m_nCellRow<=15){
        nFontW=FW_THIN;
        nFontS=40; 
	}
	else if (m_nCellCol<=10 && m_nCellRow<=20){
        nFontW=FW_THIN;
        nFontS=50; 
	}
	else if (m_nCellCol<=12 && m_nCellRow<=25){
        nFontW=FW_THIN;
        nFontS=60; 
	}
	else if (m_nCellCol<=14 && m_nCellRow<=30){
        nFontW=FW_THIN;
        nFontS=70; 
	}
	else if (m_nCellCol<=16 && m_nCellRow<=35){
        nFontW=FW_THIN;
        nFontS=80; 
	}
	else if (m_nCellCol<=18 && m_nCellRow<=40){
        nFontW=FW_THIN;
        nFontS=130;  
	}
	else if (m_nCellCol<=25 && m_nCellRow<=45){
        nFontW=FW_THIN;
        nFontS=140; 
	}
	else if (m_nCellCol<=30 && m_nCellRow<=50){
        nFontW=FW_THIN;
        nFontS=150; 
	}
	else{
        nFontW=FW_THIN;
        nFontS=160; 
	}

 
	LOGFONT lf;
	lf.lfHeight			= MulDiv(9, pDC->GetDeviceCaps(LOGPIXELSY), nFontS);		
							// 9:  기준 폰트 사이즈
							// pDC->GetDeviceCaps(LOGPIXELSY) : 현재 PC 해상도, 지금 PC는 96으로 측정됨. numerator(곱하는 수)
							// nFontS는 나누는 수(denominator)이므로  현재 해상도에 가까울 수록 9 포인트 폰트 사이즈가 나옴. 
							// nFontS가 현재 해상도 보다 크면 9보다 작은 폰트, 해상도보다  작으면 9보다 큰 폰트가 됨.
	lf.lfWidth			= 0;
	lf.lfEscapement		= 0;
	lf.lfOrientation	= 0; 
	lf.lfWeight			= nFontW;
	lf.lfItalic			= FALSE;
	lf.lfUnderline		= FALSE;
	lf.lfStrikeOut		= 0;
	lf.lfCharSet		= HANGEUL_CHARSET;
	lf.lfOutPrecision	= OUT_DEFAULT_PRECIS;
	lf.lfClipPrecision	= CLIP_DEFAULT_PRECIS;
	lf.lfQuality		= DEFAULT_QUALITY;
	lf.lfPitchAndFamily	= DEFAULT_PITCH | FF_DONTCARE;
//	sprintf(lf.lfFaceName, "%s", "굴림"); //mst 
	sprintf(lf.lfFaceName, "%s", "System"); //os-english  nano
 
	CFont* pNewFont = new CFont;
	CFont* pOldFont = NULL;
 
	pNewFont->CreateFontIndirect(&lf); 
	pOldFont = pDC->SelectObject(pNewFont);
  
 
 	//------------------------------------------
 	// Box 컬러 설정 
 	
	// BackGround를 지정한다.
	AllRect.left = m_saRectCell[nCell].left;
	AllRect.right = m_saRectCell[nCell].right ;
	AllRect.top = m_saRectCell[nCell].top;
    AllRect.bottom = m_saRectCell[nCell].bottom; 

	// nCell을 block, piece로 바꾼다.
 	int row, col, block, piece, ret;
	ret = CellToRowColBlockPiece(nCell, row, col, block, piece);	// cell로 row, col, block, piece를 획득
	if (ret < 0)	// error
		return;


	if (m_bDragMode == TRUE)
	{
		// Drag 중일때는 연한 군청색으로 표시
		if (m_waDragData[row][col] == TRUE)
			bkColor = RGB(0x8f,0xbc,0x8f);	// DARK SEA GREEN (녹두색)
		else
		{
			if (SysInfo19.m_nData[block][piece] == CELL_DISABLE)
				bkColor = RGB(0,110,110);	// DARK GREEN
			else
				bkColor=RGB(255,255,255);  	// WHITE
		}
	}
	else
	{	
		if (SysInfo19.m_nData[block][piece] == CELL_DISABLE)
			bkColor = RGB(0,110,110);	// DARK GREEN
		else
			bkColor=RGB(255,255,255);  	// WHITE
	}


	CBrush BackGrBrush;

	BackGrBrush.CreateSolidBrush(bkColor); 
	CBrush* pOldBrush = pDC->SelectObject(&BackGrBrush); 
	pDC->FillRect(AllRect, &BackGrBrush);
	pDC->SelectObject(pOldBrush);


	//----------------------------------
	// Box 그리기  
	
	Rect.top = AllRect.top;//sylee140115 
	Rect.bottom = AllRect.bottom;//sylee140115 
	Rect.left = AllRect.left;//sylee140115 
 	Rect.right = AllRect.right;//sylee140115   

 	pDC->SetBkColor(RGB(255,225,255)); // WHITE

	pDC->SetBkColor(bkColor); 
	pDC->SetTextColor(RGB(0,0,0));	
 
	if ((m_nPieceCol > 1) || (m_nPieceRow > 1))
	{  
		strMsg.Format("%d-%d",    m_waDisCell[row][col][0],  m_waDisCell[row][col][1]);//SYLEE120901
		if ((m_waDisCell[row][col][0] > 0) && (m_waDisCell[row][col][1] > 0))
			pDC->DrawText(strMsg, -1, &Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS | DT_VCENTER);	
	}
	else
	{
		strMsg.Format("%d", nCell);
		if(nCell > 0)
		    pDC->DrawText(strMsg, -1, &Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS | DT_VCENTER); 
	}
                    
 	pDC->SetBkColor(RGB(255,255,255));
  	pDC->SelectObject(pOldFont);
	delete pNewFont; 
 
	//----------------------------------
	// Box Line 그리기  
	
 	CPen m_penBack;
	m_penBack.CreatePen (PS_SOLID,0,RGB(0, 0, 0));
	CPen *pOldPen = pDC->SelectObject (&m_penBack);

	pDC->MoveTo(AllRect.left,AllRect.top);
	pDC->LineTo(AllRect.right,AllRect.top);

 	pDC->LineTo(AllRect.right,AllRect.bottom);
	pDC->LineTo(AllRect.left,AllRect.bottom);
	pDC->LineTo(AllRect.left,AllRect.top);

	pDC->MoveTo(AllRect.left+1,AllRect.top+1);
	pDC->LineTo(AllRect.right-1,AllRect.top+1);

 	pDC->LineTo(AllRect.right-1,AllRect.bottom-1);
	pDC->LineTo(AllRect.left+1,AllRect.bottom-1);
	pDC->LineTo(AllRect.left+1,AllRect.top+1);

	
	pDC->SelectObject (pOldPen);
	m_penBack.DeleteObject();
	ReleaseDC(pDC);
 
	UpdateData(FALSE);
}


void CACE400PieceDisableDlg::OnButtonFileLoad() 
{
	// TODO: Add your control notification handler code here
	InitView();
	
	SetTimer (0, 200, NULL);	// load로 cell disable 상태를 그리기 위해 timer  구동
}

void CACE400PieceDisableDlg::OnButtonFileSave() 
{
	// TODO: Add your control notification handler code here
	//
	
	UpdateData(TRUE);		// 현재 화면 컨트롤의 데이터를 가져 온다.
	
	SysInfo19.m_nBlockTot = m_nBlockTot;
	SysInfo19.m_nPieceTot = m_nPieceTot; 
    SysInfo19.m_nCellTotal = m_nCellTot;
	SysInfo19.m_nType = 1;
    SysInfo19.m_nUse = m_bUsePieceDisable;
	
	
	FileSysInfo01.LoadSaveSub19(DATA_SAVE,1);		// Save BlockDis.ini  
}

void CACE400PieceDisableDlg::OnButtonFileView() 
{
	// TODO: Add your control notification handler code here
	
	
 	CString strTemp; 
	strTemp.Format("%s\\SETUP2\\BlockDis.ini", SysInfoView01.m_pStrFilePathBDL);//SYLEE121202


	::ShellExecute(NULL, "open", "notepad.EXE", strTemp, "NULL", SW_SHOWNORMAL);
}

void CACE400PieceDisableDlg::OnButtonEnableAll() 
{
	// TODO: Add your control notification handler code here
	
	for (int block = 0; block <= m_nBlockTot; block++)
	{
		for (int piece = 0; piece <= m_nPieceTot; piece++)

			SysInfo19.m_nData[block][piece] = CELL_ENABLE;
	}

	m_nDisableBlock = 0;	// 다음 설정을 위해 0으로 초기화.

	SetTimer (0, 200, NULL);	// 모두 Enable한 cell을 그리기 위해 timer  구동
	UpdateData(FALSE);
}


// Cell 클릭시에 해당 Cell을 Disable하기 위함
void CACE400PieceDisableDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CString strTemp;
/*
	// 현재 윈도의 rect 값을 얻어온다.
	RECT rc1;
	::GetClientRect(this->m_hWnd, &rc1);	// left=0, right=1038, top=0, bottom=801
	strTemp.Format("GetClientRect(this->m_hWnd): left=%d, right=%d, top=%d, bottom=%d\n", rc1.left, rc1.right, rc1.top, rc1.bottom);
	TRACE(strTemp);
	::GetWindowRect(this->m_hWnd, &rc1);	// left=0, right=1038, top=0, bottom=801
	strTemp.Format("GetWindowRect(this->m_hWnd): left=%d, right=%d, top=%d, bottom=%d\n", rc1.left, rc1.right, rc1.top, rc1.bottom);
	TRACE(strTemp);

	
	
	// IDC_STATIC_GRAPH 내부의  rect 값을 얻어온다.  (left, top은 모두 0)
	RECT rc2;
	HWND hwndBox = ::GetDlgItem(this->m_hWnd, IDC_STATIC_GRAPH);

	::GetClientRect(hwndBox, &rc2);		// left=0, right=634, top=0, bottom=538
	strTemp.Format("GetClientRect(hwndBox:IDC_STATIC_GRAPH) left=%d, right=%d, top=%d, bottom=%d\n", 
			rc2.left, rc2.right, rc2.top, rc2.bottom);
	TRACE(strTemp);

	// IDC_STATIC_GRAPH 윈도우화면의   rect 값을 얻어온다.  (left, top은 모두 0)
	::GetWindowRect(hwndBox, &rc2);    // left=438, right=1482, top=126, bottom=955	
	strTemp.Format("GetWindowRect(hwndBox:IDC_STATIC_GRAPH) left=%d, right=%d, top=%d, bottom=%d\n", 
			rc2.left, rc2.right, rc2.top, rc2.bottom);
	TRACE(strTemp);
*/

	// 현재 클릭한 mouse의 포인트값을 출력, 상대좌표로 바꾼 값도 출력
	HWND hwndBox = ::GetDlgItem(this->m_hWnd, IDC_STATIC_GRAPH);
	CPoint	screenPt = point;
	::ClientToScreen(this->m_hWnd, &screenPt);	// 다이얼로그의 point를 윈도우 포인트로

	CPoint	boxPt = screenPt;
	::ScreenToClient(hwndBox, &boxPt);			// 윈도우포인트를 다시 Piece Disable Box 내부 포인트로
	//TRACE("Start point(x=%d, y=%d) => boxPt(x=%d, y=%d) \n", point.x,  point.y, boxPt.x, boxPt.y);


	// Drag 시작된 포인트의 cell을 drag로 표시,  row, col 값은 받아온다.
	int row, col;		
	if (SetDrag(boxPt, row, col) == _OK)	// SetDrag하면서 row, col 획득. row, col이 정상이어야 Drag를 시작
	{
		m_bDragMode = TRUE;		// Drag가 시작되었음을 표시

		m_nStartCellRow = row;
		m_nStartCellCol = col;
		
		SetTimer (0, 300, NULL);	// Drag 중의 블록을 그리기 위해 timer 시작
	}

	SetCapture();	// 마우스 커서가 윈도우를 벗어나도 메시지를 잡아온다.
					// 윈도우를 벗어난 후 후속메시지처리를 위해 필요함. 
					// SetCapture()를 하면 LButtonUp시에 반드시 ReleaseCapter()를 해야 함.
					// VisualC++ 완벽가이드 399p. 참조
	
	CDialog::OnLButtonDown(nFlags, point);
}

// 전달받은 포인트의 cell을 m_waDragData[][]에 drag로 표시,  row, col 값은 리턴한다.
int CACE400PieceDisableDlg::SetDrag(CPoint boxPt, int& rnRow, int& rnCol) 
{
	// boxPt에 맞는 cell을 찾는다.
	int cell;
	if (FindCellForPoint(boxPt, cell)  < 0)		// 맞는 cell이 없음.
		return -1;

	// cell 번호에 맞는 block, piece를 찾는다.
	int block, piece, ret;
	ret = CellToRowColBlockPiece(cell, rnRow, rnCol, block, piece); // cell로 row, col, block, piece를 획득
	if (ret < 0)	// error
		return -1;

//	TRACE("boxPt(x=%d, y=%d) => cell=%d  => block=%d, piece=%d\n", boxPt.x, boxPt.y, cell, block, piece);

	m_waDragData[rnRow][rnCol] = TRUE;

	return _OK;	// return 0
}

// 전달받은 cell을  m_waDragData[][]에 drag로 표시, 
int CACE400PieceDisableDlg::SetDrag2(int nCell) 
{

	// cell 번호에 맞는 block, piece를 찾는다.
	int row, col, block, piece, ret;
	ret = CellToRowColBlockPiece(nCell, row, col, block, piece); // cell로 row, col, block, piece를 획득
	if (ret < 0)	// error
		return -1;

	m_waDragData[row][col] = TRUE;

	return _OK;	// return 0
}

void CACE400PieceDisableDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	// 마우스를 누른 상태에서 Drag할 때
	if (m_bDragMode == TRUE)
	{
		// 현재 클릭한 mouse의 포인트값을 출력, 상대좌표로 바꾼 값도 출력
		HWND hwndBox = ::GetDlgItem(this->m_hWnd, IDC_STATIC_GRAPH);
		CPoint	screenPt = point;
		::ClientToScreen(this->m_hWnd, &screenPt);	// 다이얼로그의 point를 윈도우 포인트로

		CPoint	boxPt = screenPt;
		::ScreenToClient(hwndBox, &boxPt);			// 윈도우포인트를 다시 Piece Disable Box 내부 포인트로

		// Mouse Moving 중의 Drag 상황을 표시하기 위해 SetDrag(), SetDragRange()를 수행한다.
		// 실제 사용할 영역은 LButtonUp()에서 마지막으로 다시 지정해야 한다.
		int stopRow, stopCol;
		if (SetDrag(boxPt, stopRow, stopCol) == _OK)	// SetDrag하면서 stopRow, stopCol 획득.
			SetDragRange(boxPt, stopRow, stopCol);		// start위치부터 Drag 진행중인 현재 포인트까지 영역의 cell을 drag로 표시
	}
	
	CDialog::OnMouseMove(nFlags, point);
}

void CACE400PieceDisableDlg::SetDragRange(CPoint boxPt, int stopRow, int stopCol) 
{
	int row, col, cell, ret;

	// Start 지점에 이상이 있다면 Drag를 중단.
	if (m_nStartCellRow < 1 || m_nStartCellCol < 1)
		return;

	// 마우스 클릭 시작지점과 끝지점이 같으면 영역지정이 아니므로 중단
	if (m_nStartCellRow == stopRow && m_nStartCellCol == stopCol)
		return;


	// moving 중에 잠깐 멈춘 경우.  이전에 range 설정한 포인트이므로 넘어간다.
	if (m_nPrevRow == stopRow && m_nPrevCol == stopCol)
	{
		//TRACE("m_nPrevRow=StopRow=%d,  m_nPrevCol=StopCol=%d\n", stopRow, stopCol);
		return;
	}	
	
	
	m_nPrevRow = stopRow;
	m_nPrevCol = stopCol;

	// 현재 stop 지점 기준으로 영역지정을 위해 이전 drag 시의 drag 표시는 지운다.
	::ZeroMemory(m_waDragData,sizeof(m_waDragData));	// Drag시 녹두색 표시할 부분 초기화.


	// Rect 영역지정: 
	// 시작과 끝의 row, cell이 모두 다르므로  모서리 지역도 SetDrag해야 한다.
	if (m_nStartCellRow != stopRow && m_nStartCellCol != stopCol)
	{
		if (m_nStartCellRow >= stopRow 			// 아래에서 위로 Drag는 불허용
			|| m_nStartCellCol >= stopCol) 		// 오른쪽에서 왼쪽 Drag는 불허용
			return ;

		// 왼쪽에서 오른쪽, 위에서 아래 Drag인 경우 사각형 영역 (start~stop)을 Drag로 표시
		for (row=m_nStartCellRow; row <= stopRow; row++)
		{
			for (col=m_nStartCellCol; col <= stopCol; col++)
			{	
				ret = RowColToCell(row, col, cell);
				if (ret < 0)	// error
					continue;
				SetDrag2(cell);
			}
		}
	}

	// Row 영역지정  (row는 같은데 col이 달라짐)
	else if (m_nStartCellRow == stopRow && m_nStartCellCol != stopCol)	
	{
		if (m_nStartCellCol >= stopCol)	// 오른쪽에서 왼쪽 Drag는 불허용
			return;

		// stopRow는 고정, 왼쪽에서 오른쪽  cell 들을 Drag 표시 
		for (col=m_nStartCellCol; col <= stopCol; col++)
		{	
			ret = RowColToCell(stopRow, col, cell);
			if (ret < 0)	// error
				continue;
			SetDrag2(cell);
		}
	}
		
	// Col 영역지정  (Col은 같은데 row이 달라짐)
	else if (m_nStartCellRow != stopRow && m_nStartCellCol == stopCol)	
	{
		if (m_nStartCellRow >= stopRow)	// 오른쪽에서 왼쪽 Drag는 불허용
			return;

		// stopCol은 고정, 위에서 아래의 cell 들을 Drag 표시
		for (row=m_nStartCellRow; row <= stopRow; row++)
		{	
			ret = RowColToCell(row, stopCol, cell);
			if (ret < 0)	// error
				continue;
			SetDrag2(cell);
		}
	}

}

void CACE400PieceDisableDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	
	
	// piece box 외의 지역에서 drag start하고, piece box 안에서 stop시에 
	// DragMode가 False여도 toggle이 되는 문제가 발생.  
	// ButtonUp시에 DragMode가 True가 아니면  toggle도 안하도록 수정.
	if (m_bDragMode == TRUE)
	{

	// 현재 클릭한 mouse의 포인트값을 출력, 상대좌표로 바꾼 값도 출력
	HWND hwndBox = ::GetDlgItem(this->m_hWnd, IDC_STATIC_GRAPH);
	CPoint	screenPt = point;
	::ClientToScreen(this->m_hWnd, &screenPt);	// 다이얼로그의 point를 윈도우 포인트로

	CPoint	boxPt = screenPt;
	::ScreenToClient(hwndBox, &boxPt);			// 윈도우포인트를 다시 Piece Disable Box 내부 포인트로
	//TRACE("End point(x=%d, y=%d) => boxPt(x=%d, y=%d) \n", point.x,  point.y, boxPt.x, boxPt.y);

	// Drag가 끝난 포인트의 cell을 drag로 표시, stopRow, stopCol획득
	int stopRow, stopCol;
	if (SetDrag(boxPt, stopRow, stopCol) == _OK)	// stopRow, stopCol이 정상이어야 Drag 처리 진행
	{
		SetDragRange(boxPt, stopRow, stopCol);		// start위치부터 Drag 진행중인 현재 포인트까지 영역의 cell을 drag로 표시

		// 마우스 클릭 시작지점과 끝지점이 같으면 Drag가 아니므로 현상태를 Toggle한다.
		if (m_nStartCellRow == stopRow && m_nStartCellCol == stopCol)
			ToggleDisable(boxPt);		

		// Drag라면, Drag 표시된 모든 cell을 찾아서 Toggle한다. 
		else
			SetDragAllToToggle(); 
		}
	}
	

		m_bDragMode = FALSE;		// Drag 끝났음을 표시
		m_nStartCellRow = -1;
		m_nStartCellCol = -1;
		::ZeroMemory(m_waDragData,sizeof(m_waDragData));	// Drag시 회색표시할 부분 초기화.

	ReleaseCapture();
	
	CDialog::OnLButtonUp(nFlags, point);
}


// Drag(녹두색)으로 표시된 Cell을 모두 Toglle한다. (Enable은 Disable로, Disable은 Enable로)
void CACE400PieceDisableDlg::SetDragAllToToggle() 
{

	for (int row = 0; row <= m_nCellRow; row++)
	{
		for (int col = 0; col <= m_nCellCol; col++)
		{
			// DRAG = TRUE인 cell 만 찾아서 상태를 변경한다.
			if (m_waDragData[row][col] == TRUE)
			{
				int cell, block, piece, tempRow, tempCol, ret;
				ret = RowColToCell(row, col, cell);	// row, coll로 cell 획득.
				if (ret < 0)	// error
					continue;

				ret = CellToRowColBlockPiece(cell, tempRow, tempCol, block, piece); // cell로 block, piece를 획득
				if (ret < 0)	// error
					continue;

				// Mode : Toggle
				if (SysInfo19.m_nData[block][piece] == CELL_DISABLE)
					SysInfo19.m_nData[block][piece] = CELL_ENABLE;		// 기존값이 Disable이면 Enable로
				else
					SysInfo19.m_nData[block][piece] = CELL_DISABLE;		// 기존값이 Enable이면 Disable로
			}	
		}		

	}
}


// Drag(녹두색)으로 표시된 Cell을 Disable로 바꾼다.
void CACE400PieceDisableDlg::SetDragAllToDisable() 
{

	for (int row = 0; row <= m_nCellRow; row++)
	{
		for (int col = 0; col <= m_nCellCol; col++)
		{
			// DRAG = TRUE인 cell 만 찾아서 상태를 변경한다.
			if (m_waDragData[row][col] == TRUE)
			{
				int cell, block, piece, tempRow, tempCol, ret;
				ret = RowColToCell(row, col, cell);	// row, coll로 cell 획득.
				if (ret < 0)	// error
					continue;

				ret = CellToRowColBlockPiece(cell, tempRow, tempCol, block, piece); // cell로 block, piece를 획득
				if (ret < 0)	// error
					continue;

				// Mode : Disable
				SysInfo19.m_nData[block][piece] = CELL_DISABLE;		// 무조건 Disable
			}	
		}		
	}
}

void CACE400PieceDisableDlg::SetDragAllToEnable() 
{

	for (int row = 0; row <= m_nCellRow; row++)
	{
		for (int col = 0; col <= m_nCellCol; col++)
		{
			// DRAG = TRUE인 cell 만 찾아서 상태를 변경한다.
			if (m_waDragData[row][col] == TRUE)
			{
				int cell, block, piece, tempRow, tempCol, ret;
				
				ret = RowColToCell(row, col, cell);	// row, coll로 cell 획득.
				if (ret < 0)	// error
					continue;

				ret = CellToRowColBlockPiece(cell, tempRow, tempCol, block, piece); // cell로 block, piece를 획득
				if (ret < 0)	// error
					continue;

				// Mode : Enable
				SysInfo19.m_nData[block][piece] = CELL_ENABLE;		// 무조건 Enable
			}	
		}		
	}
}

void CACE400PieceDisableDlg::ToggleDisable(CPoint boxPt) 
{


	// boxPt에 맞는 cell을 찾는다.
	int cell;
	if (FindCellForPoint(boxPt, cell)  == -1)		// 맞는 cell이 없음.
		return;

	// cell 번호에 맞는 block, piece를 찾는다.
	int row, col, block, piece, ret;
	ret = CellToRowColBlockPiece(cell, row, col, block, piece); // cell로 row, col, block, piece를 획득
	if (ret < 0)	// error
		return;

	//TRACE("boxPt(x=%d, y=%d) => cell=%d  => block=%d, piece=%d\n", boxPt.x, boxPt.y, cell, block, piece);

	// Toggle
	if (SysInfo19.m_nData[block][piece] == CELL_DISABLE)
		SysInfo19.m_nData[block][piece] = CELL_ENABLE;		// 기존값이 Disable이면 Enable로
	else
		SysInfo19.m_nData[block][piece] = CELL_DISABLE;		// 기존값이 Enable이면 Disable로


}

// boxPt에 맞는 cell을 찾는다.
int CACE400PieceDisableDlg::FindCellForPoint(CPoint boxPt, int& rnCell) 
{
	int cell;
	for(cell = 1; cell <= m_nCellTot; cell++) //test  display
	{
		if (( boxPt.x >= m_saRectCell[cell].left && boxPt.x <= m_saRectCell[cell].right )
			&& (boxPt.y >= m_saRectCell[cell].top && boxPt.y <= m_saRectCell[cell].bottom))
			break;

	}
	if (cell == (m_nCellTot +1))		// 맞는 cell이 없음.
		return -1;

	rnCell = cell;

	return _OK;
}

// nCell로 rnRow, rnCol, rnBlock, rnPiece를 획득
int CACE400PieceDisableDlg::CellToRowColBlockPiece(int nCell, int& rnRow, int&rnCol, int& rnBlock, int& rnPiece) 
{
	int nBlockMaxXTotal,  nBlockMaxYTotal;
	nBlockMaxXTotal = m_nBlockCol * m_nPieceCol - SysInfo25.m_nColDel;  
    nBlockMaxYTotal = m_nBlockRow * m_nPieceRow - SysInfo25.m_nRowDel;  

	// nCell로 row, coll을 계산한다.
	rnRow   = ((nCell - 1) / (nBlockMaxXTotal)); // 몫    
	rnCol   = nCell - (nBlockMaxXTotal * rnRow);   // 나머지
	rnRow   = rnRow + 1;

	CString strTemp;
	if (rnRow < 1 || rnRow > m_nCellRow) 		// error check
	{
		strTemp.Format("CellToRowColBlockPiece(nCell=%d):  rnRow=%d Range Error! (1 <= rnRow <= %d)\n", 
				nCell, rnRow, m_nCellRow);
		AfxMessageBox(strTemp, MB_ICONSTOP);
		return -1;
	}

	if (rnCol < 1 || rnCol > m_nCellCol) 		// error check
	{
		strTemp.Format("CellToRowColBlockPiece(nCell=%d):  rnCol=%d Range Error! (1 <= rnCol <= %d)\n", 
				nCell, rnCol, m_nCellCol);
		AfxMessageBox(strTemp, MB_ICONSTOP);
		return -1;
	}

	// row, col에 맞는 block, piece를 찾아낸다.
	rnBlock = m_waDisCell[rnRow][rnCol][0];	
	rnPiece = m_waDisCell[rnRow][rnCol][1];	

	return _OK;	// return 0
}

// nRow, nCol 값으로 cell값을 계산한다.
int CACE400PieceDisableDlg::RowColToCell(int nRow, int nCol, int& rnCell) 
{
	int nBlockMaxXTotal,  nBlockMaxYTotal;
	nBlockMaxXTotal = m_nBlockCol * m_nPieceCol - SysInfo25.m_nColDel;  
	nBlockMaxYTotal = m_nBlockRow * m_nPieceRow - SysInfo25.m_nRowDel;  

	rnCell = ((nRow-1) * nBlockMaxXTotal) + (nCol-1)  +1;

	if (rnCell < 1 || rnCell > m_nCellTot) 		// error check
	{
		CString strTemp;
		strTemp.Format("RowColToCell(nRow=%d, nCol=%d):  rnCell=%d Range Error! (1 <= rnCell <= %d)\n", 
				nRow, nCol, rnCell, m_nCellTot);
		AfxMessageBox(strTemp, MB_ICONSTOP);
		return -1;
	}
	return _OK;		// return 0
}


//-------------------------------------------------------------------------
// editBox로 Disable할 블록을 입력받고 해당 블록을 통째로 Diable 하는 기능
void CACE400PieceDisableDlg::OnChangeEditDisableBlock() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
	
	// DoDataExchange()로 연결된 m_nDisableBlock 값을 화면에서 가져온다.
	UpdateData(TRUE);		

}

// IDC_EDIT_DISABLE_BLOCK edit 박스로 지정된 m_nDisableBlock 에 해당하는 블록의 모든 piece를 Disable한다.
void CACE400PieceDisableDlg::OnButtonBlockDisable() 
{
	// TODO: Add your control notification handler code here
	
	// DoDataExchange()로 연결된 m_nDisableBlock 값을 화면에서 가져온다.
	UpdateData(TRUE);

	if (m_nDisableBlock < 1 || m_nDisableBlock > m_nBlockTot)		// range check
	{
		CString strTemp;
		strTemp.Format("OnButtonBlockDisable():  m_nDisableBlock=%d Range Error! (1 <= m_nDisableBlock <= %d)\n", 
				m_nDisableBlock, m_nBlockTot);
		AfxMessageBox(strTemp, MB_ICONSTOP);
		return;
	}
	
	for (int piece = 0; piece <= m_nPieceTot; piece++)
		SysInfo19.m_nData[m_nDisableBlock][piece] = CELL_DISABLE;

	SetTimer (0, 200, NULL);	// disable로 변경된  cell을 그리기 위해 timer  구동

	UpdateData(FALSE);

}

