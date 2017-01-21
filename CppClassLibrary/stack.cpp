#include "stack.h"
using namespace std;

/***************************
	ѹջ
		������β��ӽڵ�
***************************/
bool Stack::push(int i, char c)
{
	while (current->next != NULL)
		current = current->next;
	return insert(i, c);	// ʹ�ø����Ա����ʵ��
}

/*************************
	��ջ
		ɾ������β�ڵ�
*************************/
bool Stack::pop(int &i, char &c)
{
	while (current->next != NULL)
		current = current->next;
	i = current->idata;
	c = current->cdata;
	return remove();
}

/*******************************
	��ʾ����ջͬ��ʾ��������
*******************************/
void Stack::show()
{
	show();
}

/***************
	���캯��
***************/
Stack::Stack()
{
	cout << "Stack constructor ..." << endl;
}

/*****************************************************
	���캯��
		������Ĺ��캯���Ĳ������ݸ�����Ĺ��캯��
*****************************************************/
Stack::Stack(int i, char c):Linklist(i, c)
{
	cout << "Stack constructor with parameters ..." << endl;
}