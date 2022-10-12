
// STL �� ����
// => STL �� ���� ����ó�� ����ȭ�� ����ؼ� ������ ���� �ʾ�����..
// => �ٸ� �뵵�� "���� ���� ������"�� ���� ����մϴ�.

template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	T* buff;
	Alloc ax;	// �޸� �Ҵ��(allocator)
				// ����, vector�� ��� ��� �Լ����� �޸� �Ҵ�/����
				// �� ax �� ����ؼ� �ϰ� �˴ϴ�.
public:
	void resize(int n)
	{
		// ���� ũ�Ⱑ �����ؼ� �ٽ� �Ҵ��Ϸ��� �մϴ�.
		// ��� �Ҵ��ұ�� ?
		// C++������ �޸𸮸� �Ҵ��ϴ� ����� ���� ���� �ֽ��ϴ�.
		// new / malloc / system call / windows api/ Ǯ�� 

//		buff = new T[n]; // �̷��� ���� �ڵ� �ߴٸ� "�޸��Ҵ���"�� ��ü
						 // �Ҽ� �����ϴ�

		buff = ax.allocate(n); // TŸ���� n�� �Ҵ�

		ax.deallocate(buff, n); // n�� ����
	}
};
vector<int> v;

