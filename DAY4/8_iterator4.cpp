#include <iostream>

// 모든 반복자(열거자)가 지켜야하는 인터페이스
// 아래 인터페이스 이름은 C#, 타이젠OS(C++,삼성)이 사용하는 이름 입니다.
template<typename T>
struct IEnumerator
{
	virtual T& get_object() = 0;
	virtual bool move_next() = 0;
	virtual ~IEnumerator() {}
};


// 모든 컨테이너가 지켜야 하는 인터페이스
template<typename T>
struct IEnumerable
{
	virtual IEnumerator<T>* get_enumerator() = 0;
	virtual ~IEnumerable() {}
};
//===================================================
template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};
//=======================================================
// 싱글리스트의 반복자(열거자)를 설계해 봅시다.
// 반복자(열거자) : 컨테이너의 1번째 요소를 가리키다가, 다음으로 이동가능하면됩니다
template<typename T>
class slist_enumerator : public IEnumerator<T>
{
	Node<T>* current;
public:
	slist_enumerator(Node<T>* p = nullptr) : current(p) {}

	virtual T& get_object() override { return current->data; }

	virtual bool move_next() override
	{
		current = current->next;

		return current != nullptr; // 마지막을 지났으면 false 
	}
};

//slist_enumerator<int> p1(400번지);
//p1.get_object(); // 요소 얻기
//p1.move_next(); // 다음으로 이동


// 모든 컨테이너에서는 반복자를 꺼낼수 있어야 합니다.

template<typename T> struct slist : public IEnumerable<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }


	virtual IEnumerator<T>* get_enumerator() override
	{
		return new slist_enumerator<T>(head);
	}
};


int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	IEnumerator<int>* p1 = s.get_enumerator();

	std::cout << p1->get_object() << std::endl; 

	p1->move_next();
	std::cout << p1->get_object() << std::endl; 

	p1->move_next();
	std::cout << p1->get_object() << std::endl; 

	delete p1;

	// 이제 vector 를 만든 사람이
	// IEnumerator<T> 를 구현한 vector_iterator 를 만들면 됩니다.
}
// 위 방식이 전통적인 디자인 패턴의 반복자 입니다.
// => 대부분의 객체지향 언어의 반복자

// 단점 
// 1. move_next 와 get_object 는 가상함수이다.. 느리다.
// 
// 2. s.get_enumerator() 가 반환 하는 반복자는 "new"로 생성되었다.
//    delete 가 필요 하다.

// 3. 모든 컨테이너에 동일한 방식으로 열거해야 하는데..
//    "raw array" 는 포인터를 사용하고, ++로 이동한다.
//    배열을 열거하는 방법이 다르다.