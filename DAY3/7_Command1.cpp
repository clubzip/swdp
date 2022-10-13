#include <iostream>
#include <vector>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};


// 메뉴 선택시 어떤 작업을 해야 한다면
// C언어  : "어떤 작업" 을 함수로 만들고 메뉴 선택시 해당함수 호출.

// 객체지향: 모든 것은 객체이다. 기본 단위는 함수가 아닌 클래스이다.

// 메뉴 선택시 해야할 일을 담은 "명령 클래스"의 인터페이스
struct ICommand
{
	virtual void execute() = 0;
	virtual bool canUndo() { return false; }
	virtual void undo() { }
	virtual ~ICommand() {}
};

// 각 메뉴를 선택시 해야할일을 담은 클래스 설계
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute() override { v.push_back(new Rect); };
	virtual bool canUndo() override { return true; }
	virtual void undo()    override 
	{
		auto p = v.back();
		v.pop_back();
		delete p;
	}
};
class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute() override { v.push_back(new Circle); };
	virtual bool canUndo() override { return true; }
	virtual void undo()    override
	{
		auto p = v.back();
		v.pop_back();
		delete p;
	}
};

class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute() override 
	{
		for (auto p : v)
			p->draw();
	};

	virtual bool canUndo() override { return true; }
	virtual void undo()    override
	{
		system("cls");
	}
};

#include <stack>

int main()
{
	std::vector<Shape*> v;

	std::stack<ICommand*> cmd_stack;

	ICommand* pcmd = nullptr;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			// 메뉴 선택시,
			// C언어라면 : 해당 기능을 수행하는 함수 호출
			// 객체지향 : 해당 기능을 수행하는 객체 생성후 기능수행

			pcmd = new AddRectCommand(v);
			pcmd->execute();

			cmd_stack.push(pcmd); // undo 를 위해 스택에 보관
			
		}
		else if (cmd == 2)
		{
			pcmd = new AddCircleCommand(v);
			pcmd->execute();

			cmd_stack.push(pcmd); 
		}
		else if (cmd == 9)
		{
			pcmd = new DrawCommand(v);
			pcmd->execute();

			cmd_stack.push(pcmd);
		}
		else if (cmd == 0)
		{
			if (cmd_stack.empty()) break;

			pcmd = cmd_stack.top();
			
			if (pcmd->canUndo())
				pcmd->undo();

			delete pcmd;	// redo 하고 싶다면 delete 하지말고
							// redo_stack.push(pcmd) 하면 됩니다.
		}
	}
}




