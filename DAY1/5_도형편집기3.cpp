#include <iostream>
#include <vector>

// �ٽ� 3. ��� �Ļ� Ŭ����(����)�� ������ Ư¡�� "�ݵ�� ��� Ŭ����" ���� 
//        �־�� �մϴ�.
//        => �׷���, ��� Ŭ���� Ÿ������ ��� �����Ҷ� �ش� Ư¡�� ��밡���մϴ�.

class Shape
{
public:
	void Draw() { std::cout << "Draw Shape" << std::endl; }
};

class Rect : public Shape
{
public:
	void Draw() { std::cout << "Draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void Draw() { std::cout << "Draw Circle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw(); 
		}
	}
}

