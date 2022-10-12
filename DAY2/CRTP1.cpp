#include <iostream>

// CRTP : Curiosly Recurring Template Pattern
// => C++ IDioms( C++ 진영만의 기술)
// => 기반 클래스 만들때 파생 클래스 이름을 사용할수 있게 하는 기술

template<typename T>
class Base
{
public:
	void foo()
	{
		// 여기서 파생 클래스 이름 사용할수 있을까 ?
		T obj;

		std::cout << typeid(obj).name() << std::endl; // 타입이름 출력
	}
};
// 이제 Base 의 파생 클래스를 만들때 Base의 템플릿 인자로 자신의 이름을 알려주면 됩니다.
class Derived : public Base< Derived >
{
};
int main()
{
	Derived d;
	d.foo();
}