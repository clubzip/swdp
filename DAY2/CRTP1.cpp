#include <iostream>

// CRTP : Curiosly Recurring Template Pattern
// => C++ IDioms( C++ �������� ���)
// => ��� Ŭ���� ���鶧 �Ļ� Ŭ���� �̸��� ����Ҽ� �ְ� �ϴ� ���

template<typename T>
class Base
{
public:
	void foo()
	{
		// ���⼭ �Ļ� Ŭ���� �̸� ����Ҽ� ������ ?
		T obj;

		std::cout << typeid(obj).name() << std::endl; // Ÿ���̸� ���
	}
};
// ���� Base �� �Ļ� Ŭ������ ���鶧 Base�� ���ø� ���ڷ� �ڽ��� �̸��� �˷��ָ� �˴ϴ�.
class Derived : public Base< Derived >
{
};
int main()
{
	Derived d;
	d.foo();
}