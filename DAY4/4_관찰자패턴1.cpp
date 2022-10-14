//1_����������1 - 94 page
#include <iostream>
#include <vector>



// ��� ������(�׷���)���� ������ �������̽�

struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}
};

// ������ ���(table)
class Table
{
	std::vector<IGraph*> v;	// ������ ����
	int value; // table �� data ��
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		// ��ϵ� ��� �׷����� �˷��ش�.
		for (auto p : v)
			p->Update(data);
	}
	// �Ʒ� �Լ��� table �� �������� ����� �Լ�.. 
	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;

			notify(value);	// table ����Ÿ������Ǿ����Ƿ�
							// ��� �����ڿ� �뺸.
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

	// ������ ���(table)�� ������(�׷���) ����
	PieGraph pg; t.attach(&pg);
	BarGraph bg; t.attach(&bg);
	t.edit();
}





