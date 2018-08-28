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
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CACE400PieceDisableDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CACE400PieceDisableDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CACE400PieceDisableDlg, CDialog)
	//{{AFX_MSG_MAP(CACE400PieceDisableDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SHOWWINDOW()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
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
	
	SetTimer ( 	0,			// OnTimer 수행시 받을 Timer Id
				1000,		// 1000ms 즉, 1sec 주기
				NULL);		// Timer 수신시 자동수행할 CallBack Function은 NULL로 설정.
				
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


 

void CACE400PieceDisableDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 0)
	{
		//KillTimer(0);		// 1회성으로 쓰기 위해  Timer 받자 마자 해당 Timer Id를 반환한다.

		//CString strTemp;
		//AfxMessageBox(strTemp, MB_ICONINFORMATION);

		for(int cell = 1; cell <= nCellMax; cell++) //test  display
		{  
			GraphDisplayBlock(cell);//display-no1			 
		}
	
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

	int nLine1, nLine2;

	FileSysInfo01.LoadSaveView01(DATA_LOAD);		// Load	SysInfoView01.m_pStrFileBDLName
	FileSysInfo01.LoadSaveSub13(DATA_LOAD);			// Load Block.ini
    FileSysInfo01.LoadSaveSub25(DATA_LOAD); 		// Load Piece.ini	
	FileSysInfo01.LoadSaveSub19(DATA_LOAD,1);		// 기존  BlockDis.ini fmf Load (기존 data를 활용해서 새 BlockDis.ini를 만들어야

 	
	nDisPMaxX=545;   
	nDisPMaxY=510;   

	nLine1=0;   
	nLine2=nLine1/2;  //nLine1  +시 축소 / - 100 확대 됨??????

   
	nBlockMaxX = SysInfo03.m_nCol;		
	nBlockMaxY = SysInfo03.m_nRow; 
	nPieceMaxX = SysInfo25.m_nCol; 
	nPieceMaxY = SysInfo25.m_nRow;  
	nCellMaxX  = nBlockMaxX * nPieceMaxX - SysInfo25.m_nColDel; 
	nCellMaxY  = nBlockMaxY * nPieceMaxY - SysInfo25.m_nRowDel; 
	nCellMax   = nCellMaxX * nCellMaxY;

 
    nBlockMax = nBlockMaxX * nBlockMaxY; 
    nPieceMax = nPieceMaxX * nPieceMaxY;
	
	if(nCellMaxX>0){
		nCellXGap=nDisPMaxX/nCellMaxX;
	}else{
		nCellXGap=1;
	}
	if(nCellMaxY>0){
		nCellYGap=nDisPMaxY/nCellMaxY;
	}else{
		nCellYGap=1;
	}	
	

	// m_Block 정보를 생성
	int k;
	for(int i=1; i<= nCellMaxY ; i++)
	{    
 	   for( int j=1; j<= nCellMaxX ; j++) //sylee20120321   nBlockMaxY-> nCellMaxY
 	   {  
			if( i==1 && j==1 )		// 최초 설정
			{
				 m_Block[1].left   = 0  ;
				 m_Block[1].right  = nCellXGap - nLine2 ;
				 m_Block[1].top    = 0 ;  //k max 200
			 	 m_Block[1].bottom = nCellYGap - nLine2 ;
			}
			else
			{  //k max 200
				 k=(int)(nCellMaxX*(i-1)+j);
				 m_Block[k].left=   m_Block[1].left + (m_Block[1].right*(j-1)) ;
				 m_Block[k].right=  m_Block[k].left +  m_Block[1].right ;
			 	 m_Block[k].top= (long)( m_Block[1].top  + (m_Block[1].bottom*(i-1))) ;  
			 	 m_Block[k].bottom= m_Block[k].top  +  m_Block[1].bottom ;
			}
		}
	}



	// 화면에 그려지는 모양 데이터를 설정
	DisplayNo();

	return TRUE;
}

int CACE400PieceDisableDlg::InitView() 
{

	UpdateData(TRUE);


	UpdateData(FALSE);

	return TRUE;
}


