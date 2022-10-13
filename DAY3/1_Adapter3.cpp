#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter
// 1. linked list 가 이미 있는데.. 
// 2. stack 이 필요 합니다. 


// Linked List 의 함수 이름을 변경해서 stack 처럼 보이게 하자.
// 상속을 사용하는 어답터 : 기존 클래스(list)의 모든 기능을 
//						새로운 클래스(stack)도 외부 노출하겠다는것
//						"인터페이스를 상속" 하겠다고 표현

// 아래 예제의 경우는 좋지 않습니다.
/*
template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()            { std::list<T>::pop_back(); }
	T&   top()			  { return std::list<T>::back(); }
};
*/
// 포함을 사용한 어답터 : 기존 클래스(list)의 구현을 사용하지만
//                     인터페이스는 사용하지 않겠다
//						list 함수를 stack 이 외부 노출하지 않겠다.

template<typename T> class stack 
{
//	std::list<T>* c;	// 이렇게 하면 외부에 이미 만들어진 객체를 가리키겠다는 의도
						// 객체 어답터가 됩니다.

	std::list<T> c; // 이렇게 하면 외부 객체를 가리키는 것이 아닌
					// stack 생성시 list를 자동으로 생성..
					// 결국 클래스 어답터 입니다.

public:
	void push(const T& a) { c.push_back(a); }
	void pop()            { c.pop_back(); }
	T& top()              { return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(20); // 이렇게 사용할수 있게 하는것이 좋을까요 ?
}



