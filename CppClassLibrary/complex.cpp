#include <iostream>
#include "complex.h"
using namespace std;

/* ���캯�� */
Complex::Complex(Complex &a)
{
	real = a.real;
	imag = a.imag;
}

/* ���캯������ */
Complex::Complex(double r, double i)
{
	real = r;
	imag = i;
}

/* ��ʾ��� */
void Complex::display()
{
	cout << real << (imag >= 0 ? "+" : "") << imag << "i" << endl;
}

/* ��ֵ���� */
void Complex::set(Complex &a)
{
	real = a.real;
	imag = a.imag;
}

/* �������� */
Complex Complex::plus(Complex a)
{
	Complex temp(real + a.real, imag + a.imag);
	return temp;
}

Complex Complex::minus(Complex a)
{
	Complex temp(real - a.real, imag - a.imag);
	return temp;
}

Complex Complex::plus(double r)
{
	Complex temp(real + r, imag);
	return temp;
}
Complex Complex::minus(double r)
{
	Complex temp(real - r, imag);
	return temp;
}

/* ���������� */
void Complex::operator = (Complex a)
{
	real = a.real;
	imag = a.imag;
}

Complex Complex::operator + (Complex a)
{
	Complex temp(real + a.real, imag + a.imag);
	return temp;
}

Complex Complex::operator - (Complex a)
{
	Complex temp(real - a.real, imag - a.imag);
	return temp;
}

Complex Complex::operator + (double r)
{
	Complex temp(real + r, imag);
	return temp;
}

Complex Complex::operator - (double r)
{
	Complex temp(real - r, imag);
	return temp;
}
