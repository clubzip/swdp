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

// ��������� �ڵ����� �����ϴ� ����Ʈ �����͸� ����
template<typename T> 
class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr) : obj(p) { if (obj) obj->AddRef(); }
	
	AutoPtr(const AutoPtr& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }

	~AutoPtr() { if (obj) obj->Release(); }

	// ����Ʈ �����ʹ� ��ü���� ������ ó�� -> ���갡���ؾ� �մϴ�.
	T* operator->() { return obj; }
	T& operator*()  { return *obj; }
};
int main()
{
	AutoPtr<ICalc> p1 = loadProxy();
	AutoPtr<ICalc> p2 = p1;

	// p1�� ��ü(����Ʈ������)���� ������ ó�� ��밡��
	std::cout << p1->Add(1, 2) << std::endl;
}

// C++ ǥ�� shared_ptr ����ϸ� �ȵǳ��� ??
// 
// std::shared_ptr : ��������� �����ϴµ�, 0�� �Ǹ� shared_ptr ��ü�� delete
// 
// AutoPtr         : ��������� �Լ��� �ڵ� ȣ��. 
//					 0�̵Ǹ� Proxy ��ü�� Release�ȿ��� delete
//					 ��, delete ��ü�� �������ȿ��� ����




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


