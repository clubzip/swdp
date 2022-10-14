#include <iostream>

// å���� ���� (chain of responsibility )
// ��û�� ��û�� ó�� �ϴ� ��ü�� �и��ϰ�
// ��û�� ó���� ���� ���� ������ü�� �����Ѵ�.





// å���� ���� ������ �⺻ ������ �����ϴ� Ŭ����
struct Handler	// ��û�� ó���ϴ� Ŭ����
{
	Handler* next = nullptr; // ��û�� ó���� ���� ��ü

	void Handle(int problem)
	{
		// 1. ���� �ڽ��� ��û�� ó���� �õ��Ѵ�.
		if (HandleRequest(problem) == true)
			return;

		// 2. �ڽ��� ��û�� ó���� �����ϰ�, ���� ��ü�� �ִٸ� ����.
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

		if (problem % 2 == 1) // Ȧ���� ��û�� ó��.
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
	SevenHandler	h1;	// 7�� ������ �ذ��ϴ� ��ü
	OddHandler		h2;	// Ȧ���� ������ �ذ��Ҽ� �ִ� ��ü
	MoreTenHandler	h3;	// 10 �̻��� ������ �ذ��Ҽ� �ִ� ��ü

	// h1 => h2 => h3 �� ����
	h1.next = &h2;
	h2.next = &h3;

//	h1.Handle(7);
	h1.Handle(12); 
//	h1.Handle(9);
	
}

// chain of responsibility 
// => ������ �ذ��� �Ѱ��� ��ü�� �ƴ� "���� ����� ��ü��ó��"
//    ó������ ���� ������ ������ü�� ����.