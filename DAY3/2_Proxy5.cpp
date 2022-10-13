// proxy5.cpp
#define USING_GUI
#include "cppmaster.h"

// Ŭ���̾�Ʈ �����ڴ� ���� �����ڿ��� 2���� ���� �޾ƾ� �մϴ�.

// 1. �������̽� ���ǰ� �ִ� ��� ���� : ICalc.h
// 2. Proxy �� �ִ� ���� ��� ����   : CalcProxy.dll

#include "ICalc.h"


ICalc* loadProxy()
{
	void* addr = ec_load_module("CalcProxy.dll"); // linux : dlopen()
												// windows : LoadLibrary()
	using F = ICalc* (*)(); // �Լ� ������ Ÿ��
	F create = (F)ec_get_function_address(addr, "CreateCalc");
									// linux   : dlsym()
									// windows : GetProcAddress()
	ICalc* p = create(); // ������⳻�� CreateCalc ȣ��
	return p;
}

int main()
{
	ICalc* pCalc = loadProxy();

	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;
}
// Proxy Dll �� �Ź����� ������(proxy �� update �Ǹ�) 
// DLL �� �����, loadProxy()�� �ٽ� ȣ��ǵ��� ����� �˴ϴ�.


