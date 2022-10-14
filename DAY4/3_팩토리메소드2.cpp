// 5_���丮�޼ҵ�
#include <iostream>

// ��� ������ ��Ʈ���� ������ ��� Ŭ���� �ʿ�
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

// ������ �ڵ尡 ������ ��� Ŭ������ �����ؼ� ����

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

	// ��ü�� ����� ���� �������̽�(���������Լ�)�� ���� �ϰ� ���������
	// � ��ü�� �������� �Ļ� Ŭ������ �����Ѵ�.
	// template method : ���ϴ� �����Լ��� �ϴ� ���� �˰��� ����, ��å�����
	// factory method  : ���ϴ� �����Լ��� �ϴ� ���� ��ü�� ������ ����
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








