#include <iostream>



// ��ü���� ī�޶� ���� ������ ����,
// ī�޶� ���Ѿ� �ϴ� ��Ģ�� ���� �����մϴ�.

// ��Ģ : ��� ī�޶�� �Ʒ� Ŭ������ ���� ��� �޾ƾ� �Ѵ�.

class ICamera
{
public:
	virtual void Take() = 0;
};

// ����, ��ü���� ī�޶�� ������, ��Ģ�� �ֽ��ϴ�.
// ����ڴ� ��Ģ ��θ� ����ϸ� �˴ϴ�.
class People
{
public:
	virtual void UseCamera(ICamera* p) { p->Take(); }
};

// ����, ��� ī�޶���� �ݵ�� ��Ģ�� ���Ѿ� �մϴ�.

class Camera : public ICamera
{
public:
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};
class UHDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take 4K Picture" << std::endl; }
};
int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc); 

	UHDCamera uhc;
	p.UseCamera(&uhc);

}






