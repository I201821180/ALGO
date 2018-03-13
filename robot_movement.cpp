/*
 * 机器人运动范围C++实现
 */

#include <iostream>


int get_digit_sum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

bool check(int threshold, int row, int col, int rows, int cols, bool *visited)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols && !visited[row*cols+col]
            && (get_digit_sum(row) + get_digit_sum(col)) <= threshold)
    {
        return true;
    }

    return false;
}

int moving_count_core(int threshold, int row, int col, int rows, int cols, bool *visited)
{
    int count = 0;

    bool valide = check(threshold, row, col, rows, cols, visited);
    if (valide)
    {
        visited[row*cols+col] = true;
        count += (1 + moving_count_core(threshold, row-1, col, rows, cols, visited)  // up
            + moving_count_core(threshold, row+1, col, rows, cols, visited)     // down
            + moving_count_core(threshold, row, col-1, rows, cols, visited)     // left
            + moving_count_core(threshold, row, col+1, rows, cols, visited));    // right
    }

    return count;
}

int movingCount(int threshold, int rows, int cols)
{
    if (threshold < 0 || rows <= 0 || cols <= 0)
    {
        return 0;
    }

    bool *visited = new bool[rows*cols];
    for (int i = 0; i < rows*cols; i++)
    {
        visited[i] = false;
    }

    int count;

    count = moving_count_core(threshold, 0, 0, rows, cols, visited);

    delete [] visited;

    return count;
}

int main()
{
    int path_count = movingCount(5, 10, 10);

    std::cout << "Moving count: " << path_count << std::endl;

    return 0;
}

