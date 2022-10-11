#include <iostream>

// C++ 에서 반드시 알아야 하는 규칙
// => 기반 클래스의 소멸자는 "public virtual" 이거나
//    "protected non-virtual" 이어야 한다.

class Base
{
	// 가상함수의 오버헤드(가상함수 테이블)를 없애기 위해서
	// 가끔 소멸자를 "non-virtual" 그리고, "protected"에 놓는 기술이 있습니다.
protected:
	~Base() {}
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};

int main()
{
	Base* p1 = new Derived;
	delete p1;	// error. 소멸자가 protected에 있으므로..

	delete static_cast<Derived*>(p1); // ok..
}
