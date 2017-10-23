#pragma once

/* 树的节点 */
class BSTNode
{
public:
    BSTNode *left;
    BSTNode *right;
    int value;

    BSTNode(BSTNode *lf = nullptr, BSTNode *rg = nullptr, const int val = 0);
};

class BST
{
public:
    BST();
    ~BST();

    void breadthFirst();                         /* 广度优先遍历 */
    void preordor();                             /* 深度优先之前序遍历 */
    void inordor();                              /* 深度优先之中序遍历 */
    void postordor();                            /* 深度优先之后序遍历 */
    int *search(const int &val) const;           /* 查找 */
    void clear();                                /* 清空树 */
    bool isEmpty() const;                        /* 判断是否为空树 */
    void insert(const int &val);                 /* 插入 */
    void deleteByMerging(BSTNode *p);            /* 合并删除 */
    void findAndDeleteByMerging(const int& val);
    void deleteByCopying(BSTNode *p);            /* 复制删除 */

private:
    BSTNode *root;

    void clear(BSTNode *p);
    int *search(BSTNode *p, const int &val) const;
    void preordor(BSTNode *p) const;
    void inordor(BSTNode *p) const;
    void postordor(BSTNode *p) const;
    void visit(BSTNode *p) const;

};

BSTNode::BSTNode(BSTNode * lf, BSTNode * rg, const int val)
{
    left = lf;
    right = rg;
    value = val;
}
