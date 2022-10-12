#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id)
		: title(title), id(id) {}

	std::string get_title() const { return title; }

	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨" << std::endl;
		_getch();
	}
};

// MenuItem 객체를 여러개 보관하는 클래스
class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title(title) {}

	void add_menu(MenuItem* p) { v.push_back(p); }

	// 팝업메뉴 선택시 해야할일(main 함수주석)을 어떻게 구할할지 생각해 보세요.
	void command()
	{

	}
};


int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);


	PopupMenu pm("오늘의 메뉴");

	pm.add_menu(&m1);
	pm.add_menu(&m2);

	pm.command();	// 팝업메뉴 선택시 "하위 메뉴"를 나타내야 합니다.
					// 1. 김밥
					// 2. 라면
					// 3. 종료
					// 메뉴를 선택하세요 >> 
}




