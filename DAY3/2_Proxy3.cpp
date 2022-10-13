#define USING_GUI
#include "cppmaster.h"

// RPC(Remote Procedure Call) 
// => 다른 프로세스(또는 PC)에 있는 함수를 호출하는것
// => Java에서는 "RMI(Remote Method Invocation)" 이라고 합니다.

// 서버와 proxy 가 동일한 서비스를 제공함을 보장하기 위해 인터페이스 설계

struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

// 이제, 서버와 Proxy를 만들때 모두 "ICalc" 인터페이스를 구현해야 한다
class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
	Calc* pCalc = new Calc;

	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;
}





