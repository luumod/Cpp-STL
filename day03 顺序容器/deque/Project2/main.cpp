#include <iostream>
#include <algorithm>
#include <functional>
#include <list>
using namespace std;


class Foo
{
public:
	bool operator()(const int& data)
	{
		return data % 2 != 0;
	}
};
int main()
{

	/*
	元素构造
	*/
	list<int> a{ 1,2,3,4,5,6,7,8,9 };
	list<int> b(a.begin(), a.end());
	list<int> c(10);
	list<int> d(10,-999);


	/*
	元素访问
	*/
	cout << a.front() << endl;
	cout << a.back() << endl;

	/*
	list容量
	*/
	cout << a.empty() << endl;
	cout << a.size() << endl;
	cout << a.max_size() << endl;
	a.resize(10);
	a.resize(20, -999);

	/*
	list修改
	*/
	a.push_back(999);
	a.push_front(666);
	a.pop_back();
	a.pop_front();


	/*
	list其他操作
	*/
	a.clear();
	list<int> temp{1,2,3,4,5,6};
	list<int> temp2(temp);
	a.splice(a.begin(),temp);		//把temp容器插入到a指定的位置，temp容器会被清空！
	//list的迭代器不具有+-等操作
	a.splice(a.begin(), temp2, --temp2.end());	//将temp2容器的指定位置元素插入到a的指定位置位置

	for (auto& x : a)
	{
		cout << x << " ";
	}
	cout <<endl;
	/*
	remove函数详解
	*/
#if 0
	//删除所有等于val的值的元素
	a.remove(6);		
	//remove_if 删除所有谓词pred中返回true的元素
	//利用lamdba表达式，删除所有偶数元素
	a.remove_if([&](const int& data) {return data % 2 == 0; });	
	//利用仿函数删除奇数
	a.remove_if(Foo());		
	//利用参数绑定，删除所有等于5的元素
	auto NotEqual = bind(equal_to<int>(), placeholders::_1, 5);	
	a.remove_if(NotEqual);
#endif


	list<int> unq{ 1,1,2,3,3,4,4,5,6,6,7,8,8 };
	//unq.unique();			//去重，删除相邻的重复元素
	//unique算法
	auto it=unique(unq.begin(), unq.end(),bind(equal_to<int>(),placeholders::_1,placeholders::_2));
	unq.erase(it, unq.end());
	
	a.sort(less<>());
	unq.merge(a);		//合并两个链表，不是有序递增的则会终止
	unq.sort();
	unq.reverse();
	for (auto& x : unq)
	{
		cout << x << " ";
	}

	return 0;
}