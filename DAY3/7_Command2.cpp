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

struct ICommand
{
	virtual void execute() = 0;
	virtual bool canUndo() { return false; }
	virtual void undo() { }
	virtual ~ICommand() {}
};

// 도형은 추가하는 명령은 유사한 코드가 많습니다.
// 1. 기반 클래스를 설계해서 상속을 사용
// 2. template 기술로 한개 클래스만 설계!

class AddCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute() override { v.push_back(createShape() ); };
	virtual bool canUndo() override { return true; }
	virtual void undo()    override
	{
		auto p = v.back();
		v.pop_back();
		delete p;
	}
	// 객체를 만들기 위한 인터페이스를 제공하고, 사용하지만
	// 어떤 객체를 만들지는 파생 클래스가 결정한다.
	// "template method" 와 동일한 모양인데.. 변하는 가상함수가 하는일이
	// 객체의 생성이라면 "factory method" 라고도 합니다.
	virtual Shape* createShape() = 0;
};
class AddRectCommand : public AddCommand
{
public:
	AddRectCommand(std::vector<Shape*>& v) : AddCommand(v) {}
	
	virtual Shape* createShape() { return new Rect; }	
};
class AddCircleCommand : public AddCommand
{
public:
	AddCircleCommand(std::vector<Shape*>& v) : AddCommand(v) {}

	virtual Shape* createShape() { return new Circle; }
};

// 위 코드는 오래된 스타일 입니다.
// => command3으로 복사한 후에 "template" 으로 변경해 보세요..


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
			pcmd = new AddRectCommand(v);
			pcmd->execute();

			cmd_stack.push(pcmd); 

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
			if (!cmd_stack.empty())
			{
				pcmd = cmd_stack.top();
				cmd_stack.pop();

				if (pcmd->canUndo())
					pcmd->undo();

				delete pcmd;	
			}
		}
	}
}




