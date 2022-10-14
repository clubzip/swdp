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
	// �Ʒ� ��ü�� ������ �Դϴ�.
	// => IOS App ���߿� �θ� ���Ǵ� "�뺸����" ��� ���� �Դϴ�.
	NotificationCenter nc;

	// ���͸� ���� ���¸� �˰� ���� ��� "�뺸����"�� ��� �մϴ�.
	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", std::bind(&goo, _1, 0));
	nc.addObserver("LOWBATTERY", [](void* p) { printf("lambda\n"); });


	// ���͸� ����ʿ��� ���͸��� ����������
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}

// ��ü���� ���谡 �����ϴٸ� "������(Mediator)" �� �����ض�
// M : N �� ���踦 �����ڿ� ��ü���� 1:N �� ����� �����ϴ� ����



