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

	// 핵심 1. 기반 클래스 타입의 포인터(또는 참조)로 파생 클래스의 주소를
	//		  담을수 있다.
	// => "Upcasting" 이라고 합니다.

	Animal* p3 = &d;// ok
	Animal& r = d;  // ok

	// 핵심 2. 기반 클래스 타입의 포인터(참조)는 기반 클래스 멤버만 가리킬수 있다.
	// => C++은 "static type check" 언어 입니다.
	// => 컴파일 시간에 "p3" 의 데이타 타입을 보고 오류 여부를 판단
	// => 파이썬은 "dynamic type check" 언어.
	//    실행시 메모리에 color 가 있으면 에러 아니고, 없으면 예외 발생
	p3->age = 10;	// ok
//	p3->color = 10;	// error

	
	// 핵심 3. p3(Animal*) 로 Dog 객체를 가리킬때
	//        Dog 의 고유 멤버에 접근하려면 캐스팅해서 접근하면 됩니다.
	static_cast<Dog*>(p3)->color = 10;
			// 단, 이경우 p3가 가리키는 곳이 Dog 라는 확신이 있어야 합니다.
			// 알수 없는 경우, "dynamic_cast" 사용

}











