#define USING_GUI
#include "cppmaster.h"


struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

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
	// 위 "Calc" Proxy 클래스는 누가 만들게 될까요 ?
	// 1. Server 제작자 ==> 정답!!
	// 2. Client 제작자


	// 클라이언트 제작자가 아래처럼 Proxy 를 사용하면
	// "강한 결합(tightly coupling)" 입니다.

	// 새로운 proxy가 나오면 코드가 수정되어야 합니다.
	// => OCP를 만족할수 없는 경직된 코드!

//	Calc* pCalc = new Calc;


	// 유연성, 확장성, OCP 를 고려한다면 약한결한(인터페이스 기반 통신)
	// 이 좋습니다.
	ICalc* pCalc = new ? ? ? ; // new ICalc 는 안됩니다.!!
								// new Calc 는 강한결합이므로 교체 안됩니다.


	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;
}





