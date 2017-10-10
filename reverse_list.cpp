/* ��дһ��������ֻɨ��һ�ξ��ܽ�������ת��������STL�е�list��ʵ�� */

#include <iostream>
#include <list>
#include <iterator>

/* ��ת����ԭ�� */
void reverse_list(const std::list<int> &original_list, std::list<int> &reversed_list);

int main()
{
	std::list<int> original_list({ { 2, 3, 7, 40, 89, 99, 444 } });
	std::list<int> reversed_list;
	
	/* ��ת�������� */
	reverse_list(original_list, reversed_list);

	/* ������ */
	copy(reversed_list.cbegin(), reversed_list.cend(), std::ostream_iterator<int>(std::cout, "  "));

	std::cout << std::endl;
	system("pause");
	return 0;
}

/* ��ת����ʵ�� */
void reverse_list(const std::list<int> &original_list, std::list<int> &reversed_list)
{
	for (auto &it : original_list)
	{
		reversed_list.push_front(it);
	}

	return;
}