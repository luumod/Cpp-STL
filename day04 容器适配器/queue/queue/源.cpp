#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
using namespace std;

void travel(const queue<string>& p)
{
	queue<string>* temp=new queue<string>(p);	//����һ����ʱ��ָ�����
	while (!temp->empty())
	{
		cout << temp->front() << "  ";
		temp->pop();
	}
	cout << endl;
	delete temp;
	temp = nullptr;
}
int main()
{
	/*deque<string> temp{ "a","b","c","d","e","f"};
	queue<string> b(temp);
	queue<int> a1(deque<int>{1, 2, 3, 4, 5, 6});
	queue<string> c(b);*/
	//while (!b.empty())
	//{
	//	auto elem = b.front();	//��ȡͷ��Ԫ��
	//	auto elem2 = b.back();	//��ȡβ��Ԫ��
	//	cout << "front: " << elem << "\tback: " << elem2 << endl;
	//	b.pop();
	//}
	/*
	ģ���Ŷӿ�ҽ���Ĺ���
	*/
	queue<string> a;
	string name;
	while (true)
	{
		int choice = 0;
		cout << "1.�Ŷ�  2.��ҽ��  3.�鿴����  0.�°�\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "�����������еĲ�������: ";
			cin >> name;
			a.push(name);
			break;
		case 2:
			if (a.empty()) {
				cout << "û���ŶӵĲ���!\n";
			}
			else {
				cout << "��ǰ����: " << a.front() << endl;
			}
			a.pop();
			break;
		case 3:
			cout << "��ǰ����: ";
			travel(a);
			break;
		case 0:
			cout << "�°��ˣ��벡������������!\n";
			goto end;
			break;
		}
	}
end:;
	return 0;
}