/* ѡ�������˼����ʵ��ð�������е����ƣ�������һ����������С��Ԫ�طŵ���ǰ�档
   ���ǹ��̲�ͬ��ð��������ͨ�����ڵıȽϺͽ�������ѡ��������ͨ���������ѡ��
   �ٸ����ӣ���5, 3, 8, 6, 4����������н��м�ѡ����������Ҫѡ��5�������С��
   ����5������Ҳ����ѡ��3��5������һ�������ͱ����3, 5, 8, 6, 4����ʣ�µ�����һ
   �ν���ѡ��ͽ��������վͻ�õ�һ���������С���ʵѡ��������Կ���ð��������Ż���
   ��Ϊ��Ŀ����ͬ��ֻ��ѡ������ֻ����ȷ������С����ǰ���²Ž��н������������˽�
   ���Ĵ�����ѡ�������ʱ�临�Ӷ�ΪO(n^2)��*/

#include <iostream>

void select_sort(int arr[], int n);

int main()
{
    int arr[] = { 9,8,7,6,5,4,3,2,1,0 };

    select_sort(arr, sizeof(arr) / sizeof(int));

    /* ��ʾѡ������Ľ�� */
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
    int tmp = 0;                                 /* ��ʱ���� */
    for (int i = 0; i != n - 1; ++i)             /* i����������һ��Ԫ�ص����� */
    {
        for (int j = i + 1; j != n; ++j)
        {
            if (arr[i] > arr[j])                 /* ���ҵ�����Сֵ�ŵ�����������ǰ�� */
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}