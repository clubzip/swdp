#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

struct Stream
{
	virtual void Write(const std::string& s) = 0;
	virtual ~Stream() {}
};

class FileStream : public Stream
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

	// 파일에 쓸때, 암호화 해서 쓰는 기능이 필요 합니다.!!
	// 최선의 방법을 찾아 봅시다.
	
	// 방법1. 데이타를 먼저 암호화 하고, Write에 전달
	// => 암호화 작업을 자주 하면 불편하다.!!

	// 방법 2. FileStream 에서 파생된 EncryptFileStream 을 만들자!!
	//        Write()를 override 하자!
	// => NetworkStream, PipeStream 도 파생 클래스를 만들어야 한다.

	// 방법 3. 모든 Stream 의 기반 클래스인 "Stream" 에 암호화 기능을 추가
	// => 새로운 요구 사항이 생길때 마다 기존 클래스를 변경 ???
	// => OCP 만족 못함!!!

	// 방법 4. 기존 클래스가 수정되지 않고, 미래의 요구사항을 계속 추가해야 한다.
	// => "Decorator"!

	EncrpytDecorator ed(&fs);
	ed.Write("Hello");	// 1. Hello 를 암호화 하고
						// 2. fs.Write(암호화된데이타) 

	ZipDecorator zd(&ed);
	zd.Write("Hello");
	
}