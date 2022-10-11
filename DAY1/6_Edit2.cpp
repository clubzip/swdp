#include <iostream>
#include <string>
#include <conio.h>

// �Է°��� validation ��å�� ���氡���ؾ� �մϴ�.
// ��� 1. ���ϴ� �κ��� �����Լ��� - ���ø� �޼ҵ� ����

class Edit
{
	std::string data;
public:
	// ���뼺�� �������� �и� 
	// => ������ ���� �ڵ� ���ο� �ִ� ���ϴ� �ڵ�� �и��Ǿ�� �մϴ�.
	// => ���ϴ� �κ��� ������ �����Լ��� �и��ϼ���
	virtual bool validate(char c)
	{
		return true;
	}

	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break;

			if (validate(c)) // �����Լ� ȣ��
			{
				std::cout << c;
				data.push_back(c);
			}
		}
		std::cout << '\n';
		return data;
	}
};

// ���� Validation ��å�� �����ϰ� �ʹٸ� Edit �Ļ� Ŭ������ ����� �˴ϴ�.
// ���� �ڵ��� ������ �ƴ� ���̺귯���� "Ȯ��"
class NumEdit : public Edit
{
public:
	virtual bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
	NumEdit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


