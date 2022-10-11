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
//			Rect rc; // 이렇게 하면 {} 벗어날때 즉시 파괴 됩니다.
			Rect* p = new Rect;
			v.push_back(p);
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
// 빌드하면 에러가 있습니다..
// 왜?? 어디서 에러일까요 ?
// 해결책은 뭘까요 ??
