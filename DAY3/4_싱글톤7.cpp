
#include <iostream>
#include <mutex>

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



// Mouse 도 힙에 만드는 싱글톤으로 하고 싶습니다.
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








