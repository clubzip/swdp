#include <iostream>
#include <vector>

// 핵심 3. 모든 파생 클래스(도형)의 공통의 특징은 "반드시 기반 클래스" 에도 
//        있어야 합니다.
//        => 그래야, 기반 클래스 타입으로 묶어서 관리할때 해당 특징을 사용가능합니다.

class Shape
{
public:
	void Draw() { std::cout << "Draw Shape" << std::endl; }
};

class Rect : public Shape
{
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
				p->Draw(); 
		}
	}
}

