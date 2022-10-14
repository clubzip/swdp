// 6_Bridge1 - 90 page
#include <iostream>

// ��� MP3 ��ǰ�� ��Ģ.
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
//	void Use(IPod* p) // ���� ����. ��ü �ȵ�
	void Use(IMP3* p) // �������̽� ���. ���� ����, ��ü ����
	{				  					  
		p->Play();
		p->Stop();

		// �׷���. �䱸������ ���� �߻��Ѵ�.
		// => 1�� �̸� ��� ����� ����� �޶�!
		p->PlayOneMinute();
	}
};



int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


