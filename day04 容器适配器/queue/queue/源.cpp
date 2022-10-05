#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
using namespace std;

void travel(const queue<string>& p)
{
	queue<string>* temp=new queue<string>(p);	//创建一个临时的指针对象
	while (!temp->empty())
	{
		cout << temp->front() << "  ";
		temp->pop();
	}
	cout << endl;
	delete temp;
	temp = nullptr;
}
int main()
{
	/*deque<string> temp{ "a","b","c","d","e","f"};
	queue<string> b(temp);
	queue<int> a1(deque<int>{1, 2, 3, 4, 5, 6});
	queue<string> c(b);*/
	//while (!b.empty())
	//{
	//	auto elem = b.front();	//获取头部元素
	//	auto elem2 = b.back();	//获取尾部元素
	//	cout << "front: " << elem << "\tback: " << elem2 << endl;
	//	b.pop();
	//}
	/*
	模拟排队看医生的过程
	*/
	queue<string> a;
	string name;
	while (true)
	{
		int choice = 0;
		cout << "1.排队  2.看医生  3.查看队伍  0.下班\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "请输入加入队列的病人名称: ";
			cin >> name;
			a.push(name);
			break;
		case 2:
			if (a.empty()) {
				cout << "没有排队的病人!\n";
			}
			else {
				cout << "当前病人: " << a.front() << endl;
			}
			a.pop();
			break;
		case 3:
			cout << "当前队伍: ";
			travel(a);
			break;
		case 0:
			cout << "下班了，请病人们明天再来!\n";
			goto end;
			break;
		}
	}
end:;
	return 0;
}