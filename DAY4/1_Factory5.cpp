// Factory5 .   2번복사

#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	virtual Shape* clone() const = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
	static Shape* create() { return new Rect; }
	virtual Shape* clone() const override { return new Rect(*this); }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
	static Shape* create() { return new Circle; }
	virtual Shape* clone() const override { return new Circle(*this); }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> prototype_map;

public:
	void Register(int key, Shape* sample)
	{
		prototype_map[key] = sample;
	}

	Shape* Create(int type)
	{
		Shape* p = nullptr;

		if (prototype_map[type] != nullptr)
			p = prototype_map[type]->clone();

		return p;
	}
};
int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// 아래 코드는 공장에 "클래스"를 등록하는 코드 입니다.
	// => 정확히는 "클래스의 객체를 만드는 함수"를 등록
//	factory.Register(1, &Rect::create);	
//	factory.Register(2, &Circle::create);

	// 공장에 클래스가 아닌 객체를 등록해 봅시다.
	Rect* blueRect = new Rect;  // 생성자에서 파란색으로 설정했다고 가정
	Rect* redRect = new Rect;   // 빨간색, 크기 10 
	Circle* redCircle = new Circle;

	// 견본(prototype) 객체를 공장에 등록
	factory.Register(1, blueRect);
	factory.Register(2, redRect);
	factory.Register(3, redCircle);

	// 도전 과제.. 아래 함수도 만들어 보세요
	factory.ShowSample();	// 등록된 모든 견본 제품을 보여주는 함수
							// map 에 등록된 모든 견본에 대해 draw 호출




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




