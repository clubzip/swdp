// proxy5.cpp
#define USING_GUI
#include "cppmaster.h"

// 클라이언트 제작자는 서버 제작자에게 2개의 파일 받아야 합니다.

// 1. 인터페이스 정의가 있는 헤더 파일 : ICalc.h
// 2. Proxy 가 있는 동적 모듈 파일   : CalcProxy.dll

#include "ICalc.h"


ICalc* loadProxy()
{
	void* addr = ec_load_module("CalcProxy.dll"); // linux : dlopen()
												// windows : LoadLibrary()
	using F = ICalc* (*)(); // 함수 포인터 타입
	F create = (F)ec_get_function_address(addr, "CreateCalc");
									// linux   : dlsym()
									// windows : GetProcAddress()
	ICalc* p = create(); // 동적모듈내의 CreateCalc 호출
	return p;
}

int main()
{
	ICalc* pCalc = loadProxy();

	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;
}
// Proxy Dll 의 신버전이 나오면(proxy 가 update 되면) 
// DLL 을 덮어쓰고, loadProxy()를 다시 호출되도록 만들면 됩니다.


