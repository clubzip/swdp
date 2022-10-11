#include <iostream>
#include <string>
#include <conio.h>

// 입력값의 validation 정책은 변경가능해야 합니다.
// 방법 1. 변하는 부분을 가상함수로 - 템플릿 메소드 패턴

class Edit
{
	std::string data;
public:
	// 공통성과 가변성의 분리 
	// => 변하지 않은 코드 내부에 있는 변하는 코드는 분리되어야 합니다.
	// => 변하는 부분을 별도의 가상함수로 분리하세요
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

			if (validate(c)) // 가상함수 호출
			{
				std::cout << c;
				data.push_back(c);
			}
		}
		std::cout << '\n';
		return data;
	}
};

// 이제 Validation 정책을 변경하고 싶다면 Edit 파생 클래스를 만들면 됩니다.
// 기존 코드의 수정이 아닌 라이브러리의 "확장"
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


