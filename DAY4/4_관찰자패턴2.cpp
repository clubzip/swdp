//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>


struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}
};

// Table 이 다루는 데이타의 형태에 상관없이
// 관찰자 패턴의 기본 로직은 동일합니다.

// 관찰자 패턴의 기본 로직을 제공하는 기반 클래스를 제공..
// => 관찰자를 Observer, 관찰의 대상을 "Subject" 라고 합니다.

class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		for (auto p : v)
			p->Update(data);
	}
};

// 다양한 종류의 Table 을 만들때 Subject 에서 파생 되면
// 관찰자 패턴의 기본 로직을 제공받을수 있습니다.

class Table : public Subject
{
	int value;
public:
	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;

			notify(value);	
		}
	}
};
//----------------------
class BarGraph : public IGraph
{
public:
	void Update(int n) override
	{
		std::cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "*";

		std::cout << std::endl;
	}
};

class PieGraph : public IGraph
{
public:
	void Update(int n) override
	{
		std::cout << "Pie Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << ")";

		std::cout << std::endl;
	}
};

int main()
{
	Table t;

	PieGraph pg; t.attach(&pg);
	BarGraph bg; t.attach(&bg);
	t.edit();
}





// 184 page - 관찰자 패턴 정리