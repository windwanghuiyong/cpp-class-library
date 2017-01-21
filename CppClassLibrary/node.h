#include <iostream>
using namespace std;

class Node
{
	/* ��Ԫ�� */
	friend class Linklist;
	friend class Stack;
	/* ��Ԫ���� */
	friend void showNode(Node &n);
public:
	/* ��ȡ��Ա���� */
	int		read_idata() const;
	char	read_cdata() const;
	Node	*read_prior() const;
	Node	*read_next() const;
	/* д���Ա���� */
	bool	set_data(int i);		// ���غ���
	bool	set_data(char c);
	bool	set_prior(Node *p);		// ����������ͬ����������
	bool	set_next(Node *n);
	/* ��ʼ������ */
	void	init(int i, char c);
	/* ���캯�� */
	Node();									// ���캯��
	Node(int i, char c = 'x');				// ���캯������1 Ĭ�ϲ���
	Node(int i, char c, Node *p, Node *n);	// ���캯������2
	Node(Node &n);							// ���캯������3 �ڵ㿽��
	/* �������� */
	~Node();
	/* ��̬��Ա���� */
	static int allocation();

private:
	/* ��Ա���� */
	int		idata;
	int		cdata;
	Node	*prior;
	Node	*next;
	/* ��̬��Ա����(˽��) */
	static int cnts;
};
