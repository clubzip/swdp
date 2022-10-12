#include <mutex>
// 동기화 정책을 변경가능하게 설계해 봅시다.

// 방법 1. 변하는 것을 가상함수로!! template method

template<typename T> class List
{
public:
	void push_front(const T& a)
	{
		lock();
		//......
		unlock();
	}
	virtual void lock()   {}
	virtual void unlock() {}
};
// 의도 : 동기화 하려면 List 파생 클래스를 만들어서 lock()/unlock() 을
//       override 하라는 것
template<typename T> class ThreadSafeList : public List<T>
{
	std::mutex m;
public:
	virtual void lock()   { m.lock(); }
	virtual void unlock() { m.unlock(); }
};


List<int> st; 

int main()
{
	st.push_front(10);
}




