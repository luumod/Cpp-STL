#include <iostream>
#include <deque>
using namespace std;

int main()
{
	/*
	构造方式
	*/
	deque<int> me{ 1,2,3,4,5,6 };
	deque<int> a(10);					//10个0元素
	deque<int> b(10, 99);				//10个99
	deque<int> c(b);					//拷贝构造
	deque<int> d(a.begin(), a.end());	//区间拷贝

	/*
	元素访问
	*/
	cout << me[5] << endl;
	//cout << me.at(10) << endl;		//越界崩溃
	cout << me.front() << endl;
	cout << me.back() << endl;
	
	/*
	管理容量
	*/
	cout << a.size() << endl;
	cout << a.max_size() << endl;	//可以存储的最大元素个数
	a.resize(20);			//重新设置大小为n
	a.resize(20, -999);	
	a.clear();
	cout << a.empty() << endl;
	a.shrink_to_fit();				//减小容量到适当大小

	/*
	元素的修改
	*/
	a.push_back(666);
	a.push_front(-1);			//deque具有头插
	a.pop_front();					//deque具有头删
	a.pop_back();

	a.emplace_back(5);
	a.emplace_front(-2);
	a.begin() += 1;
	//assign  insert的方法与vector基本一致

	for (auto& x : a)
	{
		cout << x << " ";
	}

	return 0;
}