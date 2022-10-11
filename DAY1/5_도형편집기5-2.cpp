#include <iostream>
#include <vector>


// 핵심 6. 리팩토링의 유명한 용어 입니다. 이해해 보세요

//        "Replace conditional with polymorphism"

//		  "제어문(예제5-1) 을 다형성(예제 5-2) 로 변경해라"
//         if 또는 switch 문 대신에 "가상함수"를 먼저 생각하라는 의미






class Shape
{
	int color;
public:
	void SetColor(int c) { color = c; }
	int  GetColor() const { return color; }

	virtual int GetArea() const { return -1; }
	virtual void Draw() { std::cout << "Draw Shape" << std::endl; }

	// 자신의 복사본을 만들수 있는 가상함수는 아주 유용하게 활용됩니다.
	virtual Shape* Clone() const
	{
		// Shape* p = new Shape;
		// p->color = color; // 자신의 모든 멤버를 복사

		Shape* p = new Shape(*this); // 이렇게 하면 위와 동일(복사생성자)
		return p;
	}
};





class Rect : public Shape
{
public:
	virtual void Draw() override { std::cout << "Draw Rect" << std::endl; }

	virtual Shape* Clone() const override 
	{
		Rect* p = new Rect(*this);
		return p;
	}
};

class Circle : public Shape
{
public:
	virtual void Draw() override { std::cout << "Draw Circle" << std::endl; }

	virtual Shape* Clone() const override
	{
		Circle* p = new Circle(*this);
		return p;
	}
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

			// k번째 도형이 어떤 도형인지 조사할 필요 없다.!!
			v.push_back( v[k]->Clone() );	// 다형성!!!
											// 도형이 추가되어도 이 한줄은
											// 변경되지 않는다.
		}
	}
}

