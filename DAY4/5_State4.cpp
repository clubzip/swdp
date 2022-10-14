#include <iostream>

// ��� 3. ���ϴ� ���� �ٸ� Ŭ������

// ������ ȹ�濡 ����, "����(��� ����Ÿ)"�� ������ ������, 
// "����(����Լ�)"�� ���ؾ� �մϴ�.


// ���ϴ� ��� ������ �������̽��� ����
struct IAction
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IAction() {}
	
	// ĳ������ �پ��� ���۵�..
//	virtual void slide() = 0;
//	virtual void jump() = 0;
};

class Charater
{
	int gold;
	int item;
	IAction* paction = nullptr;
public:
	void set_state(IAction* p) { paction = p; }

	void run()    { ? }
	void attack() { ? }
};



// �����ۿ� ���� �� ������ ������ Ŭ���� ����
class RedItemAction : public IAction
{
public:
	virtual void run() override { std::cout << "fast run" << std::endl; }
	virtual void attack() override { std::cout << "attack" << std::endl; }
};
class BlueItemAction : public IAction
{
public:
	virtual void run() override { std::cout << "run" << std::endl; }
	virtual void attack() override { std::cout << "power attack" << std::endl; }
};
class NoItemAction : public IAction
{
public:
	virtual void run() override { std::cout << "run" << std::endl; }
	virtual void attack() override { std::cout << "attack" << std::endl; }
};

int main()
{
	NoItemAction   na;
	BlueItemAction ba;
	RedItemAction  ra;

	Charater* p = new Charater;
	p->set_state(&na);
	p->run();
	p->attack();

	p->set_state(&ra);	
	p->run();
	p->attack();

}



// ��ü���� ������ ���Ͽ���
// ���ϴ� ���� �������̽� ������� �����ϴ� ���� 3�� �Դϴ�.


// strategy : ��ü�� ����ϴ� �˰����� ��ü
// state    : ��ü�� ��κ��� ������ ��ü(��ġ �ٸ� Ŭ������ ����ϴ� ��ó�� ����)
// builder  : ������ ��ü�� ���鶧, 
//			  ������ �����ѵ�, �� ������ ǥ���� �޶����� ��ü�� ���鶧

