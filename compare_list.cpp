/* 编写一个函数，检查两个单链表的内容是否相同 */

#include <iostream>
#include <iterator>
#include <list>
#include <set>

bool is_equal(const std::list<int> &list_a, const std::list<int> &list_b);

int main()
{
	std::list<int> list_a({ 2, 3, 7, 40, 89, 99, 444 });
	std::list<int> list_b({ 5, 7, 15, 17, 99});
	bool bequal = is_equal(list_a, list_b);

	/* 显示结果 */
	std::cout << bequal << std::endl;
	
	system("pause");
	return 0;
}

bool is_equal(const std::list<int> &list_a, const std::list<int> &list_b)
{
	std::set<int> set_a;                                             /* 由list_a产生的set */
	std::set<int> set_b;                                             /* 由list_b产生的set */
	std::set<int> set_ab;                                            /* 由set_a和set_b合并产生的set */
	/* 遍历list_a用以产生set_a，注意set_a.size() <= list_a.size()，因为list_a中可能有相同元素 */
	for (auto &it : list_a)
	{
		set_a.insert(it);
	}
	/* 遍历list_b用以产生set_b，注意set_b.size() <= list_b.size()，因为list_b中可能有相同元素 */
	for (auto &it : list_b)
	{
		set_b.insert(it);
	}
	/* 合并set_a和set_b */
	set_ab.insert(set_a.begin(), set_a.end());
	set_ab.insert(set_b.begin(), set_b.end());
	/* 根据set_a和set_b合并后产生的set_ab.size()是否变的比set_a.size() + set_b.size()小
	   来判断两个集合中是否有相同元素，从而可以确定list_a和list_b中是否有相同元素 */
	if (set_ab.size() < set_a.size() + set_b.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}
