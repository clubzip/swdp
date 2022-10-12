
#include <iostream>



// ��ü�� ��ü�� ����� �߰��ϴ� Ŭ����(Decorator��� �մϴ�)��
// ������ ��� Ŭ������ �ʿ� �ϴ�.

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

	LeftMissile lm(&ss);	// ss�� ��� �߰�
//	lm.Fire();				

	RightMissile rm(&lm); // ����� �߰��� ��ü�� �ٽ� ��� �߰�						 
	rm.Fire();
}