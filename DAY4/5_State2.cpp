#include <iostream>

// 방법 1. item 의 종류에 따라 제어문 사용
// => 모든 동작 함수에 제어문이 있어야 한다.
// => 새로운 아이템이 추가되면 모든 동작 함수를 수정해야 한다.

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



