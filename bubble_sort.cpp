/* ð������ԭ����ͷ��ʼ����������Ƚϣ����һ������������
   ��һ��������ô��������λ�ã�һֱ�Ƚϵ������������һ�ξͻ�������һ�Ρ�
   ���������Ǵ�����������ҳ������Ǹ��������������ڲ������е����е���β�� */
#include <iostream>

void bubble_sort(int parr[], int n);

int main()
{
    int arr[] = { 9,8,7,6,5,4,3,2,1,0 };

    bubble_sort(arr, sizeof(arr) / sizeof(int));

    /* ��ʾð������Ľ�� */
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
    int tmp = 0;                                 /* ��ʱ���� */
    for (int i = 0; i != n; ++i)
    {
        for (int j = 1; j != n - i; ++j)         /* j - 1ʼ�����Ѿ���������Ԫ�������ֵ������ */
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
