#include <iostream>
#include <vector>

// 핵심 5. 다형성(Polymorphism)
//			동일한 표현식이 상황(실제객체)에 따라
//			다르게 동작하는 것(다른 함수 호출)
// 새로운 도형이 추가되어도 "p->Draw()"는 변경될 필요 없다. OCP 만족

class Shape
{
	int color;
public:
	void SetColor(int c) { color = c; }
	int  GetColor() const { return color; }
	
	virtual int GetArea() const { return -1; }
	virtual void Draw() { std::cout << "Draw Shape" << std::endl; }
};

class Rect : public Shape
{
public:
	virtual void Draw() override { std::cout << "Draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	virtual void Draw() override { std::cout << "Draw Circle" << std::endl; }
};

class Triangle : public Shape
{
public:
	virtual void Draw() override { std::cout << "Draw Triangle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw(); // 다형성(Polymorphism)
							// 동일한 표현식이 상황(실제객체)에 따라
							// 다르게 동작하는 것(다른 함수 호출)
							
							// 이 코드는 새로운 도형 클래스가 추가되어도
							// 수정될 필요 없습니다.
							// OCP를 만족하는 좋은 코드 입니다.

			// 객체 지향 언어의 3가지 특징 : 캡슐화, 상속, 다형성
		}
	}
}

