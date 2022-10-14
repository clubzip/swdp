#include <iostream>

// 방법 2. 변하는 것을 가상함수로..
// => 아이템에 따라 변해는 동작 함수는 모두 가상함수로 만든다.

class Charater
{
	int gold;
	int item;
public:
	void run()    { do_run(); }
	void attack() { do_attack(); }

	virtual void do_run()    { std::cout << "run" << std::endl; }
	virtual void do_attack() { std::cout << "attack" << std::endl; }
};
class RedStarItem : public Charater
{
public:
	virtual void do_run() { std::cout << "fast run" << std::endl; }
	virtual void do_attack() { std::cout << "power attack" << std::endl; }
};

int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();

	p = new RedStarItem;	// 아이템 획득
							// 그런데, 이 코드는 기존 캐릭터의 동작 변경이 아닌
							// 동작이 변경된 새로운 캐릭터!!

							// 우리의 목표는 "기존 객체(캐릭터)"가 동작이 변경되는 것
	p->run();
	p->attack();
}



