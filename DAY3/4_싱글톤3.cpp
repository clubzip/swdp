// 7_싱글톤1 - 123 page
#include <iostream>

// 핵심 1. 싱글톤 : 오직 한개의 객체만 존재하는 것.
//		   프로그램의 어디에서도 오직 한개의 객체에 동일한 방법으로 접근 할수 있다.


// 핵심 2. 아래 3가지 규칙 알아 두세요


// 핵심 3. 단점

// => 결국 "전역변수" 와 동일한 특징을 가지게 됩니다.
// => "전역변수" 는 모듈화를 방해하고, 위험하다. 
// => 되도록 사용하지 말라고 권장.

// 오직 한개의 객체를 "힙"에 생성하는 모델.

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* sinstance;
public:
	static Cursor& getInstance()
	{
		if (sinstance == nullptr)
		{
			sinstance = new Cursor;
		}
		return *sinstance;
	}
};
Cursor* Cursor::sinstance = nullptr;



int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

}








