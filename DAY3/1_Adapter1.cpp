#include <iostream>
#include <string>
#include <vector>

// �Ʒ� Ŭ������ �̹� �־��ٰ� ������ ���ô�.

// TextView : ���ڿ��� �����ߴٰ� ȭ�鿡 �̻ڰ� ������ִ� Ŭ����
class TextView
{
	std::string data;
public:
	TextView(const std::string& s) : data(s) {}

	void Show() { std::cout << data << std::endl; }
};
//=======================================================


class Shape
{
public:
	virtual void Draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void Draw() override { std::cout << "Draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Circle" << std::endl; }
};
//=======================================
// ���������⿡ "���ڿ�"�� �ٷ�� �;���.
// => �׷���, ������ ������ "TextView" �� �ִ�.
// => ���������⿡�� Ȱ���Ҽ� ������ ?

// ������ : ����������� "Shape" �� ���� �Ļ��Ǿ�� �ϰ�, "Draw" �Լ��� �־�� �Ѵ�
//         TextView �� �䱸������ �������� ���Ѵ�.(Show �Լ��� ���)

// TextView �� �������̽�(�Լ��̸�)�� �����ؼ� ���������⿡�� ����Ҽ� �ְ��غ���

// Adapter ���� 
// => ���� Ŭ������ �������̽�(�Լ��̸�)�� �����ؼ� �䱸������ �����ϴ� Ŭ������
//    ����� ����
// => �������̽��� ����ġ�� �ذ��ϴ� ����

// Ŭ���� ����� : Ŭ������ �������̽� ����
// ��ü   ����� : ��ü�� �������̽� ����

class Text : public Shape, public TextView
{
public:
	Text(const std::string& s) : TextView(s) {}

	// �Ʒ� �Լ��� �ᱹ "�������̽��� ����(Show => Draw)" �ؼ�
	// "�������̽��� ����ġ"�� �ذ�
	virtual void Draw() override
	{
		TextView::Show(); 
	}
};
int main()
{
	std::vector<Shape*> v;

	v.push_back(new Text("hello"));

	v[0]->Draw();
}

