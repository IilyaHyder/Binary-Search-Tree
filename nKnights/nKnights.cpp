#include <iostream>
#include <vector>

void showboard(std::vector<std::vector<bool>> &board)
{
    for (int i = 0; i < (int)board.size(); i++)
    {
        for (int j = 0; j < (int)board.size(); j++)
        {
            if (board[i][j])
            {
                std::cout << "K ";
            }
            else
            {
                std::cout << "X ";
            }
        }
        std::cout << std::endl;
    }
}

bool isValid(int row, int col, int n)
{
    if (row >= 0 && col >= 0 && row < n && col < n)
    {
        return true;
    }
    return false;
}

bool isSafe(std::vector<std::vector<bool>> &board, int row, int col)
{
    int n = board.size();

    if (isValid(row - 2, col - 1, n) && board[row - 2][col - 1])
        return false;
    if (isValid(row - 2, col + 1, n) && board[row - 2][col + 1])
        return false;
    if (isValid(row - 1, col - 2, n) && board[row - 1][col - 2])
        return false;
    if (isValid(row - 1, col + 2, n) && board[row - 1][col + 2])
        return false;

    else
        return true;
}

void nKnights(std::vector<std::vector<bool>> &board, int row, int col, int knights)
{
    if (knights == 0)
    {
        showboard(board);
        std::cout << std::endl;

        return;
    }

    if (row == (int)board.size())
    {
        return;
    }

    if (col == (int)board.size())
    {
        nKnights(board, row + 1, 0, knights);
        return;
    }

    if (isSafe(board, row, col))
    {
        board[row][col] = true;
        nKnights(board, row, col + 1, knights - 1);
        board[row][col] = false;
    }

    nKnights(board, row, col + 1, knights);
}

int main()
{
    int n = 4;
    std::vector<std::vector<bool>> board(n, std::vector<bool>(n, false));

    nKnights(board, 0, 0, n);

    return 0;
}