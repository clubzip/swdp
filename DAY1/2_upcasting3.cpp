#include <iostream>
// upcasting3.cpp
class Animal 
{
public: 
	int age;
	virtual ~Animal() {} // ��κ��� ��� Ŭ������ �Ҹ��ڸ� �������� �ϰԵ˴ϴ�.
};
class Cat : public Animal 
{
};
class Dog : public Animal
{
public:
	int color;
};
// upcasting �� ���� 2. ������ ó���ϴ� �Լ� �����.
//void NewYear(Dog* p)  // Dog �� ������ �ִ� �Լ�
void NewYear(Animal* p) // ��� ������ ������ �ִ� �Լ�
{
	++(p->age); // ���ذ� �Ǹ� ���̰� ����.
	
	// ������ ������ ���ο� �䱸 ������ �����.
	// p �� ����Ű�� ���� Dog ��� color �� �����ϰ� �ʹ�.
//	p->color = 10; // error. p �� "Animal*" �̹Ƿ� color ���� �ȵ�.

	// static_cast : p�� ����Ű�� ���� Dog �� �ƴ϶� ĳ���ÿ� �����մϴ�.
	//               �̰�� "p->color = 10" �ϸ� �߸��� �����Դϴ�.
//	Dog* pDog = static_cast<Dog*>(p);
//	std::cout << pDog << std::endl;

	// static_cast �� "p�� ����Ű�� ���� Dog��� Ȯ��" �� �������� ����ϼ���
	// dynamic_cast : p �� ����Ű�� ���� Dog�� �ƴϸ� 0 ��ȯ
	//				  ����ð��� �����Լ� ���̺��� ����ؼ� �����ϰ� �˴ϴ�
	//				  => ����, �����Լ��� �ִ� Ÿ�Ը� ��밡���մϴ�.

	Dog* pDog = dynamic_cast<Dog*>(p);
	std::cout << pDog << std::endl;

	if (pDog != nullptr) // �̷��� Ȯ���� ���
	{
		pDog->color = 10; // 
	}
}

int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}












