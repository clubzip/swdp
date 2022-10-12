#include <iostream>
#include <string>
#include <conio.h>

class Edit
{
	std::string data;
public:
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
	
//	AddressEdit e2;

	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}

// edit using template method 
// => 변하는 것을 가상함수로!
// => 상속기반의 패턴.

// => Edit 와 Validatioin 정책이 결합 되어 있다.
// => NumEdit 안에 있는 Validation 정책은 
//    NumEdit 만 사용가능

// => NumEdit가 정책을 포함하고 있으므로
//    동적으로 정책 교체 안됨

// => 변하는 것(정책)을 동적으로 변경할 필요 없고, 
//    정책을 다른 곳에서 사용할 필요가 없다면
//    template method 가 좋다.
//    접근 지정자로 보호 가능하고, 멤버 데이타 접근도 쉽다.

//    도형편집기 예제에서 Rect 를 어떻게 그릴지는
//    Rect 만 알면 된다. 실행시간에 변경할필요도 없다.
