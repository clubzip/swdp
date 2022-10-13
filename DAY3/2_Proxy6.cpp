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
	ICalc* pCalc = loadProxy(); // ������⿡�� "new Calc" �ϰ� �˴ϴ�.
								// ����� "delete" �ʿ� �մϴ�.

	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;

	delete pCalc;	// ���� �ڵ� �ϱ�� ??
					// ���� ��⿡�� "new" �� ���
					// ���� ��⿡�� "delete" �ϴ� ���� �����մϴ�.

//	std::shared_ptr<ICalc> p(loadProxy()); // �������� �Դϴ�.
					// �ᱹ p�� �Ҹ��ڿ��� delete �ϴ� ��..
					// �� ��쵵 ��������� �Ҵ��� ����
					// ���������� ����(delete)�ϴ� ����.
		
}



