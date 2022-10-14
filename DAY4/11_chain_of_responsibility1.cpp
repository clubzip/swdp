#include <iostream>

// 책임의 전가 (chain of responsibility )
// 요청과 요청을 처리 하는 객체를 분리하고
// 요청의 처리를 고리에 따라 여러객체로 전달한다.





// 책임의 전가 패턴의 기본 로직을 제공하는 클래스
struct Handler	// 요청을 처리하는 클래스
{
	Handler* next = nullptr; // 요청을 처리할 다음 객체

	void Handle(int problem)
	{
		// 1. 먼저 자신이 요청의 처리를 시도한다.
		if (HandleRequest(problem) == true)
			return;

		// 2. 자신이 요청의 처리를 실패하고, 다음 객체가 있다면 전달.
		if (next != 0)
			next->Handle(problem);
	}

	virtual bool HandleRequest(int problem) = 0;
};
//============================
class OddHandler : public Handler
{
public:
	virtual bool HandleRequest(int problem) override
	{
		std::cout << "start oddhandler" << std::endl;

		if (problem % 2 == 1) // 홀수번 요청을 처리.
		{
			std::cout << "oddhandler clear request" << std::endl;
			return true;
		}
		return false;
	}
};
class SevenHandler : public Handler
{
public:
	virtual bool HandleRequest(int problem) override
	{
		std::cout << "start seven handler" << std::endl;

		if (problem == 7)
		{
			std::cout << "seven handler clear request" << std::endl;
			return true;
		}
		return false;
	}
};
class MoreTenHandler : public Handler
{
public:
	virtual bool HandleRequest(int problem) override
	{
		std::cout << "start more ten handler" << std::endl;

		if (problem > 10)
		{
			std::cout << "more ten handler clear request" << std::endl;
			return true;
		}
		return false;
	}
};

int main()
{
	SevenHandler	h1;	// 7번 문제를 해결하는 객체
	OddHandler		h2;	// 홀수번 문제를 해결할수 있는 객체
	MoreTenHandler	h3;	// 10 이상의 문제를 해결할수 있는 객체

	// h1 => h2 => h3 의 순서
	h1.next = &h2;
	h2.next = &h3;

//	h1.Handle(7);
	h1.Handle(12); 
//	h1.Handle(9);
	
}

// chain of responsibility 
// => 문제를 해결을 한개의 객체가 아닌 "고리로 연결된 객체가처리"
//    처리되지 않은 문제는 다음객체에 전달.