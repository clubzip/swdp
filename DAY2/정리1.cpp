// 정리1

// 핵심 : 공통성과 가변성의 분리
//       => 변하지 않은 코드에서 변하는 코드는 분리되어야 한다.

1. 변하는 것을 가상함수로
=> template method
=> 상속 기반의 패턴
=> 실행시간 교체 안되고, 정책을 다른 클래스에서 사용못함 
=> 도형 편집기 예제  Draw/DrawImp 

2. 변하는 것을 클래스로 분리 ( 정책(전략) 클래스 )
=> 정책 클래스를 어떻게 교체 할것인가 ?
A. 인터페이스를 설계해서 교체
   => strategy 패턴
   => 실행시간 교체 가능
   => 가상함수 기반이므로 느리다.
   => Edit/IValidator 예제

B. 템플릿 인자로 교체 
	=> 단위 전략 디자인(policy base design)
	=> 실행시간 교체 안됨
	=> 인라인 치환 가능. 빠르다.
	=> List<int, MutexLocker> 예제, vector<int, debug_alloc<int>> 예제

// 디자인 패턴 : 언어에 무관하게 사용할수 있는 객체지향 디자인 기술
//				=> strategy, template method 
// 
// IDioms    : 각 언어의 특징을 고려한 디자인 기술
// C++ IDioms: policy base design



