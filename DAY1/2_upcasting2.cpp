// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};
class Cat : public Animal {};

int main()
{
	// Upcasting ���� 1. ������ �����ϴ� �����̳� ���鶧 ���
	std::vector<Dog*>    v1;// Dog �� ���� ������ vector
	std::vector<Animal*> v2;// ��� ������ ���������� vector
							// ����(���� ��� Ŭ������ ���)�� �����ϴ� �����̳�
}