#include <iostream>


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

// 아래 2개의 클래스는 "우주선(SpaceShip)" 에 기능을 추가하기 위한 
// 클래스들 입니다. 이런 것을 "Decorator(포장지)" 라고 합니다.

// => 일반적으로 Decorator는 공통의 특징이 있게 됩니다.
// => 기반 클래스를 만들어서 공통의 특징을 제공하면 편리합니다.

class Decorator : public Component
{
protected:
	Component* ship;
public:
	Decorator(Component* ship) : ship(ship) {}
};

class LeftMissile : public Decorator
{
public:
	LeftMissile(Component* s) : Decorator(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Left Missile" << std::endl;
	}
};

class RightMissile : public Decorator
{
public:
	RightMissile(Component* s) : Decorator(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Right Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ss;
	

	LeftMissile lm(&ss);	
	
	RightMissile rm(&lm); 
	rm.Fire();
}