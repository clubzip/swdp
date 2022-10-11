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

			if (c == 13 && (pval == nullptr || pval->iscomplete(data))) break; // enter 키 입력!

			if (pval == nullptr || pval->validate(data, c)) // 값의 유효성 여부를 다른 클래스에 위임
			{
				std::cout << c;
				data.push_back(c);
			}
		}
		std::cout << '\n';
		return data;
	}
};

// 이제 다양한 정책을 가진 "validation 클래스"를 제공하면 됩니다.
class LimitDigitValidator : public IValidator
{
	int value;
public:
	LimitDigitValidator(int n) : value(n) {}

	virtual bool validate(const std::string& s, char c) override
	{
		return s.size() < value && isdigit(c);
	}
};

int main()
{
	Edit e;
	LimitDigitValidator v(5);
	e.setValidator(&v); // v를 사용해서 값의 유효성을 확인해 달라.

	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


