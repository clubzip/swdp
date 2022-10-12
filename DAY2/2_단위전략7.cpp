#include <iostream>
#include <vector>

// 사용자 정의 메모리 할당기
// => 단위 전략 디자인의 정책 클래스는 지켜야 하는 규칙(함수이름)이 있습니다
// => 모든 할당기는 "allocate, deallocate" 가 있어야 합니다 => 표준 문서에 정의!

template<typename T> struct debug_alloc
{
	T* allocate(std::size_t sz)
	{
		void* p = malloc(sizeof(T) * sz);

		printf("debug_alloc : allocate %d counts, at %p\n", sz, p);
		return static_cast<T*>(p);
	}
	void deallocate(T* p, std::size_t sz)
	{
		printf("debug_alloc : deallocate %d counts, at %p\n", sz, p);
		free(p);
	}
	// 관례적으로 모든 할당기는 아래 3개의 멤버도 필요 합니다.
	using value_type = T;
	debug_alloc() = default;
	template<typename U> debug_alloc(const debug_alloc<U>&) {}	
};

int main()
{
	std::vector<int, debug_alloc<int> > v;

	std::cout << "============" << std::endl;
	v.resize(5);

	std::cout << "============" << std::endl;
	v.resize(10);

	std::cout << "============" << std::endl;
	v.push_back(0); // 크기가 11개가 될까요 ??
					// 좀더 커질까요 ? (capacity 개념)

	std::cout << v.size() << std::endl; // size 는 11이지만
	std::cout << v.capacity() << std::endl; // 메모리 사용량은 더 커집니다.
											// vc: 1.5 배
											// g++ : 2배
}