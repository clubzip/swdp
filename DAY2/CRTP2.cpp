#include <iostream>

class Shape
{
public:
	virtual Shape* Clone() const = 0;
};

class Rect : public Shape
{
public:
	virtual Shape* Clone() const
	{
		Shape* p = new Rect(*this);
		return p;
	}
};

class Circle : public Shape
{
public:
	virtual Shape* Clone() const
	{
		Shape* p = new Circle(*this);
		return p;
	}
};

int main()
{
	Shape* p = new Rect;
	p->Clone();
}