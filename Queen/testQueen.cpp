#include "ChessBoard.h"


int main()
{
    ChessBoard test_queen(8);          /* ����8�ʺ����� */
    test_queen.findSolutions();

    std::cout << std::endl;
    system("pause");
    return 0;
}