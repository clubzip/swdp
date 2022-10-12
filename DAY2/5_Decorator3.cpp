// Decorator - 65 page
#include <iostream>

class SpaceShip // 우주 비행선
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

class LeftMissile
{
	SpaceShip* ship; 
public:
	LeftMissile(SpaceShip* s) : ship(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Left Missile" << std::endl; 
	}
};

class RightMissile
{
	SpaceShip* ship;
public:
	RightMissile(SpaceShip* s) : ship(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Right Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm(&ss);	
	lm.Fire();				

	RightMissile rm(&ss);
	rm.Fire();
}