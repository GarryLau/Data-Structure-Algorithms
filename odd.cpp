/* 编写一个递归函数，对于正整数n，求出1到n之间的奇数 */

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

/* 递归实现求奇数 */
void odd(int n, std::vector<int> &result);

int main()
{
    /* 输入正整数进行测试 */
    std::cout << "请输入一个整数：" << std::endl;
    int n = 0;
    std::cin >> n;
    std::vector<int> result;           /* 保存奇数结果 */
    odd(n, result);

    /* 输出结果 */
    std::cout << "从1到" << n << "之间的奇数为：" << std::endl;
    std::copy(result.cbegin(), result.cend(), std::ostream_iterator<int>(std::cout, "  "));

    std::cout << std::endl;
    system("pause");
    return 0;
}

void odd(int n, std::vector<int> &result)
{
    n = (n % 2 == 0 ? n - 1 : n);
    result.push_back(n);
    if (n >= 3)                        /* 注意这里n取值的下界，对于递归问题下界往往容易判断错误 */
    {
        odd(n - 2, result);
    }
}
