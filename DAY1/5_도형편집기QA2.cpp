// 5_����������QA2
#include <iostream>
#include <vector>

// Clone() ���� ������ �ڵ尡 �ݺ��Ǹ�
// 1. ���ø�
// 2. ��ũ�ε� �̰��� ������ ���
//    => ��� ������ ���Ѿ� �ϴ� ��Ģ�� ��ũ��ȭ �մϴ�.

#define DECLARE_SHAPE(classname)				\
	virtual classname* Clone() const override	\
	{                                           \
		classname* p = new classname (*this);   \
		return p;								\
	}




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

	DECLARE_SHAPE(Rect)
};

class Circle : public Shape
{
public:
	virtual void DrawImp() override { std::cout << "Draw Circle" << std::endl; }

	DECLARE_SHAPE(Circle)
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
			std::cout << "���° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->Clone());

		}
	}
}

