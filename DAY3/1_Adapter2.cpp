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
// Ŭ���� ����� : Ŭ������ �������̽� ����
class Text : public Shape, public TextView
{
public:
	Text(const std::string& s) : TextView(s) {}

	virtual void Draw() override
	{
		TextView::Show();
	}
};

// �Ʒ� �ڵ尡 ��ü ����� �Դϴ�
class ObjectAdapter : public Shape
{
	TextView* txtView; // �ٽ� : ������ �Ǵ� �����ε� ���
					// ���ο� TextView �� ����°��� �ƴ϶�
					// "�ܺο� �̹� �������" TextView ��ü�� ����ų�� �ִٴ°��� �ٽ�
public:
	ObjectAdapter(TextView* p) : txtView(p) {}

	virtual void Draw() override
	{
		txtView->Show();
	}
};


int main()
{
	std::vector<Shape*> v;

	TextView tv("hello"); // TextView : Ŭ����
						  // tv       : ��ü �Դϴ�.

	// �̹� ������� ��ü(tv) �� ������ �����ϴ� vector v �� ������ ������� ?

//	v.push_back(&tv);	// error. v�� �������� Shape �� ���� �Ļ��Ǿ�� �ϴµ�
						// tv�� Shape���� �Ļ��� Ÿ���� �ƴϴ�.

	v.push_back(new ObjectAdapter(&tv));
	
	// vector  <== ObjectAdapter��ü <== tv

	v[0]->Draw();
	
}

