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
	// �� "Calc" Proxy Ŭ������ ���� ����� �ɱ�� ?
	// 1. Server ������ ==> ����!!
	// 2. Client ������


	// Ŭ���̾�Ʈ �����ڰ� �Ʒ�ó�� Proxy �� ����ϸ�
	// "���� ����(tightly coupling)" �Դϴ�.

	// ���ο� proxy�� ������ �ڵ尡 �����Ǿ�� �մϴ�.
	// => OCP�� �����Ҽ� ���� ������ �ڵ�!

//	Calc* pCalc = new Calc;


	// ������, Ȯ�强, OCP �� ����Ѵٸ� ���Ѱ���(�������̽� ��� ���)
	// �� �����ϴ�.
	ICalc* pCalc = new ? ? ? ; // new ICalc �� �ȵ˴ϴ�.!!
								// new Calc �� ���Ѱ����̹Ƿ� ��ü �ȵ˴ϴ�.


	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;
}





