#include <iostream>
#include "node.h"
using namespace std;

int Node::cnts = 0;		// �����˳�ʼ����̬��Ա����

/*******************
	��ȡ��Ա����
*******************/
int Node::read_idata() const
{
	return idata;
}

char Node::read_cdata() const
{
	return cdata;
}

Node *Node::read_prior() const
{
	return prior;
}

Node *Node::read_next() const
{
	return next;
}

/*******************
	д���Ա����
*******************/
bool Node::set_data(int i)
{
	idata = i;
	return true;
}

bool Node::set_data(char c)
{
	cdata = c;
	return true;
}

bool Node::set_prior(Node *p)
{
	prior = p;
	return true;
}

bool Node::set_next(Node *n)
{
	next = n;
	return true;
}

/*****************
	��ʼ������
*****************/
void Node::init(int i, char c)
{
	idata = i;
	cdata = c;
	prior = NULL;
	next  = NULL;
}

/***************
	���캯��
***************/
Node::Node()
{
	// cout << "Node Constructor 0 is runing" << endl;
	idata = 0;
	cdata = '0';
	prior = NULL;
	next  = NULL;

	cnts++;
}

/******************************
	���캯�� ����1 Ĭ�ϲ���
******************************/
Node::Node(int i, char c)
{
	// cout << "Node Constructor 1 is runing" << endl;
	idata = i;
	cdata = c;
	prior = NULL;
	next  = NULL;

	cnts++;
}

/****************************
	���캯�� ����2 ������
****************************/
Node::Node(int i, char c, Node *p, Node *n)
{
	// cout << "Node Constructor 2 is runing" << endl;
	idata = i;
	cdata = c;
	prior = p;
	next  = n;

	cnts++;
}

/**********************************
	���캯�� ����3 �ڵ���󿽱�
**********************************/
Node::Node(Node &n)
{
	/* ���Զ�ȡͬ������˽�г�Ա���� */
	idata = n.idata;
	cdata = n.cdata;
	prior = n.prior;
	next  = n.next;

	cnts++;
}

/****************
	��������
****************/
Node::~Node()
{
	// cout << "Node Destructor ..." << endl;
	
	cnts--;
}

/*******************
	��̬��Ա����
*******************/
int Node::allocation()
{
	return cnts;
}

/****************
	��Ԫ����
****************/
void showNode(Node &n)
{
	/* ��Ԫ�������Է���˽�г�Ա���� */
	cout << n.idata << '\t' << n.read_cdata() << endl;
	// cout << n.idata << '\t' << n.cdata << endl;
}