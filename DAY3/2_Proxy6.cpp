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
	ICalc* pCalc = loadProxy(); // 동적모듈에서 "new Calc" 하게 됩니다.
								// 사용후 "delete" 필요 합니다.

	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;

	delete pCalc;	// 좋은 코드 일까요 ??
					// 동적 모듈에서 "new" 한 경우
					// 동적 모듈에서 "delete" 하는 것이 안전합니다.

//	std::shared_ptr<ICalc> p(loadProxy()); // 마찬가지 입니다.
					// 결국 p의 소멸자에서 delete 하는 데..
					// 이 경우도 동적모듈이 할당한 것을
					// 실행파일이 해지(delete)하는 원리.
		
}



