#include <iostream>
#include <vector>

// �ٽ� 5. ������(Polymorphism)
//			������ ǥ������ ��Ȳ(������ü)�� ����
//			�ٸ��� �����ϴ� ��(�ٸ� �Լ� ȣ��)
// ���ο� ������ �߰��Ǿ "p->Draw()"�� ����� �ʿ� ����. OCP ����

class Shape
{
	int color;
public:
	void SetColor(int c) { color = c; }
	int  GetColor() const { return color; }
	
	virtual int GetArea() const { return -1; }
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

class Triangle : public Shape
{
public:
	virtual void Draw() override { std::cout << "Draw Triangle" << std::endl; }
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
				p->Draw(); // ������(Polymorphism)
							// ������ ǥ������ ��Ȳ(������ü)�� ����
							// �ٸ��� �����ϴ� ��(�ٸ� �Լ� ȣ��)
							
							// �� �ڵ�� ���ο� ���� Ŭ������ �߰��Ǿ
							// ������ �ʿ� �����ϴ�.
							// OCP�� �����ϴ� ���� �ڵ� �Դϴ�.

			// ��ü ���� ����� 3���� Ư¡ : ĸ��ȭ, ���, ������
		}
	}
}

