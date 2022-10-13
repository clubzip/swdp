// 5_Flyweight - 167
#include <iostream>
#include <string>
#include <map>


class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	// �ٽ� : Image ��ü�� ����� "static ��� �Լ�" 
	// => Image ��ü�� ������ "�Ѱ�"������ �ϰ� �˴ϴ�.
	// => �پ��ϰ� ���� �����մϴ�.

	static std::map<std::string, Image*> image_map;

	static Image* Create(const std::string& url)
	{
		auto ret = image_map.find(url);

		Image* img = nullptr;

		if (ret != image_map.end())
		{
			img = ret->second;
		}
		else
		{
			img = new Image(url);
			image_map[url] = img;
		}		
		return img;
	}
};
std::map<std::string, Image*> Image::image_map;




int main()
{
	// Image ��ü�� �ʿ� �ϸ� "Image::Create"�� ���ؼ��� ����� �ֽ��ϴ�.

	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

}



