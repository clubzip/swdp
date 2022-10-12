#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 모든 메뉴의 공통의 기반 클래스

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title)  : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	// 모든 메뉴는 선택될수 있다!!
	// => 세부 구현은 파생 클래스에서!!
	virtual void command() = 0;
};




class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {}

	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨" << std::endl;
		_getch();
	}
};
class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v; // <<=== 핵심
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add_menu(BaseMenu* p)  // <<== 핵심
	{
		v.push_back(p); 
	}


	void command()
	{
		while (1)
		{
			system("cls");

			std::size_t sz = v.size(); 

			for (std::size_t i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". 종료" << std::endl;

			std::cout << "메뉴를 선택하세요 >> ";
			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;  

			if (cmd < 1 || cmd > sz + 1) 
				continue;


			v[cmd - 1]->command(); 
		}

	}
};

int main()
{
	MenuItem m1("참치 김밥",   11);
	MenuItem m2("소고기 김밥", 12);
	MenuItem m3("라면", 13);

	PopupMenu pm("김밥류");
	pm.add_menu(&m1);
	pm.add_menu(&m2);


	PopupMenu mainMenu("오늘의 메뉴");

	mainMenu.add_menu(&pm); // 핵심  add_menu(&팝업메뉴)
	mainMenu.add_menu(&m3); //      add_menu(&메뉴아이템)

	mainMenu.command();
}




