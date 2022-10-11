// 1_추상클래스1.cpp - 10page

// 추상 클래스 : 순수 가상함수가 한개 있는 있는 클래스
// 특징       : 객체를 생성할수 없다.
// 의도	     : Shape 로 부터 파생된 모든 도형(클래스)는 반드시 
//				Draw()를 만들어야 한다고 지시 하는 것
class Shape
{
public:
	virtual void Draw() = 0;// 순수 가상함수(pure virtual function)
							// 구현부가 없고, "=0" 으로만 표기
};
class Rect : public Shape
{
	// 핵심 : Rect 가 "Draw()"의 구현부를 제공하지 않으면 "추상 클래스" 입니다.
	//       "Draw()" 구현을 제공하면 추상이 아닌, 구체(Concrete) 클래스
	virtual void Draw() override {}
};
int main()
{
//	Shape  s; // error. 추상 클래스는 객체 생성 안됨.
	Shape* p; // ok..   포인터 변수는 가능.
	Rect  r;  // ?
}
