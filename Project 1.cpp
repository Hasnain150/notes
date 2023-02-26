// Project 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

typedef double* doubleArray;

void linebreak(){
   cout<<endl;
}


void add(doubleArray &A,int &csize,int &maxsize);
void resize(doubleArray &A,int &csize,int &maxsize);
void search(doubleArray &A,int csize);
void display(doubleArray &A,int csize);
void deleteE(doubleArray &A,int &csize);
void size(doubleArray &A,int csize,int maxsize);



int _tmain(int argc, _TCHAR* argv[])
{
	int maxsize=10;
	int csize=0;
	doubleArray aarray=new double [maxsize];
	char cont='y';
	linebreak();
	linebreak();
	linebreak();
	
	 cout<<"YOU CAN PERFORM FOLLOWING ACTIONS"<<endl;
	 linebreak();
	 cout<<"ADD ELEMENTS TO THE ARRAY\nDELETE ELEMENT FROM THE ARRAY\nSEARCH ELEMENTS IN THE ARRAY\nDISPLAY ELEMENTS OF THE ARRAY\nRESIZE THE ARRAY\nCHECKING THE SIZE OF THE ARRAY"<<endl; 	
	do{			
	 linebreak();

a:   cout<<"TYPE 1 TO ADD\nTYPE 2 TO DELETE\nTYPE 3 TO SEARCH\nTYPE 4 TO DISPLAY\nTYPE 5 TO RESIZE\nTYPE 6 FOR SIZE\nTYPE 0 TO TERMINATE THE PROGRAM"<<endl;
	 linebreak();
	 int x;
	 cin>>x;
	 switch(x){
	    case 0:
			system("pause");
			return 0;
		case 1:
			   add(aarray,csize,maxsize);
			   linebreak();
               break;
		case 2:
			deleteE(aarray,csize);
			break;
		case 3:
			search(aarray,csize);
			break;
		case 4:
			display(aarray,csize);
			break;
			
		case 5:
	     	resize(aarray,csize,maxsize);	
			break;

		case 6:
			size(aarray,csize,maxsize);
			break;
			
		default:
		    linebreak();
			cout<<"CHOSED INVALID"<<endl;
			linebreak();
			linebreak();
			goto a;
			break;
				 
	 }
	 linebreak();
	 cout<<"DO YOU WANT TO CONTINUE OR STOP THE PROGRAM"<<endl;
	 cout<<"TYPE Y TO CONTINUE"<<endl;
	 linebreak();
	 cin>>cont;


	}while(cont=='y' || cont=='Y');
	system("pause");
	return 0;
}
void add(doubleArray &A,int &csize,int &maxsize){
	linebreak();
	double value;
	cout<<"ENTER THE VALUE TO ADD "<<endl;
	cin>>value;
	if(csize<maxsize){
		A[csize]=value;
		csize++;
	}
	else{
		linebreak();
		linebreak();
		cout<<"                      ERROR "<<endl;
	    cout<<"ARRAY IS FULL, YOU WANT TO RESIZE THE ARRAY?\nOR STOP THE PROGRAM"<<endl;
        linebreak();
		cout<<"IF YOU WANT TO RESIZE TYPE Y"<<endl;

		char resizeV;
		cin>>resizeV;
		linebreak();
		if(resizeV=='Y' || resizeV=='y'){
			resize(A,csize,maxsize);

		}
	}
	}
void resize(doubleArray & A,int &csize,int &maxsize){
	int newsize;
	cout<<"ENTER THE NEW SIZE OF THE ARRAY "<<endl;
	cin>>newsize;
    linebreak();
	if(maxsize==newsize){
	  cout<<"ARRAY IS ALREADY OF THE SAME SIZE"<<endl;
	  linebreak();
	  return;	  
	}
	else{
	doubleArray p=new double [newsize];
	if(csize>newsize){
		linebreak();
		linebreak();
	  cout<<"THE GIVEN SIZE IS LESS THAN THE CURRENT SIZE\nYOU MIGHT LOSE DATA\nRETURNING";
	  linebreak();
	  return;
	
	}
	for(int i=0;i<csize;i++){
	  p[i]=A[i];
	}
	 delete [] A;
	 A=p;
	 maxsize=newsize;
	}

}

void search(doubleArray &A,int csize){
	linebreak();
	if(csize>0){
	double ssearch;
	cout<<"ENTER THE VALUE TO SEARCH"<<endl;
    cin>>ssearch;
	
    bool found=false;
	for(int i=0;i<csize;i++){
		if(ssearch==A[i]){
			linebreak();
			linebreak();
		  cout<<ssearch <<" FOUND AT INDEX "<<i<<endl;
		  linebreak();
		  found=true;
		  return;
		}
	}
	if(found==false){
	  cout<<"VALUE NOT FOUND"<<endl;
	  linebreak();
	}

	}
	else{
		linebreak();
		cout<<"          CAUTION "<<endl;
		cout<<"       ARRAY IS EMPTY"<<endl;
		linebreak();
	}
}
void display(doubleArray &A,int csize){
	if(csize>0){
	  cout<<"DO YOU WANT TO DISPLAY FULL ARRAY OR SINGLE ELEMENT"<<endl;
	  string disp;
	  cin>>disp;
	  if(disp=="FULL" || disp=="full" || disp=="Full"){
		  linebreak();
	     for(int i=0;i<csize;i++){
			 cout<<A[i]<<" ";
	  }
		 linebreak();
		 linebreak();
	}
	  else if(disp=="SINGLE" || disp=="Single" || disp=="single"){
	      linebreak();
		  cout<<"ENTER THE INDEX OF THE VALUE "<<endl;
          int index;
		  cin>>index;
		  if(index<csize){
		  cout<<A[index]<<endl;
		  linebreak();
		  }
		  else{
			  cout<<"NO ELEMENT PRESENT AT INDEX NO. "<<index<<endl;
			  linebreak();
		  return;
		  }
	  }
	}
	else{
		linebreak();
	  cout<<"ARRAY IS EMPTY "<<endl;
		linebreak();
      
	  return;
	}
}
	 
void deleteE(doubleArray &A,int &csize){
	if(csize>0){
	int valueToDelete;
	cout<<"ENTER THE INDEX OF THE VALUE THAT YOU WANT TO DELETE"<<endl;
	cin>>valueToDelete;
	for(int i=valueToDelete;i<csize;i++){
	      A[i]=A[i+1];	  
	}
	csize=csize-1;
	}
	else{
		linebreak();
		cout<<"ARRAY IS EMPTY\nYOU CAN\'T DELETE ELEMENT"<<endl;
		linebreak();
         return;	    
}
}
void size(doubleArray &A,int csize,int maxsize){
	linebreak();
    cout<<"MAX SIZE OF THE ARRAY IS "<<maxsize<<endl;
	cout<<"CURRENT NO. OF THE ELEMENTS IN THE ARRAY ARE "<<csize<<endl;
	linebreak();
}



