// 6_Bridge1 - 90 page
#include <iostream>

// 모든 MP3 제품의 규칙.
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

class People
{
public:
//	void Use(IPod* p) // 강한 결합. 교체 안됨
	void Use(IMP3* p) // 인터페이스 사용. 약한 결한, 교체 가능
	{				  					  
		p->Play();
		p->Stop();

		// 그런데. 요구사항이 자주 발생한다.
		// => 1분 미리 듣기 기능을 만들어 달라!
		p->PlayOneMinute();
	}
};



int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


