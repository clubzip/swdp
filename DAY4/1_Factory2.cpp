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

	// �ڽ��� ����� static ��� �Լ��� ���� �����ϰ� ���˴ϴ�.

	static Shape* create() 	{	return new Rect;	}
};

// Rect ��ü�� ����� 2���� ���
// 1. Rect* p1 = new Rect	// 1. ����ڰ� ���� new ���
//							// ��ü ������ �ݵ�� "Ŭ���� �̸�"�� �˾ƾ��մϴ�.
//							// => �ڷᱸ���� Ŭ���� �̸����� �����Ҽ� ����
//							//    �Լ� ���ڷε� ����Ҽ� �����ϴ�
//							// v.push_back("Rect") ó�� ���ڿ��� ������ ����������	
//							// "Rect" ���ڿ��� Rect ��ü ������ �Ҽ� ����.
// 
// 2. Rect* p2 = Rect::create();// 2. static ��� �Լ� ���
								// => �Լ� �ּҸ� �˸� ��ü ��������
								// => �Լ� �ּҴ� �ڷᱸ���� ���� �����ϰ�
								//    �Լ� ���ڷε� ��밡��.


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape*(*)(); // �Լ� ������ Ÿ��

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

	// ���忡 ��ǰ�� ����մϴ�.
	factory.Register(1, &Rect::create);		// Register(1, "Rect")
	factory.Register(2, &Circle::create);	// �ٸ� ���� ��ó�� ���ڿ���ϵ�����

	// ���ο� ������ �߰��Ǹ� ���忡 �߰��� ����� �ؾ� �մϴ�.!!
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




