#include <iostream>
#include <vector>
#include <memory> // C++ 표준 메모리 할당기

int main()
{
	// 메모리 할당 방법
	// 1. new / delete 를 직접 사용
	// => 메모리 할당 방식을 변경(malloc/free등으로)하고 싶었다면
	//    모든 문장을 수정해야 합니다.
	int* p1 = new int[10];
	delete[] p1;

	int* p2 = new int[10];
	delete[] p2;


	// 2. allocator 사용
	// => 메모리 할당 방식을 변경하려면 "할당기"만 변경하면 된다.
	std::allocator<int> ax;  // C++ 표준 메모리 할당기

	int* p3 = ax.allocate(10); // 10개 할당. 표준 할당기는 new 사용

	ax.deallocate(p3, 10);		// 10개 해지. 표준 할당기는 delete 사용

}