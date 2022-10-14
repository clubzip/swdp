// Factory5 .   2������

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

	// �Ʒ� �ڵ�� ���忡 "Ŭ����"�� ����ϴ� �ڵ� �Դϴ�.
	// => ��Ȯ���� "Ŭ������ ��ü�� ����� �Լ�"�� ���
//	factory.Register(1, &Rect::create);	
//	factory.Register(2, &Circle::create);

	// ���忡 Ŭ������ �ƴ� ��ü�� ����� ���ô�.
	Rect* blueRect = new Rect;  // �����ڿ��� �Ķ������� �����ߴٰ� ����
	Rect* redRect = new Rect;   // ������, ũ�� 10 
	Circle* redCircle = new Circle;

	// �ߺ�(prototype) ��ü�� ���忡 ���
	factory.Register(1, blueRect);
	factory.Register(2, redRect);
	factory.Register(3, redCircle);

	// ���� ����.. �Ʒ� �Լ��� ����� ������
	factory.ShowSample();	// ��ϵ� ��� �ߺ� ��ǰ�� �����ִ� �Լ�
							// map �� ��ϵ� ��� �ߺ��� ���� draw ȣ��




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




