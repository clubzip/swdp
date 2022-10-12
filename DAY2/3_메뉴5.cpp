#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

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
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* p1 = new PopupMenu("색상 변경");
	PopupMenu* p2 = new PopupMenu("해상도 변경");

	root->add_menu(p1);
	root->add_menu(p2);
//	p1->add_menu(p2);

	p1->add_menu(new MenuItem("RED",   11));
	p1->add_menu(new MenuItem("GREEN", 12));
	p1->add_menu(new MenuItem("BLUE",  13));

	p2->add_menu(new MenuItem("HD",  21));
	p2->add_menu(new MenuItem("FHD", 22));
	p2->add_menu(new MenuItem("UHD", 23));
	p2->add_menu(new MenuItem("8K",  24));

	// 이제 시작하려면 ??
	root->command();
}

// 핵심 
// Composite 패턴
// 복합객체(PopupMenu) 는 개별객체(MenuItem) 뿐 아니라
// 복합객체 자신도 보관한다.
// => 복합객체와 개별객체는 공통의 기반 클래스가 필요 한다.

// 복합객체와 개별객체는 사용법이 동일하다.
// => 선택시 모두 command 호출
// => command 는 기반 클래스에 선언이 있어야 한다.

// 복합객체는 "tree" 구조로 구성된다.
// => main 코드에서 root, 색상변경, 해상도 변경 객체의
//    구조를 생각해 보세요.





