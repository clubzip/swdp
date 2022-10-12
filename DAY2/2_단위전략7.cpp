#include <iostream>
#include <vector>

// ����� ���� �޸� �Ҵ��
// => ���� ���� �������� ��å Ŭ������ ���Ѿ� �ϴ� ��Ģ(�Լ��̸�)�� �ֽ��ϴ�
// => ��� �Ҵ��� "allocate, deallocate" �� �־�� �մϴ� => ǥ�� ������ ����!

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
	// ���������� ��� �Ҵ��� �Ʒ� 3���� ����� �ʿ� �մϴ�.
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
}