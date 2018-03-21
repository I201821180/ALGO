/*
 * 数组中出现次数超过一半的数字
 */

#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

int partition(vector<int> numbers, int start, int end)
{
    if (numbers.size() <= 0 || start > end)
    {
        throw invalid_argument("Invalid input");
    }

    if (start == end)
    {
        return start;
    }

    int pivot = numbers[start];
    int i = start, j = end;

    while (i < j)
    {
        while (numbers[j] >= pivot && j > i)
        {
            j--;
        }

        if (j > i)
        {
            numbers[i] = numbers[j];
            i++;
        }

        while (numbers[i] <= pivot && i < j)
        {
            i++;
        }

        if (i < j)
        {
            numbers[j] = numbers[i];
            j--;
        }
    }

    numbers[i] = pivot;
    return i;
}

int get_index(vector<int> numbers, int start, int end)
{
    int isplit = partition(numbers, start, end);
    if (isplit == numbers.size()/2)
    {
        return isplit;
    }

    if (isplit < int(numbers.size()/2))
    {
        return get_index(numbers, isplit+1, end);
    }
    else
    {
        return get_index(numbers, start, isplit-1);
    }
}

bool check_more_than_half(vector<int> numbers, int number)
{
    int count = 0;
    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == number)
        {
            count++;
        }
    }

    if ((unsigned int)count > numbers.size()/2)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int MoreThanHalfNum_Solution(vector<int> numbers)
{
    if (numbers.size() <= 0)
    {
        throw invalid_argument("Invalid input");
    }

    int idx = get_index(numbers, 0, numbers.size()-1);

    int median = numbers[idx];

    if (check_more_than_half(numbers, median))
    {
        return median;
    }
    else
    {
        return 0;
    }
}

int main()
{
    vector<int> numbers = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int median = MoreThanHalfNum_Solution(numbers);

    cout << median << endl;
    return 0;
}

