#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Changed board to vector<string> for easier indexing and 'char' handling
bool isSafe(int row, int col, int n, vector<string> &board)
{
    // Check this column on upper side
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

void placeNQueens(int row, int n, vector<string> &board, vector<vector<string>> &result)
{
    // Base Case: If all queens are placed
    if (row == n)
    {
        result.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col, n, board))
        {
            board[row][col] = 'Q'; // Place queen
            placeNQueens(row + 1, n, board, result);
            board[row][col] = '.'; // Backtrack (Reset)
        }
    }
}

vector<vector<string>> nQueen(int n)
{
    // Initialize an n x n board with '.'
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> result;

    // Start recursion from the first row (0)
    placeNQueens(0, n, board, result);

    return result;
}

int main()
{
    int n = 4; // Example size
    vector<vector<string>> solutions = nQueen(n);

    cout << "Found " << solutions.size() << " solutions:" << endl
         << endl;
    for (const auto &sol : solutions)
    {
        for (const string &row : sol)
        {
            cout << row << endl;
        }
        cout << "---" << endl;
    }

    return 0;
}