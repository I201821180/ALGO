#include <stdexcept>
#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if (n <= 0)
    {
        throw invalid_argument("Invalide input.");
    }

    if (n <= 2)
    {
        return 1;
    }

    int a = 1, b = 1;
    int f;

    for (int i = 3; i <= n; i++)
    {
        f = a + b;
        a = b;
        b = f;
    }

    return f;
}

int main()
{
    cout << "F(10) = " << fibonacci(10) << endl;
    return 0;
}

