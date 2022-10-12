#include <mutex>
// ��� 2. ���ϴ� ���� �ٸ� Ŭ������ - strategy

// �پ��� ����ȭ ��å�� ���� ��å Ŭ������ ��������.

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
	st.push_front(10); // st �� ����ȭ ��å�� �������� �ʾ����Ƿ� 
						// ����ȭ �ȵ�..

	MutexLocker ml;
	st.set_sync(&ml);
	st.push_front(10); // ml �� ����ؼ� ����ȭ
}




