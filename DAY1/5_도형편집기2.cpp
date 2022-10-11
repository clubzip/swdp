#include <iostream>
#include <vector>

class Shape
{
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
			// 사각형 생성
		}
		else if (cmd == 2)
		{

		}
		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw();
		}
	}

}

