/* ��ջ�е�Ԫ�ص�˳�򵹹��������ַ�����a.ʹ�����������ջ��b.ʹ��һ������Ķ��� */

#include <iostream>
#include <stack>
#include <deque>

#define NOT_USE_SCHEME 0
#define USE_SCHEME     1

int main()
{
	std::stack<int> astack({ 2, 3, 7, 40, 89, 99, 444 });            /* ԭʼ��ջ */

#if USE_SCHEME
	/* ����a��ʹ�����������ջ */
	std::stack<int> stack_a;
	std::stack<int> stack_b;
	while (!astack.empty())                                          /* ��astack˳�򵹹����洢��stack_a�� */
	{
		stack_a.push(astack.top());
		astack.pop();
	}
	while (!stack_a.empty())                                         /* ��stack_a˳�򵹹����洢��stack_b�У���ʱ��stack_b��ԭʼ��astack˳����ͬ */
	{
		stack_b.push(stack_a.top());
		stack_a.pop();
	}
	while (!stack_b.empty())                                         /* ��stack_b˳�򵹹����洢��astack�У���ʱ��astack��ԭʼ��astack���෴˳��� */
	{
		astack.push(stack_b.top());
		stack_b.pop();
	}

#endif

#if NOT_USE_SCHEME
	/* ����b��ʹ��һ������Ķ��� */
	std::deque<int> adeque;
	while (!astack.empty())                                          /* ��astack�е�Ԫ�ش洢��adeque�� */
	{
		adeque.push_back(astack.top());
		astack.pop();
	}
	for (auto &it : adeque)                                          /* ��adeque�е�Ԫ�����¸���astack����ʱ��astack��ԭʼ��astack���෴˳��� */
	{
		astack.push(it);
	}
#endif

	/* ��ʾ˳�򵹹���֮��Ľ�� */
	while (!astack.empty())
	{
		std::cout << astack.top() << "  ";
		astack.pop();
	}

	std::cout << std::endl;
	system("pause");
	return 0;
}