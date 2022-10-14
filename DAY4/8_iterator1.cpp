#include <iostream>
#include <list>
#include <vector>

// iterator ����
// => ���հ�ü�� ���� ������ ������� ������ ������� ��� ��Ҹ� ����

int main()
{
	std::list<int> s = { 1,2,3,4,5 };
	std::vector<int> v = { 1,2,3,4,5 };

	auto p1 = s.begin();
	auto p2 = v.begin();

	// p1 �� list �ݺ���
	// p2 �� vector �ݺ���
	// "list �� vector �� �޸� ������ �ٸ�����" 

	// p1, p2 �� ������ ����.!

	// ������ ������� �̵�
	++p1;
	++p2;

	// ������ ������� ��ҿ� ����
	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;

}