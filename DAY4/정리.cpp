
// 디자인 패턴의 핵심

// 1. 공통성과 가변성의 분리 => 변하는 것을 분리하라!!

//    => 변하는 것을 가상함수로    : template method, factory method
//    => 변하는 것을 다른 클래스로 : strategy, state, builder
//								 단위전략(policy base)


// 2. 재귀적 포함
//    => A는 B를 포함하는데 A 자신도 포함 가능
//    => A 와 B는 공통의 기반 클래스
//    => 재귀적 포함을 하는 의도가 뭔데 ??
// 
//    복합객체를 만들려고 : composite
//    객체에 동적 기능추가: decorator


// 3. 간접층의 도입..

// 핵심 : 왜?? 어떤의도로 간접층을 도입하는가 에 따라 패턴의 이름이 다름

// 사용자	 ===============> stack ====================> list
//									=> 의도 : 인터페이스의 변경
//									=> adapter
 
// 사용자	 ===============> TCPserver ================> socket, ipaddress
//									=> 의도 : 복잡한 절차를 대신하는
//											포괄적 개념의 인터페이스
//									=> facade

// 사용자	 ===============> MP3 ======================> IMP3
//									=> 의도 : update 의 편리함
//									=> bridge

// 사용자	 ===============> Calc =====================> remove server
//									=> 범용적 용도의 대행자
//									=> proxy




// 디자인 패턴은 용도에 따라 3가지로 분류 됩니다.

// 생성 패턴(5개) : 객체를 생성할때 사용하는 패턴
// 
// singleton : 한개의 객체만 생성
// prototype : 견본을 통한 객체의 생성 
// abstract factory : 공장도 인터페이스 부터 설계
// factory method   : 객체를 만들기 위한 인터페이스를 만들고 사용하지만
//					  어떤 객체를 만들지는 파생 클래스가 결정

// builder : 



// 구조 패턴(7개) : 구조를 변경하는 패턴

// 재귀적 포함 : composite, decorator
// 간접층 도입 : adapter, facade, bridge, proxy
// 객체의 공유 : flyweight



// 행위 패턴(11개)
//	가변성의 분리 : template method, strategy, state

//  통보, 전달   : observer, chain of responsibility
//  열거, 방문   : iterator, visitor

//  undo, 저장  : command, memento

//  객체간의 관계가 복잡하면 : mediator

//  컴파일러(파서)를 만들때 사용하는 패턴 : iterpreter ( 요즘은 사용안됨)


