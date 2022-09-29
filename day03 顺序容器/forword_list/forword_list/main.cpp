#include <iostream>
#include <algorithm>
#include <functional>
#include <forward_list>
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
	forward_list<int> a{ 1,2,3,4,5,6,7,8,9 };
	forward_list<int> b(a.begin(), a.end());
	forward_list<int> c(10);
	forward_list<int> d(10, -999);


	/*
	元素访问
	*/
	cout << a.front() << endl;

	/*
	forward_list容量
	*/
	cout << a.empty() << endl;
	cout << a.max_size() << endl;
	a.resize(10);
	a.resize(20, -999);

	/*
	forward_list修改
	*/
	a.push_front(666);
	a.pop_front();
	a.emplace_front(55);
	a.emplace_after(a.begin(), 99);	//在where 的下一个位置插入新元素
	a.insert_after(a.begin(), 6666);
	a.erase_after(a.begin());
	a.clear();

	/*
	forward_list其他操作
	*/
	forward_list<int> temp{ 1,2,3,4,5,6 };
	forward_list<int> temp2(temp);
	temp.splice_after(a.begin(),temp2);		//把temp容器插入到a指定的位置，temp容器会被清空！

	for (auto& x : a)
	{
		cout << x << " ";
	}
	cout << endl;
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


	return 0;
}