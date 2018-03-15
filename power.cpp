/*
 * 数值的整数次方
 */

#include <iostream>


double TOLERANCE = 1e-10;

double power_core(double base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }

    if (exponent == 1)
    {
        return base;
    }

    double result = power_core(base, exponent >> 1);
    result *= result;

    if ((exponent & 0x1) == 1)
    {
        result *= base;
    }

    return result;
}

double Power(double base, int exponent)
{
    if (base - 0.0 < TOLERANCE && exponent == 0)
    {
        return 0.0;
    }

    if (exponent < 0)
    {
        return 1.0/power_core(base, -exponent);
    }
    else
    {
        return power_core(base, exponent);
    }
}

int main()
{
    std::cout << "3^2 = " << Power(3, 2) << std::endl;
    return 0;
}

