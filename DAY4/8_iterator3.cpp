#include <iostream>

// C++ STL 방식이 아닌

// 전통적인 객체지향 디자인 방식을 먼저 생각
// => C#, java, python 의 반복자!!
// => 반복자(iterator) 를 "열거자(enumerator)" 라고도 합니다.

int main()
{
	slist<int> s = { 1,2,3,4,5 }; 
	vector<int> v = { 1,2,3,4,5 };

	// 규칙 1. 모든 컨테이너에서는 반복자를 꺼낼수 있어야 한다.
	// => 모든 컨테이너가 지켜야하는 규칙을 담은 인터페이스 필요
	slist_iterator* p1 = s.get_enumerator(); // list 의 반복자
	vector_iterator* p2 = v.get_enumerator(); // vector 반복자

	// 규칙 2. 모든 종류의 반복자는 사용법이 같아야 합니다.
	// => 모든 반복자가 지켜야하는 규칙을 담은 인터페이스가 필요
	// list 와 vector 는 메모리 구조가 다르지만 p1, p2 의 사용법은 같아야합니다
	p1->move_next();
	p2->move_next();

	int n1 = p1->get_object(); 
	int n2 = p2->get_object();
}






