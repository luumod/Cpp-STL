#include <iostream>
#include <string>
using namespace std;

template <class T>
class Vector
{
public:
	Vector(const int& size = 10) :Maxsize(size), cursize(0)
	{
		arr = new T[Maxsize];	//�������ҳ�ʼ��Ϊ0
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
			//ǰ��++
			return arr++;
		}
		Iterator operator++(int)
		{
			//����++
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
			//ǰ��++
			return arr--;
		}
		Reverse_Iterator operator++(int)
		{
			//����++
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
	����Ӧ�þ��� beign��end����
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
	int cursize;	//��¼��ǰԪ�ظ���
	int Maxsize;	//���Ԫ�ظ���
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

	a.push_back(Sheep("ϲ����", 18));
	a.push_back(Sheep("������", 19));
	a.push_back(Sheep("������", 20));
	a.push_back(Sheep("��̫��", 21));

	for (Vector<Sheep>::Iterator it = a.begin(); it != a.end(); it++)
	{
		cout << *it << " ";
	}

	return 0;
}