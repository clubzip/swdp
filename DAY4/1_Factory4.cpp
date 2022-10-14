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

struct AutoRegister
{
	AutoRegister(int key, Shape* (*f)())
	{
		ShapeFactory::getInstance().Register(key, f);
	}
};

// 도형을 만들때 반드시 필요한 코드를 매크로로 제공합니다.

#define DECLARE_SHAPE(classname)						\
	static Shape* create() { return new classname; }	\
	static AutoRegister ar;

#define REGISTER_SHAPE(key, classname)			\
	AutoRegister classname::ar(key, &classname::create);


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	DECLARE_SHAPE(Rect)
};
REGISTER_SHAPE(1, Rect)


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	DECLARE_SHAPE(Circle)
};
REGISTER_SHAPE(2, Circle)


class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }

	DECLARE_SHAPE(Triangle)
};
REGISTER_SHAPE(3, Triangle)



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




