/* ��дһ���ݹ麯��������������n�����1��n֮������� */

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

/* �ݹ�ʵ�������� */
void odd(int n, std::vector<int> &result);

int main()
{
    /* �������������в��� */
    std::cout << "������һ��������" << std::endl;
    int n = 0;
    std::cin >> n;
    std::vector<int> result;           /* ����������� */
    odd(n, result);

    /* ������ */
    std::cout << "��1��" << n << "֮�������Ϊ��" << std::endl;
    std::copy(result.cbegin(), result.cend(), std::ostream_iterator<int>(std::cout, "  "));

    std::cout << std::endl;
    system("pause");
    return 0;
}

void odd(int n, std::vector<int> &result)
{
    n = (n % 2 == 0 ? n - 1 : n);
    result.push_back(n);
    if (n >= 3)                        /* ע������nȡֵ���½磬���ڵݹ������½����������жϴ��� */
    {
        odd(n - 2, result);
    }
}
