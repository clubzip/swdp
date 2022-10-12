#include <iostream>
#include <vector>
#include <string>

// strategy, template method
// => ���ϴ� ���� �����Ҽ� �ְ� �ϴ� ����

// Composite ����
// => ���հ�ü�� ���鶧 ����ϴ� ������ ����
// => ����� ������ ����� ���հ�ü �����
//    (A�� B�� �ƴ϶� A�� ���� - ����� ����)

// Folder �� File �� �ƴ϶� Folder�� �����մϴ�.
// => ������ ��� Ŭ���� �ʿ� 

// Folder �� File �� ��� ũ�⸦ ���Ҽ� �ֽ��ϴ�.
// => ũ�⸦ ���ϴ� �Լ��� ���Ŭ������ ������ �־�� �Ѵ�.

// �Ʒ� main ����ǵ��� �ϼ��� ������
// => ������ ��� Ŭ���� �̸� Component �� �غ�����


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

	// ������ �ڽŸ��� ũ��� �ֽ��ϴ�.
	// ������ �ڽŸ��� ũ��� ������ ũ�⸦ ���Ҽ� �ֽ��ϴ�.
	cout << f2->getSize() << endl; // 20
	cout << fo1->getSize() << endl; // 10
	cout << root->getSize() << endl; // 30
}

