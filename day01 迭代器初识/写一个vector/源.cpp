#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

template <class T>
class Vector
{
public:
	Vector(const initializer_list<T>& list)
		:Maxsize(list.size()),cursize(0)
	{
		arr = new T[Maxsize]{0};
		for (auto& x : list)
		{
			arr[cursize++] = x;
		}
	}
	Vector(const int& size = 10) :Maxsize(size), cursize(0)
	{
		arr = new T[Maxsize]{0};	//创建并且初始化为0
	}
	~Vector()
	{
		delete[] arr;
	}
	void push_back(const T& data)
	{
		arr[cursize++] = data;
	}
public:
	class Iterator
	{
	public:
		Iterator(T* arr)
			:arr(arr)
		{}
		~Iterator() {}
		Iterator operator++()
		{
			//前置++
			return arr++;
		}
		Iterator operator++(int)
		{
			//后置++
			Iterator iter = *this;
			arr++;
			return iter;
		}
		bool operator!=(const Iterator& other)
		{
			return this->arr != other.arr;
		}
		T operator*()
		{
			return *arr;
		}
	private:
		T* arr;
	};
public:
	class Reverse_Iterator
	{
	public:
		Reverse_Iterator(T* arr)
			:arr(arr)
		{}
		~Reverse_Iterator() {}
		Reverse_Iterator operator++()
		{
			//前置++
			return arr--;
		}
		Reverse_Iterator operator++(int)
		{
			//后置++
			Reverse_Iterator iter = *this;
			arr--;
			return iter;
		}
		bool operator!=(const Reverse_Iterator& other)
		{
			return this->arr != other.arr;
		}
		T operator*()
		{
			return *arr;
		}
	private:
		T* arr;
	};
	/*
	容器应该具有 beign和end方法
	*/
	Iterator begin()const
	{
		return arr;
	}
	Iterator end()const
	{
		return arr + cursize;
	}
	Reverse_Iterator rbegin()const
	{
		return arr + cursize - 1;
	}
	Reverse_Iterator rend()const
	{
		return arr - 1;
	}
private:
	T* arr;
	int cursize;	//记录当前元素个数
	int Maxsize;	//最大元素个数
};

template <class Iterator,class FUN>
void travel(Iterator begin, Iterator end, FUN func)
{
	for (Iterator it = begin; it != end; it++)
	{
		func(*it);
	}
}

void show(int a)
{
	cout << a << " ";
}

int main()
{
	Vector<int> a{ 1,2,3,4,5,6 };

	/*for (Vector<int>::Iterator iter = a.begin(); iter != a.end(); iter++)
	{
		cout << *iter << " ";
	}*/

	travel(a.begin(), a.end(), [](const int& data) {cout << data << " "; });


	return 0;
}