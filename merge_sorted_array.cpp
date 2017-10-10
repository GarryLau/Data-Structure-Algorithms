/* ����������ġ��洢����������ϲ�Ϊһ���������飬������STL�е�array��ʵ�� */

#include <iostream>
#include <array>
#include <iterator>

int main()
{
	std::array<int, 7> array_a = { 2, 3, 7, 40, 89, 99, 444 };       /* ��һ���������� */
	std::array<int, 3> array_b = { 5, 15, 17 };                      /* �ڶ����������� */
	std::array<int, 10> array_ab;                                    /* �ϳɵ��������� */
	array_ab.fill(0);                                                /* ��ʼ��Ϊ0 */
	auto it_a = array_a.begin();
	auto it_b = array_b.begin();
	int i = 0;                                                       /* �����ϳɵ�������±� */
	/* �����������飬ֱ�����������е�һ��Ϊֹ */
	while (it_a != array_a.end() && it_b != array_b.end())
	{
		/* �ҳ���С����С������Ԫ�ؽ��丳���ϳɵ����飬������Ӧ�ĵ�������������������� */
		if (*it_a <= *it_b)
		{
			array_ab.at(i) = *it_a;
			++it_a;
			++i;
		}
		else
		{
			array_ab.at(i) = *it_b;
			++it_b;
			++i;
		}

	}
	/* ������һ������û���������� */
	if (it_a != array_a.end())
	{
		for (; it_a != array_a.end(); ++it_a)
		{
			array_ab.at(i) = *it_a;
			++i;
		}
	}
	else if (it_b != array_b.end())
	{
		for (; it_b != array_b.end(); ++it_b)
		{
			array_ab.at(i) = *it_b;
			++i;
		}
	}
	else
	{
		;                                                            /* do nothing */
	}
	/* ����ϲ���� */
	copy(array_ab.cbegin(), array_ab.cend(), std::ostream_iterator<int>(std::cout, "  "));

	std::cout << std::endl;
	system("pause");
	return 0;
}