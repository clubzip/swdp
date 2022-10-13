// 5_Flyweight - 167
#include <iostream>
#include <string>
#include <map>


// 속성이 동일한 객체는  공유 할수 있게 하자.

// Image 클래스 : 인터넷에서 그림을 다운로드해서 그리는 클래스
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
	// 아래 코드는 결국 같은 그림 입니다
	// => 동일 그림을 2번 다운로드할 필요는 없습니다.
	// => "속성이 동일한 객체는 공유" 하는 것이 좋습니다. => "flyweight" 패턴

	Image* img1 = new Image("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = new Image("www.naver.com/a.png");
	img2->Draw();

}



