#define USING_GUI
#include "cppmaster.h"

// RPC(Remote Procedure Call) 
// => �ٸ� ���μ���(�Ǵ� PC)�� �ִ� �Լ��� ȣ���ϴ°�
// => Java������ "RMI(Remote Method Invocation)" �̶�� �մϴ�.

// ������ proxy �� ������ ���񽺸� �������� �����ϱ� ���� �������̽� ����

struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

// ����, ������ Proxy�� ���鶧 ��� "ICalc" �������̽��� �����ؾ� �Ѵ�
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





