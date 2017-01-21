#include <vector>
#include <iostream>
using namespace std;

int vector_stack_operation(void)
{
	vector<char> mystack(0);
	char temp;

	cout << "input commands: " << endl;
	do
	{
		// cout << temp << endl;
		cin >> temp;
		if (temp != '#')
		{
			if (temp != '$')
				mystack.push_back(temp);
			else
				mystack.pop_back();
		}
	}while (temp != '#');

	for (int i = 0; i < mystack.size(); i++)
	{
		cout << mystack[i];
	}
	cout << endl;
	return 0;
}

/******************************
	δ�������ı���ʧ
	�������޷������ѱ�������
******************************/
int save_undo_reboot(void)
{
	vector<char> stack(0);
	char temp;

	cout << "input: " <<endl;
	do
	{
		cin >> temp;
		if (temp != '#')					// # ��ʾ�������������
		{
			if (temp != '*')
			{
				if (temp != '$')
				{
					stack.push_back(temp);	// δ������δ������δ������Ϊ��������
				}
				else						// 
				{
					if (stack.back()!='%')	// % ��ʾ����
					{
						stack.pop_back();	// $ ��ʾ����
					}
				}
			}
			else							// * ��ʾ����
			{
				while(!stack.empty() && stack.back() != '%')
				{
					stack.pop_back();		// ������ɾ�����ϴα���λ��
				}
			}
		}
	}while (temp != '#');

	if (!stack.empty())
	{
		for (int i = 0; i < stack.size(); i++)
		{
			if (stack[i]!='%')				// ������������
			{
				cout << stack[i];
			}
		}
		cout << endl;
	}
	else
	{
		cout << "Nothing left" <<endl;
	}
	return 0;
}
