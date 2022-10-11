#include <iostream>

class Animal
{
public:
	void cry1() { std::cout << "Animal Cry1" << std::endl; } 

	// virtual function : 함수 호출을 결정할때 컴파일 시간이 아닌
	//					  실행시간에 메모리를 조사후 결정해 달라는 것
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; }
};
class Dog : public Animal
{
public:
	// function override : 기반 클래스 멤버 함수를 파생 클래스가 다시 만드는것
	void cry1() { std::cout << "Dog Cry1" << std::endl; } 

	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; }
};


int main()
{
	Dog d;
	Animal* p = &d; 

	// C++에서 멤버 함수를 호출하는 원리
	// => 컴파일 할때 컴파일러가 결정, 원리는 "포인터 타입" 으로 호출
	// => 장점 : 컴파일 할때 모든것이 결정됨. 실행시 오버헤드가 없다.

	p->cry1(); // Animal Cry
				// call Animal::cry1 으로  컴파일 완료

	// 만약함수가 virtual 이라면
	// => 컴파일 할때 p가 가리키는 메모리를 조사하는 기계어 코드 생성
	// => 실행시 p가 가리키는 객체를 정확히 조사해서 호출
	// => 장점 : 논리적으로 맞는 호출
	//    단점 : 실행시간에 조사해야 하므로 느리다.
	p->cry2(); // Dog Cry
				// 1. p가 가리키는 곳을 조사하는 기계어 생성
				// 2. 조사결과에 따른 호출
}




