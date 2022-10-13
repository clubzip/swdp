#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 질문 : protected로 상속받아서 쓰는 방식은 안쓰나요?

// public 상속 : list 의 모든 함수를 stack 이 상속받겠다

template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()            { std::list<T>::pop_back(); }
	T&   top()			  { return std::list<T>::back(); }
};

stack s;
s.push_front(10); // list에서 상속받은 멤버 함수

//==================================================
// protected 또는 private 상속 : list 의 모든 멤버를 상속받을때
//								private(protected)로 상속 받겠다는 의도

template<typename T> class stack : private std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()				{ std::list<T>::pop_back(); }
	T& top()				{ return std::list<T>::back(); }
};
stack s;
s.push_front(10);	// error. push_front 를 상속받을때 private 상속이므로
					// private 멤버 함수!!

// 결국 private 상속의 의미는 list 의 모든 멤버 함수를 "내부적으로만" 사용하겠다는것
// "아래 list 를 멤버로 포함 한것과 동일한 효과!!"

// 차이점
// private 상속 : list에 가상함수가 있다면 "override" 할수 있다.
// 포함         : list 의 가상함수를 "override" 할수 있는 방법은 없다.

template<typename T> class stack
{
	std::list<T> c;
public:
	void push(const T& a) { c.push_back(a); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(20); // 이렇게 사용할수 있게 하는것이 좋을까요 ?
}



