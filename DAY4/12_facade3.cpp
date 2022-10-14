#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

class NetworkInit
{
public:
	NetworkInit()
	{
		WSADATA w;
		WSAStartup(0x202, &w);
	}
	~NetworkInit()
	{
		WSACleanup();
	}
};
class IPAddress
{
	SOCKADDR_IN addr;
public:
	IPAddress(const char* ip, short port)
	{
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip);
	}
	SOCKADDR* getRawAddress()
	{
		return (SOCKADDR*)&addr;
	}
};

class Socket
{
	int sock;
public:
	Socket(int type) { sock = socket(PF_INET, type, 0); }

	void Bind(IPAddress* ip)
	{
		::bind(sock, ip->getRawAddress(), sizeof(SOCKADDR_IN));
	}
	void Listen() { ::listen(sock, 5); }

	void Accept()
	{
		struct sockaddr_in addr2 = { 0 };
		int sz = sizeof(addr2);

		accept(sock, (SOCKADDR*)&addr2, &sz);
	}
};

// TCP 서버를 만들려면
// 몇개를 클래스를 사용해서
// 몇가지의 절차를 거쳐야 합니다.
// 이런 절차를 간결하게 할수 있는 하나의 통합된 인터페이스를 제공해 봅시다.
// => "Facade" 라는 패턴.. 

class TCPServer
{
	NetworkInit init;
	Socket sock{ SOCK_STREAM }; // 참고) 멤버 데이타에서 생성자인자 전달할때는
								//      ()로 하면 안되고 {}로 해야 합니다.
public:
	void Start(const char* sip, short port)
	{
		IPAddress addr(sip, port);

		sock.Bind(&addr);
		sock.Listen();
		sock.Accept();
	}
};

int main()
{	
	// 이제 최종 사용자는 아래와 같이 사용하면 됩니다.
	// => 최종 사용자 입장에서는 아주 간결하게 사용가능합니다.
	TCPServer server;
	server.Start("127.0.0.1", 4000);
}