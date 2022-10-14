#include <iostream>

// ��� �ݺ���(������)�� ���Ѿ��ϴ� �������̽�
// �Ʒ� �������̽� �̸��� C#, Ÿ����OS(C++,�Ｚ)�� ����ϴ� �̸� �Դϴ�.
template<typename T>
struct IEnumerator
{
	virtual T& get_object() = 0;
	virtual bool move_next() = 0;
	virtual ~IEnumerator() {}
};


// ��� �����̳ʰ� ���Ѿ� �ϴ� �������̽�
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
// �̱۸���Ʈ�� �ݺ���(������)�� ������ ���ô�.
// �ݺ���(������) : �����̳��� 1��° ��Ҹ� ����Ű�ٰ�, �������� �̵������ϸ�˴ϴ�
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

		return current != nullptr; // �������� �������� false 
	}
};

//slist_enumerator<int> p1(400����);
//p1.get_object(); // ��� ���
//p1.move_next(); // �������� �̵�


// ��� �����̳ʿ����� �ݺ��ڸ� ������ �־�� �մϴ�.

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

	// ���� vector �� ���� �����
	// IEnumerator<T> �� ������ vector_iterator �� ����� �˴ϴ�.
}
// �� ����� �������� ������ ������ �ݺ��� �Դϴ�.
// => ��κ��� ��ü���� ����� �ݺ���

// ���� 
// 1. move_next �� get_object �� �����Լ��̴�.. ������.
// 
// 2. s.get_enumerator() �� ��ȯ �ϴ� �ݺ��ڴ� "new"�� �����Ǿ���.
//    delete �� �ʿ� �ϴ�.

// 3. ��� �����̳ʿ� ������ ������� �����ؾ� �ϴµ�..
//    "raw array" �� �����͸� ����ϰ�, ++�� �̵��Ѵ�.
//    �迭�� �����ϴ� ����� �ٸ���.