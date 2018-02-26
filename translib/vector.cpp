/**
*	\author Marian Ferenz
*
*/
#include "stdafx.h"
#include "vector.h"
#include "math.h"

/**
*	Inicjalizacja z wyzerowaniem sk³adowych wektora
*
*/
Vector::Vector() 
{
	for(int i=0;i<3;i++)
		_buf[i]=0;
};
/**
*	Inicjalizacja z przypisaniem sk³adowym odpowiednich wartoœci
*	\param x sk³adowa w kierunku x;
*	\param y sk³adowa w kierunku y;
*	\param z sk³adowa w kierunku z;
*
*/
Vector::Vector(double x,double y,double z)
{
	_buf[0]=x;
	_buf[1]=y;
	_buf[2]=z;
}
/**
*	Zwraca sumê dwóch wektorów
*	\param v argument operacji
*
*/
Vector Vector::operator+(const Vector& v) const
{
	return Vector(_buf[0]+v[0],_buf[1]+v[1],_buf[2]+v[2]);
}
/**
*	Zwraca ró¿nicê dwóch wektorów
*	\param v argument operacji
*
*/
Vector Vector::operator-(const Vector& v) const
{
	return Vector(_buf[0]-v[0],_buf[1]-v[1],_buf[2]-v[2]);
}
/**
*	Zwraca iloczyn sklarny dwóch wektorów
*	\param v argument operacji
*
*/
double Vector::operator*(const Vector& v) 
{
	return (_buf[0]*v[0] + _buf[1]*v[1] + _buf[2]*v[2]);
}
/**
*	Zwraca i-t¹ sk³adow¹ wektora
*	\param i i-ta sk³adowa
*
*/
double Vector::operator[](int i) const
{
	return  _buf[i];
}
/**
*	Przeskalowuje wektor o liczbê
*	\param a parametr przeskalowania
*
*/
void Vector::Scale(double a)
{
	for(int i=0;i<3;i++)
		_buf[i]*=a;
}
/**
*	Normuje wektor
*	
*
*/
void Vector::Normalize()
{
	Vector tmp=*this;
	for(int i=0;i<3;i++)
	{
		double a=sqrt(tmp*tmp);
		if(a!=0)
		_buf[i]/=a;
	}
}
/**
*	Zwraca iloczyn wektorowy
*	\param a argument operacji
*	\param b argument operacji
*
*/
Vector Vector::VectProduct(const Vector& a,const Vector& b)
{
	return Vector(a[1]*b[2]-a[2]*b[1],a[2]*b[0]-a[0]*b[2],a[0]*b[1]-a[1]*b[0]);
}