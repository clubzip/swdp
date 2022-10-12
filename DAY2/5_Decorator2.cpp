// Decorator - 65 page
#include <iostream>

class SpaceShip // 우주 비행선
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

// 상속 : 클래스에 기능을 추가하는 것
// 포함 : 객체에 기능을 추가할수 있다.

class LeftMissile 
{
	SpaceShip* ship; // 포인터 또는 참조로 된 멤버
public:
	LeftMissile(SpaceShip* s) : ship(s) {}

	void Fire()
	{
		ship->Fire() // 기존 기능을 사용하고
		std::cout << "Fire Left Missile" << std::endl; // 새로운 기능추가
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm(&ss);	// ss 에 lm 이 가진 기능을 추가해 달라
	lm.Fire();				// 1. ss->Fire()를 사용하고
							// 2. 새로운 기능 수행.

	// 결국 lm 은 이미 존재하는 객체 "ss" 에 새로운 기능을 추가한것 입니다.
}