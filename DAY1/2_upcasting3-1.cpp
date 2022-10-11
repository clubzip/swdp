#include <iostream>
// upcasting3.cpp
class Animal
{
public:
	int age;
	virtual ~Animal() {} 
};
class Cat : public Animal
{
};
class Dog : public Animal
{
public:
	int color;
};

// 아래 함수의 최초 설계 의도는 "모든 동물의 공통의 특징만 사용" 하겠다는것!
void NewYear(Animal* p)
{
	++(p->age); 
}

// Dog에 대해서 다른 동작이 필요하면 "Dog*" 전용 버전을 따로 설계
void NewYear(Dog* p)
{
	NewYear( static_cast<Animal*>(p) ); // 기존 동작 수행후

	p->color = 10;	// 추가 동작 수행
}


int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}












