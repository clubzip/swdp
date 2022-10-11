//생성자1.cpp - 3page
#include <iostream>

// 핵심 : 생성자 호출의 원리를 정확히 살펴 봅시다.

// 1. 컴파일러가 "기반 클래스 생성자를 호출" 하는 코드를 Derived 생성자에 추가한것
// ==> 아래 Derived 의 주석 참고.
// 
// 2. 기반클래스(Base) 에 디폴트 생성자가 없다면..
// ==> 반드시 파생 클래스에서 기반 클래스 생성자를 명시적으로 호출하는 코드를 작성해야 합니다.

class Base
{
public:
//	Base()     { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
public:	
	// 사용자가 만든 코드		// 컴파일러가 변경한 코드
//	Derived()				// Derived() : Base()
	Derived() : Base(0)		// <= 사용자가 기반 클래스 생성자를 명시적으로 호출
	{ 
		std::cout << "Derived()" << std::endl; 
	}
//	Derived(int a)			// Derived(int a) : Base()  // 컴파일러는 항상 기반 클래스의 디폴트 생성자 호출 	
	Derived(int a) : Base(a)
	{ 
		std::cout << "Derived(int)" << std::endl; 
	}
	~Derived()		
	{ 
		std::cout << "~Derived()" << std::endl; 
		// 소멸자는 사용자가 만든 코드를 먼저 실행하고
		// 마지막 부분에 컴파일러가 아래 코드 추가
		// ~Base()
	}
};
int main()
{
//	Derived d1;		// call Derived::Derived()
	Derived d2(5);  // call Derived::Derived(int)

}


// github.com/codenuri/hddp

// 1. 프로젝트 버전 설정해야 합니다.
// => 프로젝트 메뉴, DAY1 속성 메뉴 선택
// => 플랫폼 도구집합, windows SDK 버전 설정 하세요
// => "Ctrl + F5" 눌러서 빌드 확인해 보세요.

// 2. 소스 파일을 빌드에서 제외/포함 하는 방법

// 교재
// 1. 디자인 패턴을 이해 하기 위한 C++ 문법 - 2시간
// 2. 다양한 예제로 배우는 디자인 기술
// 3. 디자인 패턴 총정리 - 161page ~
