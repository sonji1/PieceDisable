// FileSysInfo.cpp: implementation of the CFileSysInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FileSysInfo.h"
#include <mmsystem.h>



// 글로벌 변수
CFileSysInfo 	FileSysInfo01;
CSysInfoView01  SysInfoView01;
CSysInfo03  	SysInfo03;
CSysInfo25  	SysInfo25;
CSysInfo19  	SysInfo19;


//-------------------------
// class CFileSysInfo 함수
//-------------------------


int CFileSysInfo::LoadSaveView01(int type)
{
	FILE *fp; 
	char  fName[200]; 
	CString ; 
 


	::ZeroMemory(&fName, sizeof(fName));
	strcat( fName , "C:\\ACE400\\SETUP\\FilePathJig.ini" ); //sylee121202
 

	switch(type)
	{
	case DATA_SAVE: // 1
 
 
		fp = fopen(fName,"wt");
		if(fp == NULL){ 
			AfxMessageBox(" Error No 2002 !\n\\SETUP\\FilePathJig.ini.  file Data Saving Error !     file close!", MB_OK); //error messege
			
			return 0;
		}

	
        fprintf(fp, "%s\n",SysInfoView01.m_pStrFileDri1);  //set path file
        fprintf(fp, "%s\n",SysInfoView01.m_pStrFilePath1);  //set path file
		fprintf(fp, "%s\n",SysInfoView01.m_pStrFilePathJig1);  //set path file
		fprintf(fp, "%s\n",SysInfoView01.m_pStrFilePathJig2);  //set path file
		fprintf(fp, "%s\n",SysInfoView01.m_pStrFilePathBDL);  //SYLEE121202
        fprintf(fp, "%s\n",SysInfoView01.m_pStrFileBDLName);  //SYLEE121202	
		
		break;

	case DATA_LOAD: // 2
		fp=fopen(fName,"rt");
		if(fp == NULL){ 
	     	AfxMessageBox(" Error No 2002 !\n\\SETUP\\FilePathJig.ini.  file Data Loading Error", MB_OK); //error messege
    		return 0;
		}
		fscanf(fp, "%s\n", SysInfoView01.m_pStrFileDri1);		
		fscanf(fp, "%s\n", SysInfoView01.m_pStrFilePath1); 
		fscanf(fp, "%s\n", SysInfoView01.m_pStrFilePathJig1);
		fscanf(fp, "%s\n", SysInfoView01.m_pStrFilePathJig2);  //sw loading init folder
        fscanf(fp, "%s\n", SysInfoView01.m_pStrFilePathBDL); //SYLEE121202
		fscanf(fp, "%s\n", SysInfoView01.m_pStrFileBDLName); //SYLEE121202
          		
		break;

	default :
		break;
	}
	fclose(fp); 
	return 1;
}



//for Block.ini <-> SysInfo03
int CFileSysInfo::LoadSaveSub13(int type)
{
 
	int  i,k;
	
	FILE *fp; 
	char  fName[200];  
	CString str; 

    ::ZeroMemory(&fName, sizeof(fName));
 	str.Format("%s", SysInfoView01.m_pStrFilePathBDL);//SYLEE121202
   	strcat( fName ,str);
 	strcat( fName , "\\SETUP2\\Block.ini" );

 // 	strcat( fName , "C:\\ACE300\\SETUP2\\Block.ini" );
 
	
	switch(type)
	{
	case DATA_SAVE: // 1
        // file 삭제 
//		DeleteFile(fName);
		fp = fopen(fName,"wt");
		if(fp == NULL) return 0;


		fprintf(fp, "%10d\n",SysInfo03.m_nBlock);
		fprintf(fp, "%10d\n",SysInfo03.m_nRow);	 
		fprintf(fp, "%10d\n",SysInfo03.m_nCol);
		fprintf(fp, "%10d\n",SysInfo03.m_nType);
       
		for(i=0;i<SysInfo03.m_nRow;i++){
			for(k=0;k<SysInfo03.m_nCol;k++){
			fprintf(fp, "%10d",SysInfo03.m_nData[i][k]);
			}
			fprintf(fp,"\n");
		}
		break;

	case DATA_LOAD: // 2
		fp=fopen(fName,"rt");
		if(fp==NULL) return 0;

			fscanf(fp, "%10d\n", &SysInfo03.m_nBlock);		 
			fscanf(fp, "%10d\n", &SysInfo03.m_nRow);		 
		    fscanf(fp, "%10d\n", &SysInfo03.m_nCol);			  
			fscanf(fp, "%10d\n", &SysInfo03.m_nType);

		for(i=0;i<SysInfo03.m_nRow;i++){
			for(k=0;k<SysInfo03.m_nCol;k++){
				fscanf(fp, "%10d", &SysInfo03.m_nData[i][k]);
			}
		} 
		break;

	default :
		break;
	}
	fclose(fp); 
	return 1;
}




