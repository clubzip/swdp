//1_�߻�Ŭ����2.cpp
#include <iostream>

// OCP
// ��� Ȯ�忡 �����ְ�(Open, Ŭ����/����� �߰� �Ǵ���)
// �ڵ� �������� �����־��(Close, ���� �ڵ�� �������� �ʰ� )
// ������ �϶�� ��Ģ(Principle)

// ���� ����� ��Ģ(Open Close Principle)

// ��ü���� S/W ������ ��Ģ 5����
// => SRP, OCP, LSP, ISP, DIP  => "SOLID" ��Ģ

// ���� ����(tightly coupling )
// => �ϳ��� Ŭ������ �ٸ� Ŭ���� ����, "Ŭ���� �̸�"�� ���� ����ϴ� ��
// => ��ü �Ұ�����, ���� �� ������, OCP ���� ����.




class Camera
{
public:	
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:	
	void UseCamera(Camera* p)   { p->Take(); }
	void UseCamera(HDCamera* p) { p->Take(); }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc); // ???

}






