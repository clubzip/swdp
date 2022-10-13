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

	// 핵심 : Image 객체를 만드는 "static 멤버 함수" 
	// => Image 객체의 생성을 "한곳"에서만 하게 됩니다.
	// => 다양하게 관리 가능합니다.

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
	// Image 객체가 필요 하면 "Image::Create"를 통해서만 만들수 있습니다.

	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

}



