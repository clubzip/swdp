#include <iostream>

// C++ ���� �ݵ�� �˾ƾ� �ϴ� ��Ģ
// => ��� Ŭ������ �Ҹ��ڴ� "public virtual" �̰ų�
//    "protected non-virtual" �̾�� �Ѵ�.

class Base
{
	// �����Լ��� �������(�����Լ� ���̺�)�� ���ֱ� ���ؼ�
	// ���� �Ҹ��ڸ� "non-virtual" �׸���, "protected"�� ���� ����� �ֽ��ϴ�.
protected:
	~Base() {}
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};

int main()
{
	Base* p1 = new Derived;
	delete p1;	// error. �Ҹ��ڰ� protected�� �����Ƿ�..

	delete static_cast<Derived*>(p1); // ok..
}
