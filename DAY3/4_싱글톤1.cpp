// 7_�̱���1 - 123 page
#include <iostream>

// �̱��� : ���� �Ѱ��� ��ü�� �����ϴ� ��.

class Cursor
{
	// ��Ģ 1. �����ڸ� private ��
private:
	Cursor() {}

	// ��Ģ 2. �����Ϸ����� ����Ʈ ���� �����ڸ� ������ ����� ��û
	// => ���� �����ڸ� �����ϸ�, ���Կ����ڵ� �����ϴ� ���� �����Դϴ�.
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;


	// ��Ģ 3. ���� �Ѱ��� ��ü�� ���� ��ȯ�ϴ� static ��� �Լ�
public:
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};
int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

//	Cursor c3 = c1; // ���� �����ڸ� ����ؼ� ��ü ����.
					// �̷��� �����ϴ� �͵� ���ƾ� �մϴ�.
					// 
//	Cursor c1, c2; // error


}








