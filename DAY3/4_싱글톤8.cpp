#include <iostream>

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;
public:

	// 아래 코드는 멀티스레드 환경에 안전할까요 ??
	// => C++11 이후 부터는 안전 합니다.
	// => 아래 코드가 만들기도 쉽고, 스레드에도 안전하기 때문에 많이 권장됩니다.
	// => "Effective C++ 의 저자(scott meyer)가 처음 제안한 코드라서 이름이 
	// => "Meyer's 싱글톤" 이라고 합니다

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


}








