#include <iostream>



// 구체적인 카메라를 먼저 만들지 말고,
// 카메라가 지켜야 하는 규칙을 먼저 설계합니다.

// 규칙 : 모든 카메라는 아래 클래스로 부터 상속 받아야 한다.

class ICamera
{
public:
	virtual void Take() = 0;
};

// 아직, 구체적인 카메라는 없지만, 규칙이 있습니다.
// 사용자는 규칙 대로만 사용하면 됩니다.
class People
{
public:
	virtual void UseCamera(ICamera* p) { p->Take(); }
};

// 이제, 모든 카메라들은 반드시 규칙을 지켜야 합니다.

class Camera : public ICamera
{
public:
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};
class UHDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take 4K Picture" << std::endl; }
};
int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc); 

	UHDCamera uhc;
	p.UseCamera(&uhc);

}






