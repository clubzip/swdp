#include <iostream>
#include <string>
#include <conio.h>

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool iscomplete(const std::string& s) { return true; }
	virtual ~IValidator() {}
};

class Edit
{
	std::string data;
	//-------------------------------------
	IValidator* pval = nullptr;
public:
	void setValidator(IValidator* p) { pval = p; }
	//-------------------------------------

	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13 && (pval == nullptr || pval->iscomplete(data))) break; // enter Ű �Է�!

			if (pval == nullptr || pval->validate(data, c)) // ���� ��ȿ�� ���θ� �ٸ� Ŭ������ ����
			{
				std::cout << c;
				data.push_back(c);
			}
		}
		std::cout << '\n';
		return data;
	}
};

// ���� �پ��� ��å�� ���� "validation Ŭ����"�� �����ϸ� �˴ϴ�.
class LimitDigitValidator : public IValidator
{
	int value;
public:
	LimitDigitValidator(int n) : value(n) {}

	virtual bool validate(const std::string& s, char c) override
	{
		return s.size() < value && isdigit(c);
	}

	virtual bool iscomplete(const std::string& s) override
	{
		return s.size() == value;
	}
};



int main()
{
	Edit e;
//	LimitDigitValidator v(5);
//	e.setValidator(&v); // v�� ����ؼ� ���� ��ȿ���� Ȯ���� �޶�.

	UpperLetterValidator v2(5); // �빮��(�ִ�5��)�� �Էµǵ����ϴ� validator
	e.setValidator(&v2);


	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}

// ���� 
// ���ϴ� ��( Validation ��å) �� �и��ϴ� 2���� ���

// ���ϴ� ��(validation ��å)�� �����Լ��� �и�    : template method(Edit2)
// ���ϴ� ��(validation ��å)�� �ٸ� Ŭ������ �и� : strategy pattern(Edit4)
