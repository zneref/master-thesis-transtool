/**
*	\author Marian Ferenz
*
*/
#include "stdafx.h"
#include "vector.h"
#include "math.h"

/**
*	Inicjalizacja z wyzerowaniem sk�adowych wektora
*
*/
Vector::Vector() 
{
	for(int i=0;i<3;i++)
		_buf[i]=0;
};
/**
*	Inicjalizacja z przypisaniem sk�adowym odpowiednich warto�ci
*	\param x sk�adowa w kierunku x;
*	\param y sk�adowa w kierunku y;
*	\param z sk�adowa w kierunku z;
*
*/
Vector::Vector(double x,double y,double z)
{
	_buf[0]=x;
	_buf[1]=y;
	_buf[2]=z;
}
/**
*	Zwraca sum� dw�ch wektor�w
*	\param v argument operacji
*
*/
Vector Vector::operator+(const Vector& v) const
{
	return Vector(_buf[0]+v[0],_buf[1]+v[1],_buf[2]+v[2]);
}
/**
*	Zwraca r�nic� dw�ch wektor�w
*	\param v argument operacji
*
*/
Vector Vector::operator-(const Vector& v) const
{
	return Vector(_buf[0]-v[0],_buf[1]-v[1],_buf[2]-v[2]);
}
/**
*	Zwraca iloczyn sklarny dw�ch wektor�w
*	\param v argument operacji
*
*/
double Vector::operator*(const Vector& v) 
{
	return (_buf[0]*v[0] + _buf[1]*v[1] + _buf[2]*v[2]);
}
/**
*	Zwraca i-t� sk�adow� wektora
*	\param i i-ta sk�adowa
*
*/
double Vector::operator[](int i) const
{
	return  _buf[i];
}
/**
*	Przeskalowuje wektor o liczb�
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