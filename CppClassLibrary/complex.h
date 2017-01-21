#include<iostream>
using namespace std;

class Complex
{
public:
	/* ���캯�� */
	Complex(Complex &a);
	Complex(double r = 0, double i = 0);
	void display();
	/* ��ֵ, ��, �� */
	void set(Complex &a);
	Complex plus(Complex a);
	Complex minus(Complex a);
	Complex plus(double r);
	Complex minus(double r);
	/* ���������� */
	void operator = (Complex a);
	Complex operator + (Complex a);
	Complex operator + (double r);
	Complex operator - (Complex a);
	Complex operator - (double r);
private:
	double real;
	double imag;
};