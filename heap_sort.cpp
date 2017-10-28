/* 堆排序 */

#include <iostream>
#include <utility>
#include <iterator>
#include <algorithm>

/* 将根元素沿树向下移动 */
void move_down(int arr[], int index1, int index2);
/* 堆排序的实现 */
void heap_sort(int arr[], int n);

int main()
{
	/* 用数组表示一个堆 */
	int arrheap[] = { 12, 8, 10, 6, 4, 7, 91 };
	int n = sizeof(arrheap) / sizeof(int);       /* 数组大小 */
	heap_sort(arrheap, n);

	/* 输出堆排序结果 */
	for (int i = 0; i != n; ++i)
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
	while (largestindex <= index2)
	{
		if (arr[largestindex] < arr[largestindex + 1] && largestindex < index2)
		{
			++largestindex;
		}
		if (arr[index1] < arr[largestindex])
		{
			std::swap(arr[index1], arr[largestindex]);
			index1 = largestindex;
			largestindex = index1 * 2 + 1;
		}
		else
		{
			largestindex = index2 + 1;
		}
	}
}

void heap_sort(int arr[], int n)
{
	/* 首先根据数组构造出堆 */
	for (int i = n / 2 - 1; i >= 0; --i)
	{
		move_down(arr, i, n - 1);
	}
	/* 将堆顶元素排除在外，把最后一个元素放在原先堆顶的位置，调整元素重构堆，如此循环 */
	for (int i = n - 1; i >= 1; --i)
	{
		std::swap(arr[0], arr[i]);
		move_down(arr, 0, i - 1);
	}
}
