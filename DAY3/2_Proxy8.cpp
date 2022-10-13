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
	ICalc* p1 = loadProxy();
	pCalc->AddRef();	
	
	ICalc* p2 = pCalc;
	p2->AddRef();	
	
	p1->Release();
	p2->Release();  
}



