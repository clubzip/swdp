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
// �̿� List �� 2��° ���ø� ���ڷ� ����� ����ȭ ��å Ŭ������ ���� �����մϴ�.
// => ����, �ݵ�� "lock/unlock" �Լ��� �־�� �մϴ�.

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




