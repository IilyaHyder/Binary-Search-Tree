#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // Use arrays to track digits 1-9 seen in each row, column, and 3x3 box
        bool rowSeen[9][9] = {false};
        bool colSeen[9][9] = {false};
        bool boxSeen[9][9] = {false};

        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] == '.')
                    continue;

                int digit = board[r][c] - '1'; // Convert '1'-'9' to index 0-8
                int boxIdx = (r / 3) * 3 + (c / 3);

                // If this digit has already been seen in this row, col, or box
                if (rowSeen[r][digit] || colSeen[c][digit] || boxSeen[boxIdx][digit])
                {
                    return false;
                }

                // Mark this digit as seen
                rowSeen[r][digit] = true;
                colSeen[c][digit] = true;
                boxSeen[boxIdx][digit] = true;
            }
        }

        return true;
    }
};