#include <iostream>
#include <vector>
#include <map>

// Memento ����
// => ��ü�� �ڽ��� ���¸� �����ߴٰ�, ���� �Ҽ� �ְ� �Ѵ�.
// => ĸ��ȭ�� ���� ���� �ʰ� (��� ����Ÿ�� ���ο��� ������ �������� �ʰ�)
//    ��ü�� �ڽ��� ���¸� "������ ����"�ϰ� �ϴ� ��. 

class Graphics
{
	int penWidth = 1;
	int penColor = 0;
	int temporary_data;

	// ����Ǿ�� �ϴ� ����Ÿ�� ������ Ÿ������ ����
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
	// ���� �����߿��� "2�����" �� ����ϴ� Graphics �Դϴ�.

	Graphics g;

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);

	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200);

	int token = g.Save();	// �޸���(Memento) ����
							// => ��ü�� ���¸� �����ߴٰ� �����Ҽ� �ְ� �ϴ�����
							// => ĸ��ȭ�� ���� ���� �ʰ�, ��ü�� ����/����.

	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// ���⼭, ó���� �׷ȴ� ���� ������ �Ӽ����� ���ο� ���� �׸��� �ʹ�.
	// => �ּ��� ����� ??

	g.Restore(token); // token ���·� ����..
}









