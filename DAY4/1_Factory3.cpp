#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		using CREATOR = Shape * (*)();

	std::map<int, CREATOR> create_map;

public:
	void Register(int key, CREATOR f)
	{
		create_map[key] = f;
	}

	Shape* Create(int type)
	{
		Shape* p = nullptr;

		if (create_map[type] != nullptr)
			p = create_map[type]();

		return p;
	}
};

// ������ ���忡 �ڵ����� ����� �ִ� Ŭ����
struct AutoRegister
{
	AutoRegister(int key, Shape* (*f)())
	{
		ShapeFactory::getInstance().Register(key, f);
	}
};

// ���������� �����ڴ� main �Լ� ���� ���� ȣ��˴ϴ�.
// AutoRegister ar(1, &Rect::create); // 


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }
	
	// static ��� ����Ÿ�� Ư¡�� �� ������ ������
	// => ��ü�� ��� �޸𸮿� ���̰� �˴ϴ�.(���������� ����)
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::create);

// �Ϲ� ������ : Rect ��ü�� �����Ҷ� ���� ������ ȣ��
// ���� ar������ : Rect Ŭ������ ���� ���ʿ� �� �ѹ� ȣ���.
//               => C# ���� �� ���� "static ������" ��� ����.

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
	static AutoRegister ar;
};
AutoRegister Circle::ar(2, &Circle::create);

int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();


	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd > 0 && cmd < 8)
		{
			Shape* p = factory.Create(cmd);

			if (p != nullptr)
				v.push_back(p);
		}

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}




