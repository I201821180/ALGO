#include <vector>
#include <iostream>

using namespace std;

void print_circle(vector<vector<int>> & matrix, int start, int nrows, int ncols, vector<int> & output)
{
    int end_x = ncols - start -1;
    int end_y = nrows - start -1;

    for (int j = start; j <= end_x; j++)
    {
        output.push_back(matrix[start][j]);
    }

    if (end_y > start)
    {
        for (int i = start+1; i <= end_y; i++)
        {
            output.push_back(matrix[i][end_x]);
        }
    }

    if (end_y > start && end_x > start)
    {
        for (int j = end_x-1; j >= start; j--)
        {
            output.push_back(matrix[end_y][j]);
        }
    }

    if (end_y-1 > start && end_x > start)
    {
        for (int i = end_y-1; i >= start+1; i--)
        {
            output.push_back(matrix[i][start]);
        }
    }
}

vector<int> printMatrix(vector<vector<int> > matrix)
{
    int nrows = matrix.size();
    int ncols = matrix[0].size();

    vector<int> output;

    int i = 0;
    while (nrows > i*2 && ncols > i*2)
    {
        print_circle(matrix, i, nrows, ncols, output);
        i++;
    }

    return output;
}

int main()
{
    vector<vector<int> > matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int> output = printMatrix(matrix);

    for (size_t i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}

