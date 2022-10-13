#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL �� Adapter
// 1. linked list �� �̹� �ִµ�.. 
// 2. stack �� �ʿ� �մϴ�. 


// Linked List �� �Լ� �̸��� �����ؼ� stack ó�� ���̰� ����.
// ����� ����ϴ� ����� : ���� Ŭ����(list)�� ��� ����� 
//						���ο� Ŭ����(stack)�� �ܺ� �����ϰڴٴ°�
//						"�������̽��� ���" �ϰڴٰ� ǥ��

// �Ʒ� ������ ���� ���� �ʽ��ϴ�.
/*
template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()            { std::list<T>::pop_back(); }
	T&   top()			  { return std::list<T>::back(); }
};
*/
// ������ ����� ����� : ���� Ŭ����(list)�� ������ ���������
//                     �������̽��� ������� �ʰڴ�
//						list �Լ��� stack �� �ܺ� �������� �ʰڴ�.

template<typename T> class stack 
{
//	std::list<T>* c;	// �̷��� �ϸ� �ܺο� �̹� ������� ��ü�� ����Ű�ڴٴ� �ǵ�
						// ��ü ����Ͱ� �˴ϴ�.

	std::list<T> c; // �̷��� �ϸ� �ܺ� ��ü�� ����Ű�� ���� �ƴ�
					// stack ������ list�� �ڵ����� ����..
					// �ᱹ Ŭ���� ����� �Դϴ�.

public:
	void push(const T& a) { c.push_back(a); }
	void pop()            { c.pop_back(); }
	T& top()              { return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(20); // �̷��� ����Ҽ� �ְ� �ϴ°��� ������� ?
}



