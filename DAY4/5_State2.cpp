#include <iostream>

// ��� 1. item �� ������ ���� ��� ���
// => ��� ���� �Լ��� ����� �־�� �Ѵ�.
// => ���ο� �������� �߰��Ǹ� ��� ���� �Լ��� �����ؾ� �Ѵ�.

class Charater
{
	int gold;
	int item;
public:
	void run()
	{
		if (item == 1)
			std::cout << "run" << std::endl;

		else if (item == 2)
			std::cout << "fast run" << std::endl;
	}


	void attack() { std::cout << "attack" << std::endl; }
};


int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();
}