//for Piece.ini <-> SysInfo25
int CFileSysInfo::LoadSaveSub25(int type)
{
 
	int  i,k, nTo1;;
 	FILE *fp; 
	char  fName[200]; 
	CString str; 

    ::ZeroMemory(&fName, sizeof(fName));
 	str.Format("%s", SysInfoView01.m_pStrFilePathBDL);//SYLEE121202
   	strcat( fName ,str);
 	strcat( fName , "\\SETUP2\\Piece.ini" );
 	 
//	strcat( fName , "C:\\ACE300\\SETUP2\\Piece.ini" );
 	
	switch(type)
	{
	case DATA_SAVE: // 1
 
		nTo1=SysInfo25.m_nRow * SysInfo25.m_nCol;
 
		if( Def_MaxPiece1<300){//SYLEE170803
			if(nTo1>200){//SYLEE17032
				  AfxMessageBox("  ERROR 901,  piece  total max 200 over! ", MB_OK);			
				  return 0;
			} 
		}else{
			if(nTo1>300){//SYLEE170803
				  AfxMessageBox("  ERROR 901,  piece  total max 300 over! ", MB_OK);			
				  return 0;
			} 
		}

		fp = fopen(fName,"wt");
		if(fp == NULL) return 0; 

		fprintf(fp, "%10d\n",SysInfo25.m_nBlock);
		fprintf(fp, "%10d\n",SysInfo25.m_nRow);	 
		fprintf(fp, "%10d\n",SysInfo25.m_nCol);
		fprintf(fp, "%10d\n",SysInfo25.m_nType);
       
		for(i=0;i<SysInfo25.m_nRow;i++){
			for(k=0;k<SysInfo25.m_nCol;k++){
			  fprintf(fp, "%10d",SysInfo25.m_nData[i][k]);
			}
			fprintf(fp,"\n");
		}

		fprintf(fp, "%10d\n",SysInfo25.m_nRowDel);	 
		fprintf(fp, "%10d\n",SysInfo25.m_nColDel);

		break;

	case DATA_LOAD: // 2
		fp=fopen(fName,"rt");
		if(fp==NULL) return 0;

			fscanf(fp, "%10d\n", &SysInfo25.m_nBlock);
			fscanf(fp, "%10d\n", &SysInfo25.m_nRow);			 
		    fscanf(fp, "%10d\n", &SysInfo25.m_nCol);		 
			fscanf(fp, "%10d\n", &SysInfo25.m_nType);		 

		for(i=0;i<SysInfo25.m_nRow;i++){
			for(k=0;k<SysInfo25.m_nCol;k++){
				fscanf(fp, "%10d", &SysInfo25.m_nData[i][k]);
			}
		} 

		    fscanf(fp, "%10d\n", &SysInfo25.m_nRowDel);			 
		    fscanf(fp, "%10d\n", &SysInfo25.m_nColDel);


	    nTo1=SysInfo25.m_nRow * SysInfo25.m_nCol;
 
	 
	   if( Def_MaxPiece1<300){//SYLEE170803
			if(nTo1>200){//SYLEE17032
				  AfxMessageBox("  ERROR 901-2,  piece  total max 200 over! ", MB_OK);			
				  SysInfo25.m_nRow=10;
			      SysInfo25.m_nCol=10;
			} 
		}else{
			if(nTo1>300){//SYLEE170803
				  AfxMessageBox("  ERROR 901-2,  piece  total max 300 over! ", MB_OK);			
				  SysInfo25.m_nRow=10;
			      SysInfo25.m_nCol=10;
			} 
		}




		break;

	default :
		break;
	}
	fclose(fp); 
	return 1;
}


