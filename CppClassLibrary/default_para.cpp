#include <iostream>
using namespace std;

void create(int n = 100);	// �ں���������ָ��Ĭ�ϲ���

int default_para()
{
	create();
	create(5);
	return (0);
}

void create(int n)
{
	cout << "n = " << n << endl;
}