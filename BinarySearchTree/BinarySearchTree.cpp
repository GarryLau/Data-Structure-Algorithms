#include "BinarySearchTree.h"
#include <iostream>
#include <stack>
#include <queue>

BST::BST()
{
	root = nullptr;
}

BST::~BST()
{
	clear();
}

/* 访问节点元素 */
void BST::visit(BSTNode *p) const
{
	std::cout << p->value << "  " << std::endl;
}
/* 广度优先遍历 */
void BST::breadthFirst() const
{
	if (nullptr != root)
	{
		std::queue<BSTNode *> trackQueue;
		BSTNode *pNode = root;
		trackQueue.push(pNode);
		while (!trackQueue.empty())
		{
			pNode = trackQueue.front();
			visit(pNode);
			trackQueue.pop();
			if (pNode->left != nullptr)
			{
				trackQueue.push(pNode->left);
			}
			if (pNode->right != nullptr)
			{
				trackQueue.push(pNode->right);
			}
		}
	}
}
/* 深度优先之前序遍历-对外接口 */
void BST::preordor() const
{
	preordor(root);
}
/* 深度优先之前序遍历-递归实现 */
void BST::preordor(BSTNode *p) const
{
	if (nullptr != p)
	{
		visit(p);
		preordor(p->left);
		preordor(p->right);
	}
}
/* 深度优先之中序遍历-对外接口 */
void BST::inordor() const
{
	inordor(root);
}
/* 深度优先之中序遍历-递归实现 */
void BST::inordor(BSTNode *p) const
{
	if (nullptr != p)
	{
		inordor(p->left);
		visit(p);
		inordor(p->right);
	}
}
/* 深度优先之后序遍历-对外接口 */
void BST::postordor() const
{
	postordor(root);
}
/* 深度优先之后序遍历-递归实现 */
void BST::postordor(BSTNode *p) const
{
	if (nullptr  != p)
	{
		postordor(p->left);
		postordor(p->right);
		visit(p);
	}
}
/* 深度优先之前序遍历-非递归实现 */
void BST::interactivePreordor() const
{
	if (nullptr != root)
	{
		std::stack<BSTNode*> traceStack;
		BSTNode* pNode = root;
		traceStack.push(root);
		while (!traceStack.empty())
		{
			pNode = traceStack.top();
			visit(pNode);
			traceStack.pop();
			if (nullptr != pNode->right)
			{
				traceStack.push(pNode->right);
			}
			if (nullptr != pNode->left)
			{
				traceStack.push(pNode->left);
			}
		}
	}
}
/* 深度优先之中序遍历-非递归实现 */
void BST::interactiveInordor() const
{

}
/* 深度优先之后序遍历-非递归实现 */
void BST::interactivePostordor() const
{

}
/* 清空树-对外接口 */
void BST::clear()
{
	clear(root);
	root = nullptr;
}
/* 清空-对内实现 */
void BST::clear(BSTNode *p)
{

}
/* 判断是否为空树 */
bool BST::isEmpty() const
{
	return nullptr == root;
}
/* 插入 */
void BST::insert(const int &val)
{
	if (nullptr == root)
	{
		root = new BSTNode(val);
	}
	else
	{
		BSTNode *pNode = root;
		BSTNode *pPreNode = nullptr;
		while (pNode != nullptr)
		{
			pPreNode = pNode;
			if (pNode->value > val)
			{
				pNode = pNode->left;
			}
			else
			{
				pNode = pNode->right;
			}

		}
		if (pPreNode->value > val)
		{
			pPreNode->left = new BSTNode(val);
		}
		else
		{
			pPreNode->right = new BSTNode(val);
		}
	}
}
/* 合并删除 */
void BST::deleteByMerging(BSTNode *p)
{

}
void BST::findAndDeleteByMerging(const int& val)
{

}
/* 复制删除 */
void BST::deleteByCopying(BSTNode *p)
{

}
/* 查找-对外接口 */
int * BST::search(const int &val) const
{
	return search(root, val);
}
/* 查找-对内实现 */
int * BST::search(BSTNode *p, const int &val) const
{
    while (nullptr != p)
    {
        if (val == p->value)
        {
            return &(p->value);
        }
        else if (p->value > val)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    return 0;
}
