// 1. Visual Studio 한개 더 실행하세요 
// 2. "Server 폴더의 Server 프로젝트 열어보세요"
// 3. "Debug", "X86" 으로 맞춰 주세요..("X64말고")

// Server1.cpp
#define USING_GUI
#include "cppmaster.h" 

class Server
{
public:
	int Add(int a, int b) { return a + b; }
	int Sub(int a, int b) { return a - b; }
};
Server server;

int handler(int code, int a, int b)
{
	printf("메세지 도착 : %d, %d, %d\n", code, a, b);

	switch (code)
	{
	case 1: return server.Add(a, b);
	case 2: return server.Sub(a, b); // 이 함수의 반환 값은	
									// IPC 통신으로 클라이언트에 전달됩니다.
	}
	return 0;
}

int main()
{
	// IPC 서버로 시작
	ec_start_server("Calc",		// 서버이름
					&handler);	// 클라이언트의 요청이 도착하면 이함수 호출됨.
								// 클라이언트는 int 값 3개를 보내야 합니다.
}




