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

// ������ �߰��ϴ� ������ ������ �ڵ尡 �����ϴ�.
// 1. ��� Ŭ������ �����ؼ� ����� ���
// 2. template ����� �Ѱ� Ŭ������ ����!

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
	// ��ü�� ����� ���� �������̽��� �����ϰ�, ���������
	// � ��ü�� �������� �Ļ� Ŭ������ �����Ѵ�.
	// "template method" �� ������ ����ε�.. ���ϴ� �����Լ��� �ϴ�����
	// ��ü�� �����̶�� "factory method" ����� �մϴ�.
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

// �� �ڵ�� ������ ��Ÿ�� �Դϴ�.
// => command3���� ������ �Ŀ� "template" ���� ������ ������..


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



