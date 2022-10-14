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

// 도형을 공장에 자동으로 등록해 주는 클래스
struct AutoRegister
{
	AutoRegister(int key, Shape* (*f)())
	{
		ShapeFactory::getInstance().Register(key, f);
	}
};

// 전역변수의 생성자는 main 함수 보다 먼저 호출됩니다.
// AutoRegister ar(1, &Rect::create); // 


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }
	
	// static 멤버 데이타의 특징을 잘 생각해 보세요
	// => 객체가 없어도 메모리에 놓이게 됩니다.(전역변수와 유사)
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::create);

// 일반 생성자 : Rect 객체를 생성할때 마다 생성자 호출
// 위의 ar생성자 : Rect 클래스에 대해 최초에 단 한번 호출됨.
//               => C# 등의 언어가 가진 "static 생성자" 라는 개념.

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




