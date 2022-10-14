#include <iostream>

// 방법 3. 변하는 것을 다른 클래스로

// 아이템 획득에 따라, "상태(멤버 데이타)"는 변하지 않지만, 
// "동작(멤버함수)"는 변해야 합니다.


// 변하는 모든 동작을 인터페이스로 설계
struct IAction
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IAction() {}
	
	// 캐릭터의 다양한 동작들..
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



// 아이템에 따른 각 동작을 정의한 클래스 설계
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



// 객체지향 디자인 패턴에서
// 변하는 것을 인터페이스 기반으로 변경하는 것은 3개 입니다.


// strategy : 객체가 사용하는 알고리즘의 교체
// state    : 객체의 대부분의 동작을 교체(마치 다른 클래스를 사용하는 것처럼 보임)
// builder  : 복잡한 객체를 만들때, 
//			  과정은 동일한데, 각 과정의 표현이 달라지는 객체를 만들때

