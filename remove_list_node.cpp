/* ������L1��ɾ��һЩ�ڵ㣬��λ������������L2�и�����
   ���磬���L1=(A B C D E)����L2=(2 4 8)���ʹ�L1��
   ɾ����2�͵�4���ڵ㣨��8���ڵ㲻���ڣ��� ɾ��֮��
   L1=(A C E) */

#include <iostream>
#include <list>
#include <iterator>
#include <vector>

int main()
{
	std::list<char> L1({ 'A', 'B', 'C', 'D', 'E' });                 /* L1 */
	std::list<int> L2({ 2, 4, 8 });                                  /* L2 */
	std::vector<char> vec2del;                                       /* �洢��L2ָ����L1�е����� */
	/* ��L2�е����ݱ���L1�����������������ݴ洢��vec2del�� */
	for (auto &it2 : L2)
	{
		auto it1 = L1.begin();
		if (it2 <= L1.size())
		{
			std::advance(it1, it2 - 1);
			vec2del.push_back(*it1);
		}
	}
	/* ��L1��ɾ��vec2del�б�������� */
	for (auto &it : vec2del)
	{
		L1.remove(it);
	}
	/* ��ʾ��� */
	copy(L1.cbegin(), L1.cend(), std::ostream_iterator<char>(std::cout, "  "));

	std::cout << std::endl;
	system("pause");
	return 0;
}