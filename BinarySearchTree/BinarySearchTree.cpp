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
/* 广度优先遍历 */
void BST::breadthFirst() const
{

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
/* 查找-对外接口 */
int * BST::search(const int &val) const
{
}
/* 清空树-对外接口 */
void BST::clear()
{

}
/* 判断是否为空树 */
bool BST::isEmpty() const
{

}
/* 插入 */
void BST::insert(const int &val)
{

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
/* 清空-对内实现 */
void BST::clear(BSTNode *p)
{

}
/* 查找-对内实现 */
int * BST::search(BSTNode *p, const int &val) const
{

}
