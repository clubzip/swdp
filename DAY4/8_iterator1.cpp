#include <iostream>
#include <list>
#include <vector>

// iterator 패턴
// => 복합객체의 내부 구조에 상관없이 동일한 방법으로 모든 요소를 열거

int main()
{
	std::list<int> s = { 1,2,3,4,5 };
	std::vector<int> v = { 1,2,3,4,5 };

	auto p1 = s.begin();
	auto p2 = v.begin();

	// p1 은 list 반복자
	// p2 는 vector 반복자
	// "list 와 vector 의 메모리 구조는 다르지만" 

	// p1, p2 은 사용법이 동일.!

	// 동일한 방법으로 이동
	++p1;
	++p2;

	// 동일한 방법으로 요소에 접근
	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;

}