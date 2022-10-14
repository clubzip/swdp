
// github.com/codenuri/ hddp 에서 "DAY3-2.zip" 받아두세요

#include <iostream>
#include <list>
#include <vector>

// visitor 패턴
// 
// 반복자(iterator) : 복합객체의 모든 요소를 동일한 방식으로 열거
// 방문자(visitor)  : 복합객체의 모든 요소를 동일한 방식으로 연산수행


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 2배로 하고 싶다.
	// ================================================
	// 방법 1. 요소를 2배로 하는 코드를 작성
	// => for 문 등을 사용
	for (auto& e : s)
	{
		e = e * 2;
	}
	for (auto e : s)
		std::cout << e << ", ";






	//====================================================
	// 방법 2. 방문자 패턴을 사용
	TwiceVisitor<int> tv;	// 각 요소를 2배로 하는 방문자 객체

	s.accept(&tv);

	ShowVisitor<int> sv;   // 각 요소를 출력하는 방문자
	s.accept(&sv);

	// s.accept() 는 모든 종류의 방문자를 받아야 한다.
	// => 모든 방문자가 지켜야 하는 인터페이스 필요!!

	// list, vector 등의 모든 컨테이너는 accept 가 있어야 한다.
	// => 모든 컨테이너는 인터페이스가 필요 

}





