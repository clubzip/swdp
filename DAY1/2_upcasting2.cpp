// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};
class Cat : public Animal {};

int main()
{
	// Upcasting 장점 1. 동종을 보관하는 컨테이너 만들때 사용
	std::vector<Dog*>    v1;// Dog 만 보관 가능한 vector
	std::vector<Animal*> v2;// 모든 동물을 보관가능한 vector
							// 동종(동일 기반 클래스를 사용)을 보관하는 컨테이너
}