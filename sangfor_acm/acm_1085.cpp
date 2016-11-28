//输入
//        先输入一个整数n，表示后面总共要输入n组测试数据；
//
//然后输入n组测试数据，每组测试数据是一个双精度浮点数x。
//
//输出
//        根据输入的n组测试数据，对应输出n个输出结果，每个输出结果单独占一行，即每个输出结果后要加换行符。
//
//样例输入
//3
//25
//-2
//49
//样例输出
//        y=125.000000
//y=1.000000
//y=6.000000


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
    printf("y=%lf\n", result);
}

int main(void)
{
    double x;
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%lf", &x);
        solve(x);
    }

    return 0;
}