// for BlockDis.ini <-> SysInfo19
int CFileSysInfo::LoadSaveSub19(int type, int nFileType)
{

	int  i,k;
	
	FILE *fp; 
	char  fName[200]; 
 	CString str; 

    ::ZeroMemory(&fName, sizeof(fName));
	//SYLEE130601	strcat( fName , "C:\\ACE300\\Setup\\BlockDis.ini" );
 
  	
	if(nFileType==2){
	   strcat( fName , "Z:\\BLOCKDISABLE.TXT" );
	}else{
		str.Format("%s", SysInfoView01.m_pStrFilePathBDL);//SYLEE121202
   		strcat( fName ,str);
  		strcat( fName , "\\SETUP2\\BlockDis.ini" );
	}

	

	switch(type)
	{
	case DATA_SAVE: // 1
        // file 삭제 
		DeleteFile(fName);
		fp = fopen(fName,"wt");
		if(fp == NULL)
		{ 

			SysInfo19.m_nBlockTot=SysInfo03.m_nBlock;//block
			SysInfo19.m_nPieceTot=SysInfo25.m_nBlock;//piece
			SysInfo19.m_nCellTotal=SysInfo19.m_nBlockTot*SysInfo19.m_nPieceTot;
			SysInfo19.m_nType=1;
			SysInfo19.m_nUse=0;
			//FileSysInfo01.LoadSaveSub19(1,1); //save//sylee160203

			fp = fopen(fName,"wt");//sylee160203
			if(fp == NULL){	//sylee160203			
				if(nFileType==2){	         
					AfxMessageBox(" Error No 2218, \n\n\n    Z:\\BLOCKDISABLE.TXT  FILE,  Save Error !!! \n   ");
				}else{
					AfxMessageBox(" Error No 2218, \n\n\n   C:\\ACE300\\BDL\\...\\SETUP2\\BlockDis.ini   FILE,  Save Error !!! \n   ");
				}
			}

			return 0;
		}

		fprintf(fp, "%10d\n",SysInfo19.m_nBlockTot);
		fprintf(fp, "%10d\n",SysInfo19.m_nPieceTot); 
        fprintf(fp, "%10d\n",SysInfo19.m_nCellTotal);
		fprintf(fp, "%10d\n",SysInfo19.m_nType);
        fprintf(fp, "%10d\n",SysInfo19.m_nUse);
 
		if( SysInfo19.m_nUse!=1){
			for(i=1;i<210;i++){//sylee131122
				for(k=1;k<210;k++){
					SysInfo19.m_nData[i][k] =0; 
				}
			}
		}
		for(i=1;i<=SysInfo19.m_nBlockTot;i++){
			for(k=1;k<=SysInfo19.m_nPieceTot;k++){
				if(SysInfo19.m_nData[i][k]!=1){
					SysInfo19.m_nData[i][k]=0;
				}
				fprintf(fp, "%10d",SysInfo19.m_nData[i][k]);
			}
			fprintf(fp,"\n");
		}

		break;





	case DATA_LOAD:	// 2

		fp=fopen(fName,"rt");
		if(fp==NULL){

			SysInfo19.m_nBlockTot=SysInfo03.m_nBlock;//block
			SysInfo19.m_nPieceTot=SysInfo25.m_nBlock;//piece
			SysInfo19.m_nCellTotal=SysInfo19.m_nBlockTot*SysInfo19.m_nPieceTot;
			SysInfo19.m_nType=1;
			SysInfo19.m_nUse=1;

			//FileSysInfo01.LoadSaveSub19(1,1); //save//sylee160203

			fp=fopen(fName,"rt");//sylee160203
			if(fp == NULL){	//sylee160203
				str.Format( "   Error No 2218, \n\n       FILE Loading Error !!!   \n\n     %s \n ",fName ); 
				AfxMessageBox(str);		
			}

				str.Format( "   Error No 2218, \n\n       FILE Loading Error !!!   \n\n     %s \n ",fName ); 
			return 0;
		}

		fscanf(fp, "%10d\n", &SysInfo19.m_nBlockTot);  //block
		fscanf(fp, "%10d\n", &SysInfo19.m_nPieceTot);  //piece

		if((SysInfo19.m_nBlockTot==SysInfo03.m_nBlock)&& (SysInfo19.m_nPieceTot==SysInfo25.m_nBlock))
		{ //piece  //sylee160126-5

			fscanf(fp, "%10d\n", &SysInfo19.m_nCellTotal);
			fscanf(fp, "%10d\n", &SysInfo19.m_nType);
			fscanf(fp, "%10d\n", &SysInfo19.m_nUse);

			SysInfo19.m_nCheck=0;//sylee131117


			for(i=1;i<301;i++){//sylee131122
				for(k=1;k<201;k++){
					SysInfo19.m_nData[i][k] =0; 
				}
			}

			if(SysInfo19.m_nUse==1)
			{//sylee131123
				for(i=1;i<=SysInfo19.m_nBlockTot;i++){
					for(k=1;k<=SysInfo19.m_nPieceTot;k++){
						fscanf(fp, "%10d", &SysInfo19.m_nData[i][k] );		 

						if(SysInfo19.m_nData[i][k]==1){//sylee131117
							SysInfo19.m_nCheck=1;//sylee131117
						}

					}
				} 
			}

	   }
	   else
	   {

		   SysInfo19.m_nBlockTot=SysInfo03.m_nBlock;  //sylee160126-5
		   SysInfo19.m_nPieceTot=SysInfo25.m_nBlock;  //block //sylee160126-5

		   SysInfo19.m_nCellTotal=SysInfo19.m_nBlockTot*SysInfo19.m_nPieceTot; //sylee160126-5
		   SysInfo19.m_nType=1; //sylee160126-5
		   SysInfo19.m_nUse=0; //sylee160126-5

		   SysInfo19.m_nCheck=0;//sylee160126-5

		   for(i=1;i<301;i++){//sylee160126-5
			   for(k=1;k<201;k++){//sylee160126-5
				   SysInfo19.m_nData[i][k] =0; //sylee160126-5
			   }
		   }			  

	   }




	    int nCo1;//sylee170417-1


		if(SysInfo19.m_nUse)
		{
			for( i = 1 ; i <=SysInfo19.m_nBlockTot ; i++) 
			{ 
				nCo1=0;//sylee170417-1
				for( int  k = 1 ; k <=SysInfo19.m_nPieceTot ;  k++) 
				{ 
					if(SysInfo19.m_nData[i][k]==1){
						nCo1++;//sylee170417-1
					}
				}

			/* son 컴파일을 위해서 막음
				if(nCo1==SysInfo19.m_nPieceTot){//sylee170417-1
					nBlockMaxLast1=i-1;//sylee170417-1
				}else{
					nBlockMaxLast1=SysInfo19.m_nBlockTot;//sylee170417-1   nBlockMax
				} 
			*/
			}
		} 
		break;



	default :
		break;
	}

	fclose(fp);
	return 1;
}



