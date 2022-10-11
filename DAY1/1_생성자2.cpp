// 1_생성자2-1.cpp
#include <string>
#include <iostream>

class People
{
	std::string name;
	int age;
public:
	// 모든 사람은 반드시 초기화 되어야 한다!! 라고 하는게 안전합니다.
	People(const std::string& n, int a) : name(n), age(a) {}
};

// People 에서 파생된 Student 클래스를 생각해 봅시다.
class Student : public People
{
	int id;
public:
	// 아래 코드는 왜 에러인지 생각해 보세요. 해결책은 뭘까요 ?
	// => 컴파일러가 아래처럼 "People()" 를 추가..
	// => 그런데, People 은 디폴트 생성자가 없습니다
//	Student(int n) : id(n) {} // Student(int n) : People(), id(n) {} 


	// 해결책
	// => 기반 클래스에 디폴트 생성자가 없으면 반드시 파생 클래스에서
	//    기반 클래스 생성자를 명시적으로 호출해야 합니다.
	Student(const std::string& name, int age, int n) 
				: People(name, age), id(n) {}
};




int main()
{
//	People p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
				// error
	People p2("kim", 20); // ok

	Student s("kim", 20, 17); 
}


