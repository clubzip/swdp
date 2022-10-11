//1_추상클래스2.cpp
#include <iostream>

// OCP
// 기능 확장에 열려있고(Open, 클래스/모듈이 추가 되더라도)
// 코드 수정에는 닫혀있어야(Close, 기존 코드는 수정되지 않게 )
// 디자인 하라는 원칙(Principle)

// 개방 폐쇄의 법칙(Open Close Principle)

// 객체지향 S/W 설계의 원칙 5가지
// => SRP, OCP, LSP, ISP, DIP  => "SOLID" 원칙

// 강한 결합(tightly coupling )
// => 하나의 클래스가 다른 클래스 사용시, "클래스 이름"을 직접 사용하는 것
// => 교체 불가능한, 경직 된 디자인, OCP 만족 안함.




class Camera
{
public:	
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:	
	void UseCamera(Camera* p)   { p->Take(); }
	void UseCamera(HDCamera* p) { p->Take(); }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc); // ???

}






