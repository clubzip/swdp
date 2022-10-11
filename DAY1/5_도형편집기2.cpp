#include <iostream>
#include <vector>

class Shape
{
};

class Rect : public Shape
{
public:
	void Draw() { std::cout << "Draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void Draw() { std::cout << "Draw Circle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			// 사각형 생성
//			Rect rc; // 이렇게 하면 {} 벗어날때 즉시 파괴 됩니다.
			Rect* p = new Rect;
			v.push_back(p);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw(); // "A"
		}
	}
}
// 빌드하면 에러가 있습니다..
// 왜?? 어디서 에러일까요 ?
// ==> "A" 에서 p 는 "Shape*" 인데. Shape 에는 Draw() 가 없다.
// 해결책은 뭘까요 ??
// 1. p 를 Rect* 또는 Circle* 로 캐스팅후 사용하자.
// ==> 그런데, 코드를 작성할때는 p가 누구를 가리키는지 알수 없다.
// ==> 물론, dynamic_cast 로 조사는 할수 있지만 좋지 않다.
// 
// 2. Shape 에 Draw 를 만들자. ===> 정답
