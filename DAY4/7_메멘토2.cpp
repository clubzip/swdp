#include <iostream>
#include <vector>
#include <map>

// Memento 패턴
// => 객체가 자신의 상태를 저장했다가, 복구 할수 있게 한다.
// => 캡슐화를 위배 하지 않고 (멤버 데이타를 위부에서 꺼내서 보관하지 않고)
//    객체가 자신의 상태를 "스스로 저장"하게 하는 것. 

class Graphics
{
	int penWidth = 1;
	int penColor = 0;
	int temporary_data;

	// 저장되어야 하는 데이타만 별도의 타입으로 설계
	struct Memento
	{
		int penWidth;
		int penColor;
	};
	std::map<int, Memento*> memento_map;

public:
	int Save()
	{
		static int key = 0; 
		++key;

		Memento* p = new Memento;
		p->penColor = penColor;
		p->penWidth = penWidth;

		memento_map[key] = p;

		return key;
	}
	void Restore(int key)
	{
		Memento* p = memento_map[key];

		if (p != nullptr)
		{
			penColor = p->penColor;
			penWidth = p->penWidth;
		}
	}


	void DrawLine(int x1, int y1, int x2, int y2)
	{
	}
	void SetStrokeColor(int c) { penColor = c; }
	void SetStrokeWidth(int w) { penWidth = w; }
};


int main()
{
	// 앞의 예제중에서 "2번방식" 을 사용하는 Graphics 입니다.

	Graphics g;

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);

	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200);

	int token = g.Save();	// 메멘토(Memento) 패턴
							// => 객체의 상태를 저장했다고 복구할수 있게 하는패턴
							// => 캡슐화를 위배 하지 않고, 객체의 저장/복구.

	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// 여기서, 처음에 그렸던 선과 동일한 속성으로 새로운 선을 그리고 싶다.
	// => 최선의 방법은 ??

	g.Restore(token); // token 상태로 복구..
}









