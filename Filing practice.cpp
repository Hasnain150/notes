// Filing practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	{
	fstream f;

	f.open("F:\\data\\abcd.dat",ios::binary | ios::out);
	if(f.is_open()==false){
	   cout<<"ENABLE TO OPEN THE FILE "<<endl;
	}
	int x=20;
	double y=10.0;
	char ch='h';
	f.write((char*)(&x),sizeof(int));
	f.write((char*)(&y),sizeof(double));
	f.write((char*)(&ch),sizeof(char));
	f.close();

	}
	{
	fstream f;
	f.open("F:\\data\\abcd.dat",ios::binary | ios::in);
	if(f.is_open()==false){
	   cout<<"ENABLE TO OPEN THE FILE "<<endl;
	}
	int x;
	double y;
	char ch;
	f.read((char*)(&x),sizeof(int));
	f.read((char*)(&y),sizeof(double));
	f.read((char*)(&ch),sizeof(char));
	f.close();
	}
	system("pause");
	return 0;
}

