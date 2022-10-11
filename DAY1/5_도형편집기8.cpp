#include <iostream>
#include <vector>


// �ٽ� 11. ������ �� ����( ���� ���� )



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

		// �ٽ� 1. ������ ������ OCP �� �����ϵ��� �������� ����Ҽ� ������ ?
		// => "abstract factory" �� �˸� �˴ϴ�. - ����ϳ� ���ϴ�.

		// 2. Undo/Redo ����� �������� ��� �ұ� ??
		// => "command" ������ ���� �˴ϴ�. - ����ϳ� ���ϴ�.

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
			std::cout << "���° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->Clone());	

		}
	}
}

