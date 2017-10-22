#pragma once
#include <iostream>

class ChessBoard
{
public:
    ChessBoard();            /* Ĭ�ϣ�8�ʺ����� */
    ChessBoard(int n);       /* n�ʺ����� */
    ~ChessBoard();
    void findSolutions();    /* 8�ʺ������ܹ���92�ֽ������ */

private:
    const bool available;    /* ״̬��־ */
    const int squares;
    const int norm;          /* ���������ֵ����ҶԽ��������±꣬���������±�Ϊ���� */
    int how_many;            /* ��¼�ܹ��ж����ֽ������ */
    bool *column;            /* ��¼ÿһ�е�״̬ */
    bool *left_diagonal;     /* ��¼��Խ��ߵ�״̬ */
    bool *right_diagonal;    /* ��¼�ҶԽ��ߵ�״̬ */
    int *position_in_row;    /* ��¼ÿ�лʺ��λ�� */

    void initializeBoard();  /* ��ʼ�� */
    void putQueen(int row);  /* �õݹ鷽������������� */
    void printBoard();       /* ��ӡ������� */


};

