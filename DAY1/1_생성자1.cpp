//������1.cpp - 3page
#include <iostream>

// �ٽ� : ������ ȣ���� ������ ��Ȯ�� ���� ���ô�.

// 1. �����Ϸ��� "��� Ŭ���� �����ڸ� ȣ��" �ϴ� �ڵ带 Derived �����ڿ� �߰��Ѱ�
// ==> �Ʒ� Derived �� �ּ� ����.
// 
// 2. ���Ŭ����(Base) �� ����Ʈ �����ڰ� ���ٸ�..
// ==> �ݵ�� �Ļ� Ŭ�������� ��� Ŭ���� �����ڸ� ��������� ȣ���ϴ� �ڵ带 �ۼ��ؾ� �մϴ�.

class Base
{
public:
//	Base()     { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
public:	
	// ����ڰ� ���� �ڵ�		// �����Ϸ��� ������ �ڵ�
//	Derived()				// Derived() : Base()
	Derived() : Base(0)		// <= ����ڰ� ��� Ŭ���� �����ڸ� ��������� ȣ��
	{ 
		std::cout << "Derived()" << std::endl; 
	}
//	Derived(int a)			// Derived(int a) : Base()  // �����Ϸ��� �׻� ��� Ŭ������ ����Ʈ ������ ȣ�� 	
	Derived(int a) : Base(a)
	{ 
		std::cout << "Derived(int)" << std::endl; 
	}
	~Derived()		
	{ 
		std::cout << "~Derived()" << std::endl; 
		// �Ҹ��ڴ� ����ڰ� ���� �ڵ带 ���� �����ϰ�
		// ������ �κп� �����Ϸ��� �Ʒ� �ڵ� �߰�
		// ~Base()
	}
};
int main()
{
//	Derived d1;		// call Derived::Derived()
	Derived d2(5);  // call Derived::Derived(int)

}


// github.com/codenuri/hddp

// 1. ������Ʈ ���� �����ؾ� �մϴ�.
// => ������Ʈ �޴�, DAY1 �Ӽ� �޴� ����
// => �÷��� ��������, windows SDK ���� ���� �ϼ���
// => "Ctrl + F5" ������ ���� Ȯ���� ������.

// 2. �ҽ� ������ ���忡�� ����/���� �ϴ� ���

// ����
// 1. ������ ������ ���� �ϱ� ���� C++ ���� - 2�ð�
// 2. �پ��� ������ ���� ������ ���
// 3. ������ ���� ������ - 161page ~
