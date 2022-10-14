// 5_팩토리메소드
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
//--------------------------------------

// 유사한 코드가 많으면 기반 클래스를 설계해서 제공

class BaseDialog
{
public:
	void init()
	{
		IButton* btn = CreateButton();
		IEdit* edit = CreateEdit();

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}

	// 객체를 만들기 위한 인터페이스(순수가상함수)를 정의 하고 사용하지만
	// 어떤 객체를 만들지는 파생 클래스가 결정한다.
	// template method : 변하는 가상함수가 하는 일이 알고리즘 변경, 정책변경등
	// factory method  : 변하는 가상함수가 하는 일이 객체의 종류를 결정
	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit() = 0;
};

class WinDialog : public BaseDialog
{
public:
	virtual IButton* CreateButton() override { return new WinButton; }
	virtual IEdit* CreateEdit() override  { return new WinEdit; }
};

class OSXDialog : public BaseDialog
{
public:
	virtual IButton* CreateButton() override { return new OSXButton; }
	virtual IEdit*   CreateEdit() override { return new OSXEdit; }
};



int main(int argc, char** argv)
{

}








