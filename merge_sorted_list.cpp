/* ����������ġ��洢�����ĵ�������ϲ�Ϊһ����������������STL�е�list��ʵ�� */

#include <iostream>
#include <list>
#include <iterator>

int main()
{
    std::list<int> list_a({ 2,3,7,40,89,99,444 });         /* ��һ���������� */
    std::list<int> list_b({ 5,15,17 });                    /* �ڶ����������� */
    auto it_a = list_a.begin();
    auto it_b = list_b.begin();
    std::list<int> list_ab;                                /* �ϳɵ��������� */
    while (it_a != list_a.end() && it_b != list_b.end())
    {
        if (*it_a <= *it_b)
        {
            list_ab.push_back(*it_a);
            ++it_a;
        }
        else
        {
            list_ab.push_back(*it_b);
            ++it_b;
        }
    }
    /* ������һ������û���������� */
    if (it_a!= list_a.end())
    {
        for (; it_a != list_a.end(); ++it_a)
        {
            list_ab.push_back(*it_a);
        }
    }
    else if (it_b != list_b.end())
    {
        for (; it_b != list_b.end(); ++it_b)
        {
            list_ab.push_back(*it_b);
        }
    }
    else
    {
        ;                                                  /* do nothing */
    }

    /* ����ϲ���� */
    copy(list_ab.cbegin(), list_ab.cend(), std::ostream_iterator<int>(std::cout, "  "));

    std::cout << std::endl;
    system("pause");
    return 0;
}