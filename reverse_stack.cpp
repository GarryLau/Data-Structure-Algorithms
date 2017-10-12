/* 将栈中的元素的顺序倒过来，两种方案：a.使用两个额外的栈；b.使用一个额外的队列 */

#include <iostream>
#include <stack>
#include <deque>

#define NOT_USE_SCHEME 0
#define USE_SCHEME     1

int main()
{
	std::stack<int> astack({ 2, 3, 7, 40, 89, 99, 444 });            /* 原始堆栈 */

#if USE_SCHEME
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