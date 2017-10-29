/* �������򣬸÷����Ļ���˼���ǣ�
   �ȴ�������ȡ��һ������Ϊ��׼��
   Ȼ�󣬽�������������ȫ�ŵ������ұߣ�С�ڻ����������ȫ�ŵ�������ߡ�
   ��󣬶������������еݹ������ */

#include <iostream>

void quick_sort(int arr[], int index1, int index2);

int main()
{
    int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
    int n = sizeof(arr) / sizeof(int);
    quick_sort(arr, 0, n - 1);
    /* ��ʾ������ */
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
        int pivot = arr[low];          /* ��arr[low]��ֵ�浽pivot�У��൱�ڰ��������һ���� */
        while (low < high)
        {
            /* ���Ҳ��ұȻ�׼С���� */
            while (low < high && arr[high] > pivot)
            {
                --high;
            }
            if (low < high)
            {
                /* ���Ҳ���һ��С��pivot��ֵ����Ӵ�����ʱ���ܵ��Ҳ� */
                arr[low] = arr[high];  
                ++low;
            }
            /* ������ұȻ�׼����� */
            while (low < high && arr[low] < pivot)
            {
                ++low;
            }
            if (low < high)
            {
                /* �������һ������pivot��ֵ��Ҳ�Ӵ�����ʱ���ܵ���� */
                arr[high] = arr[low];
                --high;
            }
        }
        arr[low] = pivot;
        quick_sort(arr, index1, low - 1);
        quick_sort(arr, low + 1, index2);
    }
}