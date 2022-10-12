// Decorator - 65 page
#include <iostream>

class SpaceShip // ���� ���༱
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

// ��� : Ŭ������ ����� �߰��ϴ� ��
// ���� : ��ü�� ����� �߰��Ҽ� �ִ�.

class LeftMissile 
{
	SpaceShip* ship; // ������ �Ǵ� ������ �� ���
public:
	LeftMissile(SpaceShip* s) : ship(s) {}

	void Fire()
	{
		ship->Fire() // ���� ����� ����ϰ�
		std::cout << "Fire Left Missile" << std::endl; // ���ο� ����߰�
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm(&ss);	// ss �� lm �� ���� ����� �߰��� �޶�
	lm.Fire();				// 1. ss->Fire()�� ����ϰ�
							// 2. ���ο� ��� ����.

	// �ᱹ lm �� �̹� �����ϴ� ��ü "ss" �� ���ο� ����� �߰��Ѱ� �Դϴ�.
}