// ACE400PieceDisable.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ACE400PieceDisable.h"
#include "ACE400PieceDisableDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CACE400PieceDisableApp

BEGIN_MESSAGE_MAP(CACE400PieceDisableApp, CWinApp)
	//{{AFX_MSG_MAP(CACE400PieceDisableApp)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CACE400PieceDisableApp construction

CACE400PieceDisableApp::CACE400PieceDisableApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CACE400PieceDisableApp object

CACE400PieceDisableApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CACE400PieceDisableApp initialization

BOOL CACE400PieceDisableApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CACE400PieceDisableDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}


