#include <mutex>
// ����ȭ ��å�� ���氡���ϰ� ������ ���ô�.

// ��� 1. ���ϴ� ���� �����Լ���!! template method

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
// �ǵ� : ����ȭ �Ϸ��� List �Ļ� Ŭ������ ���� lock()/unlock() ��
//       override �϶�� ��
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




