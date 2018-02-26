/**
*	tensor.h : definiuje tensor w postaci 6x6 (Voigta) 
*	oraz tensor w postaci rozwiniêtej, 81-elementowej,
*	Zdefioniowano równie¿ m. in. funkcje przejœcia pomiêdzy dwoma postaciami 
*	oraz  transformacji wspó³czynników w ró¿nych uk³adach wspó³rzêdnych
*	
*/
#ifndef _TENSOR_H
#define _TENSOR_H

#include "matrix.h"

class VoigtTensor
{
public:
	VoigtTensor();
	void ReadTensor(const char*); 
	void PrintTensor(const char*); 
	double GetVal(int row,int col) const { return _buf[row][col];}
	void SetVal(int row,int col,double val) {_buf[row][col]=val; }
private:
	double _buf[6][6];	///> przechowuje elementy tensora w postaci macierzy 6x6
};

class Tensor
{
public:
	Tensor();
	void SetIndex(int i,int j,int& index); 
	void Convert(const Matrix&); 
	double GetVal(int pos) const {return _buf[pos]; };
	void SpreadTensor(const VoigtTensor& );
	VoigtTensor CurlTensor();
private:
	double _buf[81];	///> przechowuje elementy tensora w postaci tablicy 81-elementowej
};

#endif