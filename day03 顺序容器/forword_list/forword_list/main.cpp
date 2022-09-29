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
	Ԫ�ع���
	*/
	forward_list<int> a{ 1,2,3,4,5,6,7,8,9 };
	forward_list<int> b(a.begin(), a.end());
	forward_list<int> c(10);
	forward_list<int> d(10, -999);


	/*
	Ԫ�ط���
	*/
	cout << a.front() << endl;

	/*
	forward_list����
	*/
	cout << a.empty() << endl;
	cout << a.max_size() << endl;
	a.resize(10);
	a.resize(20, -999);

	/*
	forward_list�޸�
	*/
	a.push_front(666);
	a.pop_front();
	a.emplace_front(55);
	a.emplace_after(a.begin(), 99);	//��where ����һ��λ�ò�����Ԫ��
	a.insert_after(a.begin(), 6666);
	a.erase_after(a.begin());
	a.clear();

	/*
	forward_list��������
	*/
	forward_list<int> temp{ 1,2,3,4,5,6 };
	forward_list<int> temp2(temp);
	temp.splice_after(a.begin(),temp2);		//��temp�������뵽aָ����λ�ã�temp�����ᱻ��գ�

	for (auto& x : a)
	{
		cout << x << " ";
	}
	cout << endl;
	/*
	remove�������
	*/
#if 0
	//ɾ�����е���val��ֵ��Ԫ��
	a.remove(6);
	//remove_if ɾ������ν��pred�з���true��Ԫ��
	//����lamdba���ʽ��ɾ������ż��Ԫ��
	a.remove_if([&](const int& data) {return data % 2 == 0; });
	//���÷º���ɾ������
	a.remove_if(Foo());
	//���ò����󶨣�ɾ�����е���5��Ԫ��
	auto NotEqual = bind(equal_to<int>(), placeholders::_1, 5);
	a.remove_if(NotEqual);
#endif


	return 0;
}