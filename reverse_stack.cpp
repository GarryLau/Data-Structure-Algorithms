/* 将栈中的元素的顺序倒过来，三种方案：a.使用两个额外的栈；b.使用一个额外的队列；c.使用一个额外的栈和几个额外的非数组变量 */

#include <iostream>
#include <stack>
#include <deque>

#define NOT_USE_SCHEME 0
#define USE_SCHEME     1

int main()
{
	std::stack<int> astack({ 2, 3, 7, 40, 89, 99, 444 });            /* 原始堆栈 */

#if NOT_USE_SCHEME
	/* 方案a：使用两个额外的栈 */
	std::stack<int> stack_a;
	std::stack<int> stack_b;
	while (!astack.empty())                                          /* 将astack顺序倒过来存储在stack_a中 */
	{
		stack_a.push(astack.top());
		astack.pop();
	}
	while (!stack_a.empty())                                         /* 将stack_a顺序倒过来存储在stack_b中，此时的stack_b和原始的astack顺序相同 */
	{
		stack_b.push(stack_a.top());
		stack_a.pop();
	}
	while (!stack_b.empty())                                         /* 将stack_b顺序倒过来存储在astack中，此时的astack和原始的astack是相反顺序的 */
	{
		astack.push(stack_b.top());
		stack_b.pop();
	}

#endif

#if NOT_USE_SCHEME
	/* 方案b：使用一个额外的队列 */
	std::deque<int> adeque;
	while (!astack.empty())                                          /* 将astack中的元素存储在adeque中 */
	{
		adeque.push_back(astack.top());
		astack.pop();
	}
	for (auto &it : adeque)                                          /* 将adeque中的元素重新赋给astack，此时的astack和原始的astack是相反顺序的 */
	{
		astack.push(it);
	}
#endif

#if USE_SCHEME
	/* 方案c：使用一个额外的栈和几个额外的非数组变量 */
	std::stack<int> stack_a;
	int asize = astack.size();                                       /* 原始astack的大小 */
	int tmp = 0;                                                     /* 临时变量 */
	int count = 0;                                                   /* 用作计数的变量，表示目前已经完成了count个顺序颠倒 */
	while (!astack.empty())                                          /* 将astack顺序倒过来存储在stack_a中 */
	{
		stack_a.push(astack.top());
		astack.pop();
	}
	for (int k = 0; k != asize; ++k)
	{
		int size_a = stack_a.size();
		for (int i = 0; i != size_a - 1; ++i)
		{
			astack.push(stack_a.top());
			stack_a.pop();
		}
        /* 每次将stack_a中的元素弹出到astack中临时保存，仅剩最后一个元素，将其弹出到tmp中，
		   然后在下面一个for循环中将astack中的前size_b - count个元素（即不包括已经完成顺序颠倒的元素）
		   清空之后再把tmp压入astack作为最新的一个完成顺序颠倒的元素 */
		tmp = stack_a.top();
		stack_a.pop();
		int size_b = astack.size();
		for (int j = 0; j != size_b - count; ++j)
		{
			stack_a.push(astack.top());
			astack.pop();
		}
		astack.push(tmp);
		++count;                                                     /* 每完成一个元素的顺序颠倒计数加一 */
	}
#endif

	/* 显示顺序倒过来之后的结果 */
	while (!astack.empty())
	{
		std::cout << astack.top() << "  ";
		astack.pop();
	}

	std::cout << std::endl;
	system("pause");
	return 0;
}
