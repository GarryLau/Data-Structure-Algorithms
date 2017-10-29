/* 快速排序，该方法的基本思想是：
   先从数列中取出一个数作为基准；
   然后，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。
   最后，对两个分区进行递归操作。 */

#include <iostream>

void quick_sort(int arr[], int index1, int index2);

int main()
{
    int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
    int n = sizeof(arr) / sizeof(int);
    quick_sort(arr, 0, n - 1);
    /* 显示排序结果 */
    for (int i = 0; i!= n; ++i)
    {
        std::cout << arr[i] << "  ";
    }

    std::cout << std::endl;
    system("pause");
    return 0;
}

void quick_sort(int arr[], int index1, int index2)
{
    if (index1 < index2)
    {
        int low = index1;
        int high = index2;
        int pivot = arr[low];          /* 将arr[low]的值存到pivot中，相当于把左侧挖了一个坑 */
        while (low < high)
        {
            /* 在右侧找比基准小的数 */
            while (low < high && arr[high] > pivot)
            {
                --high;
            }
            if (low < high)
            {
                /* 在右侧找一个小于pivot的值填到左侧坑处，此时坑跑到右侧 */
                arr[low] = arr[high];  
                ++low;
            }
            /* 在左侧找比基准大的数 */
            while (low < high && arr[low] < pivot)
            {
                ++low;
            }
            if (low < high)
            {
                /* 在左侧找一个大于pivot的值填到右侧坑处，此时坑跑到左侧 */
                arr[high] = arr[low];
                --high;
            }
        }
        arr[low] = pivot;
        quick_sort(arr, index1, low - 1);
        quick_sort(arr, low + 1, index2);
    }
}