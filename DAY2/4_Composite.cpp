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

class Component
{
	// File �� Folder �� ������ Ư¡�� ��������.
	// 1. ��� �̸��� �ֽ��ϴ�.
	// 2. ũ�⸦ ���Ҽ� �ֽ��ϴ�.(��, ������ �ڽ��� ũ��� �����ϴ�.)
	std::string name;
public:
	Component(const std::string& name) : name(name) {}

	virtual int getSize() const = 0; // �ٽ�!!!
};

class File : public Component
{
	int size;
public:
	File(const std::string& name, int size)
		: Component(name), size(size) {}

	virtual int getSize() const override  { return size; }
};

class Folder : public Component
{
	std::vector<Component*> v;
public:
	Folder(const std::string& name) : Component(name) {}

	void addItem(Component* p) { v.push_back(p); }

	virtual int getSize()const override
	{
		int size = 0;
		
		// ������ ũ��� �ڽ��� �����ϴ� ��� ����� ũ�⸦ ���ϸ� �˴ϴ�
		for (auto p : v)
			size = size + p->getSize();

		return size;
	}
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
	std::cout << f2->getSize() << std::endl; // 20
	std::cout << fo1->getSize() << std::endl; // 10
	std::cout << root->getSize() << std::endl; // 30
}

