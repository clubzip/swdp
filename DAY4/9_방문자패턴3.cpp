#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem;	
class PopupMenu;


// list      : 모든 요소가 동일한 타입의 복합객체
// PopupMenu : 요소의 타입이 다른 복합객체


// 메뉴에 대한 연산을 정의하는 방문자 인터페이스
struct IMenuVisitor
{
	virtual void visit(MenuItem*) = 0;
	virtual void visit(PopupMenu*) = 0;
	virtual ~IMenuVisitor() {}
};

struct IAcceptor
{
	virtual void accept(IMenuVisitor*) = 0;
	virtual ~IAcceptor() {}
};

//=================================================
class BaseMenu : public IAcceptor
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	void set_title(const std::string& s) { title = s; }

	std::string get_title() const { return title; }

	virtual void command() = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command() override
	{
		std::cout << get_title() << " 메뉴가 선택됨" << std::endl;
		_getch();
	}

	virtual void accept(IMenuVisitor* visitor)
	{
		// MenuItem 은 하위 메뉴가 없으므로 자신만 방문자에 보냅니다.
		visitor->visit(this);
	}
};


class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	// 방문자가 팝업을 방문했을때를 생각해 보세요
	virtual void accept(IMenuVisitor* visitor)
	{
		visitor->visit(this); // 먼저 자신을 방문자에 전달 합니다.

		// 방문자를 자신이 가진 모든 하위메뉴에 방문 시킵니다.
		for (auto p : v)
			p->accept(visitor);
	}







	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command() override
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}

			std::cout << sz + 1 << ". 종료" << std::endl;

			int cmd;
			std::cout << "메뉴를 선택하세요 >> ";
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1)
				break;

			v[cmd - 1]->command();
		}

	}

};


//====================================================
// 방문자 : 한개의 요소에 대한 연산을 정의 하는 객체
class PopupMenuTitleChangeVisitor : public IMenuVisitor
{
public:
	virtual void visit(MenuItem*) override {}
	virtual void visit(PopupMenu* pm) override
	{
		std::string s = pm->get_title();
		s = "[ " + s + " ]";
		pm->set_title(s);
	}
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->add_menu(pm1);
	root->add_menu(pm2);

	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));


	//====================
	PopupMenuTitleChangeVisitor pmtv; 
	root->accept(&pmtv);				


	root->command();

}




