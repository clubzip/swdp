#include <mutex>
// 방법 2. 변하는 것을 다른 클래스로 - strategy

// 다양한 동기화 정책을 담은 정책 클래스를 설계하자.

struct ISyncObject
{
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual ~ISyncObject() {}
};

template<typename T> class List
{
	ISyncObject* psync = nullptr;
public:
	void set_sync(ISyncObject* p) { psync = p; }

	void push_front(const T& a)
	{
		if (psync != nullptr) psync->lock();
		//......
		if (psync != nullptr) psync->unlock();
	}
};

class MutexLocker : public ISyncObject
{
	std::mutex m;
public:
	virtual void lock() override { m.lock();	}
	virtual void unlock() override { m.unlock(); }
};

List<int> st; 
int main()
{
	st.push_front(10); // st 에 동기화 정책을 전달하지 않았으므로 
						// 동기화 안됨..

	MutexLocker ml;
	st.set_sync(&ml);
	st.push_front(10); // ml 을 사용해서 동기화
}




