#include <iostream>
#include <deque>
using namespace std;

int main()
{
	/*
	���췽ʽ
	*/
	deque<int> me{ 1,2,3,4,5,6 };
	deque<int> a(10);					//10��0Ԫ��
	deque<int> b(10, 99);				//10��99
	deque<int> c(b);					//��������
	deque<int> d(a.begin(), a.end());	//���俽��

	/*
	Ԫ�ط���
	*/
	cout << me[5] << endl;
	//cout << me.at(10) << endl;		//Խ�����
	cout << me.front() << endl;
	cout << me.back() << endl;
	
	/*
	��������
	*/
	cout << a.size() << endl;
	cout << a.max_size() << endl;	//���Դ洢�����Ԫ�ظ���
	a.resize(20);			//�������ô�СΪn
	a.resize(20, -999);	
	a.clear();
	cout << a.empty() << endl;
	a.shrink_to_fit();				//��С�������ʵ���С

	/*
	Ԫ�ص��޸�
	*/
	a.push_back(666);
	a.push_front(-1);			//deque����ͷ��
	a.pop_front();					//deque����ͷɾ
	a.pop_back();

	a.emplace_back(5);
	a.emplace_front(-2);
	a.begin() += 1;
	//assign  insert�ķ�����vector����һ��

	for (auto& x : a)
	{
		cout << x << " ";
	}

	return 0;
}