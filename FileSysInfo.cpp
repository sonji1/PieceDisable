// FileSysInfo.cpp: implementation of the CFileSysInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FileSysInfo.h"


// 글로벌 변수
CFileSysInfo 	FileSysInfo01;
CSysInfoView01  SysInfoView01;
CSysInfo03  	SysInfo03;
CSysInfo25  	SysInfo25;
CSysInfo19  	SysInfo19;



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

			SysInfo19.m_nCellRow=SysInfo03.m_nBlock;//block
			SysInfo19.m_nCellCol=SysInfo25.m_nBlock;//piece
			SysInfo19.m_nCellTotal=SysInfo19.m_nCellRow*SysInfo19.m_nCellCol;
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

		fprintf(fp, "%10d\n",SysInfo19.m_nCellRow);
		fprintf(fp, "%10d\n",SysInfo19.m_nCellCol); 
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
		for(i=1;i<=SysInfo19.m_nCellRow;i++){
			for(k=1;k<=SysInfo19.m_nCellCol;k++){
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

			SysInfo19.m_nCellRow=SysInfo03.m_nBlock;//block
			SysInfo19.m_nCellCol=SysInfo25.m_nBlock;//piece
			SysInfo19.m_nCellTotal=SysInfo19.m_nCellRow*SysInfo19.m_nCellCol;
			SysInfo19.m_nType=1;
			SysInfo19.m_nUse=0;

			//FileSysInfo01.LoadSaveSub19(1,1); //save//sylee160203

			fp=fopen(fName,"rt");//sylee160203
			if(fp == NULL){	//sylee160203
				str.Format( "   Error No 2218, \n\n       FILE Loading Error !!!   \n\n     %s \n ",fName ); 
				AfxMessageBox(str);		
			}

				str.Format( "   Error No 2218, \n\n       FILE Loading Error !!!   \n\n     %s \n ",fName ); 
			return 0;
		}

		fscanf(fp, "%10d\n", &SysInfo19.m_nCellRow);  //block
		fscanf(fp, "%10d\n", &SysInfo19.m_nCellCol);  //piece

		if((SysInfo19.m_nCellRow==SysInfo03.m_nBlock)&& (SysInfo19.m_nCellCol==SysInfo25.m_nBlock))
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
				for(i=1;i<=SysInfo19.m_nCellRow;i++){
					for(k=1;k<=SysInfo19.m_nCellCol;k++){
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

		   SysInfo19.m_nCellRow=SysInfo03.m_nBlock;  //sylee160126-5
		   SysInfo19.m_nCellCol=SysInfo25.m_nBlock;  //block //sylee160126-5

		   SysInfo19.m_nCellTotal=SysInfo19.m_nCellRow*SysInfo19.m_nCellCol; //sylee160126-5
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
			for( i = 1 ; i <=SysInfo19.m_nCellRow ; i++) 
			{ 
				nCo1=0;//sylee170417-1
				for( int  k = 1 ; k <=SysInfo19.m_nCellCol ;  k++) 
				{ 
					if(SysInfo19.m_nData[i][k]==1){
						nCo1++;//sylee170417-1
					}
				}

			/* son 컴파일을 위해서 막음
				if(nCo1==SysInfo19.m_nCellCol){//sylee170417-1
					nBlockMaxLast1=i-1;//sylee170417-1
				}else{
					nBlockMaxLast1=SysInfo19.m_nCellRow;//sylee170417-1   nBlockMax
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
