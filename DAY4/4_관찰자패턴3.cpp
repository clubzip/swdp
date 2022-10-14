//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>

class Subject;	// 클래스 전방 선언
				// 완전한 선언이 없어도 포인터 변수를 먼저 만들고 싶을때

struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}

	// 모든 관찰자(그래프)는 자신이 어떤 Table 과 연결되었는지 알아야 합니다.
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

		// Table에 변화가 생겼으므로 Table 에 접근 해서 
		// data 를 얻은후 사용하면 됩니다.
		// int* data = subject->getData(); // error. 왜 에러인지 생각해 보세요

		// subject 는 "Subject*" 이므로 Table의 고유 멤버에 접근할수 없습니다.
		// 해결책은 "캐스팅"밖에 없습니다.

		// 캐스팅이 디자인 관점에서 좋은코드는 아니지만.. 
		// 이경우는 다른 방법이 많지 않습니다.

		Table* table = static_cast<Table*>(subject);

		int* data = table->getData();

		// QT 의 Model/View, 
		// MFC 의 Document/View 
		// 라는 구조가 모두 관찰자 패턴입니다.
		// QT와 MFC에는 항상 캐스팅이 등장 합니다.!!

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

