#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다고 가정해 봅시다.

// TextView : 문자열을 보관했다가 화면에 이쁘게 출력해주는 클래스
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
// 클래스 어답터 : 클래스의 인터페이스 변경
class Text : public Shape, public TextView
{
public:
	Text(const std::string& s) : TextView(s) {}

	virtual void Draw() override
	{
		TextView::Show();
	}
};

// 아래 코드가 객체 어답터 입니다
class ObjectAdapter : public Shape
{
	TextView* txtView; // 핵심 : 포인터 또는 참조로된 멤버
					// 새로운 TextView 를 만드는것이 아니라
					// "외부에 이미 만들어진" TextView 객체를 가리킬수 있다는것이 핵심
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

	TextView tv("hello"); // TextView : 클래스
						  // tv       : 객체 입니다.

	// 이미 만들어진 객체(tv) 를 도형을 관리하는 vector v 에 넣을수 있을까요 ?

//	v.push_back(&tv);	// error. v에 넣으려면 Shape 로 부터 파생되어야 하는데
						// tv는 Shape에서 파생된 타입이 아니다.

	v.push_back(new ObjectAdapter(&tv));
	
	// vector  <== ObjectAdapter객체 <== tv

	v[0]->Draw();
	
}

