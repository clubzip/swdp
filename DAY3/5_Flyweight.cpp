// 5_Flyweight - 167
#include <iostream>
#include <string>
#include <map>


// �Ӽ��� ������ ��ü��  ���� �Ҽ� �ְ� ����.

// Image Ŭ���� : ���ͳݿ��� �׸��� �ٿ�ε��ؼ� �׸��� Ŭ����
class Image
{
	std::string image_url;
public:
	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
	void Draw() { std::cout << "Draw " << image_url << std::endl; }
};

int main()
{
	// �Ʒ� �ڵ�� �ᱹ ���� �׸� �Դϴ�
	// => ���� �׸��� 2�� �ٿ�ε��� �ʿ�� �����ϴ�.
	// => "�Ӽ��� ������ ��ü�� ����" �ϴ� ���� �����ϴ�. => "flyweight" ����

	Image* img1 = new Image("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = new Image("www.naver.com/a.png");
	img2->Draw();

}



