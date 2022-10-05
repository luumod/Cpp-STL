#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
using namespace std;


int main()
{
	////stack<int> a = { 1,2,3,4,5 };	//不能直接初始化
	//deque<int> temp{ 1,2,3,4,5,6 };
	//stack<int> a(temp);	//使用deque间接初始化
	//while (!a.empty())
	//{
	//	auto elem = a.top();
	//	cout << elem << " ";
	//	a.pop();
	//}
	//a.push(555);
	//a.pop();

	/*
	实现括号的匹配判断
	*/
	stack<char> a;
	cout << "请输入括号序列: ";
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
			//左括号入栈
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
		cout << "括号匹配！\n";
	}
	else
	{
		cout << "括号不匹配!\n";
	}
	return 0;
}