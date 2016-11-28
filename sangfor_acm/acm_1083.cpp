//输入
//        输入一双精度浮点数x
//
//输出
//        根据分段函数，输出x对应的y值。
//
//样例输入
//25
//样例输出
//        y=125.000000

#include <stdio.h>
#include <math.h>

void solve(double x)
{
    double result;
    if (x < 0)
    {
        result = fabs(x) / 2;
    } else if (x >= 0 && x < 10)
    {
        result = exp(x) + 3;
    } else if (x >= 10 && x < 20)
    {
        result = log10(x);
    } else if (x >= 20 && x < 30)
    {
        result = pow(x, 1.5);
    } else if (x >= 30 && x < 50)
    {
        result = sqrt(x) - 1;
    } else if (x >= 50)
    {
        result = 3 * cos(x);
    }
    printf("y=%lf", result);
}

int main(void)
{
    double x;
    while (scanf("%lf", &x) != EOF)
    {
        solve(x);
    }


    return 0;
}