// 화면에 그려지는 모양인 nDisCell1[][][]에 block, piece 번호등의 번호를 설정.
int CACE400PieceDisableDlg::DisplayNo()  
{	

 
	int posCol,posRow;

	::ZeroMemory(nDisCell1, sizeof(nDisCell1)); 
//	::ZeroMemory(nDisBlock1,sizeof(nDisBlock1));
//	::ZeroMemory(nDisPiece1,sizeof(nDisPiece1));

  

	//--------------------------------------------------
	// block map read
	posCol=posRow=0;

	int blockRow, blockCol;
	for(blockRow=1;   blockRow <= SysInfo03.m_nRow;  blockRow++)
	{	
		for(blockCol=1;   blockCol <= SysInfo03.m_nCol;  blockCol++)
			nDisBlock1[blockRow][blockCol] = SysInfo03.m_nData[blockRow-1][blockCol-1];
	}

	//--------------------------------------------------
	// PIECE map read
	posCol=posRow=0;


	int pieceRow, pieceCol;
	for(pieceRow=1;   pieceRow <= SysInfo25.m_nRow;  pieceRow++)
	{	
		for(pieceCol=1;   pieceCol<=SysInfo25.m_nCol;  pieceCol++)
			nDisPiece1[pieceRow][pieceCol] = SysInfo25.m_nData[pieceRow-1][pieceCol-1];
	}


	//--------------------------------------------------
	// Display mapping

	posCol=posRow=0;

	for(blockRow=1;   blockRow<=SysInfo03.m_nRow;  blockRow++)
	{		
		for(blockCol=1;   blockCol<=SysInfo03.m_nCol;  blockCol++)
		{
		    for(pieceRow=1;   pieceRow<=SysInfo25.m_nRow;  pieceRow++)
		    {
				for(pieceCol=1;  pieceCol<=SysInfo25.m_nCol; pieceCol++)
				{
					posCol = (blockCol-1) * SysInfo25.m_nCol + pieceCol;		// display Col
					posRow = (blockRow-1) * SysInfo25.m_nRow + pieceRow;		// display Row

					nDisCell1[posRow][posCol][0]=nDisBlock1[blockRow][blockCol];// [1,1],[2,1]		// block No
					nDisCell1[posRow][posCol][1]=nDisPiece1[pieceRow][pieceCol];// [1,1~3] [2,1~3]	// piece No
				}
			}

		}
	}
/////////////////////////////////////////////////////////////////


	nDisBlock1[0][1]=SysInfo03.m_nRow;
	nDisBlock1[0][2]=SysInfo03.m_nCol;
	nDisPiece1[0][1]=SysInfo25.m_nRow;
	nDisPiece1[0][2]=SysInfo25.m_nCol;


	return TRUE;   	               
}

