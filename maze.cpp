#include <iostream>
#include <vector>
#include <string>

int count(int row, int col)
{
    if (row == 1 || col == 1)
        return 1;

    int cnt = 0;
    int rowSum = count(row - 1, col);
    int colSum = count(row, col - 1);

    cnt = rowSum + colSum;

    return cnt;
}

void mazePath(std::string s, int row, int col)
{
    if (row == 1 && col == 1)
    {
        std::cout << s << std::endl;
    }
    if (row > 1)
    {
        mazePath(s + 'V', row - 1, col);
    }
    if (col > 1)
    {
        mazePath(s + 'H', row, col - 1);
    }
    if (row > 1 && col > 1)
    {
        mazePath(s + 'D', row - 1, col - 1);
    }
}

void mazePathWithRestrictions(std::string s, std::vector<std::vector<bool>> &maze, int row, int col)
{
    if (row == (int)maze.size() - 1 && col == (int)maze[0].size() - 1)
    {
        std::cout << s << " ";
        return;
    }

    if (!maze[row][col])
    {
        return;
    }

    if (row < (int)maze.size() - 1)
    {
        mazePathWithRestrictions(s + 'D', maze, row + 1, col);
    }
    if (col < (int)maze[0].size() - 1)
    {
        mazePathWithRestrictions(s + 'R', maze, row, col + 1);
    }
}

void backtrackingFirst(std::string s, std::vector<std::vector<bool>> &maze, int row, int col)
{
    if (row == (int)maze.size() - 1 && col == (int)maze[0].size() - 1)
    {
        std::cout << s << " ";
        return;
    }

    if (!maze[row][col])
        return;

    maze[row][col] = false;

    if (row < (int)maze.size() - 1)
    {
        backtrackingFirst(s + 'D', maze, row + 1, col);
    }
    if (col < (int)maze[0].size() - 1)
    {
        backtrackingFirst(s + 'R', maze, row, col + 1);
    }
    if (row > 0)
    {
        backtrackingFirst(s + 'U', maze, row - 1, col);
    }
    if (col > 0)
    {
        backtrackingFirst(s + 'L', maze, row, col - 1);
    }

    maze[row][col] = true;
}

void allPathsBT(std::string s, std::vector<std::vector<bool>> &maze, int row, int col, std::vector<std::vector<int>> &path, int step)
{
    if (!maze[row][col])
        return;

    maze[row][col] = false;
    path[row][col] = step;

    if (row == (int)maze.size() - 1 && col == (int)maze[0].size() - 1)
    {
        for (auto &rows : path)
        {
            for (auto &elm : rows)
            {
                std::cout << elm << " ";
            }
            std::cout << std::endl;
        }
        std::cout << s << " ";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        maze[row][col] = true;
        path[row][col] = 0;
        return;
    }

    if (row < (int)maze.size() - 1)
    {
        allPathsBT(s + 'D', maze, row + 1, col, path, step + 1);
    }
    if (col < (int)maze[0].size() - 1)
    {
        allPathsBT(s + 'R', maze, row, col + 1, path, step + 1);
    }
    if (row > 0)
    {
        allPathsBT(s + 'U', maze, row - 1, col, path, step + 1);
    }
    if (col > 0)
    {
        allPathsBT(s + 'L', maze, row, col - 1, path, step + 1);
    }
    maze[row][col] = true;
    path[row][col] = 0;
}

int main()
{
    std::vector<std::vector<bool>> maze = {{true, true, true}, {true, true, true}, {true, true, true}};
    int m = maze.size();
    int n = maze[0].size();
    std::vector<std::vector<int>> path(m, std::vector<int>(n, 0));
    allPathsBT("", maze, 0, 0, path, 1);

    return 0;
}