/**
*	vector.h : zawiera definicje podstawowych operacji na wektorach 3D.
*	
*/
#ifndef _VECTOR_H
#define _VECTOR_H

class Vector
{
public:
	Vector();
	Vector(double x,double y,double z);
	Vector operator+(const Vector& v) const;
	Vector operator-(const Vector& v) const;
	double operator*(const Vector& v); 
	double operator[](int i) const;
	void Scale(double a);
	void Normalize();
	static Vector VectProduct(const Vector& a,const Vector& b);
private:
	double _buf[3];	///> trzyelementowa tablica przechowuj¹ca wspó³rzêdne wektora
};

#endif