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

// 참조계수를 자동으로 관리하는 스마트 포인터를 도입
template<typename T> 
class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr) : obj(p) { if (obj) obj->AddRef(); }
	
	AutoPtr(const AutoPtr& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }

	~AutoPtr() { if (obj) obj->Release(); }

	// 스마트 포인터는 객체지만 포인터 처럼 -> 연산가능해야 합니다.
	T* operator->() { return obj; }
	T& operator*()  { return *obj; }
};
int main()
{
	AutoPtr<ICalc> p1 = loadProxy();
	AutoPtr<ICalc> p2 = p1;

	// p1은 객체(스마트포인터)지만 포인터 처럼 사용가능
	std::cout << p1->Add(1, 2) << std::endl;
}

// C++ 표준 shared_ptr 사용하면 안되나요 ??
// 
// std::shared_ptr : 참조계수로 관리하는데, 0이 되면 shared_ptr 자체가 delete
// 
// AutoPtr         : 참조계수용 함수만 자동 호출. 
//					 0이되면 Proxy 객체의 Release안에서 delete
//					 즉, delete 자체는 동적모듈안에서 수행




/*
int main()
{
	ICalc* p1 = loadProxy();
	p1->AddRef();	

	ICalc* p2 = p1;
	p2->AddRef();	

	p1->Release();
	p2->Release();  
}
*/


