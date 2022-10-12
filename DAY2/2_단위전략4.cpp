#include <mutex>

template<typename T, typename ThreadModel > class List
{
	ThreadModel tm;
public:
	void push_front(const T& a)
	{
		tm.lock();
		
		//......

		tm.unlock();
	}
};
// 이에 List 의 2번째 템플릿 인자로 사용할 동기화 정책 클래스를 만들어서 제공합니다.
// => 조건, 반드시 "lock/unlock" 함수가 있어야 합니다.

class MutexLocker
{
	std::mutex mtx;
public:
	inline void lock()   { mtx.lock(); }
	inline void unlock() { mtx.unlock(); }
};
class NoLock
{
public:
	inline void lock() {  }
	inline void unlock() {  }
};
//----------------------------------------
List<int, NoLock>      st1;
List<int, MutexLocker> st2;

int main()
{
	st1.push_front(10);

}




