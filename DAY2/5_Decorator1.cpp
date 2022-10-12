// Decorator - 65 page
#include <iostream>

class SpaceShip // 우주 비행선
{
public:
	void Fire()	{ std::cout << "Fire Missile" << std::endl; }
};

// 상속을 사용한 기능의 추가
class LeftMissile : public SpaceShip
{
public:
	void Fire()
	{
		SpaceShip::Fire(); // 기존 기능을 사용하고
		std::cout << "Fire Left Missile" << std::endl; // 새로운 기능추가
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm;	// 이 코드는 ss 라는 객체에 기능을 추가하것이 아니라!!
					// 기능이 추가된 새로운 객체를 만든것...!!

					// ss와는 다른 새로운 우주선을 만들것!!

					// 핵심 : "상속" 은 객체가 아닌 클래스에 기능을 추가하는것

	lm.Fire();  // 기존 기능 + 새로운 기능 수행
}