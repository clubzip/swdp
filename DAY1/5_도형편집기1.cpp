#include <iostream>
#include <vector>

// �ٽ� 1. ��� ������ Ÿ��ȭ �ϸ� ���ϴ�.
// 
// �ٽ� 2. ��� ������ ������ ��� Ŭ������ �ִٸ� 
//        ��� ������ �ϳ��� �����̳ʿ� ��� �����Ҽ� �ִ�.
class Shape
{
};

class Rect : public Shape
{
	// ��� ����Ÿ�� �����ڴ� ����....
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
//	std::vector<Rect*> v; // Rect �� ���� ������ vector

	std::vector<Shape*> v; // ��� ������ �����Ҽ� �ִ� vector

}

