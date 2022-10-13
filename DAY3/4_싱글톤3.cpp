// 7_�̱���1 - 123 page
#include <iostream>

// �ٽ� 1. �̱��� : ���� �Ѱ��� ��ü�� �����ϴ� ��.
//		   ���α׷��� ��𿡼��� ���� �Ѱ��� ��ü�� ������ ������� ���� �Ҽ� �ִ�.


// �ٽ� 2. �Ʒ� 3���� ��Ģ �˾� �μ���


// �ٽ� 3. ����

// => �ᱹ "��������" �� ������ Ư¡�� ������ �˴ϴ�.
// => "��������" �� ���ȭ�� �����ϰ�, �����ϴ�. 
// => �ǵ��� ������� ����� ����.

// ���� �Ѱ��� ��ü�� "��"�� �����ϴ� ��.

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* sinstance;
public:
	static Cursor& getInstance()
	{
		if (sinstance == nullptr)
		{
			sinstance = new Cursor;
		}
		return *sinstance;
	}
};
Cursor* Cursor::sinstance = nullptr;



int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

}








