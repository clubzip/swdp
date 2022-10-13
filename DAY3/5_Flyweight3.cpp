#include <iostream>
#include <string>
#include <map>
#include "helper.h"

// SRP : Single Responsibility Principle
//       "���� å���� ��Ģ"
//      => �ϳ��� Ŭ������ �ϳ��� å�Ӹ�


class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	friend class ImageFactory;
};

// Image ��ü�� ������ ������ �����ϴ� ���� Ŭ����
class ImageFactory
{
	MAKE_SINGLETON( ImageFactory )

	std::map<std::string, Image*> image_map;
public:
	Image* Create(const std::string& url)
	{
		auto ret = image_map.find(url);

		Image* img = nullptr;
		if (ret != image_map.end())	
			img = ret->second;
		else
		{
			img = new Image(url);
			image_map[url] = img;
		}
		return img;
	}
};





int main()
{
	ImageFactory& factory = ImageFactory::getInstance();

	Image* img1 = factory.Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.Create("www.naver.com/a.png");
	img2->Draw();

}


