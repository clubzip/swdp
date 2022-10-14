#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};
//=======================================================

template<typename T>
class slist_iterator 
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr) : current(p) {}

	inline T& operator*() { return current->data; }

	inline slist_iterator& operator++() 
	{
		current = current->next;

		return *this; // operator++ 재정의시 자신을 참조로 반환!
	}
};

template<typename T> struct slist 
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	slist_iterator<T> begin()
	{
		return slist_iterator<T>(head);
	}
};
int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	auto p1 = s.begin();

	// p1 은 ++, * 가 재정의 되어 있기 때문에 포인터 처럼 사용가능하니다.

	std::cout << *p1 << std::endl; // 40

	++p1;

	std::cout << *p1 << std::endl; // 30
}
