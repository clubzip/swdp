// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.

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








