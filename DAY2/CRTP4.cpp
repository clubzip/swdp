#include <iostream>

class Shape
{
public:
	virtual Shape* Clone() const = 0;
};
//=================================================
template<typename T>
class Cloneable : public Shape
{
public:
//	virtual T* Clone() const override //안됩니다.
					// 현재 Clone()은 Clonenable의 멤버인데 Rect*는안됩
	virtual Shape* Clone() const override
	{
		// T=Rect 인 경우를 생각해 봅시다.
		// Shape* p = new Rect(*this) 인데..this 는 Cloneable* 입니다.
		// => Rect(Cloneable) 모양의 생성자가 없으므로 에러!							
		// Shape* p = new T(*this);

		// this 를 clonenable* 가 아닌 Rect*로 변경해서 사용
		// Rect(Rect) 즉, 복사생성자 호출을 기대!! 하지만 에러.. 
		// Shape* p = new T(* static_cast<T*>(this) );
			// => 현재 Clone()은 상수함수 입니다. 상수 멤버함수안에서
			// => this 는 상수를 가리키는 포인터 입니다
			// => const Cloneable* this 
			//  const Cloneable* this  => Rect* 는 static_cast로 안됨

		Shape* p = new T(*static_cast<const T*>(this));
		// const Cloneable* this  => const Rect* 는 ok
			
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