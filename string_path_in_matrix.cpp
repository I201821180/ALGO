#include <iostream>

bool has_path(char *matrix, int row, int rows, int col, int cols, char *str, int & current_position, bool *visited)
{
    if (str[current_position] == '\0')
    {
        return true;
    }

    bool hasPath = false;

    if (row >= 0 && row < rows && col >= 0 && col < cols
            && matrix[row*cols+col] == str[current_position]
            && !visited[row*cols+col])
    {
        current_position++;
        visited[row*cols+col] = true;

        // The next.
        hasPath = has_path(matrix, row-1, rows, col, cols, str, current_position, visited)  // upper
            || has_path(matrix, row+1, rows, col, cols, str, current_position, visited)     // down
            || has_path(matrix, row, rows, col-1, cols, str, current_position, visited)     // left
            || has_path(matrix, row, rows, col+1, cols, str, current_position, visited);    // right

        if (!hasPath)
        {
            current_position--;
            visited[row*cols+col] = false;
        }
    }

    return hasPath;
}

bool hasPath(char *matrix, int rows, int cols, char *str)
{
    if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
    {
        return false;
    }

    bool *visited = new bool[rows*cols];
    for (int i = 0; i < rows*cols; i++)
    {
        visited[i] = false;
    }

    int current_position = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (has_path(matrix, row, rows, col, cols, str, current_position, visited))
            {
                delete [] visited;
                return true;
            }
        }
    }

    delete [] visited;

    return false;
}

int main()
{
    char matrix[12] = {
        'a', 'b', 't', 'g',
        'c', 'f', 'c', 's',
        'j', 'd', 'e', 'h'
    };

    char str[10] = "bfce";

    bool has_path = hasPath(matrix, 3, 4, str);

    if (has_path)
    {
        std::cout << "Has path" << std::endl;
    }
    else
    {
        std::cout << "Has no path" << std::endl;
    }

    return 0;
}

