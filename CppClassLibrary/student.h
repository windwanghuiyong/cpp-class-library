#include <iostream>
using namespace std;

class student
{
public:
	/* ���캯�� */
			student();
			student(char *n, int a, int h, int w);
	/* ��Ա���� */
	void	set_physical(char *n, int a, int h, int w);
	char   *get_name();
	int		get_age();
	int		get_height();
	int		get_weight();
protected:
	char	name[10];
	int		age;
	int		height;
	int		weight;
private:
	int		test;
};