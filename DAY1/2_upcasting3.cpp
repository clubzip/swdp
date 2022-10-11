#include <iostream>
// upcasting3.cpp
class Animal 
{
public: 
	int age;
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

	Dog* pDog = static_cast<Dog*>(p);
	std::cout << pDog << std::endl;
}

int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}












