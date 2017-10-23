#pragma once

/* ���Ľڵ� */
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

    void breadthFirst();                         /* ������ȱ��� */
    void preordor();                             /* �������֮ǰ����� */
    void inordor();                              /* �������֮������� */
    void postordor();                            /* �������֮������� */
    int *search(const int &val) const;           /* ���� */
    void clear();                                /* ����� */
    bool isEmpty() const;                        /* �ж��Ƿ�Ϊ���� */
    void insert(const int &val);                 /* ���� */
    void deleteByMerging(BSTNode *p);            /* �ϲ�ɾ�� */
    void findAndDeleteByMerging(const int& val);
    void deleteByCopying(BSTNode *p);            /* ����ɾ�� */

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
