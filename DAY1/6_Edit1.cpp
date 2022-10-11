#include <iostream>
#include <string>
#include <conio.h>

// 25 page
// Edit 에 입력 값의 유효성(Validation) 기능을 추가해 봅시다.

class Edit
{
	std::string data;
public:
	std::string getData()
	{
		data.clear(); 

		while (1)
		{
			char c = _getch();

			if (c == 13) break;

			if (isdigit(c))
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


