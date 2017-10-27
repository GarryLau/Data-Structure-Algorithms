/* ������ */

#include <iostream>
#include <utility>
#include <iterator>
#include <algorithm>

/* ����Ԫ�����������ƶ� */
void move_down(int arr[], int index1, int index2);
/* �������ʵ�� */
void heap_sort(int arr[]);

int main()
{
	/* �������ʾһ���� */
	int arrheap[] = { 12, 8, 10, 6, 4, 7, 9 };

	heap_sort(arrheap);

	/* ����������� */
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
	int largestindex = index1 * 2 + 1;	         /* ���ڶ���˵�������ڵ��������index1��
													������������������index1 * 2 + 1��
													��������������index1 * 2 + 2 */
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
