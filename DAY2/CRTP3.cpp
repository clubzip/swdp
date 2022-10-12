#include <iostream>

class Shape
{
public:
	virtual Shape* Clone() const = 0;
};

// 각 도형을 만들때 Clone()을 만들어야 하는데, 구현이 유사 합니다.
// Clone의 구현을 제공하는 기반 클래스를 설계해 봅시다.
// 아래 "Cloneable" 같은 경우가 CRTP를 사용하는 대표적인 기술입니다.
// => 그런데, 아래 코드는 에러 입니다.
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