#include <iostream>
// upcasting3.cpp
class Animal 
{
public: 
	int age;
	virtual ~Animal() {} // 대부분의 기반 클래스는 소멸자를 가상으로 하게됩니다.
};
class Cat : public Animal 
{
};
class Dog : public Animal
{
public:
	int color;
};
// upcasting 의 장점 2. 동종을 처리하는 함수 만들기.
//void NewYear(Dog* p)  // Dog 만 받을수 있는 함수
void NewYear(Animal* p) // 모든 동물을 받을수 있는 함수
{
	++(p->age); // 새해가 되면 나이가 증가.
	
	// 세월이 지나서 새로운 요구 사항이 생겼다.
	// p 가 가리키는 것이 Dog 라면 color 도 변경하고 싶다.
//	p->color = 10; // error. p 는 "Animal*" 이므로 color 접근 안됨.

	// static_cast : p가 가리키는 곳이 Dog 가 아니라도 캐스팅에 성공합니다.
	//               이경우 "p->color = 10" 하면 잘못된 실행입니다.
//	Dog* pDog = static_cast<Dog*>(p);
//	std::cout << pDog << std::endl;

	// static_cast 는 "p가 가리키는 것이 Dog라는 확신" 이 있을때만 사용하세요
	// dynamic_cast : p 가 가리키는 곳이 Dog가 아니면 0 반환
	//				  실행시간에 가상함수 테이블을 사용해서 조사하게 됩니다
	//				  => 따라서, 가상함수가 있는 타입만 사용가능합니다.

	Dog* pDog = dynamic_cast<Dog*>(p);
	std::cout << pDog << std::endl;

	if (pDog != nullptr) // 이렇게 확인후 사용
	{
		pDog->color = 10; // 
	}
}

int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}












