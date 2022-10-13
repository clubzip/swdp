#include <iostream>
#include <list>
#include <vector>
#include <deque>

// ���� : protected�� ��ӹ޾Ƽ� ���� ����� �Ⱦ�����?

// public ��� : list �� ��� �Լ��� stack �� ��ӹްڴ�

template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()            { std::list<T>::pop_back(); }
	T&   top()			  { return std::list<T>::back(); }
};

stack s;
s.push_front(10); // list���� ��ӹ��� ��� �Լ�

//==================================================
// protected �Ǵ� private ��� : list �� ��� ����� ��ӹ�����
//								private(protected)�� ��� �ްڴٴ� �ǵ�

template<typename T> class stack : private std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()				{ std::list<T>::pop_back(); }
	T& top()				{ return std::list<T>::back(); }
};
stack s;
s.push_front(10);	// error. push_front �� ��ӹ����� private ����̹Ƿ�
					// private ��� �Լ�!!

// �ᱹ private ����� �ǹ̴� list �� ��� ��� �Լ��� "���������θ�" ����ϰڴٴ°�
// "�Ʒ� list �� ����� ���� �ѰͰ� ������ ȿ��!!"

// ������
// private ��� : list�� �����Լ��� �ִٸ� "override" �Ҽ� �ִ�.
// ����         : list �� �����Լ��� "override" �Ҽ� �ִ� ����� ����.

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

	s.push_front(20); // �̷��� ����Ҽ� �ְ� �ϴ°��� ������� ?
}



