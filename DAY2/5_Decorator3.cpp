
#include <iostream>



// 객체와 객체에 기능을 추가하는 클래스(Decorator라고 합니다)는
// 공통의 기반 클래스가 필요 하다.

struct Component
{
	virtual void Fire() = 0;
	virtual ~Component() {}
};



class SpaceShip : public Component
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

class LeftMissile : public Component
{
	Component* ship;
public:
	LeftMissile(Component* s) : ship(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Left Missile" << std::endl; 
	}
};

class RightMissile : public Component
{
	Component* ship;
public:
	RightMissile(Component* s) : ship(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Right Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ss;
//	ss.Fire();

	LeftMissile lm(&ss);	// ss에 기능 추가
//	lm.Fire();				

	RightMissile rm(&lm); // 기능이 추가된 객체에 다시 기능 추가						 
	rm.Fire();
}