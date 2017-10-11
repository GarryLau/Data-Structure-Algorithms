/* 将一个单向链表连接到另一个单项链表的末尾 */

#include <iostream>
#include <list>
#include <iterator>

int main()
{
	std::list<int> list_a({ 2, 3, 7, 40, 89, 444 });
	std::list<int> list_b({ 5, 15, 17, 99 });
	/* 将单向链表list_b链接到list_a的末尾 */
	for (auto &it : list_b)
	{
		list_a.push_back(it);
	}
	/* 显示连接的结果 */
	copy(list_a.cbegin(), list_a.cend(), std::ostream_iterator<int>(std::cout, "  "));

	std::cout << std::endl;
	system("pause");
	return 0;
}