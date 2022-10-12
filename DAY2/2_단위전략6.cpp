#include <iostream>
#include <vector>
#include <memory> // C++ ǥ�� �޸� �Ҵ��

int main()
{
	// �޸� �Ҵ� ���
	// 1. new / delete �� ���� ���
	// => �޸� �Ҵ� ����� ����(malloc/free������)�ϰ� �;��ٸ�
	//    ��� ������ �����ؾ� �մϴ�.
	int* p1 = new int[10];
	delete[] p1;

	int* p2 = new int[10];
	delete[] p2;


	// 2. allocator ���
	// => �޸� �Ҵ� ����� �����Ϸ��� "�Ҵ��"�� �����ϸ� �ȴ�.
	std::allocator<int> ax;  // C++ ǥ�� �޸� �Ҵ��

	int* p3 = ax.allocate(10); // 10�� �Ҵ�. ǥ�� �Ҵ��� new ���

	ax.deallocate(p3, 10);		// 10�� ����. ǥ�� �Ҵ��� delete ���

}