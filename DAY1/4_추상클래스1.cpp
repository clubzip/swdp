// 1_�߻�Ŭ����1.cpp - 10page

// �߻� Ŭ���� : ���� �����Լ��� �Ѱ� �ִ� �ִ� Ŭ����
// Ư¡       : ��ü�� �����Ҽ� ����.
// �ǵ�	     : Shape �� ���� �Ļ��� ��� ����(Ŭ����)�� �ݵ�� 
//				Draw()�� ������ �Ѵٰ� ���� �ϴ� ��
class Shape
{
public:
	virtual void Draw() = 0;// ���� �����Լ�(pure virtual function)
							// �����ΰ� ����, "=0" ���θ� ǥ��
};
class Rect : public Shape
{
	// �ٽ� : Rect �� "Draw()"�� �����θ� �������� ������ "�߻� Ŭ����" �Դϴ�.
	//       "Draw()" ������ �����ϸ� �߻��� �ƴ�, ��ü(Concrete) Ŭ����
	virtual void Draw() override {}
};
int main()
{
//	Shape  s; // error. �߻� Ŭ������ ��ü ���� �ȵ�.
	Shape* p; // ok..   ������ ������ ����.
	Rect  r;  // ?
}
