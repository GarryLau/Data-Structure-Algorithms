/* 从链表L1中删除一些节点，其位置在有序链表L2中给出。
   例如，如果L1=(A B C D E)，而L2=(2 4 8)，就从L1中
   删除第2和第4个节点（第8个节点不存在）， 删除之后，
   L1=(A C E) */

#include <iostream>
#include <list>
#include <iterator>
#include <vector>

int main()
{
	std::list<char> L1({ 'A', 'B', 'C', 'D', 'E' });                 /* L1 */
	std::list<int> L2({ 2, 4, 8 });                                  /* L2 */
	std::vector<char> vec2del;                                       /* 存储由L2指定的L1中的内容 */
	/* 由L2中的内容遍历L1的索引并把索引内容存储到vec2del中 */
	for (auto &it2 : L2)
	{
		auto it1 = L1.begin();
		if (it2 <= L1.size())
		{
			std::advance(it1, it2 - 1);
			vec2del.push_back(*it1);
		}
	}
	/* 从L1中删除vec2del中保存的内容 */
	for (auto &it : vec2del)
	{
		L1.remove(it);
	}
	/* 显示结果 */
	copy(L1.cbegin(), L1.cend(), std::ostream_iterator<char>(std::cout, "  "));

	std::cout << std::endl;
	system("pause");
	return 0;
}