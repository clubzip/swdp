#define USING_GUI
#include "cppmaster.h"

// proxy ����    : �����ڸ� ����� ����
// remote proxy : ������ ������ ���� ������

// proxy �� ���ؼ� �پ��� ����� �߰� �Ҽ� �ִ�.
// => ����, ID & PASSWD Ȯ��
// => ���� ����ϴ� ���꿡 ���� ĳ��!!
// => ������ ��� �ִ��� ���� �Ǿ����� Ȯ��(�ȵ���̵��� alive ���)

// proxy : �Լ� ȣ���� ����ڵ�� ���� �ؼ� ������ ����
// stub  : ������ ��� �ڵ带 �Լ� ȣ��� ����  - Server�� handler �Լ�

// ���� "proxy-stub" ����̶�� �մϴ�.

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
	// ���� ������ �����Ϸ��� "Calc" Ŭ������ ����ϸ� �˴ϴ�.
	// => IPC �� ���� �Ʒ� Ŭ������ ������ ������ ��Ű����մϴ�.
	Calc* pCalc = new Calc;

	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;
}





