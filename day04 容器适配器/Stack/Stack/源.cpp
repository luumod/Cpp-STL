#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
using namespace std;


int main()
{
	////stack<int> a = { 1,2,3,4,5 };	//����ֱ�ӳ�ʼ��
	//deque<int> temp{ 1,2,3,4,5,6 };
	//stack<int> a(temp);	//ʹ��deque��ӳ�ʼ��
	//while (!a.empty())
	//{
	//	auto elem = a.top();
	//	cout << elem << " ";
	//	a.pop();
	//}
	//a.push(555);
	//a.pop();

	/*
	ʵ�����ŵ�ƥ���ж�
	*/
	stack<char> a;
	cout << "��������������: ";
	string vair;
	cin >> vair;
	char temp;
	bool isok = true;
	for (auto& x : vair)
	{
		switch (x)
		{
		case '(':
		case '[':
		case '{':
			//��������ջ
			a.push(x);
			break;
		case ')':
			if (!a.empty())
			{
				temp = a.top();
				if (temp != '(') {
					isok = false;
				}
				a.pop();
			}
			break;
		case ']':
			if (!a.empty())
			{
				temp = a.top();
				if (temp != '[') {
					isok = false;
				}
				a.pop();
			}
			break;
		case '}':
			if (!a.empty())
			{
				temp = a.top();
				if (temp != '{') {
					isok = false;
				}
				a.pop();
			}
			break;
		}  
	}
	if (a.empty() && isok)
	{
		cout << "����ƥ�䣡\n";
	}
	else
	{
		cout << "���Ų�ƥ��!\n";
	}
	return 0;
}