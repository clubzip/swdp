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

// �Ʒ� Ŭ������ Bridge(�߻�)�Դϴ�.
// ���� MP3�� ������ ������, ����ڴ� �Ʒ� Ŭ������ ����ϰ� �˴ϴ�.

// ������(IMP3)�� �߻��(����ڰ� ����ϴ� ����)�� �и��ؼ�
// ��ȣ �������� update �� �����ϰ� �Ѵ�.
// => ������ �ø��� update �� �������ٴ� ����

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
		// 1�е�..
		impl->Stop();
	}
};


class People
{
public:
//	void Use(IP3* p) // �������̽��� ���� ���.
					 // �䱸������ ��� ����� update �� ��ƴ�.
	void Use(MP3* p) // �߰��� (bridge) ���, �䱸���ǿ� ���� ������ ������ ����.
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


