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

	void Write(const std::string&  buff) 
	{
		printf("%s 쓰기\n", buff.c_str() );
	}
};

int main()
{
	// C 언어와 파일 관리 
	// => 항상 fclose()를 사용자가 해야 하므로 안전하지 않다.
	FILE* f = fopen("a.txt", "wt");
	//.. 
	fclose(f);

	// C++은 생성자/소멸자를 사용하면 자원 관리를 편하고 안전하게 할수 있습니다.
	FileStream fs("a.txt");

	// fs 가 파괴될때 소멸자 호출.. 안전하게 파일을 닫게 됩니다.
}