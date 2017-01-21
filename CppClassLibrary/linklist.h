#include <iostream>
#include "node.h"
using namespace std;

class Linklist
{
public:
	/* ����, ����, ɾ��, ��ʾ, ���� */
	bool	locate(int i);
	bool	locate(char c);
	bool	insert(int i = 0, char c = '0');
	bool	remove();
	void	show();
	void	destroy();
	/* ���캯�� */
	Linklist(int i, char c);	// �����๹�캯��
	Linklist(Linklist &l);		// ���������캯��
	/* �������� */
	~Linklist();

// private:
protected:
	Node	head;
	Node	*current;
};
