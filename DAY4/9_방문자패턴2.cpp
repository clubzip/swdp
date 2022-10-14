#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

// 핵심 1. 모든 방문자 클래스는 공통의 인터페이스가 필요
template<typename T> struct IVisitor
{
	virtual void visit(T& value) = 0;
	virtual ~IVisitor() {}
};



// 핵심 2. 모든 방문의 대상(컨테이너, 복합객체)는 accept 가 있어야 한다.
template<typename T> struct IAcceptor
{
	virtual void accept(IVisitor<T>* v) = 0;
	virtual ~IAcceptor() {}
};

//=====================================================
// 핵심 3. 방문자 클래스 : "요소 한개에 대한 연산을 정의하는 클래스"

template<typename T>
class TwiceVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& value) override { value *= 2; }
};

// 요소를 3배로 하는 방문자
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




// 핵심 4. 복합객체의 "accept" 에서 자신의 모든 요소를 방문자의 visit에 전달합니다.
// STL 의 list 자체는 방문자 패턴을 사용하지 않습니다.
// list 에서 파생 된 클래스를 만들어서 방문자 패턴을 적용!!
template<typename T>
class MyList : public IAcceptor<T>, public std::list<T>
{
public:
	using std::list<T>::list;	// 생성자 상속		
								// list 의 모든 생성자를 그대로 사용하겠다는것

	// 아래 코드가 결국 방문자 패턴의 핵심입니다.
	virtual void accept(IVisitor<T>* v) override
	{
		// 자신의 모든 요소를 방문자에게 보내 줍니다.
		for (auto& e : *this) // *this 는 현재 자신(list) 입니다.
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





