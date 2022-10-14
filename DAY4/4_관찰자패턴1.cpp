//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>



// 모든 관찰자(그래프)들의 공통의 인터페이스

struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}
};

// 관찰의 대상(table)
class Table
{
	std::vector<IGraph*> v;	// 관찰자 보관
	int value; // table 의 data 값
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		// 등록된 모든 그래프에 알려준다.
		for (auto p : v)
			p->Update(data);
	}
	// 아래 함수가 table 을 편집모드로 만드는 함수.. 
	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;

			notify(value);	// table 데이타가변경되었으므로
							// 모든 관찰자에 통보.
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

	// 관찰의 대상(table)에 관찰자(그래프) 부착
	PieGraph pg; t.attach(&pg);
	BarGraph bg; t.attach(&bg);
	t.edit();
}





