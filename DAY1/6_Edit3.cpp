#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 분리하는 2번째 방법
// => 변하는 것을 다른 클래스로
// => 변해야 하므로 "약한 결합", 인터페이스 기반 교체

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool iscomplete(const std::string& s) { return true; }
	virtual ~IValidator() {} 
};
// 주민등록번호 : 901   1    확인

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

			if (c == 13 && (pval == nullptr || pval->iscomplete(data))  ) break; // enter 키 입력!

			if ( pval == nullptr || pval->validate(data, c) ) // 값의 유효성 여부를 다른 클래스에 위임
			{
				std::cout << c;
				data.push_back(c);
			}
		}
		std::cout << '\n';
		return data;
	}
};




int main()
{
	Edit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


