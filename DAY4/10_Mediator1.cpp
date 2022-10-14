#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std::placeholders;


class NotificationCenter
{
	using HANDLER = std::function<void(void*)>;

	std::map<std::string, std::vector<HANDLER> > notif_map;
public:

	void addObserver(const std::string& key, HANDLER h)
	{
		notif_map[key].push_back(h);
	}

	void postNotificationWithName(const std::string& key, void* hint)
	{
		for (auto f : notif_map[key])
		{
			f(hint);
		}
	}
};

void foo(void* p) { std::cout << "foo : " << (int)p << std::endl; }
void goo(void* p, int a) { std::cout << "goo : " << (int)p << std::endl; }


int main()
{
	// 아래 객체가 중재자 입니다.
	// => IOS App 개발에 널리 사용되는 "통보센터" 라는 개념 입니다.
	NotificationCenter nc;

	// 배터리 변경 상태를 알고 싶은 경우 "통보센터"에 등록 합니다.
	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", std::bind(&goo, _1, 0));
	nc.addObserver("LOWBATTERY", [](void* p) { printf("lambda\n"); });


	// 배터리 모듈쪽에서 배터리가 부족해지면
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}

// 객체간의 관계가 복잡하다면 "중재자(Mediator)" 를 도입해라
// M : N 의 관계를 중재자와 객체간의 1:N 의 관계로 변경하는 패턴



