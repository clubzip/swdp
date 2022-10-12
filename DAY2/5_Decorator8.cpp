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
		printf("%s ����\n", buff.c_str());
	}
};

// Stream �� ����� �߰��ϴ� Decorator
// "���� Stream Ŭ������ Decorator�� ���� ��� Ŭ������ ����ؾ� �Ѵ�."

class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* s) : stream(s) {}

	virtual void Write(const std::string& s) override
	{
		std::string str = s + " �����"; // ������ ����

		stream->Write(str);				// stream �� ������� ����
	}
};
class EncryptDecorator : public Stream
{
	Stream* stream;
public:
	EncryptDecorator(Stream* s) : stream(s) {}

	virtual void Write(const std::string& s) override
	{
		std::string str = s + " ��ȣȭ"; 
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