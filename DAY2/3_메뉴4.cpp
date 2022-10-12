#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// ��� �޴��� ������ ��� Ŭ����

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title)  : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	// ��� �޴��� ���õɼ� �ִ�!!
	// => ���� ������ �Ļ� Ŭ��������!!
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
		std::cout << get_title() << " �޴� ���õ�" << std::endl;
		_getch();
	}
};
class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v; // <<=== �ٽ�
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add_menu(BaseMenu* p)  // <<== �ٽ�
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
			std::cout << sz + 1 << ". ����" << std::endl;

			std::cout << "�޴��� �����ϼ��� >> ";
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
	MenuItem m1("��ġ ���",   11);
	MenuItem m2("�Ұ�� ���", 12);
	MenuItem m3("���", 13);

	PopupMenu pm("����");
	pm.add_menu(&m1);
	pm.add_menu(&m2);


	PopupMenu mainMenu("������ �޴�");

	mainMenu.add_menu(&pm); // �ٽ�  add_menu(&�˾��޴�)
	mainMenu.add_menu(&m3); //      add_menu(&�޴�������)

	mainMenu.command();
}




