// 2_�����Լ�������
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// �ٽ� 1. �����Լ� �����ǽ� "virtual" �� �ٿ��� �ǰ� �Ⱥٿ��� �˴ϴ�.
	// => ������ ���̴� ���� "������"�� �����ϴ�.
	// virtual void foo() {}


	// �ٽ� 2. �����Լ� �����ǽ� �Ǽ�(��Ÿ)�� �־ ������ �ƴմϴ�.
	// => �� ������ �ذ��ϱ� ���� C++11 ���� "override" Ű���� ����
	// => ���ο� �Լ��� ����� ���� �ƴ� "��� Ŭ���� �Լ��� �������Ѵ�"�� �˷��ִ°�
//	virtual void fooo()  {}		// ���� �ƴ�
// 	virtual void goo(double)  {}

	virtual void fooo()      override {} // error
	virtual void goo(double) override {} // error

};

int main()
{
}





