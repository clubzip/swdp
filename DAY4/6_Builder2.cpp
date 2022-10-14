// 2_Builder
#include <iostream>
#include <string>

typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}라고 가정


// 모든 캐릭터를 만드는 "공정은 동일" 하지만
// 국가별 캐릭터의 모양은(각 공정의 결과)는 다릅니다

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
		// 캐릭터를 만드는 공정은 동일 합니다.
		Character c;
		c = c + pbuilder->makeHat();
		c = c + pbuilder->makeUniform();
		c = c + pbuilder->makeShoes();
		return c;
	}
};

//-------------------------------------------
// 국가별 빌더를 제공하면 됩니다.
class Korean : public IBuilder
{
public:
	virtual Hat     makeHat()     override { return "갓\n"; }
	virtual Uniform makeUniform() override { return "한복\n"; }
	virtual Shoes   makeShoes()   override { return "고무신\n"; }
};

class American : public IBuilder
{
public:
	virtual Hat     makeHat()     override { return "야구모자\n"; }
	virtual Uniform makeUniform() override { return "양복\n"; }
	virtual Shoes   makeShoes()   override { return "구두\n"; }
};
int main()
{
	Korean   k;
	American a;

	Director d;
//	d.set_builder(&a);
	d.set_builder(&k); // <= 국가 선택 을 변경할때 마다. 다른 빌더를 연결하면됩니다.

	Character c = d.construct();
	std::cout << c << std::endl;
}
// state 와 빌더는 결국 거의 동일해 보입니다.
// state   : 멤버 함수를 교체 하기 위해 사용
// builder : 복잡한 객체를 만들기 위해 사용

