// 2_Builder
#include <iostream>
#include <string>

typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}��� ����


// ��� ĳ���͸� ����� "������ ����" ������
// ������ ĳ������ �����(�� ������ ���)�� �ٸ��ϴ�

struct IBuilder
{
	virtual Hat     makeHat() = 0;
	virtual Uniform makeUniform() = 0;
	virtual Shoes   makeShoes() = 0;

	virtual ~IBuilder() {}
};

class Director
{
	IBuilder* pbuilder = nullptr;
public:
	void set_builder(IBuilder* p) { pbuilder = p; }

	Character construct()
	{
		// ĳ���͸� ����� ������ ���� �մϴ�.
		Character c;
		c = c + pbuilder->makeHat();
		c = c + pbuilder->makeUniform();
		c = c + pbuilder->makeShoes();
		return c;
	}
};

//-------------------------------------------
// ������ ������ �����ϸ� �˴ϴ�.
class Korean : public IBuilder
{
public:
	virtual Hat     makeHat()     override { return "��\n"; }
	virtual Uniform makeUniform() override { return "�Ѻ�\n"; }
	virtual Shoes   makeShoes()   override { return "����\n"; }
};

class American : public IBuilder
{
public:
	virtual Hat     makeHat()     override { return "�߱�����\n"; }
	virtual Uniform makeUniform() override { return "�纹\n"; }
	virtual Shoes   makeShoes()   override { return "����\n"; }
};
int main()
{
	Korean   k;
	American a;

	Director d;
//	d.set_builder(&a);
	d.set_builder(&k); // <= ���� ���� �� �����Ҷ� ����. �ٸ� ������ �����ϸ�˴ϴ�.

	Character c = d.construct();
	std::cout << c << std::endl;
}
// state �� ������ �ᱹ ���� ������ ���Դϴ�.
// state   : ��� �Լ��� ��ü �ϱ� ���� ���
// builder : ������ ��ü�� ����� ���� ���

