#include<iostream>

class Complex2
{
public:
	/* ���캯�� */
	Complex2(Complex2 &a);
	Complex2(double r = 0, double i = 0);
	void display();
	/* ��������Ϊ��Ԫ�������� */
	friend Complex2 operator + (Complex2 a, Complex2 b);
	friend Complex2 operator + (Complex2 a, double r);
	friend Complex2 operator - (Complex2 a, Complex2 b);
	friend Complex2 operator - (Complex2 a, double r);
	/* ++ -- ��������Ϊ��Ԫ�������� */
	friend Complex2& operator ++ (Complex2 &a);		// ǰ ++ ����
	friend Complex2  operator ++ (Complex2 &a, int);	// �� ++ ����
	friend Complex2& operator -- (Complex2 &a);		// ǰ -- ����
	friend Complex2  operator -- (Complex2 &a, int);	// �� -- ����
private:
	double real;
	double imag;
};