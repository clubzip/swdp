// 8_�޸��� - 178
#include <iostream>


// ȭ�鿡 �׸��� �׸��� ����ϴ� Ŭ����
class Graphics
{
	// ���鰡���� �׸��� �Լ��� �����մϴ�.
};

int main()
{
	Graphics g;
	g.DrawLine(0, 0, 100, 100);



	// ���� �����̳� �β� ���� �����ϰ� �ͽ��ϴ�.
	
	
	// ��� 1. DrawLine �Լ��� ���ڷ� ��������.
	// => windows os �� "GDI+" ���̺귯��
	g.DrawLine(0, 0, 100, 100, red, 10, dash);




	// ��� 2. Graphics ��ü�� �Ӽ����� �����Ҽ� �ְ� ����.
	// => IOS �� "Cocoa" ���̺귯���� ����ϴ� ���

	g.SetStrokeColor(red);
	g.SetStrokeWidth(10);
	g.SetStrokeStyle(dash);

	g.DrawLine(0, 0, 100, 100); // g�� ���� �Ӽ����� �� �׸���.
	g.DrawLine(0, 0, 200, 200);

}









