#include <iostream>

struct IMP3
{
	virtual void Play() = 0;
	virtual void Stop() = 0;

	virtual ~IMP3() {}
};


class IPod : public IMP3
{
public:
	void Play() { std::cout << "Play MP3 with IPod" << std::endl; }
	void Stop() { std::cout << "Stop" << std::endl; }
};

// 아래 클래스가 Bridge(추상)입니다.
// 실제 MP3의 구현은 없지만, 사용자는 아래 클래스를 사용하게 됩니다.

// 구현부(IMP3)과 추상부(사용자가 사용하는 계층)을 분리해서
// 상호 독립적인 update 가 가능하게 한다.
// => 계층을 늘리면 update 가 쉬워진다는 개념

class MP3
{
	IMP3* impl; 
public:
	MP3(IMP3* p = nullptr) : impl(p)
	{
		if (impl == nullptr)
			impl = new IPod;
	}

	void Play() { impl->Play(); }
	void Stop() { impl->Stop(); }

	void PlayOneMinute()
	{
		impl->Play();
		// 1분뒤..
		impl->Stop();
	}
};


class People
{
public:
//	void Use(IP3* p) // 인터페이스를 직접 사용.
					 // 요구조건이 계속 생기면 update 가 어렵다.
	void Use(MP3* p) // 중간층 (bridge) 사용, 요구조건에 대한 대응이 유연해 진다.
	{
		p->Play();
		p->Stop();

		p->PlayOneMinute();
	}
};





int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