//--------------------
// Global 함수
//--------------------


void DoEvents(DWORD dwMilliseconds)
{
	MSG msg;
	if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}
	Sleep(dwMilliseconds);
}

void Delay(UINT delaytime, UINT unit)
{
	// 입력값 측정값 검증
	// 1->7.5~8.5u  2->9u 4->11u 5->12 7->13u 10->17u
	// 100->106u 200->206u 500->506u

	//static LONGLONG FreqQuadPart=0;
	static double FreqQuadPart=0;
	static LARGE_INTEGER Freq, ZeroCnt, CurCnt;

	// 고해상도 타이머의 1초당 진동수 획득
	if(!QueryPerformanceFrequency(&Freq)) return;

	switch(unit)
	{
	case sec:
		FreqQuadPart = (double)Freq.QuadPart;
		break;

	case msec:
		FreqQuadPart = (double)Freq.QuadPart/1000.0;
		break;

	default:
	case usec:		// 1us(micro sec) 당 진동수로 변환
		FreqQuadPart = (double)Freq.QuadPart/1000000.0;
		break;
	}
	
	//---------------------------------------------------
	// ex) delaytime=200, unit=usec(2) 라면
	// 	    200 micro sec 동안 DoEvents()를 반복하여 수행한다.

	QueryPerformanceCounter(&ZeroCnt);	// 시작시점의 counter 값 획득
	do
	{
		DoEvents();
		QueryPerformanceCounter(&CurCnt);	// DoEvents()를 수행한 이후의 counter 값 획득
	}
	while((CurCnt.QuadPart-ZeroCnt.QuadPart)/FreqQuadPart < delaytime);

	TRACE("			Delay(%d %s)\n", delaytime,
						(unit == sec) ? "sec" :
					    (unit == msec) ? "msec":  
					    (unit == usec) ? "usec": "Logic Err?" ) ;
}
	
