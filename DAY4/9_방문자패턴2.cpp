#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

// �ٽ� 1. ��� �湮�� Ŭ������ ������ �������̽��� �ʿ�
template<typename T> struct IVisitor
{
	virtual void visit(T& value) = 0;
	virtual ~IVisitor() {}
};



// �ٽ� 2. ��� �湮�� ���(�����̳�, ���հ�ü)�� accept �� �־�� �Ѵ�.
template<typename T> struct IAcceptor
{
	virtual void accept(IVisitor<T>* v) = 0;
	virtual ~IAcceptor() {}
};

//=====================================================
// �ٽ� 3. �湮�� Ŭ���� : "��� �Ѱ��� ���� ������ �����ϴ� Ŭ����"

template<typename T>
class TwiceVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& value) override { value *= 2; }
};

// ��Ҹ� 3��� �ϴ� �湮��
template<typename T>
class TripleVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& value) override { value *= 3; }
};



template<typename T>
class ShowVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& value) override { std::cout << value << std::endl; }
};




// �ٽ� 4. ���հ�ü�� "accept" ���� �ڽ��� ��� ��Ҹ� �湮���� visit�� �����մϴ�.
// STL �� list ��ü�� �湮�� ������ ������� �ʽ��ϴ�.
// list ���� �Ļ� �� Ŭ������ ���� �湮�� ������ ����!!
template<typename T>
class MyList : public IAcceptor<T>, public std::list<T>
{
public:
	using std::list<T>::list;	// ������ ���		
								// list �� ��� �����ڸ� �״�� ����ϰڴٴ°�

	// �Ʒ� �ڵ尡 �ᱹ �湮�� ������ �ٽ��Դϴ�.
	virtual void accept(IVisitor<T>* v) override
	{
		// �ڽ��� ��� ��Ҹ� �湮�ڿ��� ���� �ݴϴ�.
		for (auto& e : *this) // *this �� ���� �ڽ�(list) �Դϴ�.
			v->visit(e);
	}
};


int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;
	s.accept(&tv);

	ShowVisitor<int> sv;
	s.accept(&sv);

	TripleVisitor<int> trv;
	s.accept(&trv);

	s.accept(&sv);
}





