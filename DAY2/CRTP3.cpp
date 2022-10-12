#include <iostream>

class Shape
{
public:
	virtual Shape* Clone() const = 0;
};

// �� ������ ���鶧 Clone()�� ������ �ϴµ�, ������ ���� �մϴ�.
// Clone�� ������ �����ϴ� ��� Ŭ������ ������ ���ô�.
// �Ʒ� "Cloneable" ���� ��찡 CRTP�� ����ϴ� ��ǥ���� ����Դϴ�.
// => �׷���, �Ʒ� �ڵ�� ���� �Դϴ�.
template<typename T> 
class Cloneable : public Shape
{
public:
	virtual Shape* Clone() const override 
	{
		Shape* p = new T(*this);
		return p;
	}
};

class Rect : public Cloneable<Rect>
{
};

class Circle : public Cloneable<Circle>
{
};



int main()
{
	Shape* p = new Rect;
	p->Clone();
}