#include <iostream>
#include <list>
#include <vector>
#include <deque>

// stack �� ���鶧 ���������� � �����̳ʸ� ��������� 
// ����ڰ� ���ø� ���ڷ� �����Ҽ� �ְ� ����
// => "policy base design"

// �Ʒ� �ڵ尡 C++ ǥ�� "<stack>" �� �ִ� �ڵ� �Դϴ�.
// => ���� "stack adapter" ��� �θ��ϴ�.

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
	stack<int> s; // deque �� �������̽��� �����ؼ� stack ó�� ����ϰڴ�.
	s.push(10);

	stack<int, std::list<int>>   s1;
	stack<int, std::vector<int>> s2;
}



