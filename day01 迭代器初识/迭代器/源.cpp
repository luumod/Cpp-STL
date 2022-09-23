#include <iostream>
using namespace std;
#define N 10

using Iterator = int*;

Iterator begin(int* arr)
{
	return arr;
}
Iterator end(int* arr)
{
	return arr + N-1;
}
int main()
{
	int arr[N] = { 1,2,3,4,5,6,7,8,9 };

	

	for (Iterator iter = begin(arr); iter != end(arr); iter++)
	{
		cout << *iter << " ";
	}

#if 0
	//1.数组遍历
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	//2. 基于范围的for语句
	for (auto& x : arr)
	{
		cout << x << " ";
	}
	cout << endl;

	//3. 指针访问
	for (int* it = arr; it != arr + sizeof(arr) / sizeof(arr[0]); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
#endif
	return 0;
}
