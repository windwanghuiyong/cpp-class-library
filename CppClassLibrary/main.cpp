#include "prototype.h"
#include "complex.h"
#include "undergraduate.h"
#include "stack.h"

#include <iostream>
using namespace std;

/***************
	������
***************/
int main()
{
	stack_operation();

	return 0;
}

/*******************
	ջ��ز���
*******************/
int stack_operation(void)
{
	Stack	mystack;
	int		i, j;
	char	c;

	for (j = 0; j < 3; j++)
	{
		cout << "input an integer and a char: " << endl;
		cin  >> i >> c;
		if (mystack.push(i, c))
			cout << "push success" << endl;
	}
	mystack.show();
	return 0;
}

/*******************
	ѧ����ز���
*******************/
int student_operation(void)
{
	Undergraduate student1;

	student1.set_physical("Tom", 21, 178, 60);
	student1.setGPA(3.75);
	
	cout << student1.get_name()   << endl;
	cout << student1.get_age()    << endl;
	cout << student1.get_height() << endl;
	cout << student1.get_weight() << endl;
	cout << student1.getGPA()     << endl;
	cout << student1.isAdult()    << endl;

	return 0;
}

/*******************
	������ز���
*******************/
int complex_operation(void)
{
	Complex a(3, 2), b(5, 4), c(1, 1), d(4, 2), temp;
	
	/* ��Ա������������ */
	temp.set(a.plus(b));
	temp.display();
	
	temp.set(a.minus(b));
	temp.display();
	
	/* ���������� */
	temp = a + b;
	temp.display();

	temp = a - b;
	temp.display();

	temp = (a + b) - (c + d);
	temp.display();

	temp = a + 1.5;
	temp.display();

	return 0;
}

/*******************
	������ز���
*******************/
int linklist_operation(void)
{
	int		headi;
	char	headc;
	
	/* �û��ӿ� */
	cout << "input data of head node with an integer and a char: " << endl;
	cin  >> headi >> headc;
	
	/* �����������ó�Ա����Ĺ��캯�����г�ʼ�� */
	Linklist mylist(headi, headc);

	/* ��λ current ָ�뵽���� i ���ڽڵ� */
	mylist.locate(headi);

	/* ��̬�����½ڵ㲢���뵽������ */
	mylist.insert(15, 'F');
	mylist.insert(14, 'E');
	mylist.insert(13, 'D');
	mylist.insert(12, 'C');
	mylist.insert(11, 'B');	
	cout << "after insert: " << endl;
	mylist.show();

	/* ��̬��Ա����(�ڵ����) */
	cout << "Node count: " << Node::allocation() << endl;
	
	/* ɾ���ڵ� */
	mylist.locate('D');
	mylist.remove();
	cout << "after delete: " << endl;
	mylist.show();
	
	/* �������� */
	Linklist clonelist(mylist);			//���������캯��, ���� clonelist, ���� mylist ������ clonelist
	cout << "Linklist clonelist: " << endl;
	clonelist.show();
	
	/* ɾ������ */
	mylist.destroy();
	cout << "after destroy: " << endl;
	mylist.show();
	
	// cout << "Linklist clonelist: " << endl;
	// clonelist.show();

	/* �½��ڵ� */
	Node anode;
	cout << "anode count: " << anode.allocation() << endl;
	
	/* ��Ԫ���� */
	Node node1(26, 'Z');
	showNode(node1);

	return 0;
}

/*******************
	�ڵ���ز���
*******************/
int node_operation(void)
{
	Node	my_node;
	Node	&my_node_r = my_node;
	Node	*my_node_p = &my_node;
	
	/* ���캯�� */
	Node	my_node_2(8);
	Node	my_node_3(9, 'F', NULL, NULL);
	
	/* ʹ�ù��캯����ʼ�� */
	cout << my_node.read_idata() << endl;
	cout << my_node.read_cdata() << endl;
	
	/* ��ʼ������ */
	my_node.init(1, 'a');
	cout << my_node.read_idata() << endl;
	cout << my_node.read_cdata() << endl;

	/* ʹ�ó�Ա������ʼ�� */
	my_node.set_data(2);
	my_node.set_data('b');
	cout << my_node.read_idata() << endl;
	cout << my_node.read_cdata() << endl;
	
	/* ���� */
	my_node_r.set_data(3);
	cout << my_node_r.read_idata() << endl;
	
	/* ����ָ�� */
	my_node_p->set_data('c');
	cout << my_node_p->read_cdata() << endl;
	
	/*���ع��캯��*/
	cout << my_node_2.read_idata() << endl;
	cout << my_node_2.read_cdata() << endl;

	cout << my_node_3.read_idata() << endl;
	cout << my_node_3.read_cdata() << endl;

	return 0;
}