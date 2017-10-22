#include "ChessBoard.h"


int main()
{
    ChessBoard test_queen(8);          /* 测试8皇后问题 */
    test_queen.findSolutions();

    std::cout << std::endl;
    system("pause");
    return 0;
}
