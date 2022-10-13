// �̱���6 - 4�������� ������.

#include <iostream>
#include <mutex>

// RAII ��� C++ IDioms 
// => "Resource Acquision Is Initialization" �� ����
// => "�ڿ��� ȹ���ϴ� ���� (�ڿ�������ü) �� �ʱ�ȭ �ɶ�(������)"�̴�.
// 
// �ڿ��� ȹ��/�ݳ� �ϴ� ���� ������/�Ҹ��ڸ� ����ؼ� �ؾ� �մϴ�.
template<typename T> struct lock_guard
{
	T& mtx;	
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); }
};



class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;



	static std::mutex mtx;
	static Cursor* sinstance;
public:

	static Cursor& getInstance()
	{
		{
//			lock_guard<std::mutex> g(mtx);		// �����ڿ��� lock ����
			sdt::lock_guard<std::mutex> g(mtx); // C++ ǥ�ؿ� �̹� �ֽ��ϴ�.

			//		mtx.lock();
			if (sinstance == nullptr)
			{
				sinstance = new Cursor;
			}
			//		mtx.unlock();	// <<= �ڿ��� �ݳ��� �̷��� �������� ������
									// 1. �Ǽ��� �� ������ �����Ҽ� �ִ�.
									// 2. �� �ڵ��� ���ʿ��� ���ܵ��� ���� �߻��ϸ�
									//	  �� �ڵ尡 ������� �ʽ��ϴ�.
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








