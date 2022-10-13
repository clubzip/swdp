// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"

#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// Ŭ���̾�Ʈ �����ڴ� "������� ���� �ִ� proxy" Ŭ���� �̸��� 
// �˼��� ����, �˾Ƶ� ����ϸ� �ȵ˴ϴ�.(���Ѱ���)

// ���� ��� ���� ��ӵ� �Լ��� ����� �ش� �Լ����� Proxy ��ü�� �����մϴ�
extern "C" __declspec(dllexport)
ICalc* CreateCalc()
{
	return new Calc;
}

// Proxy �� update �Ǹ�(���ο� ��������� �����)
// 1. �ݵ�� CreateCalc �Լ��� �־�� �մϴ�.
// 2. ���� ����� �̸��� ��� �����ϰ� ���� �ؾ� �մϴ�.


// �����ϴ� ��
// 1. Visual studio �� ����ϴ� C++ �����Ϸ� �̸��� "cl.exe" �Դϴ�.
// 2. ������ ���� ��ư - Visual Studio ���� - "������ ���������Ʈ����"�ϼ���

// 3. �ҽ��� �ִ� ������ �̵���
// 
//   => D:  �ϸ� ����̺� �̵�
//   => cd DAY3  �ϸ� �����̵�
//   => cd ..    ���� ������ �̵�

// 4. cl CalcProxy.cpp /LD /link user32.lib gdi32.lib kernel32.lib

// "/LD" : DLL�� �����ϴ� �ɼ�
