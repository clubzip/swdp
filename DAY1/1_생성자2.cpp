// 1_������2-1.cpp
#include <string>
#include <iostream>

class People
{
	std::string name;
	int age;
public:
	// ��� ����� �ݵ�� �ʱ�ȭ �Ǿ�� �Ѵ�!! ��� �ϴ°� �����մϴ�.
	People(const std::string& n, int a) : name(n), age(a) {}
};

// People ���� �Ļ��� Student Ŭ������ ������ ���ô�.
class Student : public People
{
	int id;
public:
	// �Ʒ� �ڵ�� �� �������� ������ ������. �ذ�å�� ����� ?
	// => �����Ϸ��� �Ʒ�ó�� "People()" �� �߰�..
	// => �׷���, People �� ����Ʈ �����ڰ� �����ϴ�
//	Student(int n) : id(n) {} // Student(int n) : People(), id(n) {} 


	// �ذ�å
	// => ��� Ŭ������ ����Ʈ �����ڰ� ������ �ݵ�� �Ļ� Ŭ��������
	//    ��� Ŭ���� �����ڸ� ��������� ȣ���ؾ� �մϴ�.
	Student(const std::string& name, int age, int n) 
				: People(name, age), id(n) {}
};




int main()
{
//	People p1;	// �̷��� ��ü�� ����� �ִٴ� ���� ������� ? (�ʱ�ȭ ���� ���� ��ü)
				// error
	People p2("kim", 20); // ok

	Student s("kim", 20, 17); 
}


