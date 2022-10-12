#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


class NotImplemented {};

// 모든 메뉴의 공통의 기반 클래스

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	// 모든 메뉴는 선택될수 있다!!
	// => 세부 구현은 파생 클래스에서!!
	virtual void command() = 0;

	virtual void add_menu(BaseMenu* p) 	{throw NotImplemented();}
	virtual BaseMenu* submenu(int idx)  {throw NotImplemented();}
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
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add_menu(BaseMenu* p)
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

	BaseMenu* submenu(int idx) { return v[idx - 1]; }
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* p1 = new PopupMenu("색상 변경");
	PopupMenu* p2 = new PopupMenu("해상도 변경");

	root->add_menu(p1);
	root->add_menu(p2);

	root->add_menu(new MenuItem("기타", 11));


	// submenu() 함수를 생각해 봅시다.
	// => submenu 반환 타입은 BaseMenu* 입니다.
	// => 아래처럼 사용하게 하려면 add_menu() 가 BaseMenu 에 있어야 합니다.
	// 1. 아래 처럼 사용하지 못하게 하자.!!
	// 2. BaseMenu 에 add_menu 선언을 넣어 주자!
	root->submenu(1)->add_menu(new MenuItem("RED", 11));

	// (*root)[1].add_menu(  ) 도 도전해보세요..

//	root->submenu(2)->add_menu(new MenuItem("기타2", 31)); // 예외
					// root->submenu(2) 는 "Popup" 이 아닌 "MenuItem"


	root->command();
}
// 173 page





