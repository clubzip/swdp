#define USING_GUI
#include "cppmaster.h"

#include "ICalc.h"


ICalc* loadProxy()
{
	void* addr = ec_load_module("CalcProxy.dll");
	using F = ICalc * (*)();
	F create = (F)ec_get_function_address(addr, "CreateCalc");
	ICalc* p = create();
	return p;
}

int main()
{
	ICalc* pCalc = loadProxy(); 

	pCalc->AddRef();	// ��Ģ 1. Proxy ��ü�� �����ϸ� ������� ����

	ICalc* p2 = pCalc;	
	p2->AddRef();		// ��Ģ 2. Proxy ��ü �ּҸ� �ٸ����� �����ϸ�
						//		������� ����

	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;

	// ��Ģ 3. ����Ŀ��� ������� ����
	pCalc->Release();

	std::cout << "================" << std::endl;

	p2->Release();  // �̼��� ���� ��� 0. Proxy ��ü �ı�

}



