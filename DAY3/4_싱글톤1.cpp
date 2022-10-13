// 7_싱글톤1 - 123 page
#include <iostream>

// 핵심 1. 싱글톤 : 오직 한개의 객체만 존재하는 것.
//		   프로그램의 어디에서도 오직 한개의 객체에 동일한 방법으로 접근 할수 있다.


// 핵심 2. 아래 3가지 규칙 알아 두세요


// 핵심 3. 단점

// => 결국 "전역변수" 와 동일한 특징을 가지게 됩니다.
// => "전역변수" 는 모듈화를 방해하고, 위험하다. 
// => 되도록 사용하지 말라고 권장.


class Cursor
{
	// 규칙 1. 생성자를 private 에
private:
	Cursor() {}

	// 규칙 2. 컴파일러에게 디폴트 복사 생성자를 만들지 말라고 요청
	// => 복사 생성자를 삭제하면, 대입연산자도 삭제하는 것이 관례입니다.
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;


	// 규칙 3. 오직 한개의 객체를 만들어서 반환하는 static 멤버 함수
public:
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};
int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

//	Cursor c3 = c1; // 복사 생성자를 사용해서 객체 생성.
					// 이렇게 생성하는 것도 막아야 합니다.
					// 
//	Cursor c1, c2; // error


}








