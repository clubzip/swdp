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
		printf("%s ����\n", buff.c_str() );
	}
};

int main()
{
	// C ���� ���� ���� 
	// => �׻� fclose()�� ����ڰ� �ؾ� �ϹǷ� �������� �ʴ�.
	FILE* f = fopen("a.txt", "wt");
	//.. 
	fclose(f);

	// C++�� ������/�Ҹ��ڸ� ����ϸ� �ڿ� ������ ���ϰ� �����ϰ� �Ҽ� �ֽ��ϴ�.
	FileStream fs("a.txt");

	// fs �� �ı��ɶ� �Ҹ��� ȣ��.. �����ϰ� ������ �ݰ� �˴ϴ�.
}