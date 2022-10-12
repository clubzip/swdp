#include <mutex>

// ���� ����(Policy Base Design)
// => ���ø� ���ڷ� �پ��� ��å�� ���� Ŭ������ ���� �޾Ƽ�
// => Ŭ������ ��� �Լ� �ۼ��� "��å Ŭ����"�� �����ؼ� �ڵ带 �ۼ��ϴ°�

// => Ŭ������ �پ��� ��å�� "�������� ����" ��ü �Ҽ� �ִ�.

// ��å Ŭ������ ��ü�ϴ� 2���� ���

//					strategy				policy base design
// ��ü ���			interface ���			���ø� ���� ���
//					st.set_sync(&ml)		List<int, MutexLocker>

// ����ð� ��ü����	����ð� ��ü ����			����ð� ��ü �ȵ�.
//					st.set_sync �ٽ�ȣ��		=> ���ø� ���ڴ� �����Ҷ� ��ü�ȵ�

// ����				�����Լ����. ������.		�ζ��� ġȯ. ������.
// 
// �Լ��̸�			�������̽��� ���			����ȭ�� ���.
//											C++20 ���ʹ� concept���� ��Ӱ���										

// ���� !! STL �� �����̳ʰ� �̷��� �Ȱ��� �ƴմϴ�.(STL �����̳ʴ� ����ȭ �ȵ�)
// => STL �� �ٸ� �뵵�� �̱���� ����մϴ�.

// webkit �� List�� �̷��� �Ǿ� �ֽ��ϴ�.


template<typename T, typename ThreadModel = NoLock > class List
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

List<int> st3; // ����Ʈ �Ķ������ NoLock ���.. ����ȭ �ȵ�.

int main()
{
	st1.push_front(10);

}