void CACE400PieceDisableDlg::GraphDisplayBlock(int nCell)
{
//	CDC  *pDC;
//	CWnd* pWnd;
	CRect AllRect;
 	RECT Rect;
	CString strMsg;
	int nFontS,nFontW;
	COLORREF bkColor;
 
 
// 	if( nProcessFlag1==1){//sylee130216joytech
//		return;
//	}
 
 
	if( nCell >  nCellMax) 
		return; 

	UpdateData(TRUE);
 
//	pWnd = (CStatic*)GetDlgItem(IDD_PIECEDISABLE_DIALOG);
//	pDC = pWnd->GetDC();
	CClientDC dc(this);
 
     if(nCellMaxX<=2 && nCellMaxY<=2){ //sylee140115 
        nFontW=100;nFontS=10;
	}else if(nCellMaxX<=4 && nCellMaxY<=4){
        nFontW=100;nFontS=20; 
	}else if(nCellMaxX<=5 && nCellMaxY<=10){
        nFontW=100;nFontS=30; 
	}else if(nCellMaxX<=8 && nCellMaxY<=15){
        nFontW=100;nFontS=40; 
	}else if(nCellMaxX<=10 && nCellMaxY<=20){
        nFontW=100;nFontS=50; 
	}else if(nCellMaxX<=12 && nCellMaxY<=25){
        nFontW=100;nFontS=60; 
	}else if(nCellMaxX<=14 && nCellMaxY<=30){
        nFontW=100;nFontS=70; 
	}else if(nCellMaxX<=16 && nCellMaxY<=35){
        nFontW=100;nFontS=80; 
	}else if(nCellMaxX<=18 && nCellMaxY<=40){
        nFontW=100;nFontS=130;  
	}else if(nCellMaxX<=25 && nCellMaxY<=45){
        nFontW=100;nFontS=140; 
	}else if(nCellMaxX<=30 && nCellMaxY<=50){
        nFontW=100;nFontS=150; 
	}else{
        nFontW=100;nFontS=160; 
	}

 
//====================================================
	LOGFONT lf;
	lf.lfHeight			= MulDiv(9, dc.GetDeviceCaps(LOGPIXELSY), nFontS);
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
	pOldFont = dc.SelectObject(pNewFont);
  
// BackGround를 지정한다.

	AllRect.left = m_Block[nCell].left;
	AllRect.right = m_Block[nCell].right ;
	AllRect.top = m_Block[nCell].top;
    AllRect.bottom = m_Block[nCell].bottom; 

 
 	//------------------------------------------
 	// Box 컬러 설정 
 	
	int nBlockMaxXTotal,  nBlockMaxYTotal;
 	int row, col, block,piece;

	nBlockMaxXTotal = nBlockMaxX * nPieceMaxX - SysInfo25.m_nColDel;  ///*******
    nBlockMaxYTotal = nBlockMaxY * nPieceMaxY - SysInfo25.m_nRowDel;  ///*******
	row   = ((nCell - 1) / (nBlockMaxXTotal)); // 몫    
	col   = nCell - (nBlockMaxXTotal * row);   // 나머지
	row   = row + 1;
	block = nDisCell1[row][col][0];	
	piece = nDisCell1[row][col][1];	

	if (SysInfo19.m_nData[block][piece] == CELL_DISABLE)
      	//bkColor = RGB(20,240,1120);     // DISABLE???	  
    	bkColor = RGB(0,110,110);		// DARK GREEN
	else
		//bkColor=RGB(0,0,0);  //BLACK 
		bkColor=RGB(255,255,255);  // WHITE


	CBrush BackGrBrush;

	BackGrBrush.CreateSolidBrush(bkColor); 
	CBrush* pOldBrush = dc.SelectObject(&BackGrBrush); 
	dc.FillRect(AllRect, &BackGrBrush);
	dc.SelectObject(pOldBrush);


	// ---------------------------------
	// Box 그리기  
	
	Rect.top = AllRect.top;//sylee140115 
	Rect.bottom = AllRect.bottom;//sylee140115 
	Rect.left = AllRect.left;//sylee140115 
 	Rect.right = AllRect.right;//sylee140115   

 	dc.SetBkColor(RGB(255,225,255)); // WHITE

	dc.SetBkColor(bkColor); // //sylee140402
	dc.SetTextColor(RGB(0,0,0));	
 
	if( (nPieceMaxX>1) || (nPieceMaxY>1) ){  //SYLEE121120
		 strMsg.Format("%d-%d",    nDisCell1[row][col][0],  nDisCell1[row][col][1]  );//SYLEE120901
		 if((nDisCell1[row][col][0]>0)&&(nDisCell1[row][col][1]>0)){//sylee121119
		    	dc.DrawText(strMsg, -1, &Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS | DT_VCENTER);	//SYLEE140402		 
		 }
	}else{
		strMsg.Format("%d", nCell);
		if(nCell>0){
		    dc.DrawText(strMsg, -1, &Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS | DT_VCENTER); //SYLEE140402	
		}
	}
                    
 	dc.SetBkColor(RGB(255,255,255));
  	dc.SelectObject(pOldFont);
	delete pNewFont; 
 
 	CPen m_penBack;
 
	m_penBack.CreatePen (PS_SOLID,0,RGB(0, 0, 0));
	CPen *pOldPen = dc.SelectObject (&m_penBack);

	dc.MoveTo(AllRect.left,AllRect.top);
	dc.LineTo(AllRect.right,AllRect.top);

 	dc.LineTo(AllRect.right,AllRect.bottom);
	dc.LineTo(AllRect.left,AllRect.bottom);
	dc.LineTo(AllRect.left,AllRect.top);

	dc.MoveTo(AllRect.left+1,AllRect.top+1);
	dc.LineTo(AllRect.right-1,AllRect.top+1);

 	dc.LineTo(AllRect.right-1,AllRect.bottom-1);
	dc.LineTo(AllRect.left+1,AllRect.bottom-1);
	dc.LineTo(AllRect.left+1,AllRect.top+1);

	
	dc.SelectObject (pOldPen);
	m_penBack.DeleteObject();
//	ReleaseDC(pDC);
 
	UpdateData(FALSE);
}



// Cell 클릭시에 해당 Cell을 Disable하기 위함
void CACE400PieceDisableDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	//ToggleDisable(point);
	
	CDialog::OnLButtonDown(nFlags, point);
}
