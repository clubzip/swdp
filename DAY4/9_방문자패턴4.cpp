// 방문자 패턴의 의미!!
class Shape
{
	virtual void Draw() = 0;
};
class Rect : public Shape {};
class Circle : public Shape {};


// 전통적인 객체지향 디자인 - ? 자리에 (1). 쉽다  (2). 어렵다 로 채워 보세요.

// 클래스의 추가    :  쉽다!!(다형성을 잘 지켰다면...)

// 가상 함수의 추가 :  어렵다 ( 기존에 만든 모든 도형을 수정해야 한다.)

// 전통적인 객체지향 디자인은 "클래스 추가"는 쉽고, "가상함수 추가"는 어렵다!







// 그런데, Move()라는 가상함수를 추가하지말고!!
ShapeMoveVisitor v;
컨테이너.accept(&v); // 이렇게 하면 ??


// 방문자 패턴으로 디자인 하면
// 
// 클래스의 추가   : 어렵다. 
//					IMenuVisitor 를 생각해 보세요.
//					새로운 메뉴 추가시 인터페이스가 변경되어야 합니다.
// 
// 가상 함수의 추가 : 쉽다(진짜 가상함수의 추가가 아닌..
//					 가상함수가 할일을 "방문자" 로 구현하면 된다는 것)
//					