// 3_추상팩토리 - 147
#include <iostream>

// 모든 종류의 컨트롤은 공통의 기반 클래스 필요
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};


struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
//-----------------

// "Factory" 라는 이름은 디자인 패턴 분류에는 없습니다.
// "Abstract Factory" 라는 이름이 있습니다.

// => 객체의 군 을 만들기 위한 인터페이스를 만들지만
//    어떤 객체들을 만들지는 파생 클래스가 결정한다.
//    "공장도 인터페이스를 먼저 설계 하자는 의미"

struct IFactory
{
	IButton* CreateButton() = 0;
	IEdit* CreateEdit() = 0;
	virtual ~WinFactory() = 0;
};

//  style 별로 각 콘트롤을 만드는 공장
class WinFactory : public IFactory
{
public:
	IButton* CreateButton() { return new WinButton; }
	IEdit*   CreateEdit()   { return new WinEdit; }
	virtual ~WinFactory() {}
};
class OSXFactory : public IFactory
{
public:
	IButton* CreateButton() { return new OSXButton; }
	IEdit*   CreateEdit() { return new OSXEdit; }
	virtual ~OSXFactory() {}
};

int main(int argc, char** argv)
{
	IFactory* factory;

	if (strcmp(argv[1], "-style:OSX") == 0)
		factory = new OSXFactory;
	else
		factory = new WinFactory;

	// 컨트롤이 필요하면 공장을 사용해서 생성
	IButton* btn = factory->CreateButton();
	btn->Draw();

	IButton* btn2 = factory->CreateButton();
	btn2->Draw();

}











