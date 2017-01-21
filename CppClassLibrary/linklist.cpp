#include <iostream>
#include "linklist.h"
using namespace std;

/******************************************
	��λ current ָ�뵽�������� i �Ľڵ�
******************************************/
bool Linklist::locate(int i)
{
	Node *temp = &head;
	while(temp != NULL)
	{
		// if (temp->read_idata() == i)
		if (temp->idata == i)
		{
			current = temp;
			return true;
		}
		// temp = temp->read_next();
		temp = temp->next;
	}
	return false;
}

/******************************************
	��λ current ָ�뵽�����ַ� c �Ľڵ�
******************************************/
bool Linklist::locate(char c)
{
	Node *temp = &head;
	while(temp != NULL)
	{
		if (temp->read_cdata() == c)
		{
			current = temp;
			return true;
		}
		temp = temp->read_next();
	}
	return false;
}

/*************************************************
	�� current ָ�������½ڵ�(�½� Node ����)
*************************************************/
bool Linklist::insert(int i, char c)
{
	if (current != NULL)
	{
		/* �½ڵ����һ���ڵ�Ϊ current ָ��, �½ڵ����һ���ڵ�Ϊ current ָ�����һ���ڵ� */
		Node *temp = new Node(i, c, current, current->read_next());

		if (current->read_next() != NULL)
		{
			current->read_next()->set_prior(temp);	// ���νڵ����һ���ڵ�Ϊ�½ڵ�
		}
		current->set_next(temp);					// ���νڵ����һ���ڵ�Ϊ�½ڵ�
		return true;
	}
	else
		return false;
}

/**********************************
	ɾ�� current ָ��ָ��Ľڵ�
**********************************/
bool Linklist::remove()
{
	if (current != NULL && current != &head)
	{
		Node *temp = current;
		if (temp->read_next() != NULL)
		{
			temp->read_next()->set_prior(current->read_prior());	// ���νڵ����һ���ڵ�Ϊ��ɾ���ڵ����һ���ڵ�
		}
		temp->read_prior()->set_next(current->read_next());			// ���νڵ����һ���ڵ�Ϊ��ɾ���ڵ����һ���ڵ�
		current = temp->read_prior();								// current ָ��ָ���ɾ���ڵ����һ���ڵ�
		delete temp;
		return true;
	}
	else
		return false;
}

/*********************************
	��ͷ�ڵ㿪ʼ���δ�ӡ���ڵ�
*********************************/
void Linklist::show()
{
	Node *temp = &head;

	while(temp != NULL)
	{
		cout << temp->read_idata() << '\t' << temp->read_cdata() << endl;
		temp = temp->read_next();
	}
}

/*********************************
	ɾ����������(������ͷ�ڵ�)
*********************************/
void Linklist::destroy()
{
	Node *temp = head.read_next();

	while (temp != NULL)
	{
		Node *temp2 = temp->read_next();
		delete temp;
		temp = temp2;
	}
	head.set_next(NULL);
}

/***********************************************
	���캯��
		���ȵ���ð�ź������Ա����Ĺ��캯��
***********************************************/
Linklist::Linklist(int i, char c):head(i, c)
{
	cout << "Linklist Constructor is running" << endl;
	current = &head;
}

/********************************************
	���캯������1 �������캯�� ǳ����
		���ýڵ㿽�����캯������ʼ�� head
********************************************/
// #define	SHALLOW 0xff
#ifdef	SHALLOW

Linklist::Linklist(Linklist &l):head(l.head)
{
	// cout << "Linklist shallow copy ..." << endl;
	current = l.current;
}

/********************************************
	���캯������2 �������캯�� ���
		���ýڵ㿽�����캯������ʼ�� head
********************************************/

#else

Linklist::Linklist(Linklist &l):head(l.head)
{
	// cout << "Linklist deep copy ..." << endl;
	current = &head;				// current ��ָ��ͷ�ڵ�
	Node *temp1 = l.head.next;		// ָ��ԭ������ͷ�ڵ�����Ҫ���ƵĽڵ�, ��Ԫ���ֱ�ӷ���˽�г�Ա����
	while (temp1 != NULL)
	{
		/* �½��ڵ� */
		Node *temp2 = new Node(temp1->read_idata(), temp1->read_cdata(), current, NULL);
		current->set_next(temp2);
		current = current->next;	// current ����ָ��β�ڵ�
		temp1 = temp1->next;
	}
}

#endif

/**************
	��������
**************/
Linklist::~Linklist()
{
	// cout << "Linklist Destructor ..." << endl;
	destroy();
}