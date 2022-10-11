// 생성자를 protected 에 놓는 이유
// => 자신은 객체를 생성할수 없지만(추상적인 존재)
// => 파생 클래스는 객체를 생성할수 있게 하겠다(구체적인 존재)

// 객체지향디자인에서 추상(abstract)의 반대의미를 구체(concrete)라고 합니다.


class Animal
{
protected:
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {} // Dog() : Animal() {} // Animal 생성자가 protected라도
									// error 아님.
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
	Animal a;	// error. 
	Dog    d;	// ok
}



