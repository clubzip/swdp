#include <iostream>
#include <vector>

// 핵심 1. 모든 도형을 타입화 하면 편리하다.
// 
// 핵심 2. 모든 도형의 공통의 기반 클래스가 있다면 
//        모든 도형을 하나의 컨테이너에 묶어서 보관할수 있다.
class Shape
{
};

class Rect : public Shape
{
	// 멤버 데이타와 생성자는 생략....
public:
	void Draw() { std::cout << "Draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void Draw() { std::cout << "Draw Circle" << std::endl; }
};

int main()
{
//	std::vector<Rect*> v; // Rect 만 보관 가능한 vector

	std::vector<Shape*> v; // 모든 도형을 보관할수 있는 vector

}

