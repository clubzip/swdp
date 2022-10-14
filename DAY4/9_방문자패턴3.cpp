#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem;	
class PopupMenu;


// list      : ��� ��Ұ� ������ Ÿ���� ���հ�ü
// PopupMenu : ����� Ÿ���� �ٸ� ���հ�ü


// �޴��� ���� ������ �����ϴ� �湮�� �������̽�
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
		std::cout << get_title() << " �޴��� ���õ�" << std::endl;
		_getch();
	}

	virtual void accept(IMenuVisitor* visitor)
	{
		// MenuItem �� ���� �޴��� �����Ƿ� �ڽŸ� �湮�ڿ� �����ϴ�.
		visitor->visit(this);
	}
};


class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	// �湮�ڰ� �˾��� �湮�������� ������ ������
	virtual void accept(IMenuVisitor* visitor)
	{
		visitor->visit(this); // ���� �ڽ��� �湮�ڿ� ���� �մϴ�.

		// �湮�ڸ� �ڽ��� ���� ��� �����޴��� �湮 ��ŵ�ϴ�.
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

			std::cout << sz + 1 << ". ����" << std::endl;

			int cmd;
			std::cout << "�޴��� �����ϼ��� >> ";
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
// �湮�� : �Ѱ��� ��ҿ� ���� ������ ���� �ϴ� ��ü
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
	PopupMenu* pm1 = new PopupMenu("�ػ� ����");
	PopupMenu* pm2 = new PopupMenu("���� ����");

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




