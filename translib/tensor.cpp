/**
*	\author Marian Ferenz
*
*/
#include "stdafx.h"
#include <fstream.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "tensor.h"

/**
*	Inicjalizuje tensor w postaci 6x6,
*	zeruj¹c wszystkie jego wspó³czynniki
*
*/
VoigtTensor::VoigtTensor()
{
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			_buf[i][j]=0;
}

/**
*	Pobiera wspó³czynniki tensora 6x6 z pliku
*	\param fileName nazwa pliku do odczytu
*/
void VoigtTensor::ReadTensor(const char* fileName)
{
	ifstream fin;
	fin.open(fileName,filebuf::text);
	char* strline= new char[256];
	// zaczytanie tensora z pliku
	for(int row=0;row<6;row++)
	{
		fin.getline(strline,255);
		char seps[]=" \t\n";
		char *strval=strtok(strline,seps);
		for(int col=row;col<6;col++)
		{
			double val=strtod(strval,NULL);
			_buf[row][col]=_buf[col][row]=val;
			strval=strtok(NULL,seps);
		}
	}
	delete[] strline;
	fin.close();
}

/**
*	Zapisuje tensor 6x6 do pliku
*	\param fileName nazwa pliku do zapisu
*/
void VoigtTensor::PrintTensor(const char* fileName)
{
	// zapisanie do pliku
	ofstream fout;
	fout.open(fileName);
	fout.precision(4);
	for(int row=0;row<6;row++)
	{
		for(int col=row;col<6;col++)
		{
			double val=_buf[row][col];
			if(fabs(val)<0.0000000000001)
				val=0.0;
			fout<<val<<"\t";
		}
		fout<<endl;
	}
	fout.close();
}

/**
*	Iicjalizacja tensora w postaci 81-elementowej,
*	z wyzerowaniem wspó³czynników
*/
Tensor::Tensor() 
{ 
	for(int i=0;i<81;i++)
		_buf[i]=0;
}

/**
*	Ustawia, zgodnie z notacj¹ Voigta, nr wiersza lub kolumny elementu tensora 6x6
*	w zale¿noœci od pary indeksów ij (ij->row) lub kl (kl->row) tensora Cijkl.
*	Zwraca ustawiony indeks w postaci referencji
*	\param i indeks i lub k postaci 81-elementowej
*	\param j indeks j lub l postaci 81-elementowej
*	\param index indeks row lub col postaci 6x6
*/
void Tensor::SetIndex(int i,int j,int& index)
{
	if(i==0 && j==0)
		index=0;
	else if(i==1 && j==1)
		index=1;
	else if(i==2 && j==2)
		index=2;
	else if((i==0 && j==1)||(i==1 && j==0))
		index=5;
	else if((i==0 && j==2)||(i==2 && j==0))
		index=4;
	else if((i==1 && j==2)||(i==2 && j==1))
		index=3;
}

/**
*	Realizuje rozwiniêcia tensora 6x6 do postaci 81-elementowej
*	\param T tensor w postaci 6x6
*/
void Tensor::SpreadTensor(const VoigtTensor& T)
{
	// rozwiniêcie do postaci 81-elementowej;
	int pos=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				for(int l=0;l<3;l++)
				{
					int row,col;
					// ustawienie wiersza;
					SetIndex(i,j,row);
					// ustawienie kolumny;
					SetIndex(k,l,col);
					// przepisanie do postaci 81 elementowej
					_buf[pos++]=T.GetVal(row,col);
				}
}

/**
*	Przekszta³ca tensor 81-elementowy do postaci 6x6
*	
*/

VoigtTensor Tensor::CurlTensor()
{
	VoigtTensor T;
	int pos=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				for(int l=0;l<3;l++)
				{
					int row,col;
					// ustawienie wiersza;
					SetIndex(i,j,row);
					// ustawienie kolumny;
					SetIndex(k,l,col);
					// przepisanie do postaci 36 elementowej
					if(fabs(_buf[pos])<0.0000000000001)
						_buf[pos]=0.0;
					T.SetVal(row,col,_buf[pos++]);					
				}
	return T;
}

/**
*	Realizuje przekszta³cenie sk³adowych tensora do innego uk³adu wspó³rzêdnych
*	\param A macierz przejœcia pomiêdzy uk³adami wspó³.
*/
void Tensor::Convert(const Matrix& A)
{
	Tensor T=*this;
	int ppos=0;
	for(int ip=0;ip<3;ip++)
		for(int jp=0;jp<3;jp++)
			for(int kp=0;kp<3;kp++)
				for(int lp=0;lp<3;lp++)
				{
					double val=0;
					int pos=0;
					for(int i=0;i<3;i++)
						for(int j=0;j<3;j++)
							for(int k=0;k<3;k++)
								for(int l=0;l<3;l++)
								{
									double Aiip=A.GetElem(i,ip);
									double Ajjp=A.GetElem(j,jp);
									double Akkp=A.GetElem(k,kp);
									double Allp=A.GetElem(l,lp);
									double Tijkl=T.GetVal(pos++);
									val+=Aiip*Ajjp*Akkp*Allp*Tijkl;
								}
					_buf[ppos++]=val;
				}	
}
