#include <iostream>
#include <list>
#include <vector>
#include <deque>

// stack 을 만들때 내부적으로 어떤 컨테이너를 사용할지를 
// 사용자가 템플릿 인자로 변경할수 있게 설계
// => "policy base design"

// 아래 코드가 C++ 표준 "<stack>" 에 있는 코드 입니다.
// => 흔히 "stack adapter" 라고 부릅니다.

template<typename T, typename C = std::deque<T> > class stack
{
	C c;
public:
	inline void push(const T& a)	{ c.push_back(a); }
	inline void pop()				{ c.pop_back(); }
	inline T& top()				{ return c.back(); }
};

int main()
{
	stack<int> s; // deque 의 인터페이스를 변경해서 stack 처럼 사용하겠다.
	s.push(10);

	stack<int, std::list<int>>   s1;
	stack<int, std::vector<int>> s2;
}



