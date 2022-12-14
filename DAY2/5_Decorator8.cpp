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

// Stream 에 기능을 추가하는 Decorator
// "실제 Stream 클래스와 Decorator는 동일 기반 클래스를 사용해야 한다."

class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* s) : stream(s) {}

	virtual void Write(const std::string& s) override
	{
		std::string str = s + " 압축됨"; // 압축기능 수행

		stream->Write(str);				// stream 의 본래기능 수행
	}
};
class EncryptDecorator : public Stream
{
	Stream* stream;
public:
	EncryptDecorator(Stream* s) : stream(s) {}

	virtual void Write(const std::string& s) override
	{
		std::string str = s + " 암호화"; 
		stream->Write(str);				
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.Write("hello");

	EncryptDecorator ed(&fs);
	ed.Write("Hello");	

	ZipDecorator zd(&ed);
	zd.Write("Hello");	
}
// C# 언어에는

// backing store(실제IO 수행)		Decorator
// 
// FileStream					ZipStream
// NetworkStream				EncryptStream
// PipeStream					XmlStream
// MemoryStream					BinaryStream
//								HtmlStream 

// C++에서는 "Decorator" 를 많이 사용하지는 않습니다
// C#, java 는 상당이 많이 사용합니다.

// python : @ 로 시작하는 것들이 decorator 입니다. 
//			개념은 위 코드와 유사한데..
//			만드는 방법은 전혀 다릅니다.
//			@class, @wrap 등