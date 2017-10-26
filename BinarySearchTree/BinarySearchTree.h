#pragma once

/* 树的节点 */
class BSTNode
{
public:
    BSTNode *left;
    BSTNode *right;
    int value;

	BSTNode(const int val = 0);
    BSTNode(BSTNode *lf = nullptr, BSTNode *rg = nullptr, const int val = 0);
};

class BST
{
public:
    BST();
    ~BST();

	void breadthFirst() const;                         /* 广度优先遍历 */
	void preordor() const;                             /* 深度优先之前序遍历-对外接口 */
	void inordor() const;                              /* 深度优先之中序遍历-对外接口 */
	void postordor() const;                            /* 深度优先之后序遍历-对外接口 */
	int *search(const int &val) const;                 /* 查找-对外接口 */
	void clear();                                      /* 清空树 */
	bool isEmpty() const;                              /* 判断是否为空树 */
	void insert(const int &val);                       /* 插入 */
	void deleteByMerging(BSTNode *p);                  /* 合并删除 */
	void findAndDeleteByMerging(const int& val);
	void deleteByCopying(BSTNode *p);                  /* 复制删除 */
	void interactivePreordor() const;                  /* 深度优先之前序遍历-非递归实现 */
	void interactiveInordor() const;                   /* 深度优先之中序遍历-非递归实现 */
	void interactivePostordor() const;                 /* 深度优先之后序遍历-非递归实现 */

private:
    BSTNode *root;

    void clear(BSTNode *p);
    int *search(BSTNode *p, const int &val) const;     /* 查找-对内实现 */
	void preordor(BSTNode *p) const;                   /* 深度优先之前序遍历-递归实现 */
	void inordor(BSTNode *p) const;                    /* 深度优先之中序遍历-递归实现 */
	void postordor(BSTNode *p) const;                  /* 深度优先之后序遍历-递归实现 */
    void visit(BSTNode *p) const;

};

/* 树节点构造函数 */
BSTNode::BSTNode(const int val)
{
	left = nullptr;
	right = nullptr;
	value = val;
}
BSTNode::BSTNode(BSTNode *lf, BSTNode *rg, const int val)
{
    left = lf;
    right = rg;
    value = val;
}
