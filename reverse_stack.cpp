/* ��ջ�е�Ԫ�ص�˳�򵹹��������ַ�����a.ʹ�����������ջ��b.ʹ��һ������Ķ��У�c.ʹ��һ�������ջ�ͼ�������ķ�������� */

#include <iostream>
#include <stack>
#include <deque>

#define NOT_USE_SCHEME 0
#define USE_SCHEME     1

int main()
{
	std::stack<int> astack({ 2, 3, 7, 40, 89, 99, 444 });            /* ԭʼ��ջ */

#if NOT_USE_SCHEME
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

#if USE_SCHEME
	/* ����c��ʹ��һ�������ջ�ͼ�������ķ�������� */
	std::stack<int> stack_a;
	int asize = astack.size();                                       /* ԭʼastack�Ĵ�С */
	int tmp = 0;                                                     /* ��ʱ���� */
	int count = 0;                                                   /* ���������ı�������ʾĿǰ�Ѿ������count��˳��ߵ� */
	while (!astack.empty())                                          /* ��astack˳�򵹹����洢��stack_a�� */
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
        /* ÿ�ν�stack_a�е�Ԫ�ص�����astack����ʱ���棬��ʣ���һ��Ԫ�أ����䵯����tmp�У�
		   Ȼ��������һ��forѭ���н�astack�е�ǰsize_b - count��Ԫ�أ����������Ѿ����˳��ߵ���Ԫ�أ�
		   ���֮���ٰ�tmpѹ��astack��Ϊ���µ�һ�����˳��ߵ���Ԫ�� */
		tmp = stack_a.top();
		stack_a.pop();
		int size_b = astack.size();
		for (int j = 0; j != size_b - count; ++j)
		{
			stack_a.push(astack.top());
			astack.pop();
		}
		astack.push(tmp);
		++count;                                                     /* ÿ���һ��Ԫ�ص�˳��ߵ�������һ */
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
