/* 选择排序的思想其实和冒泡排序有点类似，都是在一次排序后把最小的元素放到最前面。
   但是过程不同，冒泡排序是通过相邻的比较和交换。而选择排序是通过对整体的选择。
   举个栗子，对5, 3, 8, 6, 4这个无序序列进行简单选择排序，首先要选择5以外的最小数
   来和5交换，也就是选择3和5交换，一次排序后就变成了3, 5, 8, 6, 4。对剩下的序列一
   次进行选择和交换，最终就会得到一个有序序列。其实选择排序可以看成冒泡排序的优化，
   因为其目的相同，只是选择排序只有在确定了最小数的前提下才进行交换，大大减少了交
   换的次数。选择排序的时间复杂度为O(n^2)。*/

#include <iostream>

void select_sort(int arr[], int n);

int main()
{
    int arr[] = { 9,8,7,6,5,4,3,2,1,0 };

    select_sort(arr, sizeof(arr) / sizeof(int));

    /* 显示选择排序的结果 */
    for each (auto var in arr)
    {
        std::cout << var << "  ";
    }

    std::cout << std::endl;
    system("pause");
    return 0;
}

void select_sort(int arr[], int n)
{
    int tmp = 0;                                 /* 临时变量 */
    for (int i = 0; i != n - 1; ++i)             /* i是无序区第一个元素的索引 */
    {
        for (int j = i + 1; j != n; ++j)
        {
            if (arr[i] > arr[j])                 /* 把找到的最小值放到无序区的最前面 */
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
