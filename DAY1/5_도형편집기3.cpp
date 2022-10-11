#include <iostream>
#include <vector>

// �ٽ� 3. ��� �Ļ� Ŭ����(����)�� ������ Ư¡�� "�ݵ�� ��� Ŭ����" ���� 
//        �־�� �մϴ�.
//        => �׷���, ��� Ŭ���� Ÿ������ ��� �����Ҷ� �ش� Ư¡�� ��밡���մϴ�.


// �ٽ� 4. ��� Ŭ������ ��� �Լ��� �Ļ� Ŭ������ ������ �ϰ� �Ǵ� ����
//		  �ݵ�� �����Լ��� ������ �մϴ�.


class Shape
{
	int color;
public:
	// �Ʒ� 2���� ����Լ��� "virtual" �� �ұ�� ? "non-virtual"�� �ұ�� ?
	// => �Ļ� Ŭ������ ������ �� �ʿ� �����ϴ�. "non-virtual"
	void SetColor(int c) { color = c; }
	int  GetColor() const { return color; }

	// ������ ���ϴ� ����� ��� ������ �ٸ��ϴ�.
	// => "virtual" �� �����, �Ļ� Ŭ������ ������ �Ҽ� �ְ�.. 
	virtual int GetArea() const  { return -1; }


	virtual void Draw() { std::cout << "Draw Shape" << std::endl; }
};

class Rect : public Shape
{
public:
	virtual void Draw() override { std::cout << "Draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	virtual void Draw() override { std::cout << "Draw Circle" << std::endl; }
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

