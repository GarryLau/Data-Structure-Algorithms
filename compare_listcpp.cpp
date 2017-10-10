/* ��дһ���������������������������Ƿ���ͬ */

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

	/* ��ʾ��� */
	std::cout << bequal << std::endl;
	
	system("pause");
	return 0;
}

bool is_equal(const std::list<int> &list_a, const std::list<int> &list_b)
{
	std::set<int> set_a;                                             /* ��list_a������set */
	std::set<int> set_b;                                             /* ��list_b������set */
	std::set<int> set_ab;                                            /* ��set_a��set_b�ϲ�������set */
	/* ����list_a���Բ���set_a��ע��set_a.size() <= list_a.size()����Ϊlist_a�п�������ͬԪ�� */
	for (auto &it : list_a)
	{
		set_a.insert(it);
	}
	/* ����list_b���Բ���set_b��ע��set_b.size() <= list_b.size()����Ϊlist_b�п�������ͬԪ�� */
	for (auto &it : list_b)
	{
		set_b.insert(it);
	}
	/* �ϲ�set_a��set_b */
	set_ab.insert(set_a.begin(), set_a.end());
	set_ab.insert(set_b.begin(), set_b.end());
	/* ����set_a��set_b�ϲ��������set_ab.size()�Ƿ��ı�set_a.size() + set_b.size()С
	   ���ж������������Ƿ�����ͬԪ�أ��Ӷ�����ȷ��list_a��list_b���Ƿ�����ͬԪ�� */
	if (set_ab.size() < set_a.size() + set_b.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}
