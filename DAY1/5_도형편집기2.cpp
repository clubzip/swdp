#include <iostream>
#include <vector>

class Shape
{
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
			// �簢�� ����
//			Rect rc; // �̷��� �ϸ� {} ����� ��� �ı� �˴ϴ�.
			Rect* p = new Rect;
			v.push_back(p);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw(); // "A"
		}
	}
}
// �����ϸ� ������ �ֽ��ϴ�..
// ��?? ��� �����ϱ�� ?
// ==> "A" ���� p �� "Shape*" �ε�. Shape ���� Draw() �� ����.
// �ذ�å�� ����� ??
// 1. p �� Rect* �Ǵ� Circle* �� ĳ������ �������.
// ==> �׷���, �ڵ带 �ۼ��Ҷ��� p�� ������ ����Ű���� �˼� ����.
// ==> ����, dynamic_cast �� ����� �Ҽ� ������ ���� �ʴ�.
// 
// 2. Shape �� Draw �� ������. ===> ����
