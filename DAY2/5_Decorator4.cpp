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

// �Ʒ� 2���� Ŭ������ "���ּ�(SpaceShip)" �� ����� �߰��ϱ� ���� 
// Ŭ������ �Դϴ�. �̷� ���� "Decorator(������)" ��� �մϴ�.

// => �Ϲ������� Decorator�� ������ Ư¡�� �ְ� �˴ϴ�.
// => ��� Ŭ������ ���� ������ Ư¡�� �����ϸ� �����մϴ�.

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