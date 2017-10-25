#include "BinarySearchTree.h"
#include <iostream>

BST::BST()
{
}

BST::~BST()
{
}

/* 访问节点元素 */
void BST::visit(BSTNode *p) const
{
	std::cout << p->value << "  " << std::endl;
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
