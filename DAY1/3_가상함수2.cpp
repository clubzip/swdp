#include <iostream>

// C++ ���� �ݵ�� �˾ƾ� �ϴ� ��Ģ
// => ��� Ŭ������ �Ҹ��ڴ� "public virtual" �̰ų�
//    "protected non-virtual" �̾�� �Ѵ�.

class Base
{
public:
	virtual ~Base() {}
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
int main()
{
//	Derived d;

//	Derived* p1 = new Derived;	// ��ü ���� - ������ ȣ��
//	delete p1;					// ��ü �ı� - �Ҹ��� ȣ��

	// �Ʒ� �ڵ尡 �� �ҽ��� �ٽ� �Դϴ�. �����ؼ� ��� Ȯ���� ������.
	Base* p1 = new Derived;

	// �Ҹ��ڵ� �Լ� ȣ���Դϴ�. �Ʒ� ó�� ǥ���ϸ�
	delete p1;
		// 1. �����Ϸ��� p1�� "Base*" �̹Ƿ� Base ���� �Ҹ��ڰ� �������� ����
		// => Base �Ҹ��ڰ� �����Լ��� �ƴϸ� ������ ������ Ÿ������ ȣ��
		//		~Base() �Լ��� ȣ�� 

		// => Base �Ҹ��ڰ� �����Լ� ���
		//	  p1�� ����Ű�� �޸��� ��ü�� �����ϴ� �ڵ带 �����ϰ�
		//	  ����� �����ؼ� �Ҹ��� ȣ���� ����
}	
