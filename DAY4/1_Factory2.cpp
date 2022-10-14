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

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	// 자신을 만드는 static 멤버 함수는 아주 유용하게 사용됩니다.

	static Shape* create() 	{	return new Rect;	}
};

// Rect 객체를 만드는 2가지 방법
// 1. Rect* p1 = new Rect	// 1. 사용자가 직접 new 사용
//							// 객체 생성시 반드시 "클래스 이름"을 알아야합니다.
//							// => 자료구조에 클래스 이름등을 보관할수 없고
//							//    함수 인자로도 사용할수 없습니다
//							// v.push_back("Rect") 처럼 문자열로 보관은 가능하지만	
//							// "Rect" 문자열로 Rect 객체 생성은 할수 없다.
// 
// 2. Rect* p2 = Rect::create();// 2. static 멤버 함수 사용
								// => 함수 주소만 알면 객체 생성가능
								// => 함수 주소는 자료구조에 보관 가능하고
								//    함수 인자로도 사용가능.


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape*(*)(); // 함수 포인터 타입

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
int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// 공장에 제품을 등록합니다.
	factory.Register(1, &Rect::create);		// Register(1, "Rect")
	factory.Register(2, &Circle::create);	// 다른 언어는 위처럼 문자열등록도가능

	// 새로운 도형이 추가되면 공장에 추가로 등록은 해야 합니다.!!
	// factory.Register(3, &Triangle::create);

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




