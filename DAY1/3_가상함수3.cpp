// 2_가상함수재정의
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// 핵심 1. 가상함수 재정의시 "virtual" 은 붙여도 되고 안붙여도 됩니다.
	// => 하지만 붙이는 것이 "가독성"이 좋습니다.
	// virtual void foo() {}


	// 핵심 2. 가상함수 재정의시 실수(오타)가 있어도 에러가 아닙니다.
	// => 이 문제를 해결하기 위해 C++11 에서 "override" 키워드 도입
	// => 새로운 함수를 만드는 것이 아닌 "기반 클래스 함수를 재정의한다"고 알려주는것
//	virtual void fooo()  {}		// 에러 아님
// 	virtual void goo(double)  {}

	virtual void fooo()      override {} // error
	virtual void goo(double) override {} // error

};

int main()
{
}





