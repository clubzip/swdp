#include <iostream>
// upcasting3.cpp
class Animal 
{
public: 
	int age;
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

	Dog* pDog = static_cast<Dog*>(p);
	std::cout << pDog << std::endl;
}

int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}












