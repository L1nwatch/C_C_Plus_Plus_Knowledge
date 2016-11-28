//输入
//        从键盘输入一个整数n，然后按上面的公式求和。
//
//输出
//        输出求和的结果s。s为双精度浮点数，精确到小数点后面8位。
//
//样例输入
//22
//样例输出
//0.67093591

#include <stdio.h>
#include <math.h>

void solve(int n)
{
    double result = 0;
    for (int i = 1; i <= n; ++i)
    {
        result += pow(-1, i + 1) * 1 / i;
    }
    printf("%.8f", result);
}

int main(void)
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        solve(n);
    }

    return 0;
}
