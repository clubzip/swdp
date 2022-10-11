#include <iostream>
#include <vector>

// 핵심 3. 모든 파생 클래스(도형)의 공통의 특징은 "반드시 기반 클래스" 에도 
//        있어야 합니다.
//        => 그래야, 기반 클래스 타입으로 묶어서 관리할때 해당 특징을 사용가능합니다.


// 핵심 4. 기반 클래스의 멤버 함수중 파생 클래스가 재정의 하게 되는 것은
//		  반드시 가상함수로 만들어야 합니다.


class Shape
{
	int color;
public:
	// 아래 2개의 멤버함수는 "virtual" 로 할까요 ? "non-virtual"로 할까요 ?
	// => 파생 클래스가 재정의 할 필요 없습니다. "non-virtual"
	void SetColor(int c) { color = c; }
	int  GetColor() const { return color; }

	// 면적을 구하는 방법은 모든 도형이 다릅니다.
	// => "virtual" 로 만들고, 파생 클래스가 재정의 할수 있게.. 
	virtual int GetArea() const  { return -1; }


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

