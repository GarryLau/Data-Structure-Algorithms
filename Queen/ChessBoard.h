#pragma once
#include <iostream>

class ChessBoard
{
public:
    ChessBoard();            /* 默认，8皇后问题 */
    ChessBoard(int n);       /* n皇后问题 */
    ~ChessBoard();
    void findSolutions();    /* 8皇后问题总共有92种解决方案 */

private:
    const bool available;    /* 状态标志 */
    const int squares;
    const int norm;          /* 用作常数字调整右对角线数组下标，避免数组下标为负数 */
    int how_many;            /* 记录总共有多少种解决方案 */
    bool *column;            /* 记录每一列的状态 */
    bool *left_diagonal;     /* 记录左对角线的状态 */
    bool *right_diagonal;    /* 记录右对角线的状态 */
    int *position_in_row;    /* 记录每行皇后的位置 */

    void initializeBoard();  /* 初始化 */
    void putQueen(int row);  /* 用递归方法解决回溯问题 */
    void printBoard();       /* 打印解决方案 */


};

