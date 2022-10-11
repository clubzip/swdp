#include <iostream>
#include <vector>


// 핵심 10. 코드 정리!!

class NotImplemented {};

class Shape
{
	int color;
public:
	virtual ~Shape() {}  // 기반 클래스 이므로 소멸자는 가상함수로!

	void SetColor(int c) { color = c; }
	int  GetColor() const { return color; }


public:
	virtual void Draw() final
	{
		std::cout << "Mutex lock" << std::endl;
		DrawImp();
		std::cout << "Mutex unlock" << std::endl;
	}



protected:
	// 가상함수   : 파생 클래스가 재정의 하지 않으면 "기본 구현 제공" 하겠다는 것
	// 순수가상함수: 파생 클래스에게 반드시 만들라고 지시 하는 것
	virtual void DrawImp() = 0;

public:
	// Clone() 
//	virtual Shape* Clone() const = 0; // 이 코드가 제일 좋습니다.(반드시만들라는것)

	// 아래 코드의 의도!
	// 1. 파생 클래스가 Clone()을 만들지 않고, 사용하지도 않으면 ok
	// 2. 파생 클래스가 Clone()을 만들지 않고, 사용하면 예외
	// 3. 파생 클래스가 Clone()을 만들면, 사용가능!
	virtual Shape* Clone() const 
	{
		throw NotImplemented();
	}

	// GetArea()
	// 순수 가상함수로 해도 되고, 구현되지 않음을 나타내는값(-1) 반환도 가능한 구현
	virtual int GetArea() const  { return -1; }
};

class Rect : public Shape
{
public:
	virtual void DrawImp() override { std::cout << "Draw Rect" << std::endl; }

	// 가상함수 재정의시 "반환 타입 변경" 가능합니다.
	// => 단, 상속 관계의 타입으로 변경해야 합니다.
//	virtual Shape* Clone() const override
	virtual Rect*  Clone() const override
	{
		Rect* p = new Rect(*this);
		return p;
	}
};

// Rect* p1 = new Rect;
// Rect* p2 = p1->Clone(); // 되는게 좋습니다.!!

class Circle : public Shape
{
public:
	virtual void DrawImp() override { std::cout << "Draw Circle" << std::endl; }

	virtual Circle* Clone() const override
	{
		Circle* p = new Circle(*this);
		return p;
	}
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw();
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->Clone());	// 다형성!!!

		}
	}
}

