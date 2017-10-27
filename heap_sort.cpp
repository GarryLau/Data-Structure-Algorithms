/* 堆排序 */

#include <iostream>
#include <utility>
#include <iterator>
#include <algorithm>

/* 将根元素沿树向下移动 */
void move_down(int arr[], int index1, int index2);
/* 堆排序的实现 */
void heap_sort(int arr[]);

int main()
{
	/* 用数组表示一个堆 */
	int arrheap[] = { 12, 8, 10, 6, 4, 7, 9 };

	heap_sort(arrheap);

	/* 输出堆排序结果 */
	for (int i = 0; i != sizeof(arrheap) / sizeof(int); ++i)
	{
		std::cout << arrheap[i] << "  ";
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}

void move_down(int arr[], int index1, int index2)
{
	int largestindex = index1 * 2 + 1;	         /* 对于堆来说，若父节点的索引是index1，
													则其左子树的索引是index1 * 2 + 1，
													右子树的索引是index1 * 2 + 2 */
	while (largestindex < index2)
	{
		if (arr[largestindex] < arr[largestindex + 1])
		{
			++largestindex;
		}
		std::swap(arr[index1], arr[largestindex]);
		index1 = largestindex;
		largestindex = index1 * 2 + 1;
	}

	return;
}


void heap_sort(int arr[])
{

	return;
}
