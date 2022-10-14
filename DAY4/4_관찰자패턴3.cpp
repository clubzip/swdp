//1_����������1 - 94 page
#include <iostream>
#include <vector>

class Subject;	// Ŭ���� ���� ����
				// ������ ������ ��� ������ ������ ���� ����� ������

struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}

	// ��� ������(�׷���)�� �ڽ��� � Table �� ����Ǿ����� �˾ƾ� �մϴ�.
	Subject* subject;
};



class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) 
	{ 
		v.push_back(p); 

		p->subject = this;
	}


	void detach(IGraph* p) {}

	void notify(int data)
	{
		for (auto p : v)
			p->Update(data);
	}
};

class Table : public Subject
{
	int value;

	int data[5] = { 1,2,3,4,5 };
public:
	int* getData() { return data; }

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

		// Table�� ��ȭ�� �������Ƿ� Table �� ���� �ؼ� 
		// data �� ������ ����ϸ� �˴ϴ�.
		// int* data = subject->getData(); // error. �� �������� ������ ������

		// subject �� "Subject*" �̹Ƿ� Table�� ���� ����� �����Ҽ� �����ϴ�.
		// �ذ�å�� "ĳ����"�ۿ� �����ϴ�.

		// ĳ������ ������ �������� �����ڵ�� �ƴ�����.. 
		// �̰��� �ٸ� ����� ���� �ʽ��ϴ�.

		Table* table = static_cast<Table*>(subject);

		int* data = table->getData();

		// QT �� Model/View, 
		// MFC �� Document/View 
		// ��� ������ ��� ������ �����Դϴ�.
		// QT�� MFC���� �׻� ĳ������ ���� �մϴ�.!!

		for (int i = 0; i < 5; i++)
			std::cout << data[i] << ", ";

		std::cout << std::endl;
	}
};




class PieGraph : public IGraph
{
public:
	void Update(int n) override
	{
		std::cout << "Pie Graph : ";

		Table* table = static_cast<Table*>(subject);

		int* data = table->getData();
		for (int i = 0; i < 5; i++)
			std::cout << data[i] << ", ";

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

