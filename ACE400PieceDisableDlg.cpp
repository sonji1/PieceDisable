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
	m_nBlockTot = 0;
	m_nBlockRow = 0;
	m_nBlockCol = 0;
	m_nPieceTot = 0;
	m_nPieceRow = 0;
	m_nPieceCol = 0;
	m_nCellCol = 0;
	m_nCellRow = 0;
	m_nCellTot = 0;
	m_bUsePieceDisable = FALSE;
	m_nCellDelCol = 0;
	m_nCellDelRow = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CACE400PieceDisableDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CACE400PieceDisableDlg)
	DDX_Text(pDX, IDC_EDIT_BLOCK_TOT, m_nBlockTot);
	DDX_Text(pDX, IDC_EDIT_BLOCK_ROW, m_nBlockRow);
	DDX_Text(pDX, IDC_EDIT_BLOCK_COL, m_nBlockCol);
	DDX_Text(pDX, IDC_EDIT_PIECE_TOT, m_nPieceTot);
	DDX_Text(pDX, IDC_EDIT_PIECE_ROW, m_nPieceRow);
	DDX_Text(pDX, IDC_EDIT_PIECE_COL, m_nPieceCol);
	DDX_Text(pDX, IDC_EDIT_CELL_COL, m_nCellCol);
	DDX_Text(pDX, IDC_EDIT_CELL_ROW, m_nCellRow);
	DDX_Text(pDX, IDC_EDIT_CELL_TOT, m_nCellTot);
	DDX_Check(pDX, IDC_CHECK1, m_bUsePieceDisable);
	DDX_Text(pDX, IDC_EDIT_CELL_DEL_COL, m_nCellDelCol);
	DDX_Text(pDX, IDC_EDIT_CELL_DEL_ROW, m_nCellDelRow);
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
	ON_BN_CLICKED(IDC_BUTTON_FILE_LOAD, OnButtonFileLoad)
	ON_BN_CLICKED(IDC_BUTTON_FILE_SAVE, OnButtonFileSave)
	ON_BN_CLICKED(IDC_BUTTON_FILE_VIEW, OnButtonFileView)
	ON_BN_CLICKED(IDC_BUTTON_ENABLE_ALL, OnButtonEnableAll)
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

		for(int cell = 1; cell <= m_nCellTot; cell++) //test  display
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

	return TRUE;
}

int CACE400PieceDisableDlg::InitView() 
{

	UpdateData(TRUE);


	int nLine1, nLine2;

	FileSysInfo01.LoadSaveView01(DATA_LOAD);		// Load	SysInfoView01.m_pStrFileBDLName
	FileSysInfo01.LoadSaveSub13(DATA_LOAD);			// Load Block.ini
    FileSysInfo01.LoadSaveSub25(DATA_LOAD); 		// Load Piece.ini	
	FileSysInfo01.LoadSaveSub19(DATA_LOAD,1);		// 기존  BlockDis.ini 를 Load (기존 data를 활용해서 새 BlockDis.ini를 만들어야)

 	
	m_nDisPMaxX=545;   
	m_nDisPMaxY=510;   

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



	// 화면에 그려지는 모양 데이터를 설정
	DisplayNo();

	UpdateData(FALSE);

	return TRUE;
}


// 화면에 그려지는 모양인 m_waDisCell[][][]에 block, piece 번호등의 번호를 설정.
int CACE400PieceDisableDlg::DisplayNo()  
{	

 
	int posCol,posRow;

	::ZeroMemory(m_waDisCell, sizeof(m_waDisCell)); 
	::ZeroMemory(m_waDisBlock,sizeof(m_waDisBlock));
	::ZeroMemory(m_waDisPiece,sizeof(m_waDisPiece));

  

	//--------------------------------------------------
	// block map read
	posCol=posRow=0;

	int blockRow, blockCol;
	for(blockRow=1;   blockRow <= m_nBlockRow;  blockRow++)
	{	
		for(blockCol=1;   blockCol <= m_nBlockCol;  blockCol++)
			m_waDisBlock[blockRow][blockCol] = SysInfo03.m_nData[blockRow-1][blockCol-1];
	}

	//--------------------------------------------------
	// PIECE map read
	posCol=posRow=0;


	int pieceRow, pieceCol;
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
	
     if(m_nCellCol<=2 && m_nCellRow<=2){ //sylee140115 
        nFontW=100;nFontS=10;
	}else if(m_nCellCol<=4 && m_nCellRow<=4){
        nFontW=100;nFontS=20; 
	}else if(m_nCellCol<=5 && m_nCellRow<=10){
        nFontW=100;nFontS=30; 
	}else if(m_nCellCol<=8 && m_nCellRow<=15){
        nFontW=100;nFontS=40; 
	}else if(m_nCellCol<=10 && m_nCellRow<=20){
        nFontW=100;nFontS=50; 
	}else if(m_nCellCol<=12 && m_nCellRow<=25){
        nFontW=100;nFontS=60; 
	}else if(m_nCellCol<=14 && m_nCellRow<=30){
        nFontW=100;nFontS=70; 
	}else if(m_nCellCol<=16 && m_nCellRow<=35){
        nFontW=100;nFontS=80; 
	}else if(m_nCellCol<=18 && m_nCellRow<=40){
        nFontW=100;nFontS=130;  
	}else if(m_nCellCol<=25 && m_nCellRow<=45){
        nFontW=100;nFontS=140; 
	}else if(m_nCellCol<=30 && m_nCellRow<=50){
        nFontW=100;nFontS=150; 
	}else{
        nFontW=100;nFontS=160; 
	}

 
	LOGFONT lf;
	lf.lfHeight			= MulDiv(9, pDC->GetDeviceCaps(LOGPIXELSY), nFontS);
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

 	int row, col, block,piece;
	int nBlockMaxXTotal,  nBlockMaxYTotal;
	nBlockMaxXTotal = m_nBlockCol * m_nPieceCol - SysInfo25.m_nColDel;  ///*******
    nBlockMaxYTotal = m_nBlockRow * m_nPieceRow - SysInfo25.m_nRowDel;  ///*******
	row   = ((nCell - 1) / (nBlockMaxXTotal)); // 몫    
	col   = nCell - (nBlockMaxXTotal * row);   // 나머지
	row   = row + 1;
	block = m_waDisCell[row][col][0];	
	piece = m_waDisCell[row][col][1];	

	if (SysInfo19.m_nData[block][piece] == CELL_DISABLE)
      	//bkColor = RGB(20,240,1120);     // DISABLE???	  
    	bkColor = RGB(0,110,110);		// DARK GREEN
	else
		//bkColor=RGB(0,0,0);  //BLACK 
		bkColor=RGB(255,255,255);  // WHITE


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
		 strMsg.Format("%d-%d",    m_waDisCell[row][col][0],  m_waDisCell[row][col][1]  );//SYLEE120901
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


// Cell 클릭시에 해당 Cell을 Disable하기 위함
void CACE400PieceDisableDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	//ToggleDisable(point);
	
	CDialog::OnLButtonDown(nFlags, point);
}

void CACE400PieceDisableDlg::OnButtonFileLoad() 
{
	// TODO: Add your control notification handler code here
	InitView();
	
}

void CACE400PieceDisableDlg::OnButtonFileSave() 
{
	// TODO: Add your control notification handler code here
	
	SysInfo19.m_nCellRow = m_nCellRow;
	SysInfo19.m_nCellCol = m_nCellCol; 
    SysInfo19.m_nCellTotal = m_nCellTot;
//	SysInfo19.m_nType = 1;
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
}
