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

int main()
{


	// ���Ͽ� ����, ��ȣȭ �ؼ� ���� ����� �ʿ� �մϴ�.!!
	// �ּ��� ����� ã�� ���ô�.
	
	// ���1. ����Ÿ�� ���� ��ȣȭ �ϰ�, Write�� ����
	// => ��ȣȭ �۾��� ���� �ϸ� �����ϴ�.!!

	// ��� 2. FileStream ���� �Ļ��� EncryptFileStream �� ������!!
	//        Write()�� override ����!
	// => NetworkStream, PipeStream �� �Ļ� Ŭ������ ������ �Ѵ�.

	// ��� 3. ��� Stream �� ��� Ŭ������ "Stream" �� ��ȣȭ ����� �߰�
	// => ���ο� �䱸 ������ ���涧 ���� ���� Ŭ������ ���� ???
	// => OCP ���� ����!!!

	// ��� 4. ���� Ŭ������ �������� �ʰ�, �̷��� �䱸������ ��� �߰��ؾ� �Ѵ�.
	// => "Decorator"!

	FileStream fs("a.txt");
	fs.Write("hello");


	EncryptDecorator ed(&fs); // ed(&networkstream),  ed(&pipestream)
	ed.Write("Hello");	// 1. Hello �� ��ȣȭ �ϰ� <== �߰��� ���
						// 2. fs.Write(��ȣȭ�ȵ���Ÿ) 

	ZipDecorator zd(&ed);
	zd.Write("Hello");	// 1. �������� �����ϰ�
						// 2. ed.Write() <=== ��ȣȭ ��� ����
						// 3. fs.Write(�����ϰ� ��ȣȭ �� ����Ÿ)

	// ���ο� �䱸 ����(XML�� ����, json���� �����)�� �����
	// "Decorator"�鸸 ��� ����� �˴ϴ�.
	
}