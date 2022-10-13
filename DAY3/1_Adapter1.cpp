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
// 도형편집기에 "문자열"도 다루고 싶었다.
// => 그런데, 예전에 만들어둔 "TextView" 가 있다.
// => 도형편집기에서 활용할수 없을까 ?

// 문제점 : 도형편집기는 "Shape" 로 부터 파생되어야 하고, "Draw" 함수가 있어야 한다
//         TextView 는 요구조건을 만족하지 못한다.(Show 함수로 출력)

// TextView 의 인터페이스(함수이름)를 변경해서 도형편집기에서 사용할수 있게해보자

// Adapter 패턴 
// => 기존 클래스의 인터페이스(함수이름)을 변경해서 요구조건을 만족하는 클래스를
//    만드는 패텬
// => 인터페이스의 불일치를 해결하는 패턴

// 클래스 어답터 : 클래스의 인터페이스 변경
// 객체   어답터 : 객체의 인터페이스 변경

class Text : public Shape, public TextView
{
public:
	Text(const std::string& s) : TextView(s) {}

	// 아래 함수가 결국 "인터페이스를 변경(Show => Draw)" 해서
	// "인터페이스의 불일치"를 해결
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

