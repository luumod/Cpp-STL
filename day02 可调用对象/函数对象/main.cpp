#include <iostream>
#include <vector>
#include <xstddef>
#include <functional>
#include <algorithm>
using namespace std;

#if 0
/*
普通写法
*/
int equal_count(const vector<int>::iterator& a, const vector<int>::iterator& b,
	const int& val)
{
	int count_num = 0;
	for (auto it = a; it != b; it++)
	{
		if (*it == val)
		{
			count_num++;
		}
	}
	return count_num;
}

int greater_count(const vector<int>::iterator& a, const vector<int>::iterator& b,
	const int& val)
{
	int count_num = 0;
	for (auto it = a; it != b; it++)
	{
		if (*it > val)
		{
			count_num++;
		}
	}
	return count_num;
}

int less_count(const vector<int>::iterator& a, const vector<int>::iterator& b,
	const int& val)
{
	int count_num = 0;
	for (auto it = a; it != b; it++)
	{
		if (*it < val)
		{
			count_num++;
		}
	}
	return count_num;
}

#elif 1
/*
可调用对象
*/
template <class FUN>
int count_if(const vector<int>::iterator& a, const vector<int>::iterator& b,FUN func)
{
	int count_num = 0;
	for (auto it = a; it != b; it++)
	{
		if (func(*it))
		{//传进去的是值
			count_num++;
		}
	}
	return count_num;
}
bool _equal(int a)
{
	return a == 3;
}
bool _greater(int a)
{
	return a > 3;
}
bool _less(int a)
{
	return a < 3;
}

/*
仿函数
*/
struct Equal
{
	int val;
	Equal(const int& val) :val(val) {}
	bool operator()(const int& a)
	{
		return a == val;
	}
};

struct Greater
{
	int val;
	Greater(const int& val) :val(val) {}
	bool operator()(const int& a)
	{
		return a > val;
	}

};

struct Less
{
	int val;
	Less(const int& val) :val(val) {}
	bool operator()(const int& a)
	{
		return a < val;
	}
};
#endif
int main()
{
	vector<int> a{ 1,2,3,4,4,5,6,8,7};
#if 0
	int num1 = equal_count(a.begin(), a.end(), 3);
	cout << "等于3:" << num1 << "个" << endl;
	int num2 = greater_count(a.begin(), a.end(), 3);
	cout << "大于3:" << num2 << "个" << endl;
	int num3 = less_count(a.begin(), a.end(), 3);
	cout << "小于3:" << num3 << "个" << endl;
#elif 0
	/*
	使用函数的调用
	*/
	int num1 = count_if(a.begin(), a.end(), _equal);
	cout << num1 << endl;
	int num2 = count_if(a.begin(), a.end(), _greater);
	cout << num2 << endl;
	int num3 = count_if(a.begin(), a.end(), _less);
	cout << num3 << endl;
#elif 0
	/*
	lambda表达式
	*/
	int num1 = count_if(a.begin(), a.end(), [](const int& data) {return data == 3; });
	cout << num1 << endl;
	int num2 = count_if(a.begin(), a.end(), [](const int& data) {return data > 3; });
	cout << num2 << endl;
	int num3 = count_if(a.begin(), a.end(), [](const int& data) {return data < 3; });
	cout << num3 << endl;

#elif 1
	/*
	仿函数 传递数值的方式
	*/
	Less r(10);	//可以创建对象来调用
	int num1 = count_if(a.begin(), a.end(), Equal(4));
	cout << num1 << endl;
	int num2 = count_if(a.begin(), a.end(), Greater(3));
	cout << num2 << endl;
	int num3 = count_if(a.begin(), a.end(), r);
	cout << num3 << endl;
#endif
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	sort(a.begin(), a.end(),less<int>());
	for (auto& x : a)
	{
		cout << x << " ";
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	return 0;
}