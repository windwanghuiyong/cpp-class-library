#include "complex2.h"
using namespace std;

/* ���캯�� */
Complex2::Complex2(Complex2 &a)
{
	real = a.real;
	imag = a.imag;
}

/* ���캯������ */
Complex2::Complex2(double r, double i)
{
	real = r;
	imag = i;
}

/* ��ʾ��� */
void Complex2::display()
{
	cout << real << (imag >= 0 ? "+" : "") << imag << "i" << endl;
}

/* ��������Ϊ��Ԫ�������� */
Complex2 operator + (Complex2 a, Complex2 b)
{
	Complex2 temp(a.real + b.real, a.imag + b.imag);
	return temp;
}

Complex2 operator - (Complex2 a, Complex2 b)
{
	Complex2 temp(a.real - b.real, a.imag - b.imag);
	return temp;
}

Complex2 operator + (Complex2 a, double r)
{
	Complex2 temp(a.real + r, a.imag);
	return temp;
}

Complex2 operator - (Complex2 a, double r)
{
	Complex2 temp(a.real - r, a.imag);
	return temp;
}

/* �����Լ����������� */
Complex2& operator ++ (Complex2 &a)	// ǰ
{
	a.real++;
	a.imag++;
	return a;
}
Complex2 operator ++ (Complex2 &a, int)
{
	Complex2 temp(a);
	a.real++;
	a.imag++;
	return temp;
}
Complex2& operator -- (Complex2 &a)
{
	a.real--;
	a.imag--;
	return a;
}
Complex2 operator -- (Complex2 &a, int)
{
	Complex2 temp(a);
	a.real--;
	a.imag--;
	return temp;
}