/**
*	\author Marian Ferenz
*
*/
#include "stdafx.h"
#include <fstream.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "matrix.h"

double round(double);
/**
*	Inicjalizacja macierzy z wyzerowaniem poszczególnych elementów
*/
Matrix::Matrix()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			_buf[i][j]=0;
}
/**
*	Inicjalizacja macierzy z pobraniem elementów z pliku
*	\param fileName nazwa pliku do odczytu
*/
void Matrix::ReadMatrix(const char* fileName)
{
	ifstream fin;
	fin.open(fileName,filebuf::text);
	char* strline= new char[256];

	for(int row=0;row<3;row++)
	{
		fin.getline(strline,255);
		char seps[]=" \t\n";
		char *strval=strtok(strline,seps);
		for(int col=0;col<3;col++)
		{
			double val=strtod(strval,NULL);
			_buf[row][col]=val;
			strval=strtok(NULL,seps);
		}
	}
	delete[] strline;
	fin.close();
}

/**
*	Oblicza minor macierzy le¿acy na przeciêciu przekazywanego wiersza i kolumny
*	\param row nr wiersza elementu przecinaj¹cego
*	\param col nr kolumny elementu przecinaj¹cego 	
*/	
double Matrix::Minor(int row,int col) const
{
	int i,j,k,l;
	switch(row)
	{
	case 0:
		i=1;
		j=2;
		break;
	case 1:
		i=0;
		j=2;
		break;
	case 2:
		i=0;
		j=1;
	default:
		break;
	};

	switch(col)
	{
	case 0:
		k=1;
		l=2;
		break;
	case 1:
		k=0;
		l=2;
		break;
	case 2:
		k=0;
		l=1;
	default:
		break;
	};

	return (_buf[i][k]*_buf[j][l] - _buf[i][l]*_buf[j][k]);
}

/**
*	Odwraca macierz
*
*/
void Matrix::TurnOver()
{	
	// stworzenie do obliczen tymczasowej kopii macierzy
	Matrix tmp=*this;
	// obliczanie wyznacznika
	double det=tmp.Det();
	// odwracanie macierzy
	assert(det!=0); // macierz musi byc nieosobliwa
	int swtch=1;
	for(int row=0;row<3;row++)
		for(int col=0;col<3;col++)
		{
			_buf[row][col]=swtch*tmp.Minor(col,row)/det;
			swtch==1 ? swtch=-1 : swtch=1;
		}

}

/**
*	Udostêpnia mno¿enie dwóch macierzy
*	Zwraca macierz
*	\param m macierz do przemno¿enia
*/
Matrix Matrix::operator*(const Matrix& m) const
{
	Matrix M;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			double Mij=0;
			for(int k=0;k<3;k++)
				Mij+=this->GetElem(i,k)*m.GetElem(k,j);
			M.SetElem(i,j,Mij);
		}
	return M;
};

/**
*	Udostêpnia mno¿enie macierz przez wektor
*	Zwraca wektor
*	\param v wektor do przemno¿enia
*/
Vector Matrix::operator*(const Vector& v) const
{
	Matrix tmp=*this;
	tmp.Transp();
	double r[3];
	for(int i=0;i<3;i++)
	{
		double val=0;
		for(int j=0;j<3;j++)
		{
			val+=tmp.GetElem(i,j)*v[j];
		}
		r[i]=val;
	}

	return Vector(r[0],r[1],r[2]);
};

/**
*	Transponuje macierz
*
*/
void Matrix::Transp()
{
	Matrix tmp=*this;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			_buf[i][j]=tmp.GetElem(j,i);
}

/**
*	Oblicza wyznacznik
*
*/
double Matrix::Det()
{
	// stworzenie do obliczen tymczasowej kopii macierzy
	Matrix tmp=*this;
	// obliczanie wyznacznika
	double det=0;
	int swtch=1;
	for(int i=0;i<3;i++)
	{
		double A=tmp.GetElem(0,i);
		double Min=tmp.Minor(0,i);
		det+=swtch*A*Min;
		swtch==1 ? swtch=-1 : swtch=1;
	}
	return det;
}
/**
*	Zapisuje macierz do pliku
*
*/
void Matrix::Print(const char* fname)
{
	ofstream fout;
	fout.precision(3);
	fout.open(fname);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			fout<<_buf[i][j]<<"\t";
		fout<<endl;
	}
	fout.close();
}

