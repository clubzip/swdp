#include <iostream>
#include <mutex>

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;



	static std::mutex mtx;
	static Cursor* sinstance;
public:
	/*
	// �Ʒ� �Լ��� 100�� ȣ������ ���� ������ ������
	// => � �������� ������� ?
	// => ���� ��ü�� ���鶧�� ����ȭ�� �ʿ� ������ �����Ŀ��� ����ȭ �ʿ� �����ϴ�.
	// => �׷���, 99���� ������ ȣ�⿡ ���ؼ��� lock/unlock �� �ϰ� �˴ϴ�.
	static Cursor& getInstance()
	{
		mtx.lock();
		if (sinstance == nullptr)
		{
			sinstance = new Cursor;
		}
		mtx.unlock();

		return *sinstance;
	}
	*/
	// 1��° ȣ��    : if ���� 2�� ����ϰ� �˴ϴ�. - �ణ�� ������� �߻�
	// 1��° ȣ������ : lock/unlock �� ������� �ʰ� �˴ϴ�.

	// DCLP : "Double Check Locking Pattern" �̶�� �̸��� ���� ����Դϴ�.
	// => java, C# ������ �����մϴ�. 
	// => C++������ ���� �Դϴ�. ������� ������. 
	// => 2004��濡 effective-c++ ������ ��..

	static Cursor& getInstance()
	{
		if (sinstance == nullptr)
		{
			mtx.lock();

			if (sinstance == nullptr)
			{
				sinstance = new Cursor;

				// �� ������ �Ʒ��� 3��ó�� ����˴ϴ�.
				// => �Ʒ� �ּ����� temp �� �����Ϸ��� �ӽ÷� ����� ���� �Դϴ�.
				// => �׷���, �Ʒ� �ڵ������ �ణ �����ϸ� temp �� �ʿ� �����ϴ�.
				// 
				// 1. Cursor ũ�� �޸� �Ҵ� : temp = malloc(sizeof(Cursor))
				// 2. Cursor ������ ȣ��		: temp.Cursor()
				// 3. �Ҵ�� �޸� �ּҸ� sinstance�� �ֱ� : sinstance = temp

				// ����ȭ �ϸ鼭 �Ʒ� ó�� �����մϴ�.
				// 1. Cursor ũ�� �޸� �Ҵ� : sinstance = malloc(sizeof(Cursor))
				// 2. ������ ȣ��            : sinstance.Cursor();


				// �ذ�å : �����Ϸ��� ����ȭ �ϸ鼭 ������ �������� ���ϵ��� �ϸ�˴ϴ�.
				// C++11 ���� ������
				// std::atomic_thread_fence() ���� �Լ��� ����ϸ� �˴ϴ�.
				// ���ۿ��� "C++11 DCLP atomic"
				// => "Double-Checked Locking is Fixed In C++11" ������


			}
			mtx.unlock();
		}

		return *sinstance;
	}

};
Cursor* Cursor::sinstance = nullptr;
std::mutex Cursor::mtx;



int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

}








