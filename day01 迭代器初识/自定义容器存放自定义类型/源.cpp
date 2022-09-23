#include <iostream>
#include <string>
using namespace std;

template <class T>
class Vector
{
public:
	Vector(const int& size = 10) :Maxsize(size), cursize(0)
	{
		arr = new T[Maxsize];	//创建并且初始化为0
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

class Sheep
{
public:
	Sheep() = default;
	Sheep(const string& name, const int& age)
		:name(name), age(age)
	{}
	~Sheep() {}

	friend ostream& operator<<(ostream& out, const Sheep& other)
	{
		out << other.name << ":" << other.age << endl;
		return out;
	}
private:
	string name;
	int age;
};
int main()
{	
	Vector<Sheep> a;

	a.push_back(Sheep("喜羊羊", 18));
	a.push_back(Sheep("美羊羊", 19));
	a.push_back(Sheep("懒洋洋", 20));
	a.push_back(Sheep("灰太狼", 21));

	for (Vector<Sheep>::Iterator it = a.begin(); it != a.end(); it++)
	{
		cout << *it << " ";
	}

	return 0;
}