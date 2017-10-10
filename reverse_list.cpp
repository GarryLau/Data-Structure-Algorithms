/* 编写一个函数，只扫描一次就能将单链表反转，链表用STL中的list来实现 */

#include <iostream>
#include <list>
#include <iterator>

/* 反转函数原型 */
void reverse_list(const std::list<int> &original_list, std::list<int> &reversed_list);

int main()
{
	std::list<int> original_list({ { 2, 3, 7, 40, 89, 99, 444 } });
	std::list<int> reversed_list;
	
	/* 反转函数调用 */
	reverse_list(original_list, reversed_list);

	/* 输出结果 */
	copy(reversed_list.cbegin(), reversed_list.cend(), std::ostream_iterator<int>(std::cout, "  "));

	std::cout << std::endl;
	system("pause");
	return 0;
}

/* 反转函数实现 */
void reverse_list(const std::list<int> &original_list, std::list<int> &reversed_list)
{
	for (auto &it : original_list)
	{
		reversed_list.push_front(it);
	}

	return;
}