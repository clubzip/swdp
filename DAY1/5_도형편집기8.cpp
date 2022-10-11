#include <iostream>
#include <vector>


// 핵심 11. 생각해 볼 문제( 도전 과제 )



class NotImplemented {};

class Shape
{
	int color;
public:
	virtual ~Shape() {} 

	void SetColor(int c) { color = c; }
	int  GetColor() const { return color; }


public:
	virtual void Draw() final
	{
		std::cout << "Mutex lock" << std::endl;
		DrawImp();
		std::cout << "Mutex unlock" << std::endl;
	}



protected:
	virtual void DrawImp() = 0;

public:
	virtual Shape* Clone() const
	{
		throw NotImplemented();
	}

	virtual int GetArea() const { return -1; }
};

class Rect : public Shape
{
public:
	virtual void DrawImp() override { std::cout << "Draw Rect" << std::endl; }

	virtual Rect* Clone() const override
	{
		Rect* p = new Rect(*this);
		return p;
	}
};

class Circle : public Shape
{
public:
	virtual void DrawImp() override { std::cout << "Draw Circle" << std::endl; }

	virtual Circle* Clone() const override
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

		// 핵심 1. 도형의 생성을 OCP 를 만족하도록 다형성을 사용할수 없을까 ?
		// => "abstract factory" 를 알면 됩니다. - 목요일날 배웁니다.

		// 2. Undo/Redo 기능을 넣으려면 어떻게 할까 ??
		// => "command" 패턴을 배우면 됩니다. - 목요일날 배웁니다.

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

			v.push_back(v[k]->Clone());	

		}
	}
}

