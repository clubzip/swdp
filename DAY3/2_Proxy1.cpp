// 1. Visual Studio �Ѱ� �� �����ϼ��� 
// 2. "Server ������ Server ������Ʈ �������"
// 3. "Debug", "X86" ���� ���� �ּ���..("X64����")


#define USING_GUI
#include "cppmaster.h"

int main()
{
	// 1. ������ �ڵ��� ��� �ɴϴ�.
	int server = ec_find_server("Calc");

	std::cout << "���� ��ȣ : " << server << std::endl;

	// 2. ������ ����ڵ�� �Ķ���͸� �����մϴ�.
	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





