class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;
	Dog* p1 = &d;	// ok
//	int* p2 = &d;	// error

	// �ٽ� 1. ��� Ŭ���� Ÿ���� ������(�Ǵ� ����)�� �Ļ� Ŭ������ �ּҸ�
	//		  ������ �ִ�.
	// => "Upcasting" �̶�� �մϴ�.

	Animal* p3 = &d;// ok
	Animal& r = d;  // ok

	// �ٽ� 2. ��� Ŭ���� Ÿ���� ������(����)�� ��� Ŭ���� ����� ����ų�� �ִ�.
	// => C++�� "static type check" ��� �Դϴ�.
	// => ������ �ð��� "p3" �� ����Ÿ Ÿ���� ���� ���� ���θ� �Ǵ�
	// => ���̽��� "dynamic type check" ���.
	//    ����� �޸𸮿� color �� ������ ���� �ƴϰ�, ������ ���� �߻�
	p3->age = 10;	// ok
//	p3->color = 10;	// error

	
	// �ٽ� 3. p3(Animal*) �� Dog ��ü�� ����ų��
	//        Dog �� ���� ����� �����Ϸ��� ĳ�����ؼ� �����ϸ� �˴ϴ�.
	static_cast<Dog*>(p3)->color = 10;
			// ��, �̰�� p3�� ����Ű�� ���� Dog ��� Ȯ���� �־�� �մϴ�.
			// �˼� ���� ���, "dynamic_cast" ���

}











