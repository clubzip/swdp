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
	// 아래 함수를 100번 호출했을 때는 생각해 보세요
	// => 어떤 문제점이 있을까요 ?
	// => 최초 객체를 만들때는 동기화가 필요 하지만 만든후에는 동기화 필요 없습니다.
	// => 그런데, 99번의 나머지 호출에 대해서도 lock/unlock 을 하게 됩니다.
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
	// 1번째 호출    : if 문을 2번 사용하게 됩니다. - 약간의 오버헤드 발생
	// 1번째 호출이후 : lock/unlock 을 사용하지 않게 됩니다.

	// DCLP : "Double Check Locking Pattern" 이라는 이름을 가진 기술입니다.
	// => java, C# 에서는 안전합니다. 
	// => C++에서는 버그 입니다. 사용하지 마세요. 
	// => 2004년경에 effective-c++ 저자의 논문..

	static Cursor& getInstance()
	{
		if (sinstance == nullptr)
		{
			mtx.lock();

			if (sinstance == nullptr)
			{
				sinstance = new Cursor;

				// 위 한줄은 아래의 3줄처럼 실행됩니다.
				// => 아래 주석에서 temp 는 컴파일러가 임시로 만드는 변수 입니다.
				// => 그런데, 아래 코드순서를 약간 변경하면 temp 가 필요 없습니다.
				// 
				// 1. Cursor 크기 메모리 할당 : temp = malloc(sizeof(Cursor))
				// 2. Cursor 생성자 호출		: temp.Cursor()
				// 3. 할당된 메모리 주소를 sinstance에 넣기 : sinstance = temp

				// 최적화 하면서 아래 처럼 변경합니다.
				// 1. Cursor 크기 메모리 할당 : sinstance = malloc(sizeof(Cursor))
				// 2. 생성자 호출            : sinstance.Cursor();


				// 해결책 : 컴파일러가 최적화 하면서 순서를 변경하지 못하도록 하면됩니다.
				// C++11 부터 나오는
				// std::atomic_thread_fence() 같은 함수를 사용하면 됩니다.
				// 구글에서 "C++11 DCLP atomic"
				// => "Double-Checked Locking is Fixed In C++11" 보세요


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








