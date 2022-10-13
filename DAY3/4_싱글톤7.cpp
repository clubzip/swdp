#include <iostream>
#include <mutex>

// �Ʒ� �ڵ尡 "�ȵ���̵� �ҽ�" �� �ִ� �̱��� �ڵ��Դϴ�.
// github.com/aosp-mirror
// 
// platform system core
// 
// libutils/include/utils/Singleton.h ���� ������

template<typename T>
class Singleton
{
protected:
	Singleton() {}

private:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static std::mutex mtx;
	static T* sinstance; // <== 1
public:

	static T& getInstance() // <== 2
	{
		std::lock_guard<std::mutex> g(mtx); 

		if (sinstance == nullptr)
		{
			sinstance = new T;	// <== 3
		}
		return *sinstance;
	}
};

template<typename T> T* Singleton<T>::sinstance = nullptr; // <== 4
template<typename T> std::mutex Singleton<T>::mtx;

// Mouse �� ���� ����� �̱������� �ϰ� �ͽ��ϴ�.
class Mouse : public Singleton< Mouse >
{
};
int main()
{
	Mouse& c1 = Mouse::getInstance();
	Mouse& c2 = Mouse::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

}








