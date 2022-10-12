#include <iostream>
#include <vector>
#include <string>

// strategy, template method
// => 변하는 것을 변경할수 있게 하는 패턴

// Composite 패턴
// => 복합객체를 만들때 사용하는 디자인 패턴
// => 재귀적 포함을 사용한 복합객체 만들기
//    (A는 B뿐 아니라 A도 보관 - 재귀적 포함)

// Folder 는 File 뿐 아니라 Folder도 보관합니다.
// => 공통의 기반 클래스 필요 

// Folder 와 File 은 모두 크기를 구할수 있습니다.
// => 크기를 구하는 함수는 기반클래스에 선언이 있어야 한다.

// 아래 main 실행되도록 완성해 보세요
// => 공통의 기반 클래스 이름 Component 로 해보세요


class File  
{
public:
};
class Folder 
{
public:
};



int main()
{
	Folder* root = new Folder("ROOT");
	Folder* fo1  = new Folder("A");
	Folder* fo2  = new Folder("B");
	
	root->addItem(fo1);
	root->addItem(fo2);

	File* f1 = new File("a.txt", 10);
	File* f2 = new File("b.txt", 20);

	fo1->addItem(f1);
	root->addItem(f2);

	// 파일은 자신만의 크기는 있습니다.
	// 폴더는 자신만의 크기는 없지만 크기를 구할수 있습니다.
	cout << f2->getSize() << endl; // 20
	cout << fo1->getSize() << endl; // 10
	cout << root->getSize() << endl; // 30
}

