/* 将两个有序的、存储整数的数组合并为一个有序数组，数组用STL中的array来实现 */

#include <iostream>
#include <array>
#include <iterator>

int main()
{
	std::array<int, 7> array_a = { 2, 3, 7, 40, 89, 99, 444 };       /* 第一个升序数组 */
	std::array<int, 3> array_b = { 5, 15, 17 };                      /* 第二个升序数组 */
	std::array<int, 10> array_ab;                                    /* 合成的升序数组 */
	array_ab.fill(0);                                                /* 初始化为0 */
	auto it_a = array_a.begin();
	auto it_b = array_b.begin();
	int i = 0;                                                       /* 用作合成的数组的下标 */
	/* 遍历两个数组，直到遍历完其中的一个为止 */
	while (it_a != array_a.end() && it_b != array_b.end())
	{
		/* 找出最小、次小……的元素将其赋给合成的数组，并将对应的单个升序数组迭代器递增 */
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
	/* 处理有一个数组没遍历完的情况 */
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
	/* 输出合并结果 */
	copy(array_ab.cbegin(), array_ab.cend(), std::ostream_iterator<int>(std::cout, "  "));

	std::cout << std::endl;
	system("pause");
	return 0;
}