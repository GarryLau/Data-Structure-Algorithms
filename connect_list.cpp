/* ��һ�������������ӵ���һ�����������ĩβ */

#include <iostream>
#include <list>
#include <iterator>

int main()
{
	std::list<int> list_a({ 2, 3, 7, 40, 89, 444 });
	std::list<int> list_b({ 5, 15, 17, 99 });
	/* ����������list_b���ӵ�list_a��ĩβ */
	for (auto &it : list_b)
	{
		list_a.push_back(it);
	}
	/* ��ʾ���ӵĽ�� */
	copy(list_a.cbegin(), list_a.cend(), std::ostream_iterator<int>(std::cout, "  "));

	std::cout << std::endl;
	system("pause");
	return 0;
}