#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 객체지향 프로그래밍(Object Oriented Programming )

// 1. 프로그램은 객체를 생성하고 
// 2. 객체간의 관계를 설정하고, 
// 3. 객체간의 메세지를 주고 받는것이다.( 멤버 함수를 호출한다는 의미)
// 4. 프로그램의 기본 단위는 "클래스" 이다.
// => C++, JAVA, SWIFT, C#

// 메뉴 항목 한개를 나타내는 클래스를 설계..!

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id)
		: title(title), id(id) {}

	std::string get_title() const { return title; }

	// 메뉴 선택시 호출되는 함수.. 
	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨" << std::endl;
		_getch();
	}
};
int main()
{
	// 객체지향 프로그램에서 "모든 것은 객체" 입니다.
	// 메뉴항목 한개도 역시 객체로 관리되어야 합니다.
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);
	m1.command(); // 메뉴 선택시 호출되는 함수!
}




