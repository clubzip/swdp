#include <iostream>

// ��� 2. ���ϴ� ���� �����Լ���..
// => �����ۿ� ���� ���ش� ���� �Լ��� ��� �����Լ��� �����.

class Charater
{
	int gold;
	int item;
public:
	void run()    { do_run(); }
	void attack() { do_attack(); }

	virtual void do_run()    { std::cout << "run" << std::endl; }
	virtual void do_attack() { std::cout << "attack" << std::endl; }
};
class RedStarItem : public Charater
{
public:
	virtual void do_run() { std::cout << "fast run" << std::endl; }
	virtual void do_attack() { std::cout << "power attack" << std::endl; }
};

int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();

	p = new RedStarItem;	// ������ ȹ��
							// �׷���, �� �ڵ�� ���� ĳ������ ���� ������ �ƴ�
							// ������ ����� ���ο� ĳ����!!

							// �츮�� ��ǥ�� "���� ��ü(ĳ����)"�� ������ ����Ǵ� ��
	p->run();
	p->attack();
}



