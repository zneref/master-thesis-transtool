/**
*	matrix.h : zawiera definicje macierzy 3x3 oraz udostêpnia podstawowe operacje na macierzach
*	(mno¿enie, mno¿enie przez wektor (postaæ jednowierszow¹), odwracanie, transpozycja itp)
*	Ponadto zdefionowano standardow¹ macierz krystalograficzn¹,
*	oraz macierz obrotu
*
*/
#ifndef _MATRIX_H
#define _MATRIX_H

#include "vector.h"

#define PI 3.14159265358979

class Matrix
{
public:
	Matrix();
	void ReadMatrix(const char*);
	double GetElem(int i,int j) const { return _buf[i][j]; };
	void SetElem(int i,int j,double val) { _buf[i][j]=val; };
	double Minor(int row,int col) const;
	virtual Matrix operator*(const Matrix& m) const;
	Vector operator*(const Vector& v) const;
	void MatToVec(Vector& x,Vector& y,Vector& z) const;
	void VecToMat(const Vector& x,const Vector& y,const Vector& z);
	void Transp();
	double Det();
	void TurnOver();
	void Print(const char*);
protected:
	double _buf[3][3];	///>  Przechowuje elementy macierzy 3x3
};

class CrystMatrix : public Matrix
{
public:
	CrystMatrix();
	CrystMatrix(double a,double b,double c,double alpha,double beta,double gamma);
};

class RotateMatrix	: public Matrix
{
public:
	RotateMatrix();
	RotateMatrix(double theta,int axis=2/*==Z*/);
	virtual RotateMatrix operator*(const RotateMatrix& m) const;
private:
	enum {X=0,Y,Z};
};

#endif