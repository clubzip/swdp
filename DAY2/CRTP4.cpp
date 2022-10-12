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
//	virtual T* Clone() const override //�ȵ˴ϴ�.
					// ���� Clone()�� Clonenable�� ����ε� Rect*�¾ȵ�
	virtual Shape* Clone() const override
	{
		// T=Rect �� ��츦 ������ ���ô�.
		// Shape* p = new Rect(*this) �ε�..this �� Cloneable* �Դϴ�.
		// => Rect(Cloneable) ����� �����ڰ� �����Ƿ� ����!							
		// Shape* p = new T(*this);

		// this �� clonenable* �� �ƴ� Rect*�� �����ؼ� ���
		// Rect(Rect) ��, ��������� ȣ���� ���!! ������ ����.. 
		// Shape* p = new T(* static_cast<T*>(this) );
			// => ���� Clone()�� ����Լ� �Դϴ�. ��� ����Լ��ȿ���
			// => this �� ����� ����Ű�� ������ �Դϴ�
			// => const Cloneable* this 
			//  const Cloneable* this  => Rect* �� static_cast�� �ȵ�

		Shape* p = new T(*static_cast<const T*>(this));
		// const Cloneable* this  => const Rect* �� ok
			
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