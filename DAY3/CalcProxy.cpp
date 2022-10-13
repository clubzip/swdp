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

// 클라이언트 제작자는 "동적모듈 내에 있는 proxy" 클래스 이름을 
// 알수도 없고, 알아도 사용하면 안됩니다.(강한결합)

// 동적 모듈 내의 약속된 함수를 만들고 해당 함수에서 Proxy 객체를 생성합니다
extern "C" __declspec(dllexport)
ICalc* CreateCalc()
{
	return new Calc;
}

// Proxy 가 update 되면(새로운 동적모듈을 만들면)
// 1. 반드시 CreateCalc 함수가 있어야 합니다.
// 2. 동적 모듈의 이름은 계속 동일하게 유지 해야 합니다.


// 빌드하는 법
// 1. Visual studio 가 사용하는 C++ 컴파일러 이름은 "cl.exe" 입니다.
// 2. 윈도우 시작 버튼 - Visual Studio 폴더 - "개발자 명령프롬프트실행"하세요

// 3. 소스가 있는 폴더로 이동후
// 
//   => D:  하면 드라이브 이동
//   => cd DAY3  하면 폴더이동
//   => cd ..    상위 폴더로 이동

// 4. cl CalcProxy.cpp /LD /link user32.lib gdi32.lib kernel32.lib

// "/LD" : DLL로 빌드하는 옵션
