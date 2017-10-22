#include "ChessBoard.h"

/************************************************************************/
/*                            解题思路                                  */
/*  从皇后的角度来观察棋盘，对于皇后来说，棋盘可划分为行、列、斜线。
    如果皇后置于一个方块中，它并不局限于这个方块，这一方块所在的整个行、
    列、斜线均被视为其私有领地。这种思路可以用一种数据结构来表示。
    简化问题起见，用4皇后问题来进行阐释，4皇后问题棋盘如下图所示：
                        0,0   0,1   0,2   0,3
                        1,0   1,1   1,2   1,3
                    左↗2,0   2,1   2,2   2,3↖右
                        3,0   3,1   3,2   3,3
    观察可知，指示“左”的斜线上所有位置的横竖坐标加起来为2，r+c=2；
    这个数字与这条对角线相关，一共有7条对角线，与它们相关的数分别是0到6。
    指示“右”的斜线上所有位置的横竖左边之间的差值相同，r-c=-1，每条右斜
    线的这个值都不同。这样，给右斜线赋值为-3到3。左斜线使用的数据结构是一
    个下标从0到6的简单数组。对右斜线而言，其数据结构也是一个具有7个元素的
    数组，但是数组的下标不能为负数，考虑到r-c得到的负值，因此给r-c统一加上
    一个数，从而避免数组越界。
    对列来说，也需要一个类似的数组，但行不需要，因为皇后i沿着第i行移动，
    而所有小于i的皇后已置于小于i的各行上了。
/************************************************************************/

/* 8皇后问题 */
ChessBoard::ChessBoard() : squares(8), available(true), norm(squares - 1)
{
    initializeBoard();
}

/* n皇后问题 */
ChessBoard::ChessBoard(int n) : squares(n), available(true), norm(squares - 1)
{
    initializeBoard();
}

/* 初始化 */
void ChessBoard::initializeBoard()
{
    how_many = 0;
    position_in_row = new int[squares];
    column = new bool[squares];
    left_diagonal = new bool[2 * squares - 1];
    right_diagonal = new bool[2 * squares - 1];
    for (int i = 0; i != 2 * squares - 1; ++i)
    {
        left_diagonal[i] = available;
        right_diagonal[i] = available;
    }
    for (int i = 0; i != squares; ++i)
    {
        column[i] = available;
        position_in_row[i] = -1;
    }
    return;
}

/* 用递归方法解决回溯问题 */
void ChessBoard::putQueen(int row)
{
    for (int col = 0; col != squares; ++col)
    {
        if (available == column[col] &&
            available == left_diagonal[row + col] &&
            available == right_diagonal[row - col + norm])
        {
            position_in_row[row] = col;
            column[col] = !available;
            left_diagonal[row + col] = !available;
            right_diagonal[row - col + norm] = !available;
            if (row <= squares - 2)    /* 注意这里row的取值上界 */
            {
                putQueen(row + 1);
            }
            else                       /* 每找到一种解决方案就打印出来 */
            {
                ++how_many;
                printBoard();
            }
            /* 注意，下面这三句话的状态设置对于实现回溯至关重要，
               如若无法理解可以摆一个4皇后问题来辅助理解 */
            column[col] = available;
            left_diagonal[row + col] = available;
            right_diagonal[row - col + norm] = available;
        }
    }
}

void ChessBoard::printBoard()
{
    for (int i = 0; i != squares; ++i)
    {
        std::cout << position_in_row[i] << "  ";
    }
    std::cout << std::endl;
}

void ChessBoard::findSolutions()
{
    putQueen(0);             /* 从第一行开始放皇后 */
    std::cout << how_many << " solutions found." << std::endl;
}

/* 析构，释放内存 */
ChessBoard::~ChessBoard()
{
    delete[] position_in_row;
    delete[] column;
    delete[] left_diagonal;
    delete[] right_diagonal;
}

