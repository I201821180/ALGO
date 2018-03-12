#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int min_number_in_rotate_array(vector<int> rotateArray)
{
    if (rotateArray.size() <= 0)
    {
        return 0;
    }

    int mid_idx = 0;
    int idx1 = 0, idx2 = rotateArray.size() - 1;

    while (rotateArray[idx1] >= rotateArray[idx2])
    {
        if ((idx2 - idx1) == 1)
        {
            mid_idx = idx2;
            break;
        }

        mid_idx = (idx1 + idx2)/2;

        if (rotateArray[idx1] == rotateArray[mid_idx]
                && rotateArray[mid_idx] == rotateArray[idx2])
        {
            int min = 0;
            for (size_t i = 0; i < rotateArray.size(); i++)
            {
                if (rotateArray[i] < min)
                {
                    min = rotateArray[i];
                }
            }

            return min;
        }

        if (rotateArray[idx1] >= rotateArray[mid_idx])
        {
            idx2 = mid_idx;
        }
        else if (rotateArray[mid_idx] >= rotateArray[idx2])
        {
            idx1 = mid_idx;
        }
    }

    return rotateArray[mid_idx];
}

int main()
{
    vector<int> data = {3, 4, 5, 1, 2};
    cout << "Min: " << min_number_in_rotate_array(data) << endl;

    return 0;
}

