#include "prototype.h"
#include "complex2.h"
using namespace std;

/***************
	������
***************/
int main2()
{
	complex2_operation();

	return 0;
}

int complex2_operation(void)
{
	Complex2 a(3, 2), b(5, 4), c(1, 1), d(4, 2), e(2, 2), f(2, 4), temp;
	
	/* ��������Ϊ��Ԫ�������� */
	temp = a + b;
	temp.display();

	temp = a - b;
	temp.display();

	temp = (a + b) - (c + d);
	temp.display();

	temp = a + 1.5;
	temp.display();

	/* �����Լ����������� */
	temp = (e++) + f;
	temp.display();

	temp = f - (++e);
	temp.display();

	e.display();
	return 0;
}