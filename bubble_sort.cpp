/* 冒泡排序原理：从头开始，两个数相比较，如果一个数大于它的
   后一个数，那么两数交换位置，一直比较到最后两个，下一次就会少排序一次。
   概述：总是从排序的数中找出最大的那个，并将它放置在参与排列的数中的最尾。 */
#include <iostream>

void bubble_sort(int parr[], int n);

int main()
{
    int arr[] = { 9,8,7,6,5,4,3,2,1,0 };

    bubble_sort(arr, sizeof(arr) / sizeof(int));

    /* 显示冒泡排序的结果 */
    for each (auto var in arr)
    {
        std::cout << var << "  ";
    }

    std::cout << std::endl;
    system("pause");
    return 0;
}

void bubble_sort(int parr[], int n)
{
    int coutd = 0;
    int tmp = 0;                                 /* 临时变量 */
    for (int i = 0; i != n; ++i)
    {
        for (int j = 1; j != n - i; ++j)         /* j - 1始终是已经遍历过的元素中最大值的索引 */
        {
            if (parr[j - 1] > parr[j])
            {
                tmp = parr[j - 1];
                parr[j - 1] = parr[j];
                parr[j] = tmp;
            }
        }
    }
}
