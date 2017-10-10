/* 将两个有序的、存储整数的单向链表合并为一个有序链表，链表用STL中的list来实现 */

#include <iostream>
#include <list>
#include <iterator>

int main()
{
    std::list<int> list_a({ 2,3,7,40,89,99,444 });         /* 第一个升序链表 */
    std::list<int> list_b({ 5,15,17 });                    /* 第二个升序链表 */
    auto it_a = list_a.begin();
    auto it_b = list_b.begin();
    std::list<int> list_ab;                                /* 合成的升序链表 */
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
    /* 处理有一个链表没遍历完的情况 */
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

    /* 输出合并结果 */
    copy(list_ab.cbegin(), list_ab.cend(), std::ostream_iterator<int>(std::cout, "  "));

    std::cout << std::endl;
    system("pause");
    return 0;
}