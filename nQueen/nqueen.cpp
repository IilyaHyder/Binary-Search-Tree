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
                std::cout << "Q ";
            }
            else
            {
                std::cout << "X ";
            }
        }
        std::cout << std::endl;
    }
}

bool isSafe(std::vector<std::vector<bool>> &board, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col])
        {
            return false;
        }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < (int)board.size(); i--, j++)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    return true;
}

int nQueen(std::vector<std::vector<bool>> &board, int row)
{
    if (row == (int)board.size())
    {
        showboard(board);
        std::cout << std::endl;

        return 1;
    }

    int count = 0;

    for (int col = 0; col < (int)board.size(); col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = true;
            count += nQueen(board, row + 1);

            board[row][col] = false;
        }
    }

    return count;
}

int main()
{
    int n = 4;
    std::vector<std::vector<bool>> board(n, std::vector<bool>(n, false));

    std::cout << nQueen(board, 0);

    return 0;
}