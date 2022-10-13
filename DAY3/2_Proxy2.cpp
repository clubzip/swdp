#define USING_GUI
#include "cppmaster.h"

// proxy 패턴    : 대행자를 만드는 패턴
// remote proxy : 원격지 서버에 대한 대행자

// proxy 를 통해서 다양한 기능을 추가 할수 있다.
// => 보안, ID & PASSWD 확인
// => 자주 사용하는 연산에 대한 캐쉬!!
// => 서버가 살아 있는지 종료 되었는지 확인(안드로이드의 alive 기능)

// proxy : 함수 호출을 명령코드로 변경 해서 서버에 전달
// stub  : 도착한 명령 코드를 함수 호출로 변경  - Server의 handler 함수

// 흔히 "proxy-stub" 통신이라고 합니다.

class Calc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc");}

	int Add(int a, int b) { return ec_send_server(server, 1, a, b);}
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};
int main()
{
	// 이제 서버에 접속하려면 "Calc" 클래스를 사용하면 됩니다.
	// => IPC 를 몰라도 아래 클래스만 있으면 서버와 통신가능합니다.
	Calc* pCalc = new Calc;

	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;
}





