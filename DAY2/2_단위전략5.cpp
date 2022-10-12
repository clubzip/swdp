
// STL 의 원리
// => STL 은 앞의 예제처럼 동기화를 고려해서 디자인 되지 않았지만..
// => 다른 용도로 "단위 전략 디자인"을 많이 사용합니다.

template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	T* buff;
	Alloc ax;	// 메모리 할당기(allocator)
				// 이제, vector의 모든 멤버 함수에서 메모리 할당/해지
				// 는 ax 만 사용해서 하게 됩니다.
public:
	void resize(int n)
	{
		// 버퍼 크기가 부족해서 다시 할당하려고 합니다.
		// 어떻게 할당할까요 ?
		// C++에서는 메모리를 할당하는 방법이 아주 많이 있습니다.
		// new / malloc / system call / windows api/ 풀링 

//		buff = new T[n]; // 이렇게 직접 코딩 했다면 "메모리할당방식"을 교체
						 // 할수 없습니다

		buff = ax.allocate(n); // T타입을 n개 할당

		ax.deallocate(buff, n); // n개 해지
	}
};
vector<int> v;

