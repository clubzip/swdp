#include <iostream>

// C++ 에서 반드시 알아야 하는 규칙
// => 기반 클래스의 소멸자는 "public virtual" 이거나
//    "protected non-virtual" 이어야 한다.

class Base
{
public:
	virtual ~Base() {}
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
//	Derived d;

//	Derived* p1 = new Derived;	// 객체 생성 - 생성자 호출
//	delete p1;					// 객체 파괴 - 소멸자 호출

	// 아래 코드가 이 소스의 핵심 입니다. 실행해서 결과 확인해 보세요.
	Base* p1 = new Derived;

	// 소멸자도 함수 호출입니다. 아래 처럼 표기하면
	delete p1;
		// 1. 컴파일러는 p1이 "Base*" 이므로 Base 에서 소멸자가 가상인지 조사
		// => Base 소멸자가 가상함수가 아니면 무조건 포인터 타입으로 호출
		//		~Base() 함수만 호출 

		// => Base 소멸자가 가상함수 라면
		//	  p1가 가리키는 메모리의 객체를 조사하는 코드를 생성하고
		//	  실행시 조사해서 소멸자 호출을 결정
}	
