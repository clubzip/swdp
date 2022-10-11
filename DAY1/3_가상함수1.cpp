#include <iostream>

class Animal
{
public:
	void cry1() { std::cout << "Animal Cry1" << std::endl; } 

	// virtual function : �Լ� ȣ���� �����Ҷ� ������ �ð��� �ƴ�
	//					  ����ð��� �޸𸮸� ������ ������ �޶�� ��
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; }
};
class Dog : public Animal
{
public:
	// function override : ��� Ŭ���� ��� �Լ��� �Ļ� Ŭ������ �ٽ� ����°�
	void cry1() { std::cout << "Dog Cry1" << std::endl; } 

	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; }
};


int main()
{
	Dog d;
	Animal* p = &d; 

	// C++���� ��� �Լ��� ȣ���ϴ� ����
	// => ������ �Ҷ� �����Ϸ��� ����, ������ "������ Ÿ��" ���� ȣ��
	// => ���� : ������ �Ҷ� ������ ������. ����� ������尡 ����.

	p->cry1(); // Animal Cry
				// call Animal::cry1 ����  ������ �Ϸ�

	// �����Լ��� virtual �̶��
	// => ������ �Ҷ� p�� ����Ű�� �޸𸮸� �����ϴ� ���� �ڵ� ����
	// => ����� p�� ����Ű�� ��ü�� ��Ȯ�� �����ؼ� ȣ��
	// => ���� : �������� �´� ȣ��
	//    ���� : ����ð��� �����ؾ� �ϹǷ� ������.
	p->cry2(); // Dog Cry
				// 1. p�� ����Ű�� ���� �����ϴ� ���� ����
				// 2. �������� ���� ȣ��
}




