#include <iostream>
#include <vector>


// �ٽ� 10. �ڵ� ����!!

class NotImplemented {};

class Shape
{
	int color;
public:
	virtual ~Shape() {}  // ��� Ŭ���� �̹Ƿ� �Ҹ��ڴ� �����Լ���!

	void SetColor(int c) { color = c; }
	int  GetColor() const { return color; }


public:
	virtual void Draw() final
	{
		std::cout << "Mutex lock" << std::endl;
		DrawImp();
		std::cout << "Mutex unlock" << std::endl;
	}



protected:
	// �����Լ�   : �Ļ� Ŭ������ ������ ���� ������ "�⺻ ���� ����" �ϰڴٴ� ��
	// ���������Լ�: �Ļ� Ŭ�������� �ݵ�� ������ ���� �ϴ� ��
	virtual void DrawImp() = 0;

public:
	// Clone() 
//	virtual Shape* Clone() const = 0; // �� �ڵ尡 ���� �����ϴ�.(�ݵ�ø����°�)

	// �Ʒ� �ڵ��� �ǵ�!
	// 1. �Ļ� Ŭ������ Clone()�� ������ �ʰ�, ��������� ������ ok
	// 2. �Ļ� Ŭ������ Clone()�� ������ �ʰ�, ����ϸ� ����
	// 3. �Ļ� Ŭ������ Clone()�� �����, ��밡��!
	virtual Shape* Clone() const 
	{
		throw NotImplemented();
	}

	// GetArea()
	// ���� �����Լ��� �ص� �ǰ�, �������� ������ ��Ÿ���°�(-1) ��ȯ�� ������ ����
	virtual int GetArea() const  { return -1; }
};

class Rect : public Shape
{
public:
	virtual void DrawImp() override { std::cout << "Draw Rect" << std::endl; }

	// �����Լ� �����ǽ� "��ȯ Ÿ�� ����" �����մϴ�.
	// => ��, ��� ������ Ÿ������ �����ؾ� �մϴ�.
//	virtual Shape* Clone() const override
	virtual Rect*  Clone() const override
	{
		Rect* p = new Rect(*this);
		return p;
	}
};

// Rect* p1 = new Rect;
// Rect* p2 = p1->Clone(); // �Ǵ°� �����ϴ�.!!

class Circle : public Shape
{
public:
	virtual void DrawImp() override { std::cout << "Draw Circle" << std::endl; }

	virtual Circle* Clone() const override
	{
		Circle* p = new Circle(*this);
		return p;
	}
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
		else if (cmd == 8)
		{
			std::cout << "���° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->Clone());	// ������!!!

		}
	}
}

