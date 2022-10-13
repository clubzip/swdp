// 싱글톤6 - 4번복사해 오세요.

#include <iostream>
#include <mutex>

// RAII 
// 자원을 획득/반납 하는 것은 생성자/소멸자를 사용해서 해야 합니다.
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
		lock_guard<std::mutex> g(mtx);
//		mtx.lock();
		if (sinstance == nullptr)
		{
			sinstance = new Cursor;
		}
//		mtx.unlock();	// <<= 자원을 반납을 이렇게 직접하지 마세요
						// 1. 실수로 이 한줄을 생략할수 있다.
						// 2. 이 코드의 위쪽에서 예외등의 일이 발생하면
						//	  이 코드가 실행되지 않습니다.

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








