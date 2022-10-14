#include <iostream>

// C++ STL ����� �ƴ�

// �������� ��ü���� ������ ����� ���� ����
// => C#, java, python �� �ݺ���!!
// => �ݺ���(iterator) �� "������(enumerator)" ��� �մϴ�.

int main()
{
	slist<int> s = { 1,2,3,4,5 }; 
	vector<int> v = { 1,2,3,4,5 };

	// ��Ģ 1. ��� �����̳ʿ����� �ݺ��ڸ� ������ �־�� �Ѵ�.
	// => ��� �����̳ʰ� ���Ѿ��ϴ� ��Ģ�� ���� �������̽� �ʿ�
	slist_iterator* p1 = s.get_enumerator(); // list �� �ݺ���
	vector_iterator* p2 = v.get_enumerator(); // vector �ݺ���

	// ��Ģ 2. ��� ������ �ݺ��ڴ� ������ ���ƾ� �մϴ�.
	// => ��� �ݺ��ڰ� ���Ѿ��ϴ� ��Ģ�� ���� �������̽��� �ʿ�
	// list �� vector �� �޸� ������ �ٸ����� p1, p2 �� ������ ���ƾ��մϴ�
	p1->move_next();
	p2->move_next();

	int n1 = p1->get_object(); 
	int n2 = p2->get_object();
}






