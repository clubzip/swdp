// �����ڸ� protected �� ���� ����
// => �ڽ��� ��ü�� �����Ҽ� ������(�߻����� ����)
// => �Ļ� Ŭ������ ��ü�� �����Ҽ� �ְ� �ϰڴ�(��ü���� ����)

// ��ü��������ο��� �߻�(abstract)�� �ݴ��ǹ̸� ��ü(concrete)��� �մϴ�.


class Animal
{
protected:
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {} // Dog() : Animal() {} // Animal �����ڰ� protected��
									// error �ƴ�.
};
int main()
{
	// ������ ������ ��� ��� ������
	Animal a;	// error. 
	Dog    d;	// ok
}



