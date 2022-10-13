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

	pCalc->AddRef();	// 규칙 1. Proxy 객체를 생성하면 참조계수 증가

	ICalc* p2 = pCalc;	
	p2->AddRef();		// 규칙 2. Proxy 객체 주소를 다른곳에 복사하면
						//		참조계수 증가

	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;

	// 규칙 3. 사용후에는 참조계수 감소
	pCalc->Release();

	std::cout << "================" << std::endl;

	p2->Release();  // 이순간 참조 계수 0. Proxy 객체 파괴

}