void Matrix::MatToVec(Vector& x,Vector& y,Vector& z) const
{
	Matrix tmp=*this;
	x=tmp*Vector(1,0,0);	//tmp*e1
	y=tmp*Vector(0,1,0);	//tmp*e2
	z=tmp*Vector(0,0,1);	//tmp*e3
}

void Matrix::VecToMat(const Vector& x,const Vector& y,const Vector& z)
{
	for(int i=0;i<3;i++)
	{
		_buf[0][i]=x[i];
		_buf[1][i]=y[i];
		_buf[2][i]=z[i];
	}
}
/**
*	Inicjalizacja macierzy krystalograficznej z wyzerowaniem wspó³czynników
*
*/
CrystMatrix::CrystMatrix()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			_buf[i][j]=0;
}

/**
*	Inicjalizacja macierzy krystalograficznej,
*	elementy ustawiane s¹ zgodnie z podanymi wzorami 
*	\param a jednostka osiowa wzd³u¿ X
*	\param b jednostka osiowa wzd³u¿ Y
*	\param c jednostka osiowa wzd³u¿ Z
*	\param alpha k¹t miêdzy YZ
*	\param beta k¹t miêdzy XZ
*	\param gammma k¹t miêdzy XY
*/
CrystMatrix::CrystMatrix(double a,double b,double c,double alpha,double beta,double gamma)
{
	assert(a>0 && b>0 && c>0);
	assert(alpha!=0 && beta!=0 && gamma!=0);
    double rad=PI/180.0;
	alpha*=rad;
	beta*=rad;
	gamma*=rad;
	
	_buf[0][0]=a;
	_buf[0][1]=0;
	_buf[0][2]=0;
	_buf[1][0]=b*round(cos(gamma));
	_buf[1][1]=b*round(sin(gamma));
	_buf[1][2]=0;
	_buf[2][0]=c*round(cos(beta));
	_buf[2][1]=c*(round(cos(alpha))-round(cos(beta))*round(cos(gamma)))/round(sin(gamma));
	_buf[2][2]=c*sqrt(1+2*round(cos(alpha))*round(cos(beta))*round(cos(gamma))-(pow(round(cos(alpha)),2)+pow(round(cos(beta)),2)+pow(round(cos(gamma)),2)))/round(sin(gamma));
};

/**
*	Inicjalizacja macierzy obrotu z ustawieniem elementów na 0
*	
*/
RotateMatrix::RotateMatrix()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			_buf[i][j]=0;
}

/**
*	Inicjalizacja macierzy obrotu z ustawieniem elementów,
*	w zale¿noœci od osi obrotu oraz k¹ta
*	\param theta k¹t obrotu
*	\param axis oœ obrotu
*/
RotateMatrix::RotateMatrix(double theta,int axis)
{
	assert(axis>-1 && axis<3);
	double rad=PI/180.0;
	theta*=rad;
	
	switch(axis)
	{
	case X:
		_buf[0][0]=1;
		_buf[0][1]=0;
		_buf[0][2]=0;
		_buf[1][0]=0;
		_buf[1][1]=round(cos(theta));
		_buf[1][2]=-round(sin(theta));
		_buf[2][0]=0;
		_buf[2][1]=round(sin(theta));
		_buf[2][2]=round(cos(theta));
		break;
	case Y:
		_buf[0][0]=round(cos(theta));
		_buf[0][1]=0;
		_buf[0][2]=round(sin(theta));
		_buf[1][0]=0;
		_buf[1][1]=1;
		_buf[1][2]=0;
		_buf[2][0]=-round(sin(theta));
		_buf[2][1]=0;
		_buf[2][2]=round(cos(theta));
		break;
	case Z:
		_buf[0][0]=round(cos(theta));
		_buf[0][1]=-round(sin(theta));
		_buf[0][2]=0;
		_buf[1][0]=round(sin(theta));
		_buf[1][1]=round(cos(theta));
		_buf[1][2]=0;
		_buf[2][0]=0;
		_buf[2][1]=0;
		_buf[2][2]=1;
		break;
	}
}

RotateMatrix RotateMatrix::operator*(const RotateMatrix& m) const
{
	RotateMatrix M;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			double Mij=0;
			for(int k=0;k<3;k++)
				Mij+=this->GetElem(i,k)*m.GetElem(k,j);
			M.SetElem(i,j,Mij);
		}
	return M;
};

double round(double x)
{
	if(fabs(x)<0.000000000001)
		return 0;
	return x;
}