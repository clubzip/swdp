#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	int type;

	void SetColor(int c) { color = c; }
	int  GetColor() const { return color; }

	virtual int GetArea() const { return -1; }
	virtual void Draw() { std::cout << "Draw Shape" << std::endl; }
};




class Rect : public Shape
{
public:
	Rect() { type = 1; }
	virtual void Draw() override { std::cout << "Draw Rect" << std::endl; }
};


class Circle : public Shape
{
public:
	Circle() { type = 2; }

	virtual void Draw() override { std::cout << "Draw Circle" << std::endl; }
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
		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;

			// 도형의 종류를 관리하는 타입 변수를 사용해서 조건문으로 조사
			// => C언어 스타일.!!! C 개발시 많이 사용하는 방식
			// => OCP 를 만족하지 못하는 좋지 않은 스타일 입니다.
			if (v[k]->type)
			{
			case 1: v.push_back(new Rect(* static_cast<Rect*>(v[k]))); break;
			case 2: v.push_back(new Circle(*static_cast<Circle*>(v[k]))); break;
			}
		}
	}
}

