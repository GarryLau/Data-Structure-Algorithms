#include "ChessBoard.h"

/************************************************************************/
/*                            ����˼·                                  */
/*  �ӻʺ�ĽǶ����۲����̣����ڻʺ���˵�����̿ɻ���Ϊ�С��С�б�ߡ�
    ����ʺ�����һ�������У�������������������飬��һ�������ڵ������С�
    �С�б�߾�����Ϊ��˽����ء�����˼·������һ�����ݽṹ����ʾ��
    �������������4�ʺ����������в��ͣ�4�ʺ�������������ͼ��ʾ��
                        0,0   0,1   0,2   0,3
                        1,0   1,1   1,2   1,3
                    ��J2,0   2,1   2,2   2,3�I��
                        3,0   3,1   3,2   3,3
    �۲��֪��ָʾ���󡱵�б��������λ�õĺ������������Ϊ2��r+c=2��
    ��������������Խ�����أ�һ����7���Խ��ߣ���������ص����ֱ���0��6��
    ָʾ���ҡ���б��������λ�õĺ������֮��Ĳ�ֵ��ͬ��r-c=-1��ÿ����б
    �ߵ����ֵ����ͬ������������б�߸�ֵΪ-3��3����б��ʹ�õ����ݽṹ��һ
    ���±��0��6�ļ����顣����б�߶��ԣ������ݽṹҲ��һ������7��Ԫ�ص�
    ���飬����������±겻��Ϊ���������ǵ�r-c�õ��ĸ�ֵ����˸�r-cͳһ����
    һ�������Ӷ���������Խ�硣
    ������˵��Ҳ��Ҫһ�����Ƶ����飬���в���Ҫ����Ϊ�ʺ�i���ŵ�i���ƶ���
    ������С��i�Ļʺ�������С��i�ĸ������ˡ�
/************************************************************************/

/* 8�ʺ����� */
ChessBoard::ChessBoard() : squares(8), available(true), norm(squares - 1)
{
    initializeBoard();
}

/* n�ʺ����� */
ChessBoard::ChessBoard(int n) : squares(n), available(true), norm(squares - 1)
{
    initializeBoard();
}

/* ��ʼ�� */
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

/* �õݹ鷽������������� */
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
            if (row <= squares - 2)    /* ע������row��ȡֵ�Ͻ� */
            {
                putQueen(row + 1);
            }
            else                       /* ÿ�ҵ�һ�ֽ�������ʹ�ӡ���� */
            {
                ++how_many;
                printBoard();
            }
            /* ע�⣬���������仰��״̬���ö���ʵ�ֻ���������Ҫ��
               �����޷������԰�һ��4�ʺ�������������� */
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
    putQueen(0);             /* �ӵ�һ�п�ʼ�Żʺ� */
    std::cout << how_many << " solutions found." << std::endl;
}

/* �������ͷ��ڴ� */
ChessBoard::~ChessBoard()
{
    delete[] position_in_row;
    delete[] column;
    delete[] left_diagonal;
    delete[] right_diagonal;
}

