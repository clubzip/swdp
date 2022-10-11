#include <iostream>


// 약한 결합(loosely coupling, 느슨한 결합 )
// => 하나의 클래스가 다른 클래스 사용시, 
//    규칙은 담은 인터페이스(추상클래스)를 사용해서 접근하는것
// => 확장성 있는 유연한 디자인

// 추상 클래스 : 지켜야하는 규칙(순수 가상함수) + 다른 멤버
// 인터 페이스 : 지켜야하는 규칙(순수 가상함수) 만 있는 경우

// C#, java 등에는 "interface" 라는 별도의 키워드가 존재 합니다.
// 하지만 C++ 에서는 "추상 클래스 문법으로 인터페이스도 표현"



// 구체적인 카메라를 먼저 만들지 말고,
// 카메라가 지켜야 하는 규칙을 먼저 설계합니다.

// 규칙 : "모든 카메라는 아래 클래스로 부터 상속 받아야 한다." 라고표현하지말고
//       "모든 카메라는 아래 인터페이스를 구현해야 한다"  라고 표현합니다.

struct ICamera
{
	virtual void Take() = 0;
	virtual ~ICamera() {}	// 인터페이스도 결국 기반 클래스 입니다.
							// 소멸자는 반드시 가상함수로!
};

// DIP( Dependancy Inversion Principle, 의존 관계 역전의 법칙)
// => 구체적인 구현에 의존하지 말고, 추상에 의존해라!!
// => "Camera*" 를 사용하지말고, "ICamera*" 를 사용하라는 의미



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






