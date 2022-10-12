#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class FileStream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void Write(const std::string& buff)
	{
		printf("%s 쓰기\n", buff.c_str());
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.Write("hello");

	// FileStream 외에 다양한 Stream 이 있다고 가정해 봅시다.
	NetworkStream ns("127.0.0.1", 4000);
	ns.Write("hello");

	PipeStream ps("namedpipe");
	ps.Write("hello");
}